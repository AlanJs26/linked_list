#include "../Item.h"
#include "../List.h"

#include <iostream>
using namespace std;

void merge(List& A, int inicio, int meio, int fim){
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;
    List E = List(n1+1);
    List D = List(n2+1);

    for (int i = 0; i < n1; i++) {
        E.set(i, A[inicio + i]);
    }

    for (int i = 0; i < n2; i++) {
        D.set(i, A[meio + i + 1]);
    }
    Item* d = new Item(-1);
    d->deleted = true;
    E.set(n1, d);

    d = new Item(-1);
    d->deleted = true;
    D.set(n2, d);

    cout << "Merge -----" << endl;
    E.print();
    D.print();

    int i = 0;
    int j = 0;
    for (int k = inicio; k <= fim; k++) {
        if ((E[i]->deleted == false && E[i]->chave <= D[j]->chave) || D[j]->deleted == true) {
            A.set(k, E[i]);
                i++;
        }else{
            A.set(k, D[j]);
            j++;
        }
    }
    A.print();
    cout << "==============" << endl;
    
    
}

void mergeSort(List& A, int inicio, int fim){
    // cout << inicio << " --- " << fim << endl;
    if(inicio < fim){
        int meio = (inicio+fim)/2;
        mergeSort(A, inicio, meio);
        mergeSort(A, meio+1, fim);
        merge(A, inicio, meio, fim);

    }
}