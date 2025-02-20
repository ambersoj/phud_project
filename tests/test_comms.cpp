#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>
#include "UnixSocketComms.hpp"
#include <thread>
#include <chrono>

TEST_CASE("UnixSocketComms - IPC Communication", "[comms]") {
    const std::string socketPath = "/tmp/mpp_socket";

    UnixSocketComms server;
    UnixSocketComms client;

    // Start the server in a separate thread
    std::thread serverThread([&]() {
        server.startServer(socketPath);  // ✅ Pass socket path
    });

    // Give server time to initialize
    std::this_thread::sleep_for(std::chrono::milliseconds(50));

    // Connect the client
    REQUIRE_NOTHROW(client.connectToServer(socketPath));  // ✅ Fixed function name

    // Send a message
    std::string testMessage = "Hello, MPP!";
    REQUIRE_NOTHROW(client.sendMessage(testMessage));

    std::this_thread::sleep_for(std::chrono::milliseconds(50));  // Give time for message transfer

    // Receive the message on the server side
    std::string receivedMessage = server.receiveMessage();
    REQUIRE(receivedMessage == testMessage);

    // Join the server thread before ending the test
    serverThread.join();
}
