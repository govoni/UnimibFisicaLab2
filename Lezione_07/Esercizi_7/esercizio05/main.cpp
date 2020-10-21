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

    auto v2 = v * 2;
    std::cout << "Elements:" << std::endl;
    for(int i = 0; i < 10; ++i){
        std::cout << v2.at(i) << " ";
    }
    std::cout << std::endl;

    std::cout << "Norm: " << v2.norm() << std::endl;

    auto v3 = v2 + v;
    std::cout << "Elements:" << std::endl;
    for(int i = 0; i < 10; ++i){
        std::cout << v3.at(i) << " ";
    }
    std::cout << std::endl;

    std::cout << "Norm: " << v3.norm() << std::endl;


    return 0;
}