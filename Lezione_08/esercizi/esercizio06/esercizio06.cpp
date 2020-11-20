// g++ -o Esercizio06 esercizio06.cpp ordinamento.cc

/*
 *  Lezione 8 - esercizio 06
 *
 *  Si costruisca un vector che contenga cento numeri interi casuali generati fra -10 e 10.
 *      - Si ordini il contenitore utilizzando l'algoritmo std::sort.
 *      - Si ordini il contenitore mettendo prima tutti i numeri positivi, ordinati fra di loro in ordine 
 *          crescente, quindi tutti quelli negativi, ordinati in ordine decrescente, utilizzando un oggetto 
 *          come algoritmo di ordinamento.
 */ 

#include <iostream>
#include <vector>
#include <algorithm> // std::sort
#include <cstdlib> // rand

#include "ordinamento.h"

using std::cout;
using std::endl;

/*
 *  Numeri casuali uniformemente distribuiti
 */
int rand_range( int min, int max ) {
    return min + rand() % (( max + 1 ) - min);
}

/*
 *  Funzione per l'ordinamento : prima tutti i positivi, ordinati in ordine crescente, poi i negativi, in ordine decrescente
 */ 
bool func_ordinamento( int a, int b ) {
    // La funzione ritorna true se a va anteposto a b 
    //
    // Consideriamo 0 come positivo

    if( a >= 0 ) {
        // a è positivo
        if( b < 0 ) {
            // se b è negativo, a va messo prima
            return true;
        } else {
            // se anche b è positivo, ordinamento crescente
            return (a < b);
            /*
             *  Equivalente a
             *
             *  if( a < b )
             *      return true;
             *  else
             *      return false;
             */
        }
    } else {
        // a è negativo
        if( b >= 0 ) {
            // se b è positivo, b va messo prima
            return false;
        } else {
            // se anche b è negativo, ordinamento decrescente
            return (a > b);
        }
    }
}

int main( int argc, char** argv ) {

    // Genero un vettore con 100 numeri casuali tra -10 e 10
    std::vector<int> numeri_casuali(100, 0);
    for(unsigned int i = 0; i < 100; i++) {
        numeri_casuali[i] = rand_range(-10, 10);
    }

    // Riordino il vector con std::sort
    std::sort( numeri_casuali.begin(), numeri_casuali.end() );

    // Riordino con una funzione
    std::sort( numeri_casuali.begin(), numeri_casuali.end(), func_ordinamento );

    // Test dell'ordinamento
    std::vector<int>::iterator it;
    cout << "Numeri ordinati usando una funzione" << endl;
    for(it = numeri_casuali.begin(); it != numeri_casuali.end(); it++) {
        cout << *it << " ";
    }
    cout << endl << endl;

    // Riordino con una classe
    ordinamento classe_ordinamento;
    std::sort( numeri_casuali.begin(), numeri_casuali.end(), classe_ordinamento );

    cout << "Numeri ordinati usando una classe" << endl;
    for(it = numeri_casuali.begin(); it != numeri_casuali.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
