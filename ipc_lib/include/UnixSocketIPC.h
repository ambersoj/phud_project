#ifndef UNIX_SOCKET_IPC_H
#define UNIX_SOCKET_IPC_H

#include "IPCInterface.h"
#include <string>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

class UnixSocketIPC : public IPCInterface {
private:
    int socket_fd;
    struct sockaddr_un address;
    std::string socket_path = "/tmp/unix_socket_ipc";
public:
    UnixSocketIPC();
    ~UnixSocketIPC();
    void sendMessage(const std::string& message) override;
    std::string receiveMessage() override;
};

#endif // UNIX_SOCKET_IPC_H