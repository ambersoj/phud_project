#include <ncurses.h>
#include <unistd.h> // For usleep
#include <cstdlib>  // For random traffic bursts
#include <ctime>

void draw_tx_channel(int progress, int traffic_load) {
    clear(); // Clear the screen for redrawing
    
    mvprintw(1, 10, "TX Channel");
    mvprintw(2, 10, "============");
    
    // Display traffic load level
    mvprintw(4, 30, "Traffic Load: %d", traffic_load);
    
    // Draw the TX channel (vertical bar)
    for (int i = 0; i < 10; ++i) {
        mvprintw(5 + i, 15, "|");
    }

    // Moving spinner
    const char spinner[] = "|/-\\";
    mvprintw(5 + (10 - progress % 10), 15, "%c", spinner[progress % 4]);

    refresh();
}

int main() {
    initscr();      // Start ncurses mode
    noecho();       // Don't echo user input
    curs_set(0);    // Hide the cursor
    nodelay(stdscr, TRUE); // Make getch non-blocking
    
    srand(time(nullptr)); // Seed random traffic bursts
    
    int progress = 0;
    char ch;
    int traffic_load = 1; // Default to normal traffic
    
    while ((ch = getch()) != 'q') { // Press 'q' to exit
        if (ch == KEY_UP && traffic_load < 2) {
            traffic_load++; // Increase traffic intensity
        } else if (ch == KEY_DOWN && traffic_load > 0) {
            traffic_load--; // Decrease traffic intensity
        }
        
        int delay_time;
        
        if (traffic_load == 0) {
            delay_time = 200000; // Low traffic - slow updates
        } else if (traffic_load == 1) {
            delay_time = 100000; // Normal traffic
        } else {
            delay_time = 50000; // High burst - rapid updates
        }

        draw_tx_channel(progress, traffic_load);
        progress++;
        usleep(delay_time); // Adjust speed dynamically
    }

    endwin(); // End ncurses mode
    return 0;
}
