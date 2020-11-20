/*
c++ -o es4 main.cpp

Testo:
    Si implementi una classe templata dal nome DynamicArray che inizialmente non 
    contenga alcun elemento ed abbia un metodo push_back () che permetta di aggiungere un 
    elemento in fondo all'array degli elementi già esistenti.

    Si progetti un meccanismo che rimpiazzi l'array che contiene gli elementi quando è pieno, s
    ostituendolo con uno più capiente.
    Si aggiunga un metodo che permetta anche di svuotare l'oggetto di tipo DynamicArray.
*/

#include <iostream> 
#include "DynamicArray.h"

int main(){

    DynamicArray<int> arr;
    for(int i = 0; i < 10; ++i) arr.push_back(i);

    for(int i = 0; i < 10; ++i){ //this syntax is named "range based for loop".
        std::cout << arr[i] << " ";
    }
    std::cout  <<  std::endl;

    //clearing
    arr.clear();
    for(int i = 10; i < 20; ++i) arr.push_back(i);

    for(int i = 0; i < 10; ++i){ //this syntax is named "range based for loop".
        std::cout << arr[i] << " ";
    }
    std::cout  <<  std::endl;



    return 0;
}