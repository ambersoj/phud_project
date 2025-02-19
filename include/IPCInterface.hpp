#ifndef IPC_INTERFACE_HPP
#define IPC_INTERFACE_HPP

#include <string>

class IPCInterface {
public:
    virtual ~IPCInterface() = default;

    virtual void initialize() = 0; // ✅ Added to enforce proper initialization
    virtual void sendMessage(const std::string& message) = 0;
    virtual std::string receiveMessage() = 0;
};

#endif // IPC_INTERFACE_HPP
