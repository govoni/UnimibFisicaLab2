/*
c++ -o main_01 `root-config --cflags --glibs` main_01.cpp
*/

#include <cstdlib>
#include <iostream>

#include "TH1F.h"
#include "TCanvas.h"

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
    int NToys = 40000 ;

    statistiche s_singleToy ;
    statistiche s_tot ;
    TH1F h_medie ("h_medie", "distribuzione delle medie", 41, -0.5, 0.5) ;

    // loop sui toy experiment
    for (int iToy = 0 ; iToy < NToys ; ++iToy)
      {
        int i = 0 ;
        // il loop seguente e' un singolo toy experiment
        while (i++ < NMAX) s_singleToy.addEvent (rand_range (-3., 3.)) ;
        s_tot.addEvent (s_singleToy.getMean ()) ;
        h_medie.Fill (s_singleToy.getMean ()) ;
        s_singleToy.reset () ;
      } // loop sui toy experiment

    std::cout << "prodotti " << s_tot.getN () << " toy" << std::endl ;

    TCanvas c1 ("c1", "c1", 100, 100, 1000, 1000) ;
    h_medie.SetFillColor (kOrange + 1) ;
    h_medie.GetXaxis ()->SetTitle ("media del campione") ;
    h_medie.Draw () ;
    c1.Print ("medie.png", "png") ;

    return 0 ;
  }
