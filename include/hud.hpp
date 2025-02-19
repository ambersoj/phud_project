#ifndef HUD_HPP
#define HUD_HPP

#include "PacketInfo.hpp"

class Hud {
public:
    Hud() = default;
    ~Hud() = default;

    void initialize();
    void render();
    void update(const PacketInfo& packet);
    PacketInfo getLastPacket() const;

private:
    PacketInfo lastPacket;
};

#endif // HUD_HPP
