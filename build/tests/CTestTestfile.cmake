# CMake generated Testfile for 
# Source directory: /usr/local/phud_project/tests
# Build directory: /usr/local/phud_project/build/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(IPC_Test "/usr/local/phud_project/build/tests/test_ipc")
set_tests_properties(IPC_Test PROPERTIES  _BACKTRACE_TRIPLES "/usr/local/phud_project/tests/CMakeLists.txt;28;add_test;/usr/local/phud_project/tests/CMakeLists.txt;0;")
add_test(SharedMemoryIPC_Test "/usr/local/phud_project/build/tests/test_SharedMemoryIPC")
set_tests_properties(SharedMemoryIPC_Test PROPERTIES  _BACKTRACE_TRIPLES "/usr/local/phud_project/tests/CMakeLists.txt;29;add_test;/usr/local/phud_project/tests/CMakeLists.txt;0;")
subdirs("../_deps/catch2-build")
