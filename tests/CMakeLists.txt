cmake_minimum_required(VERSION 3.10)

add_executable(test_comms test_comms.cpp)
target_link_libraries(test_comms PRIVATE comms Catch2::Catch2WithMain)

# Add test executable for CLI
add_executable(test_cli test_cli.cpp)
target_link_libraries(test_cli PRIVATE cli_lib comms Catch2::Catch2WithMain)
add_test(NAME CliTests COMMAND test_cli)

# Register tests
include(CTest)
add_test(NAME CommsTests COMMAND test_comms)

add_executable(test_integration test_integration.cpp)
target_link_libraries(test_integration PRIVATE cli_lib comms Catch2::Catch2WithMain)
add_test(NAME IntegrationTests COMMAND test_integration)
