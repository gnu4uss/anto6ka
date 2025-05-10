#include "sorts.h"

void insertion_sort(int* ar, int size, bool isAscending) {
    for (int i = 1; i < size; ++i) {
        int key = ar[i];
        int j = i - 1;

        if (isAscending) {
            while (j >= 0 && ar[j] > key) {
                ar[j + 1] = ar[j];
                j--;
            }
        } else {
            while (j >= 0 && ar[j] < key) {
                ar[j + 1] = ar[j];
                j--;
            }
        }
        ar[j + 1] = key;
    }
}

void bubble_sort(int* ar, int size, bool isAscending) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            bool condition = isAscending ? ar[j] > ar[j + 1] : ar[j] < ar[j + 1];
            if (condition) {
                int temp = ar[j];
                ar[j] = ar[j + 1];
                ar[j + 1] = temp;
            }
        }
    }
}

void selection_sort(int* ar, int size, bool isAscending) {
    for (int i = 0; i < size - 1; ++i) {
        int extreme_index = i;
        for (int j = i + 1; j < size; ++j) {
            if (isAscending ? (ar[j] < ar[extreme_index]) : (ar[j] > ar[extreme_index])) {
                extreme_index = j;
            }
        }
        if (extreme_index != i) {
            int temp = ar[i];
            ar[i] = ar[extreme_index];
            ar[extreme_index] = temp;
        }
    }
}
