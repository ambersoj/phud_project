cmake_minimum_required(VERSION 3.10)
project(phud_tests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add test executable
add_executable(phud_tests test_main.cpp test_hud.cpp test_net.cpp)

# Link required libraries
target_link_libraries(phud_tests PRIVATE hud net Catch2::Catch2WithMain)

# Include directories
target_include_directories(phud_tests PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Enable testing with CTest
include(CTest)
add_test(NAME PhudTests COMMAND phud_tests)
