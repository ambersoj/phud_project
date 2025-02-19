#include <iostream>
#include <cstring>
#include "../include/SharedMemoryIPC.hpp"

int main() {
    SharedMemoryIPC ipc("/phud_shm");
    char buffer[1024];

    ipc.readData(buffer, sizeof(buffer));
    std::cout << "[ipc_reader] Message received: " << buffer << std::endl;

    return 0;
}
