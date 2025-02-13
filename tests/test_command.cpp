#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "CommandManager.h"

TEST_CASE("CommandManager loads command plugins", "[Command]") {
    CommandManager manager;
    REQUIRE(manager.loadCommandsFromDirectory("./plugins"));
}
