#include "Item.h"

Item::Item(int chave) { this->chave = chave; }

Item::~Item() {
    this->chave = 0;
    this->deleted = true;
    this->proximo = NULL;
}