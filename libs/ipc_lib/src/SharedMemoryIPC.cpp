#include "SharedMemoryIPC.h"
#include <iostream>
#include <cstring>
#include <cstdlib>

#define SHM_SIZE 1024  // 1KB shared memory size

SharedMemoryIPC::SharedMemoryIPC(const std::string& name) : shm_name(name) {
    shm_fd = shm_open(shm_name.c_str(), O_CREAT | O_RDWR, 0666);
    if (shm_fd == -1) {
        std::cerr << "Failed to create shared memory!" << std::endl;
        return;
    }
    ftruncate(shm_fd, SHM_SIZE);
    shared_mem = (char*) mmap(0, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (shared_mem == MAP_FAILED) {
        std::cerr << "Failed to map shared memory!" << std::endl;
        return;
    }
    
    // Initialize semaphore
    semaphore = sem_open("/phud_semaphore", O_CREAT, 0666, 1);
    if (semaphore == SEM_FAILED) {
        std::cerr << "Failed to create semaphore!" << std::endl;
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
