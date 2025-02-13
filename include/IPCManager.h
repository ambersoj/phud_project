#ifndef IPC_MANAGER_H
#define IPC_MANAGER_H

#include <memory>
#include "IPCInterface.h"
#include "IPCType.h"
class IPCManager {
private:
    std::unique_ptr<IPCInterface> ipc;
    IPCType currentType;
public:
    void setIPCType(IPCType type);
    IPCType getCurrentIPCType() const;
    void sendMessage(const std::string& message);
    std::string receiveMessage();
};

#endif // IPC_MANAGER_H
