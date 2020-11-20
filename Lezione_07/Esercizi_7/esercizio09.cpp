/*
c++ -o es9 esercizio09.cpp esercizio02/complesso.cc

Testo:
    Si crei una std::map vuota e la si riempia con una sequenza di numeri complessi, 
    utilizzando la norma dei numeri stessi come chiave di ordinamento della mappa.

    Si stampino quindi a schermo i numeri, ordinati per norma.
*/

#include <iostream>
#include <map>
#include "esercizio02/complesso.h"

static const int seed = 1234567; 

template <typename T>
double rand_range(T min, T max){
    return min + (max - min) * rand () / static_cast<float> (RAND_MAX) ;
}

int main(){

    srand(seed);
    std::map<double, complesso> c_m;
    std::cout << "Filling..." << std::endl;
    for(int i = 0; i < 10; ++i){
        complesso num(rand_range(-10., 10.), rand_range(-10., 10.));
        std::cout << num.modulo() << " ";
        c_m[num.modulo()] = num;
    }
    std::cout << '\n';

    std::cout << "Print sorted based on this->first" << std::endl;
    for(std::map<double, complesso>::iterator it = c_m.begin() ; it != c_m.end(); ++it){
        std::cout << "Norm: " << it->first  << " Number: "; 
        it->second.stampami();
    }

    return 0;
}