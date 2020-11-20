/*
c++ -o es3 main.cpp SimpleArray.cc ../esercizio02/complesso.cc 

Testo:
    Si costruisca la classe SimpleArray, templata sul tipo degli oggetti che contiene, implementando 
    le funzioni definite nel prototipo presentato a lezione.

    Si ricordi di utilizzare correttamente l'allocazione dinamica della memoria.
    Si aggiungano alla classe anche metodi che permettano di accedere agli elementi della classe in caso vengano 
    chiamati su un oggetto const.
    Si faccia in modo che i metodi di accesso al contenuto del SimpleArray controllino il valore dell'indice prima 
    di accedere all'array salvato in memoria.
    Si verifichi che la classe SimpleArray può essere templata sulla classe dei numeri complessi sviluppata 
    durante la Lezione 3.
*/

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