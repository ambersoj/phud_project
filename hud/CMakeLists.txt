add_library(hud STATIC hud.cpp)
target_include_directories(hud PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(hud PRIVATE ipc)
