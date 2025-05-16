#include "sorts_high.h"

bool ascending(int a, int b) {
    return a < b;
}

void fillArray(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 10000;
    }
}

void bubbleSort(int* arr, int size, bool (*comp)(int, int)) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (!comp(arr[j], arr[j + 1])) {
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
        std::swap(ar[i], ar[ext]);
    }
}

int partition(int* ar, int low, int high, bool (*comp)(int, int)) {
    int pivot = ar[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (comp(ar[j], pivot)) {
            i++;
            std::swap(ar[i], ar[j]);
        }
    }
    std::swap(ar[i + 1], ar[high]);
    return i + 1;
}

void quickSortHelper(int* ar, int low, int high, bool (*comp)(int, int)) {
    if (low < high) {
        int pi = partition(ar, low, high, comp);
        quickSortHelper(ar, low, pi - 1, comp);
        quickSortHelper(ar, pi + 1, high, comp);
    }
}

void quickSort(int* ar, int size, bool (*comp)(int a, int b)) {
    quickSortHelper(ar, 0, size - 1, comp);
}

void merge(int* ar, int left, int mid, int right, bool (*comp)(int, int)) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = ar[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = ar[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (comp(L[i], R[j])) {
            ar[k] = L[i];
            i++;
        } else {
            ar[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        ar[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        ar[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSortHelper(int* ar, int left, int right, bool (*comp)(int, int)) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortHelper(ar, left, mid, comp);
        mergeSortHelper(ar, mid + 1, right, comp);
        merge(ar, left, mid, right, comp);
    }
}

void mergeSort(int* ar, int size, bool (*comp)(int a, int b)) {
    mergeSortHelper(ar, 0, size - 1, comp);
}

