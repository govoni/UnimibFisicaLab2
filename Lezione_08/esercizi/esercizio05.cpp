// g++ -o Esercizio05 esercizio05.cpp

/*
 *  Lezione 8 - Esercizio 05
 *
 *  Si costruisca un vector di numeri interi contenente il doppio dei primi dieci numeri interi.
 *      - Si mostri che l'algoritmo std::find non trova alcuno dei primi dieci numeri dispari al suo interno.
 *      - Si trovi l'iteratore all'elemento che contiene il numero 6.
 *      - Si mostri che ognuno dei primi dieci numeri pari compare una volta sola all'interno del vector.
 */

#include <iostream>
#include <vector>
#include <algorithm> // std::find

using std::cout;
using std::endl;

int main(int argc, char** argv) {

    // Vector contenente il doppio dei primi dieci interi

    std::vector<int> doppio_interi(10, 0);
    for(int i = 1; i <= 10; i++)
        doppio_interi[i-1] = 2*i;

    /*
     *  Equivalentemente (più lento per vector di grandi dimensioni): 
     *
     *  std::vector<int> doppio_interi;
     *  for(int i = 1; i <= 10; i++)
     *      doppio_interi.push_back( 2*i );
     */

    // std::find non trova nessun numero dispari 
    for(int i = 1; i <= 19; i+=2) {
        if( std::find( doppio_interi.begin(), doppio_interi.end(), i) != doppio_interi.end() ) {
            cout << "Trovato il numero dispari " << i << endl;
        }
    }

    // Iteratore che contiene il numero 6
    std::vector<int>::const_iterator it_6 = std::find( doppio_interi.begin(), doppio_interi.end(), 6 );

    // Ognuno dei numeri pari in doppio_interi compare una volta sola
    
    std::vector<int>::iterator it, it2;
    for(it = doppio_interi.begin(); it != doppio_interi.end(); it++) {

        // Valore dell'intero nella posizione corrente
        int valore = *it;

        // Ciclo sugli elementi successivi del vector
        for( it2 = it+1; it2 != doppio_interi.end(); it2++ ) {
            // Controllo che il valore originale non si ripeta
            if( std::find( it2, doppio_interi.end(), valore ) != doppio_interi.end() ) {
                cout << "Il valore " << valore << " si ripete!" << endl;
            }
        }
    }
    
    // In alternativa, è possibile usare std::count, sempre dalla libreria algorithm
    for(unsigned int i = 0; i < doppio_interi.size(); i++) {
        int nRip = std::count( doppio_interi.begin(), doppio_interi.end(), doppio_interi[i] );
        cout << "Ripetizioni del valore " << doppio_interi[i] << " : " << nRip << endl;
    }


    return 0;
}
