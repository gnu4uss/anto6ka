#include <iostream>
#include "array_info.h"
#include "sorts.h"

int main(){
// 	int* ar = new int[6] {1, 2, 3, 4, 5, 10};
// 	int size = 6;
// 	struct ArrayInfo myArrayInfo;
// 	myArrayInfo.ar = ar;
// 	myArrayInfo.size = size;
// 	getInfoArray(&myArrayInfo);
// 	MinMax res_MinMax = GetMaxMin(ar, size);
// 	CountNum res_CouNum = GetStatNumber(ar, size);
// 	std::cout << "Min: " << res_MinMax.ind_min << "\n" << "Max: " << res_MinMax.ind_max << std::endl;
// 	std::cout << "Pos: " << res_CouNum.pos << "\n" << "Zero: " << res_CouNum.zero << "\n" << "Neg: " << res_CouNum.neg << std::endl;
// 	delete[] ar;

// 	int min = 50;
// 	int max = 100;
// 	int size = 6;
// 	int* myArray = CreateAr(size, min, max);
// 	for (int i = 0; i < size; ++i) {
// 		std::cout << myArray[i] << " ";
//     }
//     std::cout << std::endl;
// 	delete [] myArray;
//
	int arr[] = {5, 3, 8, 1, 2, 7, 4, 6, 9, 10};
    const int size = 10;

    selection_sort(arr, size, true);
    ShowElement(arr, size, 4, '\t');

    selection_sort(arr, size, false);
    ShowElement(arr, size, 3, ' ');
    return 0;
}

