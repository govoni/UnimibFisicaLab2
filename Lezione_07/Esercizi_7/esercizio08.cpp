//c++ -o es8 esercizio08.cpp
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

    std::vector<std::unique_ptr<complesso>> v_; //unique pointers are pointers that clear memory when they go out of scope
                                                //(among other things)

    for(int i = 0; i < 5; ++i) v_.push_back(std::unique_ptr<complesso>(new complesso(i,i)));
    for(int i = 0; i < 5; ++i) v_[i]->stampami();

    std::cout << "--- Destructors at the end -----" << std::endl;

    return 0;
}