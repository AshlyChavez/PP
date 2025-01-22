#include <iostream>
#include <pthread.h>

#define NUM_HILOS 6

void* print_message(void* arg) {
    std::cout << "Thread 1: Thread prints a message." << std::endl;
    return NULL;
}

void* calculate_sum(void* arg) {
    int sum = 0;
    for (int i = 1; i <= 10; i++) {
        sum += i;
    }
    std::cout << "Thread 2: Theads sum of numbers from 1 to 10  " << sum << "." << std::endl;
    return NULL;
}

void* calculate_product(void* arg) {
    int product = 1;
    for (int i = 1; i <= 5; i++) {
        product *= i;
    }
    std::cout << "Thread 3: The product of numbers from 1 to 5 " << product << "." << std::endl;
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
    pthread_t threads[NUM_HILOS];

    pthread_create(&threads[0], NULL, print_message, NULL);
    pthread_create(&threads[1], NULL, calculate_sum, NULL);
    pthread_create(&threads[2], NULL, calculate_product, NULL);
    pthread_create(&threads[3], NULL, countdown, NULL);
    pthread_create(&threads[4], NULL, print_even, NULL);
    pthread_create(&threads[5], NULL, print_odd, NULL);

    for (int i = 0; i < NUM_HILOS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("Error joining thread");
            return 1;
        }
    }
    return 0;
}
