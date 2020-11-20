/*
c++ -o es7 esercizio07.cpp

Testo:
    Si crei un std::vector vuoto e, tramite un ciclo for, lo si riempia con i primi 10 numeri 
    della successione di Fibonacci.

    E' conveniente, dal punto di vista dell'esecuzione di questo esercizio, utilizzare una funzione esterna 
    al ciclo per il calcolo dei numeri di Fibonacci?
    Si stampi a schermo il suo contenuto utilizzando un ciclo su un numero intero, oppure utilizzando un iteratore.
*/

#include <iostream>
#include <vector>

void fibonacci(std::vector<int> & v){
    
    if(v.size() >= 2) v.push_back( v.end()[-2] + v.end()[-1] ) ;
    else{
        std::cout << "Fill the vector with the first two Fibonacci numbers" << std::endl;
    }
    return;

}

int main(){

    std::vector<int> v;
    int F_0 = 0; 
    int F_1 = 1;

    //Inline fill
    for(int i = 0; i < 5; ++i){
        v.push_back(F_0);
        v.push_back(F_1);
        F_0 = F_0 + F_1;
        F_1 = F_0 + F_1;
    }

    for (std::vector<int>::iterator it = v.begin() ; it != v.end(); ++it)
        std::cout << *it << ' ';
    std::cout << '\n';

    //External function fill
    v.clear();
    v.push_back(0); v.push_back(1);
    for(int i = 0; i < 8; ++i){
        fibonacci(v);
    }

    for(int i = 0; i < v.size(); ++i) std::cout << v.at(i) << ' ';
    std::cout << '\n';

    return 0;
}