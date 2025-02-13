cmake_minimum_required(VERSION 3.10)
project(phud_project)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(ipc_lib)
add_subdirectory(command_lib)

enable_testing()
add_subdirectory(tests)
