#include <iostream>
#include <thread>
#include <chrono>

void processThread(const std::string& text) {
    while (true) {
        std::cout << text << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(10)); // Pausa breve
    }
}

int main() {
    std::thread process1(processThread, "hello");
    std::thread process2(processThread, "goodbye");

    process1.join();
    process2.join();

    return 0;
}
