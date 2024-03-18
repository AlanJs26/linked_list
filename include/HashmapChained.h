#ifndef HASHMAPCHAINED_h
#define HASHMAPCHAINED_h

#include "Linkedlist.h"
#include "Item.h"


class HashmapChained {
  private:
    LinkedList** list;
    int size;

    int (*customHash)(int) = NULL;
    int hash(int k);
  public:
    HashmapChained(int size);
    HashmapChained(int size, int(*h)(int));
    ~HashmapChained();
    Item* operator[](int index);
    int insert(Item* x);
    int insert(int k);
    int remove(Item* x);
    Item* search(int k);
    void print();
};

#endif