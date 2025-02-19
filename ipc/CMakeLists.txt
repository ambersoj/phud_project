add_library(ipc STATIC
    IPCManager.cpp
    SharedMemoryIPC.cpp
    UnixSocketIPC.cpp
)

target_include_directories(ipc PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(ipc PRIVATE pthread)
