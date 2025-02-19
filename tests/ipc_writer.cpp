#include <iostream>
#include <cstring>
#include "../include/SharedMemoryIPC.hpp"

int main() {
    SharedMemoryIPC ipc("/phud_shm");
    const char* message = "Hello from ipc_writer!";
    
    ipc.writeData(message, strlen(message) + 1);

    std::cout << "[ipc_writer] Message written to shared memory: " << message << std::endl;

    std::cout << "[ipc_writer] Waiting for reader... Press ENTER to exit." << std::endl;
    std::cin.get();  // Keep the process running until user presses ENTER

    return 0;
}
