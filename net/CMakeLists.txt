add_library(net STATIC net.cpp)
target_include_directories(net PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(net PRIVATE ipc)
