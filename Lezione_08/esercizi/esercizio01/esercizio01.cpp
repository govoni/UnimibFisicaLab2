// g++ -o Esercizio01 esercizio01.cpp forma.cc quadrato.cc

#include "forma.h"
#include "quadrato.h"

#include <iostream>

using std::cout;
using std::endl;

/*
 *  Lezione 8 - Esercizio 01
 *
 *  Si definisca una semplice struttura di ereditarieta' delle forme geometriche, seguendo l'esempio presentato ad inizio lezione.
 *    - Si aggiunga alla classe forma un membro private (ad esempio un'etichetta) e si verifichi che e' accessibile 
 *      dalle classi derivate solamente tramite un metodo aggiuntivo public o protected della classe base.
 *    - Si verifichi la sequenza delle chiamate dei costruttori e dei distruttori della parte base e derivata delle 
 *      classi al momento della creazione e della distruzione dei diversi oggetti, inserendo in ogni costruttore e 
 *      distruttore un messaggio a schemo.
 *
 *
 *  Vengono definite due classi, forma è una classe generale e quadrato eredita da forma.
 *  
 *  La classe 'forma' ha un membro protected (m_area), direttamente accessibile nella classe quadrato, 
 *  e un membro privato (m_nome), NON accessibile nella classe quadrato.
 */

int main(int argc, char** argv) {

    cout << "Creo un oggetto di tipo forma" << endl;
    forma forma_generica(10);

    cout << "forma_generica" << endl;
    cout << "  nome: " << forma_generica.GetNome() << endl;
    cout << "  area: " << forma_generica.GetArea() << endl << endl;

    cout << "Creo un oggetto di tipo quadrato" << endl;
    quadrato forma_quadrata(5);

    cout << "forma_quadrata" << endl;
    cout << "  nome: " << forma_quadrata.GetNome() << endl;
    cout << "  area: " << forma_quadrata.GetArea() << endl << endl;
}
