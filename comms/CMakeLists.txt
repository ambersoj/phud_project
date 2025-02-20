cmake_minimum_required(VERSION 3.10)

add_library(comms UnixSocketComms.cpp)

target_include_directories(comms PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(comms PRIVATE pthread)
