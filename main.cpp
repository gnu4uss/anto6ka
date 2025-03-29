#include <iostream>
#include "dz1.h"
int main(int, char**){
	const int arr_size = 15;
	int array[arr_size];

	for (size_t i = 0; i < arr_size; ++i)
		array[i] = i;

	//std::random_device rd; 
    //std::mt19937 gen(rd());
	//std::uniform_int_distribution<> dis(1, 100);

    //for (int i = 0; i < arr_size; i++) {
    //    array[i] = dis(gen);
    //}
// 	std::cout << "Running ShowNum\n";
	ShowNum(array, arr_size); std::cout << std::endl;
// 	std::cout << "Running ShowNum_reverse\n";
	ShowNum_reverse(array, arr_size); std::cout << std::endl;
// 	std::cout << "Running ShowEven\n";
	ShowEven(array, arr_size); std::cout << std::endl;
	//std::cout << std::endl;

	return 0;
}

