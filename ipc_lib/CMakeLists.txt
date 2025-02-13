add_library(ipc_lib ../src/IPCManager.cpp ../ipc_lib/src/UnixSocketIPC.cpp)
target_include_directories(ipc_lib PUBLIC ../include ../ipc_lib/include)
