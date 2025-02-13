add_library(ipc_lib
    src/SharedMemoryIPC.cpp
    include/SharedMemoryIPC.h
)

target_include_directories(ipc_lib PUBLIC include)
target_link_libraries(ipc_lib PRIVATE pthread)

add_subdirectory(tests)
