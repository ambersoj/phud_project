#ifndef IPC_MANAGER_H
#define IPC_MANAGER_H

#include <memory>
#include "IPCInterface.h"
#include "IPCType.h"
#include "SharedMemoryIPC.h"

class IPCManager {
private:
    std::unique_ptr<IPCInterface> ipc;
    IPCType currentType;  // Track the selected IPC type
public:
    void setIPCType(IPCType type);
    IPCType getCurrentIPCType() const;  // Add this function
    void sendMessage(const std::string& message);
    std::string receiveMessage();
};

#endif // IPC_MANAGER_H
