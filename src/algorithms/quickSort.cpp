#include "algorithms.h"

#include <iostream>
using namespace std;
int count = 0;


int partition(List& A, int inicio, int fim){
    Item* e_pivo = A[fim];
    int pmenor = inicio - 1;

    for(int pos = inicio; pos <= fim - 1; pos++){
        if(A[pos]->chave <= e_pivo->chave){
            pmenor++;
            A.swap(pos, pmenor);
        }
    }
    A.swap(fim, pmenor+1);

    return pmenor+1;
}

void quickSort(List& A, int inicio, int fim){
    if (inicio < fim){
        int pivo = partition(A, inicio, fim);
        count++;
        cout << count << "   pivo: " << pivo+1 << endl;
        A.print();
        quickSort(A, inicio, pivo -1);
        quickSort(A, pivo + 1, fim);
    }
}
