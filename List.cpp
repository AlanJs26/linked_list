#include "List.h"
#include <iostream>
using namespace std;

List::List(int tamanho){
    list = new Item*[tamanho];

    this->tamanho = tamanho;

    for (int i = 0; i < tamanho; i++) {
        list[i] = NULL;
    }

    randomItems();
}
List::List(int arr[], int tamanho){
    list = new Item*[tamanho];

    this->tamanho = tamanho;

    for (int i = 0; i < tamanho; i++) {
        list[i] = new Item(arr[i]);
    }
}

List::~List(){
    // for (int i = 0; i < tamanho; i++)
    // {
        // if(list[i] != NULL)
            // delete list[i];
    // }
    delete[] list;
}

int List::random(){
    return rand() % tamanho+1;
}

void List::swap(int aIndex, int bIndex){
    Item* temp = list[aIndex];
    list[aIndex] = list[bIndex];
    list[bIndex] = temp;
}

void List::set(int index, Item* x){
    // if(list[index] != NULL)
        // delete list[index];

    list[index] = x;
}

void List::set(int index, int k){
    set(index, new Item(k));
}

void List::print(){
    for (int i = 0; i < tamanho; i++)
    {
        if (list[i] != NULL) {
            cout << list[i]->chave << " ";
        }
    }
    cout << endl;
    
}

void List::randomItems(){
    for (int i = 0; i < tamanho; i++)
    {
        if (list[i] != NULL) {
            list[i]->chave = random();
            // delete list[i];
        }else{
            list[i] = new Item(random());
        }
    }
}

void List::orderedItems(){
    for (int i = 0; i < tamanho; i++)
    {
        if (list[i] != NULL) {
            list[i]->chave = i+1;
            // delete list[i];
        }else{
            list[i] = new Item(i+1);
        }
    }
}


Item* List::operator[](int index){
    if(index >= 0 && index < tamanho){
        return list[index];
    }
    return NULL;
}