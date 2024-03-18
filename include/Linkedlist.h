#ifndef LINKEDLIST_h
#define LINKEDLIST_h

#include <iostream>
#include "Item.h"

class LinkedList {
  public:
    LinkedList();
    LinkedList(int arr[], int arrSize);
    Item *inicio = NULL;

    void insert(Item *x);
    void insert(int k);
    void insert(int arr[], int arrSize);

    void insertEnd(Item *x);
    void insertEnd(int k);

    Item *remove(Item *x);
    Item *remove(int k);

    bool empty();

    Item *search(int key);

    void print();
};

#endif
