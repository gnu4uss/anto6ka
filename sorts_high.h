#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
bool ascending(int a, int b);
void fillArray(int* arr, int size);
void bubbleSort(int* ar, int size, bool (*comp)(int a, int b));
void insertionSort(int* ar, int size, bool (*comp)(int a, int b));
void selectionSort(int* ar, int size, bool (*comp)(int a, int b));
void quickSort(int* ar, int size, bool (*comp)(int a, int b));
void mergeSort(int* ar, int size, bool (*comp)(int a, int b));
