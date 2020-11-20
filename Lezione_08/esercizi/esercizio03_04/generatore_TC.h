#ifndef generatoreTC
#define generatoreTC

/*
 *  Generatore Try-And-Catch
 */ 

#include "generatore.h"

enum funzioni {
    kGAUS,
    kEXP
};

class generatore_TC: public generatore {
    public:
        // Costruttore - parametri
        generatore_TC(int seed, unsigned int function = kGAUS, double min = 0., double max = 1.);
        // Distruttore
        ~generatore_TC();

        // Genera un numero casuale dalla distribuzione richiesta
        double generate();

    private:
        // Seleziona il tipo di funzione da utilizzare
        unsigned int m_function;

        // Minimo valore X per l'estrazione
        double m_min;
        // Massimo valore X per l'estrazione
        double m_max;

        // Genera un numero casuale con try and catch
        double rand_TAC(double f(double), double y_max);

        // Calcola il valore della gaussiana (centro=0, sigma=5)
        static double eval_gaus(double x);
        // Calcola il valore dell'esponenziale e^(-0.1*x)
        static double eval_exp(double x);

};

#endif
