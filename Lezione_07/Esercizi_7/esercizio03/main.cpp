//c++ -o es3 main.cpp SimpleArray.cc ../esercizio02/complesso.cc 
#include "SimpleArray.h"
#include "../esercizio02/complesso.h"

int main(){

    int dim = 10;
    SimpleArray<complesso*> arr(10);
    
    for(int i = 0; i < dim; ++i){
        arr[i] = new complesso(i,i);
        arr[i]->stampami();
    }

    return 0;
}