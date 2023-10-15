#include <iostream>
#include <chrono>
#include <conio.h>

int main() {
    char key;
    bool running = false;
    std::chrono::steady_clock::time_point start_time, end_time;

    while (true) {
        if (_kbhit()) {
            key = _getch();
            if (key == 's' || key == 'S') {
                if (!running) {
                    start_time = std::chrono::steady_clock::now();
                    running = true;
                } else {
                    end_time = std::chrono::steady_clock::now();
                    running = false;
                }
            } else if (key == 'r' || key == 'R') {
                running = false;
                start_time = end_time = std::chrono::steady_clock::now();
            } else if (key == 'q' || key == 'Q') {
                break;
            }
        }

        std::chrono::steady_clock::time_point current_time = running ? std::chrono::steady_clock::now() : end_time;
        std::chrono::duration<double> elapsed_time = current_time - start_time;

        system("cls");  // Clear the screen (Windows-specific)

        std::cout << "Stopwatch (S: Start/Stop, R: Reset, Q: Quit)" << std::endl;
        std::cout << "Time: " << elapsed_time.count() << " seconds" << std::endl;

        // Sleep for a short time to reduce CPU usage
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}
