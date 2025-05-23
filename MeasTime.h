#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <cstdlib>
#include <ctime>
bool ascending(int a, int b);
void bubbleSort(int* arr, int size, bool (*comp)(int, int));
void insertionSort(int* arr, int size, bool (*comp)(int, int));
void selectionSort(int* arr, int size, bool (*comp)(int, int));
int partition(int* ar, int low, int high, bool (*comp)(int a, int b));
void quickSortHelper(int* ar, int low, int high, bool (*comp)(int a, int b));
void quickSort(int* ar, int size, bool (*comp)(int a, int b));
void merge(int* ar, int left, int mid, int right, bool (*comp)(int a, int b)); 
void mergeSortHelper(int* ar, int left, int right, bool (*comp)(int a, int b));
void mergeSort(int* ar, int size, bool (*comp)(int a, int b));
	
void getTime();

