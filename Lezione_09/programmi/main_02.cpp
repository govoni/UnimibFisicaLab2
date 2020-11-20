/*
c++ -o main_02 funzioni.cc main_02.cpp

Testo:
  Si scriva una libreria di funzioni per determinare il parametro τ della distribuzione 
  esponenziale utilizzata per generare gli eventi presenti nel file dati_esponenziali.txt, 
  a partire dal vector di numeri creato negli esercizi precedenti.

  Si implementino i prototipi delle funzioni presentate a lezione.
  Si confronti il risultato ottenuto con la media dei numeri salvati nel vector.
  Come dipende il risultato dall'intervallo inziale passato alla funzione sezione_aurea_max?
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

#include "statistiche_vector.h"
#include "funzioni.h"

using namespace std ;

int main (int argc, char ** argv)
  {

    if (argc < 2)
      {
        cerr << "uso: " << argv[0] << " nomeFile [numero_di_eventi]" << endl ;
        exit (1) ;
      }

    ifstream input_file ; 
    input_file.open (argv[1], ios::in) ;

    int numeroMax = -1 ;
    if (argc > 2) numeroMax = atoi (argv[2]) ;

    vector<double> data ;
    double input_val ;
    while (true) 
      {
        input_file >> input_val ;
        if (input_file.eof () == true) break ;
        data.push_back (input_val) ;
        if (numeroMax > 0 && data.size () == numeroMax) break ;
      } 
    input_file.close () ;

    cout << "letti " << data.size () << " eventi" << endl ;

    double media_v = media (data) ;
    cout << "media = " << media_v << endl ; 

    double massimo = sezione_aurea_max (loglikelihood, 0.5 * media_v, 1.5 * media_v, data) ;

    cout << "massimo della likelihood = " << massimo << endl ; 

    return 0 ;
}
