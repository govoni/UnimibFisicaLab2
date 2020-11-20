/*
c++ -o es8 esercizio08.cpp esercizio02/complesso.cc

Testo:
    Si crei un std::vector vuoto e lo si riempia con cinque oggetti del tipo della classe 
    complesso sviluppato durante la Lezione 3.

    Tramiti opportuni messaggi a schermo, si verifichi quando vengono chiamati costruttore, 
    copy constructor, operatore di assegnazione e distruttore della classe complesso
*/

#include "esercizio02/complesso.h"
#include <vector>
#include <memory>

int main(){
    std::vector<complesso> v;

    for(int i = 0; i < 5; ++i){
        complesso a(i,i);
        v.push_back(a);
    }
    for(int i = 0; i < 5; ++i) v[i].stampami();

    std::cout << "-------------" << std::endl;

    std::vector<complesso*> v_;

    for(int i = 0; i < 5; ++i) v_.push_back(new complesso(i,i));
    for(int i = 0; i < 5; ++i) v_[i]->stampami();

    //clean memory
    for(int i = 0; i < 5; ++i) delete v_[i];

    std::cout << "--- Destructors at the end -----" << std::endl;

    return 0;
}