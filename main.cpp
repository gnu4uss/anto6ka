#include <iostream>
#include "array_info.h"

int main(){
	int* ar = new int[6] {1, 2, 3, 4, 5, 10};
	int size = 6;
	struct ArrayInfo myArrayInfo;
	myArrayInfo.ar = ar;
	myArrayInfo.size = size;
	getInfoArray(&myArrayInfo);
	MinMax res_MinMax = GetMaxMin(ar, size);
	CountNum res_CouNum = GetStatNumber(ar, size);

// 	std::cout << "Min: " << res_MinMax.ind_min << "\n" << "Max: " << res_MinMax.ind_max << std::endl;
// 	std::cout << "Pos: " << res_CouNum.pos << "\n" << "Zero: " << res_CouNum.zero << "\n" << "Neg: " << res_CouNum.neg << std::endl;

	delete[] ar;
    return 0;
}

