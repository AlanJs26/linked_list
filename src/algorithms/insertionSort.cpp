#include "algorithms.h"

void insertionSort(List& V){
    int chave;
    int i;
    for (int j = 1; j < V.tamanho-1; j++) {
        chave = V[j]->chave;
        i = j - 1;

        while (i >= 0 && V[i]->chave > chave) {
            V.set(i + 1,V[i]->chave);
            i = i -1;
        }
        V.set(i + 1, chave);
    }
    
}
