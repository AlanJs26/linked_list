#ifndef PRIORITYLIST_h
#define PRIORITYLIST_h

#include "Heap.h"


class PriorityList : protected Heap {
  public:
    PriorityList(int tamanho) : Heap(tamanho){};
    PriorityList(int arr[], int arrSize, int tamanho) : Heap(arr,arrSize, tamanho){};
    // ~PriorityList();
    using Heap::operator[];
    using Heap::replace;
    using Heap::getSize;
    using Heap::insert;
    using Heap::print;

    Item* extractTop();
    Item* showTop();
};

#endif