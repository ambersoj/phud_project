#include "IPCManager.h"
#include "../include/UnixSocketIPC.h"
#include "../include/SharedMemoryIPC.h"

void IPCManager::setIPCType(IPCType type) {
    currentType = type;
    if (type == IPCType::SOCKETS) {
        ipc = std::make_unique<UnixSocketIPC>();
    } else if (type == IPCType::SHARED_MEMORY) {
        ipc = std::make_unique<SharedMemoryIPC>();
    }
}

IPCType IPCManager::getCurrentIPCType() const {
    return currentType;
}

void IPCManager::sendMessage(const std::string& message) {
    if (ipc) {
        ipc->sendMessage(message);
    }
}

std::string IPCManager::receiveMessage() {
    if (ipc) {
        return ipc->receiveMessage();
    }
    return "";
}
