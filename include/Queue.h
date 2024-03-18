#ifndef QUEUE_h
#define QUEUE_h 

#include "Linkedlist.h"
#include <iostream>

class Queue
{
public:
  LinkedList* L = new LinkedList;
  bool empty();
  void enqueue(Item* x);
  void enqueue(int k);
  void print();
  Item* dequeue();
};

#endif 
