#include <catch2/catch_all.hpp>
#include "../include/IPCManager.hpp"

TEST_CASE("IPC Initialization", "[ipc]") {
    IPCManager ipc;
    REQUIRE_NOTHROW(ipc.initialize());
}

TEST_CASE("IPC Data Transfer", "[ipc]") {
    IPCManager ipc;
    ipc.initialize();

    std::string testData = "Hello, IPC!";
    ipc.writeData(testData);
    REQUIRE(ipc.readData() == testData);
}
