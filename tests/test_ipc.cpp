#include <catch2/catch_all.hpp>
#include "../include/IPCManager.hpp"

TEST_CASE("IPC Communication", "[ipc]") {
    IPCManager ipc;
    
    SECTION("Initialize IPC") {
        REQUIRE_NOTHROW(ipc.initialize());
    }

    SECTION("Write and Read Data") {
        ipc.initialize();
        std::string data = "Hello, IPC!";
        ipc.writeData(data);

        REQUIRE(ipc.readData() == data);
    }
}
