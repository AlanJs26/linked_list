#include "algorithms.h"

int linearSearch(List &V, int k){
    for (int i = 0; i < V.tamanho; i++) {
        if (V[i]->chave == k) {
            return i;
        }
    }

    return -1;
}
