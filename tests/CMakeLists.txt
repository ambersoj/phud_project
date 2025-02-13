cmake_minimum_required(VERSION 3.10)
project(tests)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.3.2
)
FetchContent_MakeAvailable(Catch2)

include_directories(${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/ipc_lib/include ${CMAKE_SOURCE_DIR}/command_lib/include)

add_executable(test_ipc test_ipc.cpp)
add_executable(test_command test_command.cpp)

target_link_libraries(test_ipc PRIVATE Catch2::Catch2WithMain ipc_lib)
target_link_libraries(test_command PRIVATE Catch2::Catch2WithMain command_lib)

enable_testing()
add_test(NAME IPC_Test COMMAND test_ipc)
add_test(NAME Command_Test COMMAND test_command)
add_test(NAME SharedMemoryIPC_Test COMMAND test_shared_memory_ipc)

