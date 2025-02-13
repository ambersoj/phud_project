#include "IPCManager.h"
#include "UnixSocketIPC.h"

void IPCManager::setIPCType(IPCType type) {
    currentType = type;  // Store the selected type
    if (type == IPCType::SOCKETS) {
        ipc = std::make_unique<UnixSocketIPC>();
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
