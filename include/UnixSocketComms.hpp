#ifndef UNIXSOCKETCOMMS_HPP
#define UNIXSOCKETCOMMS_HPP

#include <string>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

/**
 * @class UnixSocketComms
 * @brief Handles inter-process communication using Unix domain sockets.
 */
class UnixSocketComms {
public:
    /**
     * @brief Constructor - Initializes a Unix domain socket communication endpoint.
     */
    UnixSocketComms();

    /**
     * @brief Destructor - Closes the socket.
     */
    ~UnixSocketComms();

    /**
     * @brief Starts the IPC server listening on a socket.
     * @param socketPath Path for the Unix domain socket.
     */
    void startServer(const std::string& socketPath);

    /**
     * @brief Connects to the IPC server as a client.
     * @param socketPath Path for the Unix domain socket.
     */
    void connectToServer(const std::string& socketPath);

    /**
     * @brief Sends a message over the Unix socket.
     * @param message The message to send.
     */
    void sendMessage(const std::string& message);

    /**
     * @brief Receives a message over the Unix socket.
     * @return The received message as a string.
     */
    std::string receiveMessage();

private:
    int socket_fd;  ///< File descriptor for the socket
    sockaddr_un address; ///< Socket address structure
};

#endif // UNIXSOCKETCOMMS_HPP
