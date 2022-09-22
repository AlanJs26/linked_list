#include "PriorityList.h"
#include <iostream>
using namespace std;

Item* PriorityList::extractTop(){
    return remove(0);
}

Item* PriorityList::showTop(){
    return (*this)[0];
}