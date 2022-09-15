#ifndef ITEM_h
#define ITEM_h

#include <iostream>

class Item {
  public:
    Item(int chave);
    ~Item();
    Item *proximo = NULL;
    bool deleted = false;
    int chave;
};

#endif