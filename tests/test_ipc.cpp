#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include "IPCManager.h"

TEST_CASE("IPCManager selects IPC type", "[IPC]") {
    IPCManager ipc;
    ipc.setIPCType(IPCType::SOCKETS);
    REQUIRE(ipc.getCurrentIPCType() == IPCType::SOCKETS);
}
