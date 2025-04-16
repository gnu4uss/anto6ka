#include "array_info.h"

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
