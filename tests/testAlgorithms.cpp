#include "List.h"

#include "algorithms.h"

#include <iostream>
#include <string>
#include <chrono>
#include <functional>

void measure(std::function<void(List& arr)> algo, List& arr, std::string title){
  std::cout << std::endl << "__________________" << title << std::endl;

  arr.randomItems();
  std::cout << "-=-=-=-=-= before:" << std::endl;
  arr.print();
  std::cout << std::endl;

  auto start = std::chrono::high_resolution_clock::now();
  algo(arr);
  auto stop = std::chrono::high_resolution_clock::now();

  std::cout << "\n" << "-=-=-=-=-= after:" << std::endl;
  arr.print();

  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop-start);
  std::cout << "took: " << duration.count() << " microseconds" << std::endl;
}

void testLinearSearch(List& arr){
  int searchNum = 7; 

  auto start = std::chrono::high_resolution_clock::now();

  std::cout << "__________________Testing linear search Algorithm" << std::endl;
  std::cout << "searching: " << searchNum << std::endl;
  std::cout << "index: " << linearSearch(arr, searchNum) << std::endl;

  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop-start);
  std::cout << "took: " << duration.count() << " microseconds" << std::endl;
}

void testBinarySearch(List& arr){
  int searchNum = 7;

  auto start = std::chrono::high_resolution_clock::now();

  std::cout << std::endl << "__________________Testing binarySearch Algorithm" << std::endl;
  std::cout << "searching: " << searchNum << std::endl;
  std::cout << "index: " << binarySearch(arr, searchNum) << std::endl;

  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop-start);
  std::cout << "took: " << duration.count() << " microseconds" << std::endl;
}


void testInsertionSort(List& arr){
  measure([](List& arr){
      insertionSort(arr);
  }, arr, "Testing selection sort Algorithm");
}

void testSelectionSort(List& arr){
  measure([](List& arr){
      selectionSort(arr);
  }, arr, "Testing selection sort Algorithm");
}


void testMergeSort(List& arr){
  measure([](List& arr){
      mergeSort(arr, 0, arr.tamanho-1);
  }, arr, "Testing merge sort Algorithm");
}

void testQuickSort(List& arr){
  measure([](List& arr){
    quickSort(arr, 0, arr.tamanho-1);
  }, arr, "Testing quick sort Algorithm");
}

