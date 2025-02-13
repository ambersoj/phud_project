cmake_minimum_required(VERSION 3.10)
project(tests)

set(CMAKE_CXX_STANDARD 17)

enable_testing()

add_executable(test_ipc test_ipc.cpp)
add_executable(test_command test_command.cpp)

target_link_libraries(test_ipc Catch2::Catch2)
target_link_libraries(test_command Catch2::Catch2)
