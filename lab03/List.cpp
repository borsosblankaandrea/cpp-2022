//
// Created by ASUS on 2022. 10. 05..
//

#include "List.h"
#include <iostream>
using namespace std;

List::List() {
    cout << "Konstruktor" << endl;
    this->first = nullptr;
}

List::~List() {
    //cout << "Destruktor" << endl;

//    Node *act = this->first;
//    while(act != nullptr){
//        Node *temp = act;
//        act = act->next;
//        delete temp;
//    }

    while( first != nullptr){
        Node *temp = first;
        first = first->next;
        delete temp;
    }

    this->nodeCounter = 0;

}

bool List::exists(int d) const {

    for(Node *ptr = this->first; ptr != nullptr; ptr = ptr->next) {
        if(ptr->value == d) return true;
    }
    return false;
}

int List::size() const {
    return this->nodeCounter;
}

bool List::empty() const {
    if(this->nodeCounter == 0) return true;
    return false;
}

void List::insertFirst(int d) {
//    Node *temp = new Node(d, first);
//    first = temp;

    this->first = new Node(d, first);
    this->nodeCounter++;
}

int List::removeFirst() {

        Node *temp = first->next;
        first = first->next;
        delete temp;

        this->nodeCounter--;

}

void List::print() const {
    cout << "[ ";
    for(Node *ptr = this->first; ptr != nullptr; ptr = ptr->next){
        cout << ptr->value << ' ';
    }
    cout << ']' << endl;
}




