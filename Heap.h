#ifndef HEAP_h
#define HEAP_h

#include "Item.h"


class Heap {
  private:
    Item** list;
    int tamanho;
    int heapSize = 0;
    bool isMax = true;

    bool validIndex(int index);
    void heapify(int index);
    void upwardsHeapify(int index);
    void sortHeap();

  public:
    Heap(int tamanho);
    Heap(int tamanho, bool isMax);
    Heap(int arr[], int arrSize, int tamanho);
    Heap(int arr[], int arrSize, int tamanho, bool isMax);
    ~Heap();

    int filhoEsquerda(int index);
    int filhoDireita(int index);
    int pai(int index);

    Item* operator[](int index);
    
    void replace(int index, Item* x);
    void replace(int index, int k);
    int getSize();

    void insert(Item* x);
    void insert(int k);
    Item* remove(int index);
    // Item* search(int k);
    void print();
};

#endif