#ifndef IPC_MANAGER_H
#define IPC_MANAGER_H

#include <memory>
#include "../ipc_lib/include/IPCInterface.h"
#include "IPCType.h"

class IPCManager {
private:
    std::unique_ptr<IPCInterface> ipc;
public:
    void setIPCType(IPCType type);
    void sendMessage(const std::string& message);
    std::string receiveMessage();
};

#endif // IPC_MANAGER_H
