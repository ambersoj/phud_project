#include "SharedMemoryIPC.hpp"
#include <iostream>

SharedMemoryIPC::SharedMemoryIPC() {
    std::cout << "SharedMemoryIPC Constructor" << std::endl;
}

SharedMemoryIPC::~SharedMemoryIPC() {
    std::cout << "SharedMemoryIPC Destructor" << std::endl;
}

void SharedMemoryIPC::initialize() {
    std::cout << "Initializing shared memory IPC..." << std::endl;
}

void SharedMemoryIPC::sendMessage(const std::string& message) {
    std::cout << "Writing message to shared memory: " << message << std::endl;
}

std::string SharedMemoryIPC::receiveMessage() {
    std::cout << "Reading message from shared memory" << std::endl;
    return "MockMessage"; // Fake data for now
}
