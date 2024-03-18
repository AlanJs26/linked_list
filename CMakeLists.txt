cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(linked_list)

include_directories(
  include 
)

add_library(algorithms
  src/algorithms/binarySearch.cpp
  src/algorithms/insertionSort.cpp
  src/algorithms/linearSearch.cpp
  src/algorithms/mergeSort.cpp
  src/algorithms/quickSort.cpp
  src/algorithms/selectionSort.cpp
)
add_library(datastructures
  src/datastructures/Hashmap.cpp
  src/datastructures/HashmapChained.cpp
  src/datastructures/Heap.cpp
  src/datastructures/Item.cpp
  src/datastructures/List.cpp
  src/datastructures/Linkedlist.cpp
  src/datastructures/PriorityList.cpp
  src/datastructures/Queue.cpp
)
add_library(tests
  tests/testDataStructures.cpp
  tests/testAlgorithms.cpp
)

add_executable(main
  src/main.cpp
)

target_link_libraries(main
  tests
)
target_link_libraries(tests
  algorithms
  datastructures
)
target_link_libraries(algorithms
  datastructures
)

