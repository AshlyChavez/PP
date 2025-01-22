#include <iostream>
#include <pthread.h>
#include <unistd.h>

void* infinite_greeting(void* arg) {
    while (true) {
        std::cout << "Infinite loop!" << std::endl;
        sleep(1);
    }
    return NULL;
}

//Función para el primer hilo que saluda
void* greet(void* arg) {
    for (int i = 0; i < 5; i++) {
        std::cout << "Thread 1: Hello!" << std::endl;
        sleep(1);
    }
    return NULL;
}

//Función para el segundo hilo que se despide
void* say_goodbye(void* arg) {
    for (int i = 0; i < 5; i++) {
        std::cout << "Thread 2: Goodbye!" << std::endl;
        sleep(1); // Pausa de 1 segundo
    }
    return NULL;
}

int main() {
    pthread_t infinite_thread, thread1, thread2;

    pthread_create(&infinite_thread, NULL, infinite_greeting, NULL);
    pthread_create(&thread1, NULL, greet, NULL);
    pthread_create(&thread2, NULL, say_goodbye, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    return 0;
}
