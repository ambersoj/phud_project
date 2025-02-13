#ifndef IPC_INTERFACE_H
#define IPC_INTERFACE_H

#include <string>

class IPCInterface {
public:
    virtual ~IPCInterface() = default;
    virtual void sendMessage(const std::string& message) = 0;
    virtual std::string receiveMessage() = 0;
};

#endif // IPC_INTERFACE_H