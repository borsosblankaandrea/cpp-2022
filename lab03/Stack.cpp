//
// Created by ASUS on 2022. 10. 05..
//

#include "Stack.h"


Stack::Stack(int capacity) {
    this->capacity = capacity;
    elements = new int(capacity);
    top = elements;
}

void Stack::push(int e) {
    //if not full
    *top = e;
    top++;
}

int Stack::pop() {
    if(isEmpty()) {return -1;}
    int temp = *top;
    top = nullptr;
    top--;
    return temp;
    //helyes igy?
}

bool Stack::isEmpty() const {
    if (top == nullptr) return true; // ??
    else return false;
}



