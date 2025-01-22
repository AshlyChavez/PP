
#include <iostream>
#include <pthread.h>
#include <thread>

void* message(void* arg) {
    std::cout << "Thread 1: This thread prints a message HELLO"  << std::endl;
    return NULL;
}

void* calculate_sum(void* arg) {
    int sum = 0;
    for (int i = 1; i <= 10; i++) {
        sum += i;
    }
    std::cout << "Thread 2: The sum of numbers from 1 to 10 is " << sum << "." << std::endl;
    return NULL;
}

void* calculate_product(void* arg) {
    int product = 1;
    for (int i = 1; i <= 5; i++) {
        product *= i;
    }
    std::cout << "Thread 3: The product of numbers from 1 to 5 is " << product << "." << std::endl;
    return NULL;
}

void* countdown(void* arg) {
    std::cout << "Thread 4: Countdown: ";
    for (int i = 5; i >= 1; i--) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return NULL;
}

void* print_even(void* arg) {
    std::cout << "Thread 5: Even numbers from 1 to 10: ";
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
    return NULL;
}

void* print_odd(void* arg) {
    std::cout << "Thread 6: Odd numbers from 1 to 10: ";
    for (int i = 1; i <= 10; i++) {
        if (i % 2 != 0) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
    return NULL;
}

int main() {
    pthread_t proc1, proc2, proc3, proc4, proc5, proc6;
    pthread_create(&proc1, NULL, message, NULL);
    pthread_join(proc1, NULL);

    pthread_create(&proc2, NULL, calculate_sum, NULL);
    pthread_join(proc2, NULL);

    pthread_create(&proc3, NULL, countdown, NULL);
    pthread_join(proc3, NULL);
    pthread_create(&proc4, NULL, calculate_product, NULL);
    pthread_join(proc4, NULL);

    pthread_create(&proc5, NULL, print_even, NULL);
    pthread_join(proc5, NULL);

    pthread_create(&proc6, NULL, print_odd, NULL);
    pthread_join(proc6, NULL);

    return 0;
}