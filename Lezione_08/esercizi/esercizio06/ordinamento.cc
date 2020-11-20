#include "ordinamento.h"

// Costruttore
ordinamento::ordinamento() {}

// Distruttore
ordinamento::~ordinamento() {}

// Operatore() per ordinare i numeri
bool ordinamento::operator() (int a, int b) {
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
