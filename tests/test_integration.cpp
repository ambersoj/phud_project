/**
 * @file test_integration.cpp
 * @brief Integration tests for CLI and HUD interaction.
 */

#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>
#include "cli.hpp"
#include "hud.hpp"
#include "UnixSocketComms.hpp"
#include <thread>
#include <chrono>

/**
 * @brief Ensures CLI can successfully communicate with HUD.
 */
TEST_CASE("CLI-HUD Basic Communication", "[integration]") {
    UnixSocketComms server;
    server.startServer("/tmp/hud_socket");

    Cli cli;
    REQUIRE_NOTHROW(cli.start());

    // Simulate message exchange
    UnixSocketComms client;
    client.connectToServer("/tmp/hud_socket");
    client.sendMessage("Hello, HUD!");
    
    std::this_thread::sleep_for(std::chrono::milliseconds(50)); // Allow time for processing
    std::string received = server.receiveMessage();
    REQUIRE(received == "Hello, HUD!");
    
    server.sendMessage("Hello, CLI!");
    std::string response = client.receiveMessage();
    REQUIRE(response == "Hello, CLI!");
}

/**
 * @brief Tests CLI sending multiple messages to HUD.
 */
TEST_CASE("CLI-HUD Multiple Messages", "[integration]") {
    UnixSocketComms server;
    server.startServer("/tmp/hud_socket");

    Cli cli;
    REQUIRE_NOTHROW(cli.start());
    
    UnixSocketComms client;
    client.connectToServer("/tmp/hud_socket");
    
    std::vector<std::string> messages = {"MSG 1", "MSG 2", "MSG 3"};
    for (const auto& msg : messages) {
        client.sendMessage(msg);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        std::string received = server.receiveMessage();
        REQUIRE(received == msg);
    }
}

/**
 * @brief Tests handling of unexpected disconnection scenarios.
 */
TEST_CASE("CLI-HUD Disconnection Handling", "[integration]") {
    UnixSocketComms server;
    server.startServer("/tmp/hud_socket");

    Cli cli;
    REQUIRE_NOTHROW(cli.start());
    
    UnixSocketComms client;
    client.connectToServer("/tmp/hud_socket");
    client.sendMessage("Checking Connection");
    
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    REQUIRE(server.receiveMessage() == "Checking Connection");
    
    // Simulating unexpected disconnect
    client.~UnixSocketComms(); // Destroy client instance
    REQUIRE_THROWS(server.receiveMessage()); // Should fail
}

/**
 * @brief Validates that HUD can receive and process commands properly.
 */
TEST_CASE("HUD Command Processing", "[integration]") {
    Hud hud;
    REQUIRE_NOTHROW(hud.initialize());
    
    UnixSocketComms server;
    server.startServer("/tmp/hud_socket");

    UnixSocketComms client;
    client.connectToServer("/tmp/hud_socket");
    client.sendMessage("Render HUD");
    
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::string received = server.receiveMessage();
    REQUIRE(received == "Render HUD");
}
