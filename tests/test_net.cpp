#include <catch2/catch_all.hpp>
#include "../include/net.hpp"

TEST_CASE("Network Initialization", "[net]") {
    Net net;
    REQUIRE_NOTHROW(net.initialize("eth0"));
}

TEST_CASE("Packet Capture", "[net]") {
    Net net;
    net.initialize("eth0");

    PacketInfo packet = net.capturePacket();
    REQUIRE(packet.size > 0);
    REQUIRE(!packet.src_ip.empty());
    REQUIRE(!packet.dst_ip.empty());
}
