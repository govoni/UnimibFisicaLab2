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
 *  Restituisce l'area
 */
double forma::GetArea() {
    return m_area;
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
