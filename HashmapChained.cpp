#include "HashmapChained.h"
#include <iostream>
using namespace std;

int HashmapChained::hash(int k){
    if(this->customHash != NULL){
        return customHash(k);
    }
    return k % this->size;
}

HashmapChained::HashmapChained(int size){
    list = (LinkedList**) malloc(size * sizeof(LinkedList*));
    this->size = size;
    for (int i = 0; i < this->size; i++)
    {
        list[i] = NULL;
    }
}
HashmapChained::HashmapChained(int size, int(*h)(int)){
    list = (LinkedList**) malloc(size * sizeof(LinkedList*));
    this->size = size;
    for (int i = 0; i < this->size; i++)
    {
        list[i] = NULL;
    }
    customHash = h;
}

HashmapChained::~HashmapChained(){
    for (int i = 0; i < this->size; i++){
        if (list[i] != NULL)
        {
            delete list[i];
        }
    }
    free(list);
}

Item* HashmapChained::operator[](int index){
    return this->search(index);
}

int HashmapChained::insert(Item* x){
    int j = hash(x->chave);

    if(list[j] == NULL){
        list[j] = new LinkedList();
    }

    list[j]->insert(x);
    return j;
}
int HashmapChained::insert(int k){
    Item* x = new Item(k);
    this->insert(x);
    return k;
}

Item* HashmapChained::search(int k){
    int j = hash(k);

    if(list[j] == NULL || list[j]->empty()){
        return NULL;
    }

    Item* x = list[j]->inicio;

    while(x->proximo != NULL){
        if(x->chave == k){
            return x;
        }
        x = x->proximo;
    };
    return NULL;
}


int HashmapChained::remove(Item* x){
    int j = hash(x->chave);

    if(list[j] == NULL || list[j]->empty()){
        return -1;
    }

    if(list[j]->remove(x) == NULL){
        return -1;
    };
    
    return j;
}



void HashmapChained::print(){
    for(int i = 0; i < this->size; i++){
    if(list[i] == NULL){
        cout << i << " -> -" << endl;
    }else if(list[i]->empty()){
        cout << i << " -> DELETED" << endl;
    }else{
        Item* x = list[i]->inicio;
        cout << i;
        while(x != NULL){
            cout << " -> ";
            cout << x->chave;
            x = x->proximo;
        }
        cout << endl;
    }
    }
}