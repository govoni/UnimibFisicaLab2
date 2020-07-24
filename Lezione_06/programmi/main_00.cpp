/*
c++ -o main_00 main_00.cpp
*/

#include <cstdlib>
#include <iostream>
#include "../../Lezione_05/programmi/statistiche.h"

float rand_range (float min, float max)
  {
    return min + (max - min) * rand () / static_cast<float> (RAND_MAX) ;
  } 


int main (int argc, char ** argv)
  {
    // numero di eventi generati per esperimento
    int NMAX = 500 ;
    // numero di toy per construire la pdf della media per campionamento
    int NToys = 100 ;

    statistiche s_singleToy ;
    statistiche s_tot ;

    // loop sui toy experiment
    for (int iToy = 0 ; iToy < NToys ; ++iToy)
      {
        int i = 0 ;
        // il loop seguente e' un singolo toy experiment
        while (i++ < NMAX) s_singleToy.addEvent (rand_range (-3., 3.)) ;
        s_tot.addEvent (s_singleToy.getMean ()) ;
        s_singleToy.reset () ;
      } // loop sui toy experiment

    std::cout << "prodotti " << s_tot.getN () << " toy" << std::endl ;

    return 0 ;
  }
