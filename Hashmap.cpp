#include "Hashmap.h"
#include <iostream>
using namespace std;

int Hashmap::hash(int k){
    if(this->customHash != NULL){
        return customHash(k);
    }
    return k % this->size; 
}

Hashmap::Hashmap(int size) : size(size){
    list = new Item*[size];

    for (int i = 0; i < this->size; i++)
    {
        list[i] = NULL;
    }
}
Hashmap::Hashmap(int size, int(*h)(int)) : size(size){
    list = new Item*[size];

    for (int i = 0; i < this->size; i++)
    {
        list[i] = NULL;
    }
    customHash = h;
}

Hashmap::~Hashmap(){
    for (int i = 0; i < this->size; i++){
        if (list[i] != NULL)
        {
            delete list[i];
        }
    }
    delete[] list;
}

Item* Hashmap::operator[](int index){
    return this->search(index);
}

int Hashmap::insert(Item* x){
    int j = hash(x->chave);

    do{
        if(list[j] == NULL || list[j]->deleted){
            list[j] = x;
            return j;
        }else{
            j++;
            if(j == size){
                j = 0;
            }
        }
    }while(j != hash(x->chave));

    return -1;
}
int Hashmap::insert(int k){
    Item* x = new Item(k);
    this->insert(x);
    return k;
}

Item* Hashmap::search(int k){
    int j = hash(k);

    if(list[j] == NULL){
        return NULL;
    }

    do{
        if(list[j]->chave == k){
            return list[j];
        }else{
            j++;
            if(j == size){
                j = 0;
            }
        }
    }while(j != hash(k) && list[j] != NULL);
    return NULL;
}


int Hashmap::remove(Item* x){
    int j = hash(x->chave);

    if(list[j] == NULL){
        return -1;
    }

    do{
        if (list[j] == x) {
            list[j]->~Item();
            return j;
        }else{
            j++;
            if(j == size){
                j = 0;
            }
        }
        
    }while(j != hash(x->chave) && list[j] != NULL);
    return -1;
}



void Hashmap::print(){
    for(int i = 0; i < this->size; i++){
    if(list[i] == NULL){
        cout << i << " -> -" << endl;
    }else if(list[i]->deleted){
        cout << i << " -> DELETED" << endl;
    }else{
        cout << i << " -> " << list[i]->chave << endl;
    }
    }
}
