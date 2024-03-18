#include "Queue.h"
#include "Item.h"

bool Queue::empty(){
  return L->empty();
}
void Queue::enqueue(Item* x){
  L->insertEnd(x);
}
void Queue::enqueue(int k){
  Item* x = new Item(k);
  this->enqueue(x);
}
void Queue::print(){
  L->print();
}
Item* Queue::dequeue(){
  return L->remove(L->inicio);
}

