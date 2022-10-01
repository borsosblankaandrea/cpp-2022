#include "functions.h"
#include <iostream>

using namespace std;

void test_function1();
void test_function2();
void test_function3();

int main(){

    test_function1();
    test_function2();
    test_function3();
    return 0;
}

void test_function1(){
    for(int i=0; i<128; ++i){
        cout << i << ":" <<countBits(i) << endl;
    }
}

void test_function2(){

    for (int i = 0; i < 35; ++i) {
        int n = 0;
        if(setBit(n, i)){
            cout<<i<<" ---> " << n <<endl;
        }else{
            cout<<"Impossible operation!" << endl;
        }
    }

}

void test_function3(){
    int numElements;
    cout << "Enter number of elements: ";
    cin >> numElements;

    double array[numElements];

    cout << endl << "Read array: ";
    for(int i=0; i<numElements; i++){
        cin >> array[i];
    }

    cout << "Average: " << mean(array,numElements);

}

/*void test_function2_1(){
    istringstream iss("1 2 3 alma 4");
    double number;
    while(iss >> number){
        cout<<number<<endl;
    }
    return 0;
}*/