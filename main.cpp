#include "Linkedlist.h"
#include "Queue.h"
#include "Hashmap.h"
#include "HashmapChained.h"
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
  
  for (int i = 0; i < sizeof(keys)/sizeof(int); i++)
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

int main ()
{
  // testLinkedlist();
  // testQueue();
  // testHashmap();
  testHashmapChained();


  return 0;
}
