/**
 * @file MPPComms.hpp
 * @brief Base interface for MPP Communication.
 *
 * This abstract class defines the communication interface
 * for all MPP IPC implementations.
 */

#ifndef MPP_COMMS_HPP
#define MPP_COMMS_HPP

#include <string>

/**
 * @class MPPComms
 * @brief Abstract base class for MPP communication.
 *
 * Defines a common interface for IPC mechanisms used in MPP.
 */
class MPPComms {
public:
    virtual ~MPPComms() = default;

    /**
     * @brief Starts the server for inter-process communication.
     */
    virtual void startServer() = 0;

    /**
     * @brief Connects a client to the IPC server.
     */
    virtual void connectClient() = 0;

    /**
     * @brief Sends a message over the IPC channel.
     * @param msg The message to send.
     */
    virtual void sendMessage(const std::string& msg) = 0;

    /**
     * @brief Receives a message from the IPC channel.
     * @return The received message.
     */
    virtual std::string receiveMessage() = 0;
};

#endif // MPP_COMMS_HPP
