#include "SharedMemoryIPC.hpp"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sys/stat.h>

#define SHM_SIZE 1024  // 1KB shared memory size

SharedMemoryIPC::SharedMemoryIPC(const std::string& name) : shm_name(name) {
    // Attempt to open existing shared memory
    shm_fd = shm_open(shm_name.c_str(), O_RDWR, 0666);

    if (shm_fd == -1) {
        // If shared memory doesn't exist, create it
        shm_fd = shm_open(shm_name.c_str(), O_CREAT | O_RDWR, 0666);
        if (shm_fd == -1) {
            perror("shm_open failed");
            exit(1);
        }
        is_writer = true;  // This process is the first writer
    }

    // If this is the first process, set the shared memory size
    struct stat shm_info;
    if (fstat(shm_fd, &shm_info) == 0 && shm_info.st_size == 0) {
        std::cout << "[DEBUG] First process detected. Setting up shared memory." << std::endl;
        if (ftruncate(shm_fd, 1024) == -1) {
            perror("ftruncate failed");
            exit(1);
        }
    }

    // Map the shared memory into the process’s address space
    shared_mem = static_cast<char*>(mmap(0, 1024, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0));
    if (shared_mem == MAP_FAILED) {
        perror("mmap failed");
        exit(1);
    }

    std::cout << "[DEBUG] Shared memory mapped at address: " 
              << static_cast<void*>(shared_mem) 
              << " for process " << getpid() << std::endl;

    if (is_writer) {
        // Clear shared memory only if this is the first writer process
        memset(shared_mem, 0, 1024);
    }

    // Initialize semaphore for synchronization
    semaphore = sem_open("/phud_semaphore", O_CREAT, 0666, 1);
    if (semaphore == SEM_FAILED) {
        perror("sem_open failed");
        exit(1);
    }
}

SharedMemoryIPC::~SharedMemoryIPC() {
    munmap(shared_mem, SHM_SIZE);
    close(shm_fd);
    shm_unlink(shm_name.c_str());
    sem_close(semaphore);
    sem_unlink("/phud_semaphore");
}

void SharedMemoryIPC::sendMessage(const std::string& message) {
    sem_wait(semaphore);
    strncpy(shared_mem, message.c_str(), SHM_SIZE);
    sem_post(semaphore);
}

std::string SharedMemoryIPC::receiveMessage() {
    sem_wait(semaphore);
    std::string msg(shared_mem);
    sem_post(semaphore);
    return msg;
}

void SharedMemoryIPC::writeData(const char* data, size_t size) {
    sem_wait(semaphore); // Lock before writing
    memset(shared_mem, 0, size); // Clear memory
    memcpy(shared_mem, data, size - 1);
    shared_mem[size - 1] = '\0'; // Ensure null-termination
    sem_post(semaphore); // Unlock after writing

    // Debug print
    std::cout << "[DEBUG] Data written to shared memory: '" << shared_mem << "'" << std::endl;
}

void SharedMemoryIPC::readData(char* buffer, size_t size) {
    sem_wait(semaphore); // Lock before reading
    memset(buffer, 0, size); // Clear buffer
    memcpy(buffer, shared_mem, size - 1);
    buffer[size - 1] = '\0'; // Ensure null-termination
    sem_post(semaphore); // Unlock after reading

    // Debug print
    std::cout << "[DEBUG] Data read into buffer: '" << buffer << "'" << std::endl;
}
