#ifndef SHARED_MEMORY_IPC_HPP
#define SHARED_MEMORY_IPC_HPP

#include "IPCInterface.hpp"
#include <string>

class SharedMemoryIPC : public IPCInterface {  // ✅ FIXED: Correct inheritance
public:
    SharedMemoryIPC();
    ~SharedMemoryIPC();

    void initialize() override;  // ✅ Use initialize() instead of connect()
    void sendMessage(const std::string& message) override;  // ✅ FIXED
    std::string receiveMessage() override;  // ✅ FIXED

private:
    int shmid;
    void* shmaddr;
};

#endif // SHARED_MEMORY_IPC_HPP
