#include "List.h"

#include "testDataStructures.h"
#include "testAlgorithms.h"

#include <iostream>

int main () {
  // srand(time(NULL));
  
  // ==== Data Structures ====
  testLinkedlist();
  testQueue();
  testHashmap();
  testHashmapChained();
  testHeap();
  testPriorityList();

  // ======= Algorithms =======
  
  // int list[] = {9,8,7,6,5,4};
  List arr = List(10);
  // arr.orderedItems();
  arr.print();
  std::cout << std::endl;

  testLinearSearch(arr);
  testBinarySearch(arr);
  testInsertionSort(arr);
  testSelectionSort(arr);
  testMergeSort(arr);
  testQuickSort(arr);
  return 0;
}
