# Fetch Catch2 for unit testing
include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.4.0
)
FetchContent_MakeAvailable(Catch2)

# Add unit test executable
add_executable(test_command_lib test_CommandExecutor.cpp)
target_link_libraries(test_command_lib PRIVATE command_lib Catch2::Catch2WithMain)

# Enable automatic test discovery
include(Catch)
catch_discover_tests(test_command_lib)
