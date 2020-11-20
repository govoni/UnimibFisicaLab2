// g++ -o Esercizio03_04 esercizio03_04.cpp generatore.cc generatore_TC.cc generatore_IF.cc generatore_LC.cc

#include "generatore.h"
#include "generatore_TC.h"
#include "generatore_IF.h"
#include "generatore_LC.h"

#include <iostream>
#include <map>
#include <string>
#include <ctime>

using std::cout;
using std::endl;

/*
 *  Lezione 8 - Esercizio 03
 *
 *  Si implementino i generatori di numeri casuali scritti durante la Lezione 4 
 *  come oggetti derivati della seguente classe puramente virtuale e si verifichi 
 *  il dynamic binding.
 *
 *      class generatore {
 *          ...
 *      };
 *
 *
 *  Lezione 8 - Esercizio 04
 *
 *  Si inseriscano i generatori precedenti in una std::map e si utilizzi un 
 *  loop sugli elementi della mappa per verificare quanto tempo impieghi 
 *  ciascun generatore, in media, a generare un evento pseudo-casuale.
 */

int main(int argc, char** argv) {

    // Chiave: nome del generatore
    // Valore: puntatore a un oggetto derivante da generatore
    std::map<std::string, generatore*> mappa_generatori;

    int seed = 14741;
    long long int nPoints = 100000;

    // Aggiungo i generatori alla mappa, associandoli al proprio nome
    mappa_generatori["lineare congruenziale"] = new generatore(seed);
    mappa_generatori["try and catch - gaus"] = new generatore_TC(seed, kGAUS, -20, 20);
    mappa_generatori["try and catch - exp"] = new generatore_TC(seed, kEXP, 0, 100);
    mappa_generatori["funzione inversa - exp"] = new generatore_IF(seed, 0, 100);
    mappa_generatori["teorema limite centrale - 100 iterazioni"] = new generatore_LC(seed, 100, -5, 5);
    cout << endl;

    // Itero sulla mappa di generatori
    cout << "Tempo richiesto per generare " << nPoints << " numeri casuali" << endl;
    std::string nome;
    generatore* gen;

    std::map<std::string, generatore*>::const_iterator gen_it;
    for(gen_it = mappa_generatori.begin(); gen_it != mappa_generatori.end(); gen_it++) {
        nome = gen_it->first;
        gen = gen_it->second;

        clock_t startTime = clock();
        for(int i = 0; i < nPoints; i++) {
            double val = gen->generate();
        }
        clock_t endTime = clock();

        cout << nome << " : " << (endTime-startTime)/(static_cast<double>CLOCKS_PER_SEC) << endl;
    }
    cout << endl;

    // Pulizia del contenuto della mappa
    for(gen_it = mappa_generatori.begin(); gen_it != mappa_generatori.end(); gen_it++) {
        delete gen_it->second;
    }
    mappa_generatori.clear();

    return 0;
}
