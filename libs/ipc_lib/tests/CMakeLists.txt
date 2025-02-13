# Fetch Catch2 if not already available
include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.4.0
)
FetchContent_MakeAvailable(Catch2)

add_executable(test_shared_memory_ipc test_SharedMemoryIPC.cpp)
target_link_libraries(test_shared_memory_ipc PRIVATE ipc_lib Catch2::Catch2WithMain)

# Discover tests using Catch2
catch_discover_tests(test_shared_memory_ipc)
