/*
Esercizio 03: Si utilizzi la classe statistiche sviluppata durante la Lezione 4 per confrontare la deviazione standard della media calcolata per ogni singolo toy con la deviazione standard del campione delle medie.

c++ -o esercizio03 esercizio03.cpp ../../Lezione_04/Esercizi/statistiche.cc  
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

#include "../../Lezione_04/Esercizi/statistiche.h" 

float rand_range (float min, float max)
  {
    return min + (max - min) * rand () / static_cast<float> (RAND_MAX) ;
  }
  
//----------------- MAIN -----------------  
  
int main (int argc, char ** argv)
  {
    srand(time(NULL));   
  
    // numero di eventi generati per un singolo toy experiment
    int NMAX = 500 ;
    // numero di toy experiment per construire la pdf della media per campionamento
    int NToys = 10000 ;
            
    statistiche* s_singleToy = new statistiche(NMAX);
    statistiche* s_media = new statistiche(NToys);
    statistiche* s_incertezzaMedia = new statistiche(NToys);
           
    // loop su tutti i toy experiment
    for (int iToy = 0 ; iToy < NToys ; ++iToy)
      {
        int i = 0 ;
        //loop sul singolo esperimento
        while (i++ < NMAX) s_singleToy->aggiungiNumero (rand_range (-3., 3.)) ;

        s_media->aggiungiNumero (s_singleToy->media ()) ;                      
        s_incertezzaMedia->aggiungiNumero(s_singleToy->dev_standard_media ());
                       
        s_singleToy->reset () ;
      } 


    //valori finali
    std::cout << "media delle deviazioni standard della media per i singoli toy experiment: " 
              << s_incertezzaMedia->media () << " \n" ;
    std::cout << "deviazione standard della distribuzione delle medie dei singoli toy experiment: " 
              << s_media->dev_standard_SQ () << " \n" ;


    delete s_singleToy;
    delete s_media;
    delete s_incertezzaMedia;


    return 0 ;
  }
