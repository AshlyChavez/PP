#include <windows.h>
#include <tlhelp32.h>
#include <psapi.h>
#include <iostream>
#include <string>
#include <thread>

void check_process(const std::string& proc_name) {
    HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    PROCESSENTRY32 proc;
    proc.dwSize = sizeof(PROCESSENTRY32);

    int process_count = 0;
    int t_threads = 0;

    if (Process32First(hSnap, &proc)) {
        do {
            if (proc_name == proc.szExeFile) {
                process_count++;
                t_threads += proc.cntThreads;
            }
        } while (Process32Next(hSnap, &proc));
    }

    if (process_count > 0) {
        std::cout <<  proc_name << " \nProcesses found: " << process_count << std::endl;
        std::cout << "Threads : " << t_threads << std::endl;
    } else {
        std::cout << "\nNo processes found for " << proc_name << std::endl;
    }

    CloseHandle(hSnap);
}

void execute_program() {
    system("Program_6threads.exe");
}

int main() {
    std::thread program_thread(execute_program);

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::string proc_name = "Program_6threads.exe";
    check_process(proc_name);

    program_thread.join();

    return 0;
}
