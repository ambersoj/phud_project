cmake_minimum_required(VERSION 3.10)
project(phud_project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Fetch Catch2 for testing
include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.8.0
)
FetchContent_MakeAvailable(Catch2)

# Add core components
add_subdirectory(ipc)
add_subdirectory(hud)
add_subdirectory(net)
add_subdirectory(comms)  # ✅ Add comms
add_subdirectory(cli)    # ✅ Add CLI component
add_subdirectory(tests)  # ✅ Add tests

# Enable Testing
enable_testing()
