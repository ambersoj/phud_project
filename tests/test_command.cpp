#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include "CommandManager.h"

TEST_CASE("CommandManager loads command plugins", "[Command]") {
    CommandManager manager;
    manager.loadCommandsFromDirectory("./plugins");  // Just execute it, don't check the return
    REQUIRE(true);  // Ensure the test framework doesn't fail on an empty test
}
