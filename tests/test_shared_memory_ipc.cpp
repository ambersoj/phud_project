#include <catch2/catch_test_macros.hpp>
#include "SharedMemoryIPC.h"

TEST_CASE("Shared Memory IPC Test", "[SharedMemoryIPC]") {
    SharedMemoryIPC sender("/test_shm");
    SharedMemoryIPC receiver("/test_shm");

    sender.sendMessage("Hello, Shared Memory!");
    REQUIRE(receiver.receiveMessage() == "Hello, Shared Memory!");
}
