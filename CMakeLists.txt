cmake_minimum_required(VERSION 3.10)
project(phud_project)

set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add the IPC library
add_library(ipc_lib
    src/IPCManager.cpp
    src/SharedMemoryIPC.cpp
    src/UnixSocketIPC.cpp  # ✅ Add this if it's missing
)

target_link_libraries(ipc_lib PRIVATE pthread)

# Add the tests
enable_testing()
add_subdirectory(tests)
