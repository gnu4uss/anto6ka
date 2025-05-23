#include "MeasTime.h"
bool ascending(int a, int b) {
    return a < b;
}

void bubbleSort(int* arr, int size, bool (*comp)(int, int)) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (comp(arr[j], arr[j + 1])) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }     
}


void insertionSort(int* ar, int size, bool (*comp)(int a, int b)) {
    for (int i = 1; i < size; i++) {
        int key = ar[i];
        int j = i - 1;
        while (j >= 0 && comp(key, ar[j])) {
            ar[j + 1] = ar[j];
            j--;
        }
        ar[j + 1] = key;
    }
}


void selectionSort(int* ar, int size, bool (*comp)(int a, int b)) {
    for (int i = 0; i < size - 1; i++) {
        int ext = i; 
        for (int j = i + 1; j < size; j++) {
            if (comp(ar[j], ar[ext])) {
                ext = j;
            }
        }
        
        int temp = ar[i];
        ar[i] = ar[ext];
        ar[ext] = temp;
    }
}

void quickSort(int* ar, int size, bool (*comp)(int a, int b)) {
    if (size <= 1) return;

    int pivot = ar[size - 1];
    int i = 0;

    for (int j = 0; j < size - 1; j++) {
        if (comp(ar[j], pivot)) {
            std::swap(ar[i], ar[j]);
            i++;
        }
    }
    std::swap(ar[i], ar[size - 1]);

    quickSort(ar, i, comp);
    quickSort(ar + i + 1, size - i - 1, comp);
}

void mergeSort(int* ar, int size, bool (*comp)(int a, int b)) {
    if (size <= 1) return;

    int mid = size / 2;
    int* left = new int[mid];
    int* right = new int[size - mid];

    for (int i = 0; i < mid; i++) left[i] = ar[i];
    for (int i = mid; i < size; i++) right[i - mid] = ar[i];

    mergeSort(left, mid, comp);
    mergeSort(right, size - mid, comp);

    int i = 0, j = 0, k = 0;
    while (i < mid && j < size - mid) {
        if (comp(left[i], right[j])) {
            ar[k++] = left[i++];
        } else {
            ar[k++] = right[j++];
        }
    }

    while (i < mid) ar[k++] = left[i++];
    while (j < size - mid) ar[k++] = right[j++];

    delete[] left;
    delete[] right;
}

void getTime() {
    const int numSizes = 27;
    int sizes[numSizes] = {100, 500, 750, 900, 1400, 2000, 2500, 4100,
                         5000, 7800, 9500, 12000, 13000, 15000, 25000, 33000, 
                         50000, 100000, 140000, 180000, 250000, 400000, 
                         500000, 655000, 800000, 840000, 1000000};
    
    const auto TIME_LIMIT = std::chrono::seconds(2); 
    
    std::cout << std::left << std::setw(8) << "N" 
              << std::setw(12) << "Bubble" 
              << std::setw(12) << "Insert" 
              << std::setw(12) << "Select" 
              << std::setw(12) << "Quick" 
              << std::setw(12) << "Merge" 
              << "\n" << std::endl;

    void(*name_sort[5])(int*, int, bool(*) (int, int)) = {
        bubbleSort, insertionSort, selectionSort, quickSort, mergeSort
    };
    
    bool algorithmStopped[5] = {false};
    
    for (int i = 0; i < numSizes; i++) {
        int size = sizes[i];
        std::cout << std::left << std::setw(8) << size;
        
        int* original_arr = new int[size];
        for (int k = 0; k < size; k++) {
            original_arr[k] = rand() % 100;
        }
        
        for (int n = 0; n < 5; n++) {
            if (algorithmStopped[n]) {
                std::cout << std::setw(12) << "-";
                continue;
            }
            
            int* arr = new int[size];
            for (int j = 0; j < size; j++) {
                arr[j] = original_arr[j];
            }
            
            auto start = std::chrono::high_resolution_clock::now();
            name_sort[n](arr, size, ascending);
            auto end = std::chrono::high_resolution_clock::now();
            
            auto duration_time = end - start;
            
            if (duration_time > TIME_LIMIT) {
                algorithmStopped[n] = true;
                std::cout << std::setw(12) << "-";
            } else {
                std::cout << std::setw(12) 
                          << std::chrono::duration_cast<std::chrono::nanoseconds>(duration_time).count();
            }
            
            delete[] arr;
        }
        
        delete[] original_arr;
        std::cout << "\n";
    }
}
