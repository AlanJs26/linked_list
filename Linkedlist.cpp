#include "Linkedlist.h"
#include "Item.h"
using namespace std;

LinkedList::LinkedList(){}
LinkedList::LinkedList(int arr[], int arrSize){
  this->insert(arr,arrSize);
}


void LinkedList::insert(Item *x) {
  x->proximo = this->inicio;
  this->inicio = x;
}
void LinkedList::insert(int k){
  Item *x = new Item(k);
  insert(x);
}
void LinkedList::insert(int arr[], int arrSize){
  for (int i = 0; i < arrSize; i++) {
    this->insertEnd(arr[i]);
  }
}

void LinkedList::insertEnd(Item *x) {
  if (this->empty()) {
    this->inicio = x;
    return;
  }
  Item *xEnd = this->inicio;
  while (xEnd->proximo != NULL) {
    xEnd = xEnd->proximo;
  }
  xEnd->proximo = x;
}
void LinkedList::insertEnd(int k){
  Item *x = new Item(k);
  insertEnd(x);
}

Item *LinkedList::remove(Item *x) {
  if (x == this->inicio) {
    this->inicio = x->proximo;
  } else {
    Item *buscador = this->inicio;
    while (buscador->proximo != x) {
      buscador = buscador->proximo;
    }
    buscador->proximo = x->proximo;
  }
  x->proximo = NULL;
  return x;
}
Item *LinkedList::remove(int k){
  Item *x = new Item(k);
  return remove(x);
}

bool LinkedList::empty() { return this->inicio == NULL; }

Item *LinkedList::search(int key) {
  Item *x = this->inicio;
  while (x != NULL && x->chave != key) {
    x = x->proximo;
  }
  return x;
}

void LinkedList::print() {
  Item *xEnd = this->inicio;
  cout << "L -> ";
  while (xEnd != NULL) {
    cout << xEnd->chave << " -> ";
    xEnd = xEnd->proximo;
  }
  cout << "/" << endl;
}
