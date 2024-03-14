#include "task1.h"

void fillInFibonacciNumbers(int* result, int length) {
    if (length == 0) {
        return;
    }
    result[0] = 0;
    if (length == 1) {
        return;
    }
    result[1] = 1;
    for (int i = 2; i < length; i++) {
       result[i] = result[i - 1] + result[i - 2];
    }
}


void printArray(int* arr, int length) {
    for (int i = 0; i < length; i++) {
        std::cout << arr[i] << std::endl;
    }
}


void createFibonacci() {
    int length; 
    std::cout << "Hvor mange fibonacci tall vil du generere?" << std::endl;
    std::cin >> length;
    std::cout << "Fibonacci tallene er:" << std::endl;

    int* result = new int[length];
    fillInFibonacciNumbers(result, length);
    printArray(result, length);

    std::cout << result << std::endl;

    delete[] result;
    result = nullptr;
}


