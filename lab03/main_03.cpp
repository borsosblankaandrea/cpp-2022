#include <iostream>
#include "List.h"
using namespace std;

int main() {
    List list1;
    for (int i = 0; i < 10; ++i) {
        list1.insertFirst(i);
    }

    list1.print();

    int x;
    cout << "Enter a number:";
    cin >> x;
    if(list1.exists(x)) cout << "Exists!" << endl;
    else cout << "Does not exist!" << endl;

    cout << "Size: " << list1.size() << endl;

    if(list1.empty()) cout << "List is empty!" << endl;
    else cout << "List is not empty!" << endl;

    cout << endl << "Insert first:" << endl;
    cout << "Enter a number:";
    cin >> x;
    list1.insertFirst(x);
    list1.print();
    cout << "Size: " << list1.size() << endl;

    cout << endl << "Remove first: " << endl;
    try{
        list1.removeFirst();
    } catch (invalid_argument &error){
        cout << error.what();
    }
    list1.print();

    return 0;
}
