#include "generatore_LC.h"

#include <iostream>

using std::cout;
using std::endl;

/*
 *  Costruttore
 */
generatore_LC::generatore_LC(int seed, int N, double min, double max): m_N(N), m_min(min), m_max(max), generatore(seed) {
    cout << "Chiamato il costruttore del generatore con teorema del limite centrale" << endl;
}

/*
 *  Distruttore
 */
generatore_LC::~generatore_LC() {
    cout << "Chiamato il distruttore del generatore con teorema del limite centrale" << endl;
}

/*
 *  Genera numeri casuali
 */
double generatore_LC::generate() {
    double mean = 0;

    for(int i = 0; i < m_N; i++) 
        mean += rand_range(m_min, m_max);

    return mean/m_N;
}
