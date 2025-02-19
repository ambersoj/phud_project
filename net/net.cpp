#include "net.hpp"
#include <iostream>

void Net::initialize(const std::string& interface) {
    netInterface = interface;
    std::cout << "Initializing network capture on interface: " << netInterface << std::endl;
}

PacketInfo Net::capturePacket() {
    std::cout << "Capturing packet..." << std::endl;
    return {};  // Empty packet info for now
}
