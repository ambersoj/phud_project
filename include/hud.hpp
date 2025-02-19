#ifndef HUD_HPP
#define HUD_HPP

#include "PacketInfo.hpp"
#include "SharedMemoryIPC.hpp"

class Hud {
public:
    Hud() = default;
    ~Hud() = default;

    void initialize();
    void render();
    void update();

    PacketInfo getLastPacket() const;  // ✅ Restored for testing

private:
    SharedMemoryIPC sharedMemory;
    PacketInfo lastPacket;  // ✅ Keep track of last received packet
};

#endif // HUD_HPP
