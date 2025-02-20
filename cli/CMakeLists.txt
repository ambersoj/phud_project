# cli/CMakeLists.txt
add_library(cli_lib STATIC cli.cpp)
target_link_libraries(cli_lib PRIVATE comms)
target_include_directories(cli_lib PUBLIC ${CMAKE_SOURCE_DIR}/include)

# Create the CLI executable
add_executable(phud_cli cli.cpp)
target_link_libraries(phud_cli PRIVATE cli_lib comms)
