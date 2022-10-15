//
// Created by ASUS on 2022. 10. 05..
//

#ifndef CPP_2022_STACK_H
#define CPP_2022_STACK_H

#include "List.h"

class Stack : public List{
public:
    Stack (int capacity);
    void push(int e);
    int pop();
    bool isEmpty() const;

private:
    int capacity;
    int *elements;
    int *top;

};

#endif //CPP_2022_STACK_H
