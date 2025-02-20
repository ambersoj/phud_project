/**
 * @file test_cli_hud_integration.cpp
 * @brief Integration tests for CLI and HUD communication via UnixSocketComms.
 */

#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>
#include "cli.hpp"
#include "hud.hpp"
#include "UnixSocketComms.hpp"
#include <thread>
#include <chrono>

/**
 * @brief Ensures CLI and HUD can communicate over UnixSocketComms.
 */
TEST_CASE("CLI-HUD Communication", "[integration]") {
    UnixSocketComms server;
    REQUIRE(server.startServer("/tmp/hud_socket"));

    Cli cli;
    REQUIRE_NOTHROW(cli.start());

    UnixSocketComms client;
    REQUIRE(client.connectToServer("/tmp/hud_socket"));

    // Send a message and check reception
    std::string testMessage = "Status";
    client.sendMessage(testMessage);
    
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Allow processing time

    std::string received = server.receiveMessage();
    REQUIRE(received == testMessage);

    // Server responds
    server.sendMessage("HUD Status: OK");
    std::string response = client.receiveMessage();
    REQUIRE(response == "HUD Status: OK");
}

/**
 * @brief Tests that multiple commands can be sent from CLI to HUD.
 */
TEST_CASE("CLI-HUD Multiple Messages", "[integration]") {
    UnixSocketComms server;
    REQUIRE(server.startServer("/tmp/hud_socket"));

    Cli cli;
    REQUIRE_NOTHROW(cli.start());

    UnixSocketComms client;
    REQUIRE(client.connectToServer("/tmp/hud_socket"));

    std::vector<std::string> messages = {"Render", "Status", "Shutdown"};

    for (const auto& msg : messages) {
        client.sendMessage(msg);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        REQUIRE(server.receiveMessage() == msg);
    }
}

/**
 * @brief Tests HUD handling an unexpected disconnection.
 */
TEST_CASE("HUD Handles Disconnection", "[integration]") {
    UnixSocketComms server;
    REQUIRE(server.startServer("/tmp/hud_socket"));

    Cli cli;
    REQUIRE_NOTHROW(cli.start());

    UnixSocketComms client;
    REQUIRE(client.connectToServer("/tmp/hud_socket"));

    client.sendMessage("Checking Connection");
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    REQUIRE(server.receiveMessage() == "Checking Connection");

    // Simulating unexpected disconnect
    client.~UnixSocketComms();
    REQUIRE_THROWS(server.receiveMessage());
}

/**
 * @brief Tests that HUD correctly processes different commands.
 */
TEST_CASE("HUD Processes Commands", "[integration]") {
    Hud hud;
    REQUIRE_NOTHROW(hud.initialize());

    REQUIRE(hud.processCommand("Status") == "HUD Status: OK");
    REQUIRE(hud.processCommand("Render") == "Rendering HUD...");
    REQUIRE(hud.processCommand("Shutdown") == "Shutting down HUD...");
    REQUIRE(hud.processCommand("Unknown") == "Unknown Command");
}
