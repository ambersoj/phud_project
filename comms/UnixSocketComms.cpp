/**
 * @file UnixSocketComms.cpp
 * @brief Implementation of Unix Socket-based IPC for MPP.
 */

#include "UnixSocketComms.hpp"
#include <iostream>
#include <unistd.h>
#include <cstring>

/**
 * @brief Constructor: Initializes socket file descriptor.
 */
UnixSocketComms::UnixSocketComms() : socketFd(-1) {}

/**
 * @brief Destructor: Closes the socket if open.
 */
UnixSocketComms::~UnixSocketComms() {
    if (socketFd != -1) {
        close(socketFd);
    }
}

/**
 * @brief Starts a Unix socket server for IPC.
 */
void UnixSocketComms::startServer() {
    socketFd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (socketFd == -1) {
        perror("Error creating socket");
        return;
    }

    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, "/tmp/mpp_socket", sizeof(addr.sun_path) - 1);

    unlink("/tmp/mpp_socket"); // Remove previous socket if exists

    if (bind(socketFd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
        perror("Error binding socket");
        close(socketFd);
        return;
    }

    if (listen(socketFd, 5) == -1) {
        perror("Error listening on socket");
        close(socketFd);
        return;
    }

    std::cout << "[UnixSocketComms] Server listening on /tmp/mpp_socket\n";
}

/**
 * @brief Connects as a Unix socket client.
 */
void UnixSocketComms::connectClient() {
    socketFd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (socketFd == -1) {
        perror("Error creating client socket");
        return;
    }

    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, "/tmp/mpp_socket", sizeof(addr.sun_path) - 1);

    if (connect(socketFd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
        perror("Error connecting to server");
        close(socketFd);
        return;
    }

    std::cout << "[UnixSocketComms] Connected to server.\n";
}

/**
 * @brief Sends a message over the Unix socket.
 * @param msg The message to send.
 */
void UnixSocketComms::sendMessage(const std::string& msg) {
    if (socketFd == -1) {
        std::cerr << "Socket not initialized.\n";
        return;
    }

    if (write(socketFd, msg.c_str(), msg.length()) == -1) {
        perror("Error sending message");
    }
}

/**
 * @brief Receives a message from the Unix socket.
 * @return The received message.
 */
std::string UnixSocketComms::receiveMessage() {
    if (socketFd == -1) {
        std::cerr << "Socket not initialized.\n";
        return "";
    }

    char buffer[256] = {0};
    int bytesRead = read(socketFd, buffer, sizeof(buffer) - 1);
    if (bytesRead == -1) {
        perror("Error reading message");
        return "";
    }

    return std::string(buffer);
}
