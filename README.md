# Estruturas de Dados e Algoritmos em C++

Aqui foram implementadas as seguintes estruturas de dados:

## Estruturas de Dados

- **Lista Ligada** (linked list)
- **Fila** (queue)
- **Tabela Hash** (hashmap) usando **sondagem linear** (linear probing) no caso de conflito
- **Tabela Hash** (hashmap) usando **encadeamento** no caso de conflito
- **Heap** (Max e Min)
- **Lista de Prioridade**

## Algoritmos

- **busca linear**
- **busca binária**
- **ordenação por seleção** (selection sort)
- **ordenação por inserção** (insertion sort)
- **ordenação por mescla** (merge sort)

## Testar

para testar tenha certeza que você tem instalado o `make`, `g++`, `cmake` e `ninja`. Com isso, basta executar os seguintes comandos:

```bash
mkdir build
cd build
cmake -G Ninja ..
ninja
./main
```

isso vai compilar todos os arquivos `.cpp` e executar o programa de teste.
