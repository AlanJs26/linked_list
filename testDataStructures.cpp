#include "Linkedlist.h"
#include "Queue.h"
#include "Hashmap.h"
#include "HashmapChained.h"
#include "Heap.h"
#include "PriorityList.h"

using namespace std;


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
  cout << T.insert(it) << endl;
  cout << T.remove(it) << endl;

  cout << "Alan" << endl;

  if(T[3] != NULL){
    cout << T[3]->chave << endl;
  }

  T.print();
}

// int myhash(int k){
//   return (k*2)%7;
// }

void testHashmapChained(){
  // HashmapChained T(7, &myhash);
  HashmapChained T(7);

  int keys[] = {16,20,4,18,19,0,5,2,8,11};
  
  for (size_t i = 0; i < sizeof(keys)/sizeof(int); i++)
  {
    cout << T.insert(keys[i]) << " - " << keys[i] << endl;
  }
  
  // cout << T.remove(it) << endl;

  cout << "T[3]-----" << endl;
  if(T[3] != NULL){
    cout << T[3]->chave << endl;
  }
  cout << "Print-----" << endl;


  T.print();
}

void testHeap(){
  int list[] = {4,1,3,2,16,9,10,14,8,7};
  Heap T(list, sizeof(list)/sizeof(int), 10);
  T.print();

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


void testAllDataStructures(){
  testLinkedlist();
  testQueue();
  testHashmap();
  testHashmapChained();
  testHeap();
  testPriorityList();
}