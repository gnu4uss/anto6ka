#pragma once
#include <chrono>
#include <functional>
double measureSortTime(std::function<void(int[], int)> sortFunction, int array[], int size);
