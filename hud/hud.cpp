#include "hud.hpp"
#include <iostream>

void Hud::initialize() {
    std::cout << "HUD Initialized" << std::endl;
}

void Hud::render() {
    std::cout << "Rendering HUD" << std::endl;
}

void Hud::update(const PacketInfo&) {
    std::cout << "Updating HUD with new packet info" << std::endl;
}

PacketInfo Hud::getLastPacket() const {
    return {};  // Return an empty PacketInfo struct
}
