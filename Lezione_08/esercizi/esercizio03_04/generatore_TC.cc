#include "generatore_TC.h"

#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

/*
 *  Costruttore
 */
generatore_TC::generatore_TC(int seed, unsigned int function, double min, double max) : m_function(function), m_min(min), m_max(max), generatore(seed) {
    cout << "Chiamato il costruttore del generatore try and catch" << endl;

    if( m_function > 1 ) {
        cout << "Funzione non valida!" << endl;
    }
}

/*
 *  Distruttore
 */
generatore_TC::~generatore_TC() {
    cout << "Chiamato il distruttore del generatore try and catch" << endl;
}

/*
 *  Genera un numero casuale dalla distribuzione richiesta
 */
double generatore_TC::generate() {

    double y_max = 0;
    double val = 0;

    double x = 0;
    double y = 0;
        
    switch( m_function ) {
        case kGAUS:
            // Valuto y_max a seconda di m_min e m_max
            if( m_min < 0 && m_max > 0 ) {
                // La gaussiana passa da 0, il massimo è quello della gaussiana
                y_max = eval_gaus(0); 
            } else {
                // La gaussiana non passa da 0, è monotona
                y_max = eval_gaus(m_min);
                double y2 = eval_gaus(m_max);
                if( y2 > y_max )
                    y_max = y2;
            }
            val = rand_TAC(eval_gaus, y_max);

            break;
        case kEXP:
            // Calcolo di y_max - esponenziale monotono decrescente
            y_max = eval_exp(m_min); 

            val = rand_TAC(eval_exp, y_max);

            break;
        default:
            // Solo Gaus e Exp sono implementate
            break;
    }
    
    return val;
}

/*
 *  Genera un numero casuale con try and catch
 */
double generatore_TC::rand_TAC(double f(double), double y_max) {
    double x = 0;
    double y = 0;

    do {
        x = rand_range(m_min, m_max);
        y = rand_range(0, y_max);
    } while( y > f(x) );

    return x;
}

/*
 *  Calcola il valore della gaussiana (centro=0, sigma=5)
 */ 
double generatore_TC::eval_gaus(double x) {
    return 1./sqrt(2*M_PI*5.*5.) * exp( -0.5 * pow( x/5., 2));
}

/*
 *  Calcola il valore dell'esponenziale e^(-0.1*x)
 */
double generatore_TC::eval_exp(double x) {
    return exp(-0.1*x);
}
