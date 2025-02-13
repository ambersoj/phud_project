#ifndef IPC_MANAGER_H
#define IPC_MANAGER_H

#include <memory>
#include "IPCInterface.h"

class IPCManager {
private:
    std::unique_ptr<IPCInterface> ipc;
public:
    void setIPCType(IPCType type);
    void sendMessage(const std::string& message);
    std::string receiveMessage();
};

#endif // IPC_MANAGER_H