#define CATCH_CONFIG_MAIN
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

TEST_CASE("HUD Packet Update", "[hud]") {
    Hud hud;
    hud.initialize();

    SECTION("HUD should update from IPC") {
        REQUIRE_NOTHROW(hud.update());  // ✅ Updated test to match new method signature
    }
}
