#include "cli.hpp"
#include "UnixSocketComms.hpp"
#include <iostream>

void Cli::start() {
    UnixSocketComms client;
    
    std::cout << "[CLI] Connecting to HUD socket..." << std::endl;
    client.connectToServer("/tmp/hud_socket");  // ✅ Fixed method name

    client.sendMessage("Hello, PHUD!");
    std::string response = client.receiveMessage();

    std::cout << "[CLI] Received response: " << response << std::endl;
}

int main() {
    Cli cli;
    cli.start();
    return 0;
}
