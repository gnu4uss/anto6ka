#include "MeasTime.h"
double measureSortTime(std::function<void(int[], int)> sortFunction, int array[], int size) {
    auto start = std::chrono::high_resolution_clock::now();
    sortFunction(array, size); 
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
}

