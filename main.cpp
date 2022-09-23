#include "List.h"

// #include "testDataStructures.cpp"
#include "algorithms/linearSearch.cpp"
#include "algorithms/binarySearch.cpp"
#include "algorithms/selectionSort.cpp"
#include "algorithms/insertionSort.cpp"


#include <iostream>
#include <chrono>
// #include <time.h>

using namespace std;

#define ARR_SIZE 10

void testAlgorithms(){
  // int list[] = {9,8,7,6,5,4};
  List arr = List(1000);
  // arr.orderedItems();
  // arr.print();
  cout << endl;

  int searchNum = 7; 


  auto start = std::chrono::high_resolution_clock::now();

  cout << "Testing linear search Algorithm" << endl;
  cout << "searching: " << searchNum << endl;
  cout << "index: " << linearSearch(arr, searchNum) << endl;

  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop-start);
  cout << "took: " << duration.count() << " microseconds" << endl;

  //----------------------

  start = std::chrono::high_resolution_clock::now();

  cout << endl << "Testing binarySearch Algorithm" << endl;
  cout << "searching: " << searchNum << endl;
  cout << "index: " << binarySearch(arr, searchNum) << endl;

  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop-start);
  cout << "took: " << duration.count() << " microseconds" << endl;

  //----------------------

  start = std::chrono::high_resolution_clock::now();

  cout << endl << "Testing insertion sort Algorithm" << endl;
  cout << "before:" << endl;
  // arr.print();
  cout << "after:" << endl;
  insertionSort(arr);
  // arr.print();

  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop-start);
  cout << "took: " << duration.count() << " microseconds" << endl;

  //-----------------------

  start = std::chrono::high_resolution_clock::now();

  cout << endl << "Testing selection sort Algorithm" << endl;
  arr.randomItems();
  cout << "before:" << endl;
  // arr.print();
  cout << "after:" << endl;
  selectionSort(arr);
  // arr.print();

  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop-start);
  cout << "took: " << duration.count() << " microseconds" << endl;
  
}

int main () {
  // srand(time(NULL));
  // testAllDataStructures();
  testAlgorithms();


  return 0;
}
