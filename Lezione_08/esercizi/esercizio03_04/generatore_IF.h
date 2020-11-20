#ifndef generatore_IF_h
#define generatore_IF_h


/*
 *  Generatore con funzione inversa - esponenziale
 */

#include "generatore.h"

class generatore_IF:public generatore {
    public:
        // Costruttore
        generatore_IF(int seed, double min, double max);
        // Distruttore
        ~generatore_IF();

        // Genera un numero casuale
        double generate();

    private:
        // Minimo valore di X su cui generare
        double m_min;
        // Massimo valore di X su cui generare
        double m_max;

        // Genera un numero casuale da distribuzione esponenziale
        double rand_IF(double y);
};

#endif
