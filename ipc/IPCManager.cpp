#include "IPCManager.hpp"
#include "SharedMemoryIPC.hpp"
#include <iostream>

IPCManager::IPCManager() {
    std::cout << "IPCManager Constructor" << std::endl;
}

IPCManager::~IPCManager() {
    std::cout << "IPCManager Destructor" << std::endl;
}

void IPCManager::initialize() {
    std::cout << "Initializing IPC Manager..." << std::endl;
    ipc = std::make_unique<SharedMemoryIPC>(); // ✅ Now works with IPCInterface
    ipc->initialize();  // ✅ FIXED: This works because initialize() is in IPCInterface
}

void IPCManager::sendPacket(const std::string& message) {
    ipc->sendMessage(message);
}

std::string IPCManager::receivePacket() {
    return ipc->receiveMessage();
}
