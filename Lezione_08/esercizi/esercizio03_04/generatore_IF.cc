#include "generatore_IF.h"

#include <iostream>
#include <cmath> // log

using std::cout;
using std::endl;

/*
 *  Costruttore
 */
generatore_IF::generatore_IF(int seed, double min, double max): m_min(min), m_max(max), generatore(seed) {
    cout << "Chiamato il costruttore del generatore con funzione inversa" << endl;
}

/*
 *  Distruttore
 */
generatore_IF::~generatore_IF() {
    cout << "Chiamato il distruttore del generatore con funzione inversa" << endl;
}

/*
 *  Genera un numero casuale
 */
double generatore_IF::generate() {
    double rand_val = rand_range(m_min, m_max);
    return rand_IF(rand_val);
}

/*
 *  Genera un numero casuale da e^(-0.1*x)
 */
double generatore_IF::rand_IF(double y) {
    double lambda = 0.1;
    return - (log(1-y)/lambda);
}
