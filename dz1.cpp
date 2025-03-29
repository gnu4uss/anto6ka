#include "dz1.h"
#include <iostream>
#include <random>

void ShowNum_reverse(const int* array, size_t size_ar){
	for (size_t i = size_ar; i > 0; i--){
		std::cout << array[i-1] << "\t";
	}
}

void ShowNum(const int* array, size_t size_ar){
	for (size_t i = 0; i < size_ar; i++){
		std::cout << array[i] << "\t";
	}
}

void ShowEven(const int* array, size_t size_ar){
	for (size_t i = 0; i < size_ar; i++){
		if (!(array[i] & 1)){
			std::cout << array[i] << "\t";
		}
	}
}

