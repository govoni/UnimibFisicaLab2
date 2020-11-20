#include "rettangolo.h"

#include <iostream>

using std::cout;
using std::endl;

/*
 *  Costruttore di default
 */
rettangolo::rettangolo(): m_lato_1(1), m_lato_2(1), forma(1) {
    /*
     *  Non posso modificare direttamente il contenuto di m_nome, è un membro privato
     *  di 'forma'. Usare qui m_nome = "rettangolo" sarebbe un errore
     *  Usando SetNome(), che è un metodo pubblico, non ci sono errori
     */
    // m_nome = "rettangolo";
    SetNome("rettangolo");
    cout << "Chiamato il costruttore (default) di rettangolo" << endl;
}

/*
 *  Costruttore con parametro
 */
rettangolo::rettangolo(double lato_1, double lato_2): 
    m_lato_1(lato_1), m_lato_2(lato_2), forma(lato_1*lato_2) {
    /*
     *  Non posso modificare direttamente il contenuto di m_nome, è un membro privato
     *  di 'forma'. Usare qui m_nome = "rettangolo" sarebbe un errore.
     *  Usando SetNome(), che è un metodo pubblico, non ci sono errori
     */
    // m_nome = "rettangolo";
    SetNome("rettangolo");
    cout << "Chiamato il costruttore (con parametro) di rettangolo" << endl;
}

/*
 *  Distruttore
 */
rettangolo::~rettangolo() {
    cout << "Chiamato il distruttore di rettangolo" << endl;
}

/*
 *  Cambia lato
 */
void rettangolo::cambia_lato_1( double lato_1 ) {
    m_lato_1 = lato_1;
    // Posso accedere a m_area, membro di forma, perchè è protected
    m_area = m_lato_1*m_lato_2;
}

/*
 *  Calcola l'area
 */
double rettangolo::calcola_area() {
    cout << "chiamata la funzione calcola_area di rettangolo" << endl;
    m_area = m_lato_1*m_lato_2;
    return m_area;
}

/*
 *  Calcola l'area - metodo non virtual
 */
double rettangolo::calcola_area_non_virtual() {
    cout << "chiamata la funzione calcola_area_non_virtual di rettangolo" << endl;
    m_area = m_lato_1*m_lato_2;
    return m_area;
}
