// g++ -o Esercizio01_02 esercizio01_02.cpp forma.cc quadrato.cc rettangolo.cc

#include "forma.h"
#include "quadrato.h"
#include "rettangolo.h"

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

/*
 *  Lezione 8 - Esercizio 01 
 *
 *  Si definisca una semplice struttura di ereditarieta' delle forme geometriche, seguendo l'esempio presentato ad inizio lezione.
 *    - Si aggiunga alla classe forma un membro private (ad esempio un'etichetta) e si verifichi che e' accessibile 
 *        dalle classi derivate solamente tramite un metodo aggiuntivo public o protected della classe base.
 *    - Si verifichi la sequenza delle chiamate dei costruttori e dei distruttori della parte base e derivata delle 
 *        classi al momento della creazione e della distruzione dei diversi oggetti, inserendo in ogni costruttore e 
 *        distruttore un messaggio a schemo.
 *
 *
 *  Lezione 8 - Esercizio 02
 *  Si modifichi la struttura precedente aggiungendo la funzione calcola_area in tutta la catena di ereditarieta'.
 *
 *    - Si verifichi il comportamento polimorfico introdotto dal dynamic binding.
 *    - Si verifichi che, eliminando la parola chiave virtual, il dynamic binding non funziona.
 *    - Si verifichi che il dynamic binding avviene in esecuzione e non in fase di compilazione, 
 *        implementando una funzione void stampa_area (forma * input) che stampa a schermo l'area 
 *        di un oggetto di tipo rettangolo o quadrato a seconda della scelta dell'utente.
 *
 */

int main(int argc, char** argv) {

    /*
     *  Esercizio 01
     *
     *  Vengono definite due classi, forma è una classe generale e quadrato eredita da forma.
     *  
     *  La classe 'forma' ha un membro protected (m_area), direttamente accessibile nella classe quadrato, 
     *  e un membro privato (m_nome), NON accessibile nella classe quadrato.
     */
    cout << "Creo un oggetto di tipo forma" << endl;
    forma forma_generica(10);

    cout << "forma_generica" << endl;
    cout << "  nome: " << forma_generica.GetNome() << endl;
    cout << endl;

    cout << "Creo un oggetto di tipo quadrato" << endl;
    quadrato forma_quadrata(5);

    cout << "forma_quadrata" << endl;
    cout << "  nome: " << forma_quadrata.GetNome() << endl;
    cout << endl;

    /*
     *  Esercizio 02
     *
     *      Vengono aggiunti i metodi calcola_area (definito come virtual) e 
     *      calcola_area_non_virtual (non definito come virtual) e si verifica 
     *      che, nel caso di metodo virtual, il dynamic binding funziona
     */

    // Area di forma_generica
    cout << "Calcolo l'area" << endl;
    cout << "forma_generica" << endl;
    double area_forma = forma_generica.calcola_area();
    cout << "  area: " << area_forma << endl;
    cout << endl;

    // Area di forma_quadrata
    cout << "forma_quadrata" << endl;
    double area_quadrato = forma_quadrata.calcola_area();
    cout << "  area: " << area_quadrato << endl;
    cout << endl;

    // Esempio di dynamic binding: usando un puntatore a un oggetto di tipo forma
    // viene chiamato il metodo 'calcola_area' della classe derivata quadrato
    //
    // Bisogna definire forma::calcola_area() come virtual!

    forma* puntatore_quadrato = &forma_quadrata;
    cout << "dynamic binding" << endl;
    double area_quadrato_virtual = puntatore_quadrato->calcola_area();
    cout << endl;

    // Esempio errato di dynamic binding: usando il metodo calcola_area_non_virtual
    // (non definito come virtual) non viene chiamato il metodo corretto
    cout << "dynamic binding errato - metodo non virtual" << endl;
    double area_quadrato_non_virtual = puntatore_quadrato->calcola_area_non_virtual();
    cout << endl;

    // Il dynamic binding ha effetto in fase di esecuzione, non di compilazione
    int risultato = -1;
    while( risultato != 0 && risultato != 1 ) {
        cout << "Inserire 0 per un quadrato (area 400), 1 per un rettangolo (area 150)" << endl;
        cin >> risultato;
        cout << endl;
    }

    // Lego un puntatore a forma a un oggetto di tipo quadrato o rettangolo,
    // a seconda della scelta dell'utente
    forma* forma_dyn;
    if( risultato == 0 ) {
        forma_dyn = new quadrato(20);
    } else if( risultato == 1 ) {
        forma_dyn = new rettangolo(15, 10);
    }

    if( forma_dyn ) {
        double area = forma_dyn->calcola_area();
        cout << "Area : " << area << endl;
        delete forma_dyn;
        cout << endl;
    }
}
