/**
 * @file SharedMemoryIPC.h
 * @brief Shared Memory IPC implementation
 *
 * This file contains the SharedMemoryIPC class, which allows interprocess
 * communication using POSIX shared memory and semaphores.
 */

#ifndef SHARED_MEMORY_IPC_H
#define SHARED_MEMORY_IPC_H

#include "IPCInterface.h"
#include <string>
#include <fcntl.h>       // O_* constants
#include <sys/mman.h>    // mmap
#include <unistd.h>      // ftruncate
#include <semaphore.h>   // POSIX semaphores

/**
 * @class SharedMemoryIPC
 * @brief Handles IPC using shared memory and semaphores.
 *
 * This class provides methods to send and receive messages
 * using a shared memory segment and a named semaphore.
 */
class SharedMemoryIPC : public IPCInterface {
private:
    int shm_fd;          ///< File descriptor for shared memory
    char* shared_mem;    ///< Pointer to the shared memory segment
    std::string shm_name; ///< Name of the shared memory segment
    sem_t* semaphore;    ///< POSIX semaphore for synchronization
    bool is_writer;      ///< Flag indicating if this instance is the writer

public:
    /**
     * @brief Constructor to initialize shared memory IPC.
     * @param name The name of the shared memory segment.
     * @param writer Flag indicating if this instance is a writer.
     */
    SharedMemoryIPC(const std::string& name, bool writer);

    /**
     * @brief Destructor to clean up shared memory and semaphores.
     */
    ~SharedMemoryIPC();

    /**
     * @brief Writes data to the shared memory segment.
     * @param message The message to write.
     */
    void writeData(const char* message);

    /**
     * @brief Reads data from the shared memory segment.
     * @param buffer The buffer to store the read data.
     */
    void readData(char* buffer);
};

#endif // SHARED_MEMORY_IPC_H
