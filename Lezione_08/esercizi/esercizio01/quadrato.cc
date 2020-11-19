#include "quadrato.h"

#include <iostream>

using std::cout;
using std::endl;

/*
 *  Costruttore di default
 */
quadrato::quadrato(): m_lato(1), forma(1) {
    /*
     *  Non posso modificare direttamente il contenuto di m_nome, è un membro privato
     *  di 'forma'. Usare qui m_nome = "quadrato" sarebbe un errore
     *  Usando SetNome(), che è un metodo pubblico, non ci sono errori
     */
    // m_nome = "quadrato";
    SetNome("quadrato");
    cout << "Chiamato il costruttore (default) di quadrato" << endl;
}

/*
 *  Costruttore con parametro
 */
quadrato::quadrato(double lato): m_lato(lato), forma(lato*lato) {
    /*
     *  Non posso modificare direttamente il contenuto di m_nome, è un membro privato
     *  di 'forma'. Usare qui m_nome = "quadrato" sarebbe un errore.
     *  Usando SetNome(), che è un metodo pubblico, non ci sono errori
     */
    // m_nome = "quadrato";
    SetNome("quadrato");
    cout << "Chiamato il costruttore (con parametro) di quadrato" << endl;
}

/*
 *  Distruttore
 */
quadrato::~quadrato() {
    cout << "Chiamato il distruttore di quadrato" << endl;
}

/*
 *  Cambia lato
 */
void quadrato::cambia_lato( double lato ) {
    m_lato = lato;
    // Posso accedere a m_area, membro di forma, perchè è protected
    m_area = m_lato*m_lato;
}
