#include <iostream>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <semaphore.h>
#include <ncurses.h>
#include <cstring>

#define SHM_NAME "/phud_shm"
#define SEM_NAME "/phud_sem"
#define SHM_SIZE 1024
#define CHANNEL_HEIGHT 10 // Number of rows in the RX channel

// Shared memory and semaphore
char *shared_mem;
sem_t *semaphore;

// HUD elements
int spinner_position = 0;
const char spinner_chars[] = "|/-\\";

// Function to read from shared memory
std::string read_shared_memory() {
    sem_wait(semaphore); // Wait for access
    std::string data(shared_mem);
    sem_post(semaphore); // Release access
    return data;
}

// Function to draw the HUD
void draw_hud(const std::string &packet_info) {
    clear();
    mvprintw(0, 5, "RX Channel");

    // Draw the channel
    for (int i = 1; i <= CHANNEL_HEIGHT; ++i) {
        mvprintw(i, 5, "|");
    }

    // Draw the spinner
    mvprintw(spinner_position + 1, 5, "%c", spinner_chars[spinner_position % 4]);

    // Display latest packet info
    mvprintw(2, 10, "Packet Info: %s", packet_info.c_str());

    refresh();
}

int main() {
    // Open shared memory
    int shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    if (shm_fd == -1) {
        std::cerr << "[ERROR] Failed to open shared memory.\n";
        return 1;
    }

    ftruncate(shm_fd, SHM_SIZE);
    shared_mem = (char *)mmap(0, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (shared_mem == MAP_FAILED) {
        std::cerr << "[ERROR] Failed to map shared memory.\n";
        return 1;
    }

    // Open semaphore
    semaphore = sem_open(SEM_NAME, O_CREAT, 0666, 1);
    if (semaphore == SEM_FAILED) {
        std::cerr << "[ERROR] Failed to open semaphore.\n";
        return 1;
    }

    // Initialize ncurses
    initscr();
    noecho();
    curs_set(0);

    std::cout << "[HUD] Listening for packet updates...\n";

    // Main loop: Read from shared memory and update the display
    while (true) {
        std::string packet_info = read_shared_memory();
        draw_hud(packet_info);

        // Update spinner position
        spinner_position = (spinner_position + 1) % CHANNEL_HEIGHT;
        usleep(50000); // Sleep for 50ms for smooth rendering
    }

    // Cleanup
    endwin();
    shm_unlink(SHM_NAME);
    sem_close(semaphore);
    sem_unlink(SEM_NAME);
    return 0;
}
