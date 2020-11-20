/*
c++ -o es2 esercizio02.cpp complesso.cc

Testo:
    Si testi la funzione somma sviluppata nell'esercizio precedente sulla classe dei numeri complessi 
    sviluppata durante la Lezione 3, aggiungendo anche una specializzazione per un tipo a piacere.

*/

#include "complesso.h"

template <typename T1, typename T2>
T1 somma_t (T1 a, T2 b){ //returning T2 -> valid for each object supporting + operator overloading
    return a + b ;
}

template<>
complesso somma_t(complesso a, double b){
    std::cout << "Specialization complex + double" << std::endl;
    return a + b;
}

int main(){

    complesso c(3,5); //3 + i*5
    complesso d(1.5,10.7); //1.5 + i*10.7
    int a_i = 5;
    double a_d = 1.4;

    auto s = somma_t(c, a_i);
    s.stampami();
    s = somma_t(c, d);
    s.stampami();
    s = somma_t(c, a_d);
    s.stampami();
    

    return 0;
}



