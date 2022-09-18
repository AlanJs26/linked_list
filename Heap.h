#ifndef HEAP_h
#define HEAP_h

#include "Linkedlist.h"
#include "Item.h"


class Heap {
  private:
    Item** list;
    int tamanho;
    int heapSize = 0;
    bool isMax = true;
    bool validIndex(int index);
    void heapify(int index);

    void initialize(int tamanho);
    void initializeFromArray(int arr[], int arrSize, int tamanho);

  public:
    Heap(int tamanho);
    Heap(int tamanho, bool isMax);
    Heap(int arr[], int arrSize, int tamanho);
    Heap(int arr[], int arrSize, int tamanho, bool isMax);
    ~Heap();

    int filhoEsquerda(int index);
    int filhoDireita(int index);
    int pai(int index);

    void sortHeap();
    // Item* operator[](int index);
    void insert(Item* x);
    void insert(int k);
    // int remove(Item* x);
    // Item* search(int k);
    void print();
};

#endif