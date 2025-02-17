#include <iostream>
#include <ctime>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <netinet/ip.h>
#include <netinet/ether.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <semaphore.h>
#include <ncurses.h>
#include <chrono>

#define SHM_NAME "/phud_shm"
#define SEM_NAME "/phud_sem"
#define SHM_SIZE 1024
#define CHANNEL_HEIGHT 10 // Number of rows in the RX channel

// Define PGEN's MAC and IP (Laptop running pgen)
#define PGEN_MAC "bc:e9:2f:80:3b:56"
#define PGEN_IP "192.168.0.111"

// Shared memory and semaphore
char *shared_mem;
sem_t *semaphore;

// HUD elements
int spinner_position = 0;
const char spinner_chars[] = "|/-\\";
bool packet_received = false;  
double last_packet_time = 0.0;  // ✅ Track the last received timestamp

// Function to parse and update HUD from shared memory
void update_hud() {
    sem_wait(semaphore);
    std::string packet_data(shared_mem);
    sem_post(semaphore);

    if (packet_data.empty()) return;

    clear();
    mvprintw(0, 5, "RX Channel");

    // Draw the channel
    for (int i = 1; i <= CHANNEL_HEIGHT; ++i) {
        mvprintw(i, 5, "|");
    }

    // Parse JSON-like packet info
    std::string src_mac, dst_mac, src_ip, dst_ip;
    int size;
    double packet_timestamp = 0.0;

    std::stringstream ss(packet_data);
    std::string token;

    while (std::getline(ss, token, ',')) {
        if (token.find("\"size\"") != std::string::npos)
            size = std::stoi(token.substr(token.find(":") + 1));
        else if (token.find("\"timestamp\"") != std::string::npos)
            packet_timestamp = std::stod(token.substr(token.find(":") + 1));
        else if (token.find("\"src_mac\"") != std::string::npos)
            src_mac = token.substr(token.find(":") + 3, 17);
        else if (token.find("\"dst_mac\"") != std::string::npos)
            dst_mac = token.substr(token.find(":") + 3, 17);
        else if (token.find("\"src_ip\"") != std::string::npos)
            src_ip = token.substr(token.find(":") + 3, token.length() - 4);
        else if (token.find("\"dst_ip\"") != std::string::npos)
            dst_ip = token.substr(token.find(":") + 3, token.length() - 4);
    }

    // ✅ Calculate correct timestamp delta
    double delta_time = packet_timestamp - last_packet_time;
    last_packet_time = packet_timestamp;  // ✅ Update last timestamp

    // Show detailed info
    mvprintw(2, 10, "SRC MAC: %s", src_mac.c_str());
    mvprintw(3, 10, "DST MAC: %s", dst_mac.c_str());
    mvprintw(4, 10, "SRC IP: %s", src_ip.c_str());
    mvprintw(5, 10, "DST IP: %s", dst_ip.c_str());
    mvprintw(6, 10, "Size: %d bytes", size);
    mvprintw(7, 10, "Timestamp: %.6f sec", packet_timestamp);  // ✅ Show full precision!
    mvprintw(8, 10, "Delta Time: %.6f sec", delta_time);  // ✅ Show packet timing gap!

    // ✅ Spinner moves only when a new packet arrives
    if (packet_received) {
        spinner_position = (spinner_position + 1) % CHANNEL_HEIGHT;
        packet_received = false;  
    }
    mvprintw(spinner_position + 1, 5, "%c", spinner_chars[spinner_position % 4]);

    refresh();
}

int main() {
    // Open shared memory
    int shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, SHM_SIZE);
    shared_mem = (char *)mmap(0, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);

    // Initialize semaphore
    semaphore = sem_open(SEM_NAME, O_CREAT, 0666, 1);

    // Initialize ncurses
    initscr();
    noecho();
    curs_set(0);

    while (true) {
        update_hud();
        usleep(50000); // Reduce CPU usage
    }

    // Cleanup
    endwin();
    shm_unlink(SHM_NAME);
    sem_close(semaphore);
    sem_unlink(SEM_NAME);
    return 0;
}
