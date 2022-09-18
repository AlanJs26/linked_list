#include "Heap.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void Heap::initialize(int tamanho){
    list = (Item**) malloc(tamanho * sizeof(Item*));
    this->tamanho = tamanho;
    for (int i = 0; i < this->tamanho; i++)
    {
        list[i] = NULL;
    }
}

void Heap::initializeFromArray(int arr[], int arrSize, int tamanho){
    list = (Item**) malloc(tamanho * sizeof(Item*));
    this->tamanho = tamanho;
    this->heapSize = arrSize;

    Item* x;
    for (int i = 0; i < tamanho; i++) {
        if(i < arrSize){
            x = new Item(arr[i]);
            list[i] = x;
        }else{
            list[i] = NULL;
        }
    }
}

Heap::Heap(int tamanho){
    this->initialize(tamanho);
}
Heap::Heap(int tamanho, bool isMax){
    this->initialize(tamanho);
    this->isMax = isMax;
}
Heap::Heap(int arr[], int arrSize, int tamanho){
    this->initializeFromArray(arr, arrSize, tamanho);
}
Heap::Heap(int arr[], int arrSize, int tamanho, bool isMax){
    this->initializeFromArray(arr, arrSize, tamanho);
    this->isMax = isMax;
}


Heap::~Heap(){
    for (int i = 0; i < this->tamanho; i++){
        if (list[i] != NULL)
        {
            delete list[i];
        }
    }
    free(list);
}


int Heap::filhoEsquerda(int index){
    return 2*(index+1)-1;
};
int Heap::filhoDireita(int index){
    return 2*(index+1);
};
int Heap::pai(int index){
    return index/2;
};

bool Heap::validIndex(int index){
    return index >= 0 && index < tamanho && list[index] != NULL;
}

void Heap::heapify(int index){
    int esquerda = filhoEsquerda(index);
    int direita = filhoDireita(index);

    int maior = index;
    if(esquerda <= heapSize &&
      (validIndex(esquerda) && validIndex(index) &&
      (isMax && list[esquerda]->chave > list[index]->chave ||
      !isMax && list[esquerda]->chave < list[index]->chave)
      )
      ){
        maior = esquerda;
    }
    if(direita <= heapSize &&
      (validIndex(direita) && validIndex(maior) &&
      (isMax && list[direita]->chave > list[maior]->chave ||
      !isMax && list[direita]->chave < list[maior]->chave))
      ){
        maior = direita;
    }

    if(maior != index){
        Item* temp = list[index];
        list[index] = list[maior];
        list[maior] = temp;
        this->heapify(maior);
    }
}

void Heap::sortHeap(){
    for (int i = pai(heapSize); i >= 0; i--)
    {
        heapify(i);
    }
}

void Heap::insert(Item* x){
    if(heapSize < tamanho){
        list[heapSize] = x;
        heapSize++;
    }
}

void Heap::insert(int k){
    Item* x = new Item(k);
    this->insert(x);
}

void repeatPrint(char c, int n){
    for (int i = 0; i < n; i++) {
        cout << c;
    }
}

string centered(int width, int value) {
    string str = to_string(value);
    int len = str.length();
    if(width < len) { return str; }

    int diff = width - len;
    int pad1 = diff/2;
    int pad2 = diff - pad1;
    return string(pad1, ' ') + str + string(pad2, ' ');
}


void Heap::print(){

    // cout << previousPai << endl;

    for (int j = 0; j < heapSize; j++)
    {
        cout << list[j]->chave << " ";
    } 
    cout << endl;

    int originalTw = 6;
    int tw = originalTw;
    int count = tw;

    int offset = heapSize*tw/4;
    repeatPrint(' ', offset-tw/2);

    int i = 2;
    for (int j = 0; j < heapSize; j++)
    {
        cout << centered(tw, list[j]->chave);
        count += tw;
        if(i-1 <= j+1){
            cout << endl << endl;
            tw--;
            offset-=count/(originalTw-tw+1);
            repeatPrint(' ', offset+(originalTw-tw));
            count = 0;

            i = i*2;
        }
    } 
    cout << endl;
    
}