#ifndef IPC_MANAGER_HPP
#define IPC_MANAGER_HPP

#include <memory>
#include "IPCInterface.hpp"
#include "IPCType.hpp"

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
