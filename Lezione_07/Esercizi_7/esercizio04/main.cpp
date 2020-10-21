//c++ -o es4 main.cpp
#include <iostream> 
#include "DynamicArray.h"

int main(){

    DynamicArray<int> arr;
    for(int i = 0; i < 10; ++i) arr.push_back(i);

    for(auto& val : arr){ //this syntax is named "range based for loop".
        std::cout << val << " ";
    }
    std::cout  <<  std::endl;

    //clearing
    arr.clear();
    for(int i = 10; i < 20; ++i) arr.push_back(i);

    for(auto& val : arr){ //this syntax is named "range based for loop".
        std::cout << val << " ";
    }
    std::cout  <<  std::endl;



    return 0;
}