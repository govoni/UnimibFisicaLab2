/*
c++ -o es5 main.cpp

Testo:
    Si implementi la classe templata vettore definita nella lezione.

    Si ricordi di controllare che gli indici passati ai metodi della classe siano entro i 
    limiti della memoria occupata dagli oggetti di tipo vettore
    Si aggiungano gli operatori algebrici necessari per la definizione di uno spazio vettoriale
*/

#include <iostream>
#include "vettore.h"

int main(){

    vettore<10> v;
    for(int i = 0;  i < 10; ++i){
        v.setCoord(i,i);
    }

    std::cout << "Elements:" << std::endl;
    for(int i = 0; i < 10; ++i){
        std::cout << v.at(i) << " ";
    }
    std::cout << std::endl;

    std::cout << "Norm: " << v.norm() << std::endl;

    vettore<10> v2 = v * 2;
    std::cout << "Elements:" << std::endl;
    for(int i = 0; i < 10; ++i){
        std::cout << v2.at(i) << " ";
    }
    std::cout << std::endl;

    std::cout << "Norm: " << v2.norm() << std::endl;

    vettore<10> v3 = v2 + v;
    std::cout << "Elements:" << std::endl;
    for(int i = 0; i < 10; ++i){
        std::cout << v3.at(i) << " ";
    }
    std::cout << std::endl;

    std::cout << "Norm: " << v3.norm() << std::endl;


    return 0;
}