//
// Created by ASUS on 2022. 11. 23..
//

#ifndef CPP_2022_ORDEREDLIST_H
#define CPP_2022_ORDEREDLIST_H

#include <functional>
#include <iostream>
using namespace std;
// Class declaration
template< class T, class LessComp=less<T>, class Equal=equal_to<T> >
class Iterator;
// Class definition
template <class T, class LessComp = less<T>, class Equal = equal_to<T> >
class OrderedList{
private:
    struct Node{
        T value;
        Node* next;

        Node(T value, Node *next = nullptr) : value(value), next(next){}
    };
    Node* first{nullptr};
    int numElements{0};
public:
    ~OrderedList();

    void listElements(ostream &os=cout);
    void insert(const T &what);
    void remove(T &what);
    int size();
    bool isEmpty();
    bool find(T& what);
    friend class Iterator<T, LessComp, Equal>;

};

// Class definition
template< class T, class LessComp, class Equal >
class Iterator{
    OrderedList<T, LessComp, Equal>& list;
    typename OrderedList<T, LessComp, Equal>::Node* act;
public:
    Iterator(OrderedList<T, LessComp, Equal> &list) : list(list), act(list.first) {}
    bool hasNext();
    T next();
};

template<class T, class LessComp, class Equal>
bool Iterator<T, LessComp, Equal>::hasNext() {
    if( act == nullptr) return false;
    return true;
}

template<class T, class LessComp, class Equal>
T Iterator<T, LessComp, Equal>::next() {
    T aux = act->value;
    act = act->next;
    return aux;
}


template<class T, class LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::listElements(ostream &os) {
    Node *aux = first;
    while(aux != nullptr){
        os << aux->value << " ";
        aux = aux->next;
    }
    os << endl;
}

template<class T, class LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::insert(const T &what) {
    Node *newNode = new Node(what);
    Node *act = first;
    Node *prev = nullptr;

    while (act != nullptr && LessComp()(act->value, what)){
        prev = act;
        act = act->next;
    }

    //ha ures lista vagy az elejere kell tenni
    if( prev == nullptr){
        newNode->next = first;
        first = newNode;
        ++ numElements;
        return;
    }

    //insert - altalanos eset
    prev->next = newNode;
    newNode->next = act;
    ++numElements;

}

template<class T, class LessComp, class Equal>
OrderedList<T, LessComp, Equal>::~OrderedList() {
    while(first != nullptr){
        Node *aux = first;
        first = first->next;
        delete aux;
    }
    //cout << "Destruktor" << endl;
}

template<class T, class LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::remove(T &what) {
    Node *act = first;
    Node *prev = nullptr;

    while (act != nullptr && act->value != what){
        prev = act;
        act = act->next;
    }

    if( prev == nullptr && numElements!= 0){
        first = first->next;
        return;
    }
    prev->next = act->next;
    delete act;
}

template<class T, class LessComp, class Equal>
int OrderedList<T, LessComp, Equal>::size() {
    return numElements;
}

template<class T, class LessComp, class Equal>
bool OrderedList<T, LessComp, Equal>::isEmpty() {
    if (numElements == 0) return true;
    else return false;
}

template<class T, class LessComp, class Equal>
bool OrderedList<T, LessComp, Equal>::find(T &what) {
    Node *act = first;

    while (act != nullptr){
        if(Equal()(act->value, what)){
            return true;
        }
        act = act->next;
    }
    if( act == nullptr ){
        return false;
    }

}


#endif //CPP_2022_ORDEREDLIST_H
