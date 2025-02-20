// hud.hpp - Updated to support Unix socket commands

#ifndef HUD_HPP
#define HUD_HPP

#include <string>
#include "UnixSocketComms.hpp"

class Hud {
public:
    Hud();
    ~Hud();

    void initialize();
    void render();
    void shutdown();
    void listenForCommands(); // ✅ New: Listens for Unix socket commands
    void processCommand(const std::string& command); // ✅ New: Processes received commands

private:
    UnixSocketComms comms;
};

#endif // HUD_HPP
