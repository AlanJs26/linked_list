#include "algorithms.h"

int binarySearch(List& V, int k){
    int esquerda = 0;
    int direita = V.tamanho-1;
    int meio = 0;

    while (esquerda <= direita) {
        meio = (esquerda+direita)/2;

        if (V[meio]->chave == k) {
            return meio;
        }else if(V[meio]->chave < k){
            esquerda = meio+1;
        }else{
            direita = meio-1;
        }
    }
    
    return -1;
}
