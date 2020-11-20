#include "generatore.h"

#include <iostream>

using std::cout;
using std::endl;

/*
 *  Costruttore
 */
generatore::generatore(int seed): m_seed(seed) {
    cout << "Chiamato il costruttore del generatore lineare congruenziale" << endl;
}

/*
 *  Distruttore
 */
generatore::~generatore() {
    cout << "Chiamato il distruttore del generatore lineare congruenziale" << endl;
}

/*
 *  Imposta il seed  
 */
void generatore::set_seed(int seed) {
    m_seed = seed;
    cout << "Chiamato il metodo set_seed del generatore lineare congruenziale" << endl;
}

/*
 *  Restituisce il prossimo numero casuale
 */
double generatore::generate() {
    m_seed = (A*m_seed + C) % M;
    return m_seed;
}

/*
 *  Genera un numero casuale in un range [m_min, m_max]
 */
double generatore::rand_range(double min, double max) {
    // Genero un numero casuale dal generatore congruenziale
    double rnd = generatore::generate();

    return min + (max - min) * rnd / static_cast<double> (M);
}

