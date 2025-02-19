/**
 * @file UnixSocketComms.hpp
 * @brief Unix Socket-based implementation of MPPComms.
 */

#ifndef UNIX_SOCKET_COMMS_HPP
#define UNIX_SOCKET_COMMS_HPP

#include "MPPComms.hpp"
#include <sys/socket.h>
#include <sys/un.h>
#include <string>

/**
 * @class UnixSocketComms
 * @brief Implements IPC using Unix Domain Sockets.
 *
 * This class provides inter-process communication using Unix sockets,
 * allowing MPP components to communicate with terminals or other MPP processes.
 */
class UnixSocketComms : public MPPComms {
public:
    /**
     * @brief Constructs a UnixSocketComms object.
     */
    UnixSocketComms();

    /**
     * @brief Destructor - Closes the socket if open.
     */
    ~UnixSocketComms();

    /**
     * @brief Starts a Unix socket server.
     */
    void startServer() override;

    /**
     * @brief Connects as a Unix socket client.
     */
    void connectClient() override;

    /**
     * @brief Sends a message over a Unix socket.
     * @param msg The message to send.
     */
    void sendMessage(const std::string& msg) override;

    /**
     * @brief Receives a message from a Unix socket.
     * @return The received message.
     */
    std::string receiveMessage() override;

private:
    int socketFd;  ///< File descriptor for the socket
    struct sockaddr_un addr;  ///< Address structure for the Unix socket
};

#endif // UNIX_SOCKET_COMMS_HPP
