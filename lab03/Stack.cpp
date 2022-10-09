//
// Created by ASUS on 2022. 10. 05..
//

#include "Stack.h"

void Stack::push(int e) {
    last->next = new Node(e, nullptr);
    last = last->next;
    this->nodeCounter++;
}

int Stack::pop() {
//    if(this->isEmpty()){
//        throw invalid_argument("Empty!");
//    }

    ///utolso visszaillitasa az elotte levore ???

    int value = last->value;
    delete last;
    this->nodeCounter--;

    return value;
}

bool Stack::isEmpty() const {
    if (this->nodeCounter == 0) return true;
    return false;
}
