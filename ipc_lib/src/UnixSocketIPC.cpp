#include "UnixSocketIPC.h"
#include <iostream>
#include <cstring>

UnixSocketIPC::UnixSocketIPC() {
    socket_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        std::cerr << "Error creating socket" << std::endl;
        return;
    }
    memset(&address, 0, sizeof(address));
    address.sun_family = AF_UNIX;
    strncpy(address.sun_path, socket_path.c_str(), sizeof(address.sun_path) - 1);

    if (connect(socket_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        std::cerr << "Error connecting to socket" << std::endl;
        close(socket_fd);
    }
}

UnixSocketIPC::~UnixSocketIPC() {
    close(socket_fd);
}

void UnixSocketIPC::sendMessage(const std::string& message) {
    send(socket_fd, message.c_str(), message.size(), 0);
}

std::string UnixSocketIPC::receiveMessage() {
    char buffer[256];
    memset(buffer, 0, sizeof(buffer));
    recv(socket_fd, buffer, sizeof(buffer), 0);
    return std::string(buffer);
}