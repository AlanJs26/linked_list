#include "algorithms.h"

void selectionSort(List& V){
    int menor;
    for (int i = 0; i < V.tamanho-2; i++) {
        menor = i;
        for (int j = i+1; j < V.tamanho; j++) {
            if (V[j]->chave < V[menor]->chave) {
                menor = j;
            }
        }
        V.swap(menor, i); 
    }
}
