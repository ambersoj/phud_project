#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>
#include "hud.hpp"

TEST_CASE("HUD Initialization", "[hud]") {
    Hud hud;
    REQUIRE_NOTHROW(hud.initialize());
}

TEST_CASE("HUD Rendering", "[hud]") {
    Hud hud;
    REQUIRE_NOTHROW(hud.render());
}

TEST_CASE("HUD Update (Stub)", "[hud]") {
    Hud hud;
    PacketInfo packet{128, "192.168.0.111", "192.168.0.101"};
    
    REQUIRE_NOTHROW(hud.update(packet));  // Just check that it doesn't crash
}
