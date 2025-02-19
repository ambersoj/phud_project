#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>
#include "net.hpp"

TEST_CASE("Network Initialization", "[net]") {
    Net net;
    REQUIRE_NOTHROW(net.initialize("eno1"));
}

TEST_CASE("Packet Capture (Stub)", "[net]") {
    Net net;
    net.initialize("eno1");

    REQUIRE_NOTHROW(net.capturePacket());  // Just check that it runs without crashing
}
