#ifndef SHARED_MEMORY_IPC_HPP
#define SHARED_MEMORY_IPC_HPP

#include "IPCInterface.hpp"
#include <string>
#include <fcntl.h>       // O_* constants
#include <sys/mman.h>    // mmap
#include <unistd.h>      // ftruncate
#include <semaphore.h>   // POSIX semaphores

class SharedMemoryIPC : public IPCInterface {
private:
    bool is_writer = false;
    int shm_fd;
    char* shared_mem;
    std::string shm_name;
    sem_t* semaphore;

public:
    SharedMemoryIPC(const std::string& name = "/phud_shm");
    ~SharedMemoryIPC();

    void sendMessage(const std::string& message) override;
    std::string receiveMessage() override;

    void writeData(const char* data, size_t size);
    void readData(char* buffer, size_t size);
};

#endif // SHARED_MEMORY_IPC_H
