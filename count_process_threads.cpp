#include <windows.h>
#include <tlhelp32.h>
#include <iostream>

//Función para contar el número total de procesos y subprocesos
void count_processes_and_threads() {
    //Crear un snapshot del sistema para saber cuantos procesos estan activos
    HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    PROCESSENTRY32 pe32;
    pe32.dwSize = sizeof(PROCESSENTRY32);
    int total_processes = 0, total_threads = 0;
    //Verificar si se puede obtener el primer proceso
    if (Process32First(hSnap, &pe32)) {
        do {
            total_processes++;
            total_threads += pe32.cntThreads;
        } while (Process32Next(hSnap, &pe32)); //Pasar al siguiente proceso
    }
    //Mostrar el total de procesos y subproceso
    std::cout << "Total processes: " << total_processes << std::endl;
    std::cout << "Total threads: " << total_threads << std::endl;
    CloseHandle(hSnap);
}

int main() {
    count_processes_and_threads();
    return 0;
}
