#include "hud.hpp"
#include <iostream>
#include <thread>

Hud::Hud() {
    // Initialization
}

Hud::~Hud() {
    shutdown();
}

void Hud::initialize() {
    std::cout << "HUD Initialized" << std::endl;
    comms.startServer("/tmp/hud_socket");
    std::thread listener(&Hud::listenForCommands, this);
    listener.detach();
}

void Hud::render() {
    std::cout << "Rendering HUD" << std::endl;
}

void Hud::shutdown() {
    std::cout << "Shutting down HUD" << std::endl;
}

void Hud::listenForCommands() {
    while (true) {
        std::string command = comms.receiveMessage();
        if (!command.empty()) {
            processCommand(command);
        }
    }
}

void Hud::processCommand(const std::string& command) {
    std::cout << "Processing command: " << command << std::endl;
    if (command == "render") {
        render();
    } else if (command == "shutdown") {
        shutdown();
    }
}
