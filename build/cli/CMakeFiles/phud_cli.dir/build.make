# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /usr/local/phud_project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /usr/local/phud_project/build

# Include any dependencies generated for this target.
include cli/CMakeFiles/phud_cli.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include cli/CMakeFiles/phud_cli.dir/compiler_depend.make

# Include the progress variables for this target.
include cli/CMakeFiles/phud_cli.dir/progress.make

# Include the compile flags for this target's objects.
include cli/CMakeFiles/phud_cli.dir/flags.make

cli/CMakeFiles/phud_cli.dir/cli.cpp.o: cli/CMakeFiles/phud_cli.dir/flags.make
cli/CMakeFiles/phud_cli.dir/cli.cpp.o: /usr/local/phud_project/cli/cli.cpp
cli/CMakeFiles/phud_cli.dir/cli.cpp.o: cli/CMakeFiles/phud_cli.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/usr/local/phud_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object cli/CMakeFiles/phud_cli.dir/cli.cpp.o"
	cd /usr/local/phud_project/build/cli && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT cli/CMakeFiles/phud_cli.dir/cli.cpp.o -MF CMakeFiles/phud_cli.dir/cli.cpp.o.d -o CMakeFiles/phud_cli.dir/cli.cpp.o -c /usr/local/phud_project/cli/cli.cpp

cli/CMakeFiles/phud_cli.dir/cli.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/phud_cli.dir/cli.cpp.i"
	cd /usr/local/phud_project/build/cli && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /usr/local/phud_project/cli/cli.cpp > CMakeFiles/phud_cli.dir/cli.cpp.i

cli/CMakeFiles/phud_cli.dir/cli.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/phud_cli.dir/cli.cpp.s"
	cd /usr/local/phud_project/build/cli && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /usr/local/phud_project/cli/cli.cpp -o CMakeFiles/phud_cli.dir/cli.cpp.s

# Object files for target phud_cli
phud_cli_OBJECTS = \
"CMakeFiles/phud_cli.dir/cli.cpp.o"

# External object files for target phud_cli
phud_cli_EXTERNAL_OBJECTS =

cli/phud_cli: cli/CMakeFiles/phud_cli.dir/cli.cpp.o
cli/phud_cli: cli/CMakeFiles/phud_cli.dir/build.make
cli/phud_cli: cli/libcli_lib.a
cli/phud_cli: comms/libcomms.a
cli/phud_cli: cli/CMakeFiles/phud_cli.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/usr/local/phud_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable phud_cli"
	cd /usr/local/phud_project/build/cli && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/phud_cli.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
cli/CMakeFiles/phud_cli.dir/build: cli/phud_cli
.PHONY : cli/CMakeFiles/phud_cli.dir/build

cli/CMakeFiles/phud_cli.dir/clean:
	cd /usr/local/phud_project/build/cli && $(CMAKE_COMMAND) -P CMakeFiles/phud_cli.dir/cmake_clean.cmake
.PHONY : cli/CMakeFiles/phud_cli.dir/clean

cli/CMakeFiles/phud_cli.dir/depend:
	cd /usr/local/phud_project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /usr/local/phud_project /usr/local/phud_project/cli /usr/local/phud_project/build /usr/local/phud_project/build/cli /usr/local/phud_project/build/cli/CMakeFiles/phud_cli.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : cli/CMakeFiles/phud_cli.dir/depend

