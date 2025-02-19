#ifndef IPC_MANAGER_HPP
#define IPC_MANAGER_HPP

#include "IPCInterface.hpp"
#include "PacketInfo.hpp"
#include <memory>

class IPCManager {
public:
    IPCManager();
    ~IPCManager();

    void initialize();
    void sendPacket(const std::string& message);  // ✅ FIXED: Matches IPCInterface
    std::string receivePacket(); // ✅ FIXED: Matches IPCInterface

private:
    std::unique_ptr<IPCInterface> ipc; // ✅ FIXED: Polymorphic pointer
};

#endif // IPC_MANAGER_HPP
