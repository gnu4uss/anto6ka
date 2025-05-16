#include "sorts_high.h"
#include "MeasTime.h"

int main() {
    srand(time(0));

    const int numSizes = 5;
    int sizes[numSizes] = {1000, 5000, 10000, 20000, 50000};

    for (int i = 0; i < numSizes; ++i) {
        int size = sizes[i];
        int* arr = new int[size];

        std::cout << "\nArray size: " << size << std::endl;
        
        fillArray(arr, size);
        auto start = std::chrono::high_resolution_clock::now();
        bubbleSort(arr, size, ascending);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;
        std::cout << "Bubble Sort: " << diff.count() << " sec" << std::endl;
        
        fillArray(arr, size);
        start = std::chrono::high_resolution_clock::now();
        insertionSort(arr, size, ascending);
        end = std::chrono::high_resolution_clock::now();
        diff = end - start;
        std::cout << "Insertion Sort: " << diff.count() << " sec" << std::endl;
        
        fillArray(arr, size);
        start = std::chrono::high_resolution_clock::now();
        selectionSort(arr, size, ascending);
        end = std::chrono::high_resolution_clock::now();
        diff = end - start;
        std::cout << "Selection Sort: " << diff.count() << " sec" << std::endl;
        
        fillArray(arr, size);
        start = std::chrono::high_resolution_clock::now();
        quickSort(arr, size, ascending);
        end = std::chrono::high_resolution_clock::now();
        diff = end - start;
        std::cout << "Quick Sort: " << diff.count() << " sec" << std::endl;
        
        fillArray(arr, size);
        start = std::chrono::high_resolution_clock::now();
        mergeSort(arr, size, ascending);
        end = std::chrono::high_resolution_clock::now();
        diff = end - start;
        std::cout << "Merge Sort: " << diff.count() << " sec" << std::endl;

        delete[] arr;
    }

    return 0;
}

