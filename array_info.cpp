#include "array_info.h"
#include <iostream>

void getInfoArray(struct ArrayInfo* arInfo){
// 	arInfo->ar = nullptr;
// 	arInfo->size = 0;
	arInfo->ind_max = 0;
	arInfo->ind_min = 0;
	arInfo->mean = 0;
}

MinMax GetMaxMin(const int* ar, int size){
	MinMax result;
	result.ind_max = 0;
	result.ind_min = 0;
	for (int i = 1; i < size; i++) {
        if (ar[i] < ar[result.ind_min]) {
            result.ind_min = ar[i];
        }
        if (ar[i] > ar[result.ind_max]) {
            result.ind_max = ar[i];
        }
    }
	return result;
}

CountNum GetStatNumber(const int* ar, int size){
	CountNum result;
	result.pos = 0;
	result.zero = 0;
	result.neg = 0;
	for (int i = 1; i < size; i++) {
		if (ar[i] > 0)
			result.pos++;
		if (ar[i] == 0)
			result.zero++;
		if (ar[i] < 0)
			result.neg++;
	}
	return result;
}

int* CreateAr(int size) {
    return new int[size];
}

int* CreateAr(int size, int number) {
    int* arr = new int[size];
    for (int i = 0; i < size; ++i) {
        arr[i] = number;
    }
    return arr;
}

int* CreateAr(int size, int min, int max) {
    int* arr = new int[size];
    srand(time(0));
    for (int i = 0; i < size; ++i) {
        arr[i] = min + rand() % (max - min + 1);
    }
    return arr;
}

StatArray GetStatArray(const int* ar, int size) {
    StatArray result;
    result.ar = nullptr;
    result.probabilities = nullptr;
    result.size = 0;
    result.size_prob = 0;

    if (size == 0 || ar == nullptr) {
        return result;
    }
    
    int max_num = ar[0];
    for (int i = 1; i < size; ++i) {
        if (ar[i] > max_num) {
            max_num = ar[i];
        }
    }
    result.size_prob = max_num + 1;
    
    int* freq = new int[result.size_prob](); 
    
    for (int i = 0; i < size; ++i) {
        freq[ar[i]]++;
    }
    
    int unique_count = 0;
    for (int i = 0; i < result.size_prob; ++i) {
        if (freq[i] > 0) {
            unique_count++;
        }
    }
    result.size = unique_count;
    
    result.ar = new int[result.size];
    result.probabilities = new double[result.size_prob]();
    int index = 0;
    for (int i = 0; i < result.size_prob; ++i) {
        if (freq[i] > 0) {
            result.ar[index++] = i;
            result.probabilities[i] = static_cast<double>(freq[i]) / size;
        }
    }

    delete[] freq;
    return result;
}

void ShowElement(const int* ar, int size, int col_count, char delimeter) {
    for (int i = 0; i < size; ++i) {
        std::cout << ar[i];
        if ((i + 1) % col_count == 0 || i == size - 1) {
            std::cout << '\n';
        } else {
            std::cout << delimeter;
        }
    }
}
