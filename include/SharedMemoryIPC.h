#ifndef SHARED_MEMORY_IPC_H
#define SHARED_MEMORY_IPC_H

#include "IPCInterface.h"
#include <string>
#include <fcntl.h>       // O_* constants
#include <sys/mman.h>    // mmap
#include <unistd.h>      // ftruncate
#include <semaphore.h>   // POSIX semaphores

class SharedMemoryIPC : public IPCInterface {
private:
    int shm_fd;
    char* shared_mem;
    std::string shm_name;
    sem_t* semaphore;

public:
    SharedMemoryIPC(const std::string& name = "/phud_shm");
    ~SharedMemoryIPC();

    void sendMessage(const std::string& message) override;
    std::string receiveMessage() override;
};

#endif // SHARED_MEMORY_IPC_H
