#include <pcap.h>
#include <iostream>
#include <ctime>
#include <cstring>
#include <netinet/ip.h>
#include <netinet/ether.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <semaphore.h>
#include <sstream>

#define SNAP_LEN 1518 // Max packet size
#define SHM_NAME "/phud_shm"
#define SEM_NAME "/phud_sem"
#define SHM_SIZE 1024

// Define PGEN's MAC and IP (Laptop running pgen)
#define PGEN_MAC "bc:e9:2f:80:3b:56"
#define PGEN_IP "192.168.0.111"

// Shared memory and semaphore
char *shared_mem;
sem_t *semaphore;

// Packet handler function
void packet_handler(u_char *user, const struct pcap_pkthdr *pkthdr, const u_char *packet) {
    struct ether_header *eth_hdr = (struct ether_header *)packet;
    
    // Extract MAC addresses
    std::string src_mac = ether_ntoa((struct ether_addr *)eth_hdr->ether_shost);
    std::string dst_mac = ether_ntoa((struct ether_addr *)eth_hdr->ether_dhost);
    
    // Extract IP addresses if it's an IP packet
    std::string src_ip = "", dst_ip = "";
    if (ntohs(eth_hdr->ether_type) == ETHERTYPE_IP) {
        struct ip *ip_hdr = (struct ip *)(packet + sizeof(struct ether_header));
        src_ip = inet_ntoa(ip_hdr->ip_src);
        dst_ip = inet_ntoa(ip_hdr->ip_dst);
    }
    
    // Filter: Only write packets from PGEN (Laptop)
    if (src_mac != PGEN_MAC || src_ip != PGEN_IP) {
        return; // Ignore all other packets
    }
    
    std::time_t timestamp = pkthdr->ts.tv_sec;
    std::stringstream packet_info;
    packet_info << "{" << "\"size\": " << pkthdr->len
                << ", \"timestamp\": " << timestamp
                << ", \"src_mac\": \"" << src_mac << "\""
                << ", \"dst_mac\": \"" << dst_mac << "\"";
    
    if (!src_ip.empty()) {
        packet_info << ", \"src_ip\": \"" << src_ip << "\""
                    << ", \"dst_ip\": \"" << dst_ip << "\"";
    }
    packet_info << "}";
    
    // Write to shared memory
    sem_wait(semaphore);  // Wait for access
    memset(shared_mem, 0, SHM_SIZE);
    strncpy(shared_mem, packet_info.str().c_str(), SHM_SIZE - 1);
    sem_post(semaphore);  // Signal update
    
    std::cout << "[NET] PGEN Packet Captured: " << packet_info.str() << "\n";
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <network_interface>\n";
        return 1;
    }

    // Open shared memory
    int shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, SHM_SIZE);
    shared_mem = (char *)mmap(0, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    
    // Initialize semaphore
    semaphore = sem_open(SEM_NAME, O_CREAT, 0666, 1);
    
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_live(argv[1], SNAP_LEN, 1, 1000, errbuf);
    if (!handle) {
        std::cerr << "[ERROR] Unable to open interface " << argv[1] << ": " << errbuf << "\n";
        return 1;
    }

    std::cout << "[NET] Listening on interface: " << argv[1] << "\n";
    pcap_loop(handle, -1, packet_handler, nullptr);
    
    pcap_close(handle);
    shm_unlink(SHM_NAME);
    sem_close(semaphore);
    sem_unlink(SEM_NAME);
    return 0;
}
