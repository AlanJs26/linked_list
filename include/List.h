#ifndef LIST_h
#define LIST_h

#include "Item.h"

class List {
private:
    Item** list;
    int random();
    
public:
    int tamanho;

    List(int tamanho);
    List(int arr[], int tamanho);
    ~List();
    Item* operator[](int index);

    void randomItems();
    void orderedItems();
    void print();
    void swap(int aIndex, int bIndex);
    void set(int index, Item* x);
    void set(int index, int k);
};


#endif // !LIST_h