#include "UnixSocketComms.hpp"
#include <iostream>
#include <cstring>
#include <fcntl.h>
#include <thread>
#include <chrono>

/**
 * @brief Constructor: Initializes the socket descriptor to an invalid value.
 */
UnixSocketComms::UnixSocketComms() : socket_fd(-1) {}

/**
 * @brief Destructor: Closes the socket if it's open.
 */
UnixSocketComms::~UnixSocketComms() {
    if (socket_fd != -1) {
        close(socket_fd);
    }
}

/**
 * @brief Starts the Unix domain socket server.
 */
void UnixSocketComms::startServer(const std::string& socketPath) {
    socket_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        perror("Error creating server socket");
        return;
    }

    memset(&address, 0, sizeof(address));
    address.sun_family = AF_UNIX;
    strncpy(address.sun_path, socketPath.c_str(), sizeof(address.sun_path) - 1);

    unlink(socketPath.c_str());  // Ensure it's not already in use

    if (bind(socket_fd, (struct sockaddr*)&address, sizeof(address)) == -1) {
        perror("Error binding server socket");
        return;
    }

    if (listen(socket_fd, 1) == -1) {
        perror("Error listening on server socket");
        return;
    }

    std::cout << "[UnixSocketComms] Server listening on " << socketPath << std::endl;

    int client_fd = accept(socket_fd, nullptr, nullptr);
    if (client_fd == -1) {
        perror("Error accepting connection");
        return;
    }

    socket_fd = client_fd; // Use client socket for communication
}

/**
 * @brief Connects as a client to a Unix domain socket server.
 */
void UnixSocketComms::connectToServer(const std::string& socketPath) {
    socket_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        perror("Error creating client socket");
        return;
    }

    memset(&address, 0, sizeof(address));
    address.sun_family = AF_UNIX;
    strncpy(address.sun_path, socketPath.c_str(), sizeof(address.sun_path) - 1);

    if (connect(socket_fd, (struct sockaddr*)&address, sizeof(address)) == -1) {
        perror("Error connecting to server");
        return;
    }

    std::cout << "[UnixSocketComms] Connected to server." << std::endl;
}

/**
 * @brief Sends a message over the Unix domain socket.
 */
void UnixSocketComms::sendMessage(const std::string& message) {
    if (socket_fd == -1) {
        std::cerr << "Socket not connected!" << std::endl;
        return;
    }

    std::cout << "[UnixSocketComms] Sending message: " << message << std::endl;
    if (send(socket_fd, message.c_str(), message.size(), 0) == -1) {
        perror("Error sending message");
    }
}

/**
 * @brief Receives a message over the Unix domain socket.
 */
std::string UnixSocketComms::receiveMessage() {
    if (socket_fd == -1) {
        std::cerr << "Socket not connected!" << std::endl;
        return "";
    }

    char buffer[1024] = {0};
    int bytesReceived = recv(socket_fd, buffer, sizeof(buffer) - 1, 0);

    if (bytesReceived <= 0) {
        perror("Error reading message (or connection closed)");
        return "";
    }

    buffer[bytesReceived] = '\0'; // Ensure null termination
    std::string received(buffer);
    std::cout << "[UnixSocketComms] Received: " << received << std::endl;
    return received;
}
