//
// Created by ASUS on 2022. 10. 05..
//

#ifndef CPP_2022_STACK_H
#define CPP_2022_STACK_H

#include "List.h"

class Stack : public List{
public:
    void push(int e);
    int pop();
    bool isEmpty() const;

private:
    int nodeCounter{0};
    struct Node {
        int value;
        Node* next;

        Node(int v, Node* n) : value(v), next(n) {
        }
    };
    Node* last;

};

#endif //CPP_2022_STACK_H
