#include <windows.h>
#include <tlhelp32.h>
#include <iostream>
#include <string>

//Función que busca procesos con el nombre que le damos
void check_office_process(const std::string& process_name) {
    HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0); // Obtiene una lista de procesos
    PROCESSENTRY32 proc;
    proc.dwSize = sizeof(PROCESSENTRY32);

    int process_count = 0;
    int total_threads = 0;

    if (Process32First(hSnap, &proc)) {
        do {
            if (process_name == proc.szExeFile) {
                process_count++;
                total_threads += proc.cntThreads; //Suma los hilos que usa este proceso
                std::cout << "Process: " << proc.szExeFile<< std::endl
                          << "Threads: " << proc.cntThreads << std::endl;
            }
        } while (Process32Next(hSnap, &proc));
    }
    CloseHandle(hSnap);
}

int main() {
    std::cout << "Video game: Resident evil biohazard " << std::endl;
    check_office_process("re7.exe");
    return 0;
}
