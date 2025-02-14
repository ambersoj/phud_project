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
list(APPEND CMAKE_MODULE_PATH ${Catch2_SOURCE_DIR}/extras)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(test_ipc test_ipc.cpp)
add_executable(test_SharedMemoryIPC test_SharedMemoryIPC.cpp)
add_executable(ipc_writer ipc_writer.cpp)
add_executable(ipc_reader ipc_reader.cpp)

target_link_libraries(test_ipc PRIVATE Catch2::Catch2WithMain ipc_lib)
target_link_libraries(test_SharedMemoryIPC PRIVATE Catch2::Catch2WithMain ipc_lib)
target_link_libraries(ipc_writer PRIVATE ipc_lib)
target_link_libraries(ipc_reader PRIVATE ipc_lib)

enable_testing()
add_test(NAME IPC_Test COMMAND test_ipc)
add_test(NAME SharedMemoryIPC_Test COMMAND test_SharedMemoryIPC)

