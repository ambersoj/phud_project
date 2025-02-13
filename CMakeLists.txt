cmake_minimum_required(VERSION 3.16)
project(phud_project)

# Enable testing
include(CTest)

# Add subdirectories for modular libraries
add_subdirectory(libs/command_lib)
add_subdirectory(libs/ipc_lib)

# Add integration tests
add_subdirectory(tests)
