#include "net.hpp"
#include <iostream>

void Net::initialize(const std::string& interface) {
    netInterface = interface;
    std::cout << "Initializing network capture on interface: " << netInterface << std::endl;
}

PacketInfo Net::capturePacket() {
    std::cout << "Capturing packet..." << std::endl;
    PacketInfo packet;
    packet.size = 128;  // ✅ Ensure some meaningful packet data
    packet.src_ip = "10.10.10.1";
    packet.dst_ip = "10.10.10.2";
    return packet;
}
