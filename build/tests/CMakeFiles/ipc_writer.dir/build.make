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
include tests/CMakeFiles/ipc_writer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/CMakeFiles/ipc_writer.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/ipc_writer.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/ipc_writer.dir/flags.make

tests/CMakeFiles/ipc_writer.dir/ipc_writer.cpp.o: tests/CMakeFiles/ipc_writer.dir/flags.make
tests/CMakeFiles/ipc_writer.dir/ipc_writer.cpp.o: /usr/local/phud_project/tests/ipc_writer.cpp
tests/CMakeFiles/ipc_writer.dir/ipc_writer.cpp.o: tests/CMakeFiles/ipc_writer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/usr/local/phud_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/ipc_writer.dir/ipc_writer.cpp.o"
	cd /usr/local/phud_project/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/ipc_writer.dir/ipc_writer.cpp.o -MF CMakeFiles/ipc_writer.dir/ipc_writer.cpp.o.d -o CMakeFiles/ipc_writer.dir/ipc_writer.cpp.o -c /usr/local/phud_project/tests/ipc_writer.cpp

tests/CMakeFiles/ipc_writer.dir/ipc_writer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ipc_writer.dir/ipc_writer.cpp.i"
	cd /usr/local/phud_project/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /usr/local/phud_project/tests/ipc_writer.cpp > CMakeFiles/ipc_writer.dir/ipc_writer.cpp.i

tests/CMakeFiles/ipc_writer.dir/ipc_writer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ipc_writer.dir/ipc_writer.cpp.s"
	cd /usr/local/phud_project/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /usr/local/phud_project/tests/ipc_writer.cpp -o CMakeFiles/ipc_writer.dir/ipc_writer.cpp.s

# Object files for target ipc_writer
ipc_writer_OBJECTS = \
"CMakeFiles/ipc_writer.dir/ipc_writer.cpp.o"

# External object files for target ipc_writer
ipc_writer_EXTERNAL_OBJECTS =

tests/ipc_writer: tests/CMakeFiles/ipc_writer.dir/ipc_writer.cpp.o
tests/ipc_writer: tests/CMakeFiles/ipc_writer.dir/build.make
tests/ipc_writer: libipc_lib.a
tests/ipc_writer: tests/CMakeFiles/ipc_writer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/usr/local/phud_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ipc_writer"
	cd /usr/local/phud_project/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ipc_writer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/ipc_writer.dir/build: tests/ipc_writer
.PHONY : tests/CMakeFiles/ipc_writer.dir/build

tests/CMakeFiles/ipc_writer.dir/clean:
	cd /usr/local/phud_project/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/ipc_writer.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/ipc_writer.dir/clean

tests/CMakeFiles/ipc_writer.dir/depend:
	cd /usr/local/phud_project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /usr/local/phud_project /usr/local/phud_project/tests /usr/local/phud_project/build /usr/local/phud_project/build/tests /usr/local/phud_project/build/tests/CMakeFiles/ipc_writer.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : tests/CMakeFiles/ipc_writer.dir/depend

