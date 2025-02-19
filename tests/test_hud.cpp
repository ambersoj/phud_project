#include <catch2/catch_all.hpp>
#include "../include/hud.hpp"

TEST_CASE("HUD Initialization", "[hud]") {
    Hud hud;
    REQUIRE_NOTHROW(hud.initialize());
}

TEST_CASE("HUD Rendering", "[hud]") {
    Hud hud;
    hud.initialize();
    REQUIRE_NOTHROW(hud.render());
}

TEST_CASE("HUD Packet Updates", "[hud]") {
    Hud hud;
    hud.initialize();

    PacketInfo packet1{64, "10.0.0.1", "10.0.0.2"};
    PacketInfo packet2{128, "192.168.1.1", "192.168.1.2"};

    hud.update(packet1);
    REQUIRE(hud.getLastPacket().size == 64);
    REQUIRE(hud.getLastPacket().src_ip == "10.0.0.1");

    hud.update(packet2);
    REQUIRE(hud.getLastPacket().size == 128);
    REQUIRE(hud.getLastPacket().src_ip == "192.168.1.1");
}
