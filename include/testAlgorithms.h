#include "List.h"

#include "algorithms.h"

#include <string>
#include <functional>

void measure(std::function<void(List& arr)> algo, List& arr, std::string title);
void testLinearSearch(List& arr);
void testBinarySearch(List& arr);
void testInsertionSort(List& arr);
void testSelectionSort(List& arr);
void testMergeSort(List& arr);
void testQuickSort(List& arr);

