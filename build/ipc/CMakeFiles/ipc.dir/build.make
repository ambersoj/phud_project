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
include ipc/CMakeFiles/ipc.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include ipc/CMakeFiles/ipc.dir/compiler_depend.make

# Include the progress variables for this target.
include ipc/CMakeFiles/ipc.dir/progress.make

# Include the compile flags for this target's objects.
include ipc/CMakeFiles/ipc.dir/flags.make

ipc/CMakeFiles/ipc.dir/IPCManager.cpp.o: ipc/CMakeFiles/ipc.dir/flags.make
ipc/CMakeFiles/ipc.dir/IPCManager.cpp.o: /usr/local/phud_project/ipc/IPCManager.cpp
ipc/CMakeFiles/ipc.dir/IPCManager.cpp.o: ipc/CMakeFiles/ipc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/usr/local/phud_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object ipc/CMakeFiles/ipc.dir/IPCManager.cpp.o"
	cd /usr/local/phud_project/build/ipc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT ipc/CMakeFiles/ipc.dir/IPCManager.cpp.o -MF CMakeFiles/ipc.dir/IPCManager.cpp.o.d -o CMakeFiles/ipc.dir/IPCManager.cpp.o -c /usr/local/phud_project/ipc/IPCManager.cpp

ipc/CMakeFiles/ipc.dir/IPCManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ipc.dir/IPCManager.cpp.i"
	cd /usr/local/phud_project/build/ipc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /usr/local/phud_project/ipc/IPCManager.cpp > CMakeFiles/ipc.dir/IPCManager.cpp.i

ipc/CMakeFiles/ipc.dir/IPCManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ipc.dir/IPCManager.cpp.s"
	cd /usr/local/phud_project/build/ipc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /usr/local/phud_project/ipc/IPCManager.cpp -o CMakeFiles/ipc.dir/IPCManager.cpp.s

ipc/CMakeFiles/ipc.dir/SharedMemoryIPC.cpp.o: ipc/CMakeFiles/ipc.dir/flags.make
ipc/CMakeFiles/ipc.dir/SharedMemoryIPC.cpp.o: /usr/local/phud_project/ipc/SharedMemoryIPC.cpp
ipc/CMakeFiles/ipc.dir/SharedMemoryIPC.cpp.o: ipc/CMakeFiles/ipc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/usr/local/phud_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object ipc/CMakeFiles/ipc.dir/SharedMemoryIPC.cpp.o"
	cd /usr/local/phud_project/build/ipc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT ipc/CMakeFiles/ipc.dir/SharedMemoryIPC.cpp.o -MF CMakeFiles/ipc.dir/SharedMemoryIPC.cpp.o.d -o CMakeFiles/ipc.dir/SharedMemoryIPC.cpp.o -c /usr/local/phud_project/ipc/SharedMemoryIPC.cpp

ipc/CMakeFiles/ipc.dir/SharedMemoryIPC.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ipc.dir/SharedMemoryIPC.cpp.i"
	cd /usr/local/phud_project/build/ipc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /usr/local/phud_project/ipc/SharedMemoryIPC.cpp > CMakeFiles/ipc.dir/SharedMemoryIPC.cpp.i

ipc/CMakeFiles/ipc.dir/SharedMemoryIPC.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ipc.dir/SharedMemoryIPC.cpp.s"
	cd /usr/local/phud_project/build/ipc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /usr/local/phud_project/ipc/SharedMemoryIPC.cpp -o CMakeFiles/ipc.dir/SharedMemoryIPC.cpp.s

ipc/CMakeFiles/ipc.dir/UnixSocketIPC.cpp.o: ipc/CMakeFiles/ipc.dir/flags.make
ipc/CMakeFiles/ipc.dir/UnixSocketIPC.cpp.o: /usr/local/phud_project/ipc/UnixSocketIPC.cpp
ipc/CMakeFiles/ipc.dir/UnixSocketIPC.cpp.o: ipc/CMakeFiles/ipc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/usr/local/phud_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object ipc/CMakeFiles/ipc.dir/UnixSocketIPC.cpp.o"
	cd /usr/local/phud_project/build/ipc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT ipc/CMakeFiles/ipc.dir/UnixSocketIPC.cpp.o -MF CMakeFiles/ipc.dir/UnixSocketIPC.cpp.o.d -o CMakeFiles/ipc.dir/UnixSocketIPC.cpp.o -c /usr/local/phud_project/ipc/UnixSocketIPC.cpp

ipc/CMakeFiles/ipc.dir/UnixSocketIPC.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ipc.dir/UnixSocketIPC.cpp.i"
	cd /usr/local/phud_project/build/ipc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /usr/local/phud_project/ipc/UnixSocketIPC.cpp > CMakeFiles/ipc.dir/UnixSocketIPC.cpp.i

ipc/CMakeFiles/ipc.dir/UnixSocketIPC.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ipc.dir/UnixSocketIPC.cpp.s"
	cd /usr/local/phud_project/build/ipc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /usr/local/phud_project/ipc/UnixSocketIPC.cpp -o CMakeFiles/ipc.dir/UnixSocketIPC.cpp.s

# Object files for target ipc
ipc_OBJECTS = \
"CMakeFiles/ipc.dir/IPCManager.cpp.o" \
"CMakeFiles/ipc.dir/SharedMemoryIPC.cpp.o" \
"CMakeFiles/ipc.dir/UnixSocketIPC.cpp.o"

# External object files for target ipc
ipc_EXTERNAL_OBJECTS =

ipc/libipc.a: ipc/CMakeFiles/ipc.dir/IPCManager.cpp.o
ipc/libipc.a: ipc/CMakeFiles/ipc.dir/SharedMemoryIPC.cpp.o
ipc/libipc.a: ipc/CMakeFiles/ipc.dir/UnixSocketIPC.cpp.o
ipc/libipc.a: ipc/CMakeFiles/ipc.dir/build.make
ipc/libipc.a: ipc/CMakeFiles/ipc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/usr/local/phud_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libipc.a"
	cd /usr/local/phud_project/build/ipc && $(CMAKE_COMMAND) -P CMakeFiles/ipc.dir/cmake_clean_target.cmake
	cd /usr/local/phud_project/build/ipc && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ipc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
ipc/CMakeFiles/ipc.dir/build: ipc/libipc.a
.PHONY : ipc/CMakeFiles/ipc.dir/build

ipc/CMakeFiles/ipc.dir/clean:
	cd /usr/local/phud_project/build/ipc && $(CMAKE_COMMAND) -P CMakeFiles/ipc.dir/cmake_clean.cmake
.PHONY : ipc/CMakeFiles/ipc.dir/clean

ipc/CMakeFiles/ipc.dir/depend:
	cd /usr/local/phud_project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /usr/local/phud_project /usr/local/phud_project/ipc /usr/local/phud_project/build /usr/local/phud_project/build/ipc /usr/local/phud_project/build/ipc/CMakeFiles/ipc.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : ipc/CMakeFiles/ipc.dir/depend

