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

# Add core IPC at root level
add_subdirectory(ipc)  

# Add other components
add_subdirectory(hud)  # ✅ Fixed directory structure (no src/)
add_subdirectory(net)  # ✅ Fixed directory structure (no src/)
add_subdirectory(tests)  # ✅ Tests directory

# Enable Testing
enable_testing()
