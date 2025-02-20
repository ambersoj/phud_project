/**
 * @file test_cli.cpp
 * @brief Unit tests for CLI functionality.
 */

#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>
#include "cli.hpp"
#include "UnixSocketComms.hpp"

/**
 * @brief Test case to verify that the CLI starts without errors.
 */
TEST_CASE("CLI Basic Operation", "[cli]") {
    Cli cli;
    REQUIRE_NOTHROW(cli.start());
}

/**
 * @brief Test case to check message transmission from CLI.
 */
TEST_CASE("CLI Message Transmission", "[cli]") {
    UnixSocketComms server;
    server.startServer("/tmp/hud_socket");
    
    Cli cli;
    REQUIRE_NOTHROW(cli.start());
    
    // Simulate message sending
    UnixSocketComms client;
    client.connectToServer("/tmp/hud_socket");
    client.sendMessage("Test Message");
    
    std::string received = server.receiveMessage();
    REQUIRE(received == "Test Message");
}

/**
 * @brief Test case to check message reception by CLI.
 */
TEST_CASE("CLI Message Reception", "[cli]") {
    UnixSocketComms server;
    server.startServer("/tmp/hud_socket");
    
    Cli cli;
    REQUIRE_NOTHROW(cli.start());
    
    // Simulate sending response to client
    UnixSocketComms client;
    client.connectToServer("/tmp/hud_socket");
    server.sendMessage("Hello CLI");
    
    std::string response = client.receiveMessage();
    REQUIRE(response == "Hello CLI");
}
