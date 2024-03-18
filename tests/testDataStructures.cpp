#include "Linkedlist.h"
#include "Queue.h"
#include "Hashmap.h"
#include "HashmapChained.h"
#include "Heap.h"
#include "PriorityList.h"

#include <iostream>

void testLinkedlist(){
  int arr[] = {1,2,3,4};
  LinkedList L(arr, sizeof(arr)/sizeof(int));

  L.print();
}

void testQueue(){
  Queue q;

  q.enqueue(1);
  q.enqueue(4);
  q.dequeue();
  q.enqueue(2);
  q.enqueue(3);
  q.enqueue(q.dequeue());
  q.enqueue(5);
  q.dequeue();
  q.enqueue(q.L->inicio->chave + q.L->inicio->proximo->chave);
  q.enqueue(q.dequeue());
  q.dequeue();

  q.print();
}

void testHashmap(){
  Hashmap T(10);

  Item* it = new Item(33);
  std::cout << T.insert(it) << std::endl;
  std::cout << T.remove(it) << std::endl;

  std::cout << "Alan" << std::endl;

  if(T[3] != NULL){
    std::cout << T[3]->chave << std::endl;
  }

  T.print();
}

void testHashmapChained(){
  // HashmapChained T(7, [](int k){
  //     return (k*2)%7;
  // });
  HashmapChained T(7);

  int keys[] = {16,20,4,18,19,0,5,2,8,11};

  for (size_t i = 0; i < sizeof(keys)/sizeof(int); i++)
  {
    std::cout << T.insert(keys[i]) << " - " << keys[i] << std::endl;
  }

  // std::cout << T.remove(it) << std::endl;

  std::cout << "T[3]-----" << std::endl;
  if(T[3] != NULL){
    std::cout << T[3]->chave << std::endl;
  }
  std::cout << "Print-----" << std::endl;


  T.print();
}

void testHeap(){
  int list[] = {8, 7, 4, 6, 5, 3};
  Heap T(list, sizeof(list)/sizeof(int), 6);
  T.print();
  T.sort();
  // T.print();

}

void testPriorityList(){
  int list[] = {36,18,28,16,15,25,20};

  PriorityList T(list, sizeof(list)/sizeof(int), 13);

  T.print();
  T.extractTop();
  T.insert(26);
  T.extractTop();

  T.print();
}

