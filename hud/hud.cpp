#include "hud.hpp"
#include <iostream>

void Hud::initialize() {
    std::cout << "HUD Initialized" << std::endl;
    sharedMemory.initialize();
}

void Hud::render() {
    std::cout << "Rendering HUD" << std::endl;
    sharedMemory.sendMessage("Packet data");  // ✅ sendMessage() replaces writeData()
}

void Hud::update() {
    std::cout << "Updating HUD with new packet info" << std::endl;
    std::string message = sharedMemory.receiveMessage();
    lastPacket.size = message.size();  // ✅ Store packet info
    lastPacket.src_ip = "10.10.10.1";
    lastPacket.dst_ip = "10.10.10.2";
}

PacketInfo Hud::getLastPacket() const {  // ✅ Added for testing
    return lastPacket;
}
