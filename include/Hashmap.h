#ifndef HASHMAP_h
#define HASHMAP_h

#include "Item.h"

class Hashmap {
  private:
    Item** list;
    int size;

    int (*customHash)(int) = NULL;
    int hash(int k);
  public:
    Hashmap(int size);
    Hashmap(int size, int(*h)(int));
    ~Hashmap();
    Item* operator[](int index);
    int insert(Item* x);
    int insert(int k);
    int remove(Item* x);
    Item* search(int k);
    void print();
};

#endif