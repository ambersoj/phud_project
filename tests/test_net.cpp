#include <catch2/catch_all.hpp>
#include "../include/net.hpp"

TEST_CASE("Network Capture Operations", "[net]") {
    Net net;
    
    SECTION("Network Initializes Successfully") {
        REQUIRE_NOTHROW(net.initialize("eth0"));
    }

    SECTION("Network Captures Packets") {
        net.initialize("eth0");
        PacketInfo packet = net.capturePacket();

        REQUIRE(packet.size > 0);
        REQUIRE(!packet.src_ip.empty());
        REQUIRE(!packet.dst_ip.empty());
    }
}
