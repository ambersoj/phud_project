add_library(command_lib
    src/CommandExecutor.cpp
    include/CommandExecutor.h
)

target_include_directories(command_lib PUBLIC include)
add_subdirectory(tests)
