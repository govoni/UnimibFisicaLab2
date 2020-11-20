#ifndef generatore_LC_h
#define generatore_LC_h

/*
 *  Generatore con teorema del limite centrale
 */

#include "generatore.h"

class generatore_LC: public generatore {
    public:
        // Costruttore
        generatore_LC(int seed, int N, double min, double max);
        // Distruttore
        ~generatore_LC();

        // Genera numeri casuali
        double generate();

    private:
        // Numero di estrazioni 
        int m_N;

        // Valore minimo
        double m_min;
        // Valore massimo
        double m_max;
};

#endif
