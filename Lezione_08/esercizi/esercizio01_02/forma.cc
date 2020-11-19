#include "forma.h"

#include <iostream>

// In alternativa a 'using namespace std;', è possibile importare solo
// alcune funzioni da un namespace
using std::cout;
using std::endl;

/*
 *  Costruttore di default
 */
forma::forma(): m_area(-1), m_nome("forma") {
    cout << "Chiamato il costruttore (default) di forma" << endl;
}

/*
 *  Costruttore con un parametro
 */
forma::forma(double area): m_area(area), m_nome("forma") {
    cout << "Chiamato il costruttore (con parametro) di forma" << endl;
}

/*
 *  Distruttore
 */
forma::~forma() {
    cout << "Chiamato il distruttore di forma" << endl;
}

/*
 *  Restituisce il nome 
 */
std::string forma::GetNome() {
    return m_nome;
}

/*
 *  Imposta il nome
 */
void forma::SetNome(std::string nome) {
    m_nome = nome;
}

/*
 *  Calcola l'area 
 */ 
double forma::calcola_area() {
    cout << "Chiamata la funzione calcola_area di forma" << endl;
    return m_area;
}

/*
 *  Calcola l'area - metodo non virtual
 */
double forma::calcola_area_non_virtual() {
    cout << "Chiamata la funzione calcola_area_non_virtual di forma" << endl;
    return m_area;
}
