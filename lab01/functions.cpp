//
// Created by ASUS on 2022. 10. 01..
//
#include "functions.h"
#include <string>
#include <iostream>

int countBits(int number){
    int counter = 0;
    while( number != 0 ){
        if((number & 1) == 1){
            ++counter;
        }
        number = number >> 1;
    }
    return counter;
}

bool setBit(int& number, int order){

    if( order < 0 || order > 31 ){
        return false;
    }

    else {

        int mask = 1 << order;
        number = number | mask;

        return true;
    }

}

double mean(double array[], int numElements){

    if(numElements <= 0) return NAN;

    double sum=0;
    for(int i = 0; i < numElements; i++){
        sum = sum + array[i];
    }

    sum = sum / numElements;
    return sum;
}

//double stddev(double array[], int numElements){
///     szoras = variaciok szama ??
//}

/*pair<double, double> max2(double array[], int numElements){
    pair<double, double> numbers =
}*/

void max_elem (double array[], int numElements){
    //double m1 = NAN, m2 = NAN; //helyes igy??
    double m1 = array[0], m2 = array[1];
    for(int i=2; i < numElements; i++){
        if( array[i] > m1 || array[i] > m2){
            if( m1 > m2 ) m2 = array[i];
            else m1 = array[i];
        }
    }

    cout << "A ket legnagyobb szam:" << m1 << ' ' << m2;
}

//nem tudom mit jelent es hogy kell hasznalni a istringstream-t ezert nelkule oldottam meg
int countWords(string text){
    int counter=0;
    int n = text.length();

    for (int i=0; i<n; i++){
        if( text[i] == ' '){ // hogyha tobb feher karakter vagy szamok is vannak a szavak kozott:  && (( (text[i-1] >= 'a' && text[i-1] <= 'z') || (text[i-1] >= 'A' && text[i-1] <= 'Z') ) && ( (text[i+1] >= 'a' && text[i+1] <= 'z') || (text[i+1] >= 'A' && text[i+1] <= 'Z') ))
            counter++;
        }
    }

    counter++;

    return counter;

}

string code(string text){
    int n = text.length();

    for (int i=0; i<n; i++){
        if( (text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z') ){
            if(text[i] == 'z' or text[i] == 'Z'){
                text[i] = text[i] - 25;
            }

            else text[i] = text[i] + 1;
        }
    }

    return text;
}

string decode(string text){
    int n = text.length();

    for (int i=0; i<n; i++){
        if( (text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z') ){
            if(text[i] == 'a' or text[i] == 'A'){
                text[i] = text[i] + 25;
            }

            else text[i] = text[i] - 1;
        }
    }

    return text;
}

string capitalizeWords(string text){
    int n = text.length();

    if(text[0] >= 'a' && text[0] <= 'z'){
        text[0] = text[0]-32;
    }

    int i=1;
    while(text[i] != '\0'){
        while(text[i] != ' '){
            if(text[i] >= 'A' && text[i] <= 'Z'){
                text[i] = text[i] + 32;
            }
            i++;
        }
        i++;
        if(text[i] >= 'a' && text[i] <= 'z'){
            text[i] = text[i]-32;
        }
        i++;
    }

    return text;
}
