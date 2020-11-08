/*
Esercizio 01: Si scriva un programma che, fissato NMAX numero di eventi di un campione, generi NToys toy experiment di quel campione e ne calcoli la media.
Esercizio 02: Si Aggiunge al programma precedente un oggetto di tipo TH1F che visualizzi la distribuzione delle medie al variare dei toy experiment.

c++ -o esercizi01_02 esercizi01_02.cpp ../../Lezione_04/Esercizi/statistiche.cc `root-config --glibs --cflags` 
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

#include "TH1F.h"
#include "TCanvas.h"

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
            
    //definisco due oggetti della classe statistiche
    statistiche* s_singleToy = new statistiche(NMAX);
    statistiche* s_media = new statistiche(NToys);
    
    TH1F h_medie ("h_medie", "Distribuzione delle medie", 41, -0.5, 0.5) ;
    
    // loop su tutti i toy experiment
    for (int iToy = 0 ; iToy < NToys ; ++iToy)
      {
        int i = 0 ;
        //loop sul singolo esperimento
        while (i++ < NMAX) s_singleToy->aggiungiNumero (rand_range (-3., 3.)) ;
                       
        h_medie.Fill(s_singleToy->media());
        s_media->aggiungiNumero (s_singleToy->media ()) ;        
        s_singleToy->reset () ;
      } 

     TCanvas c1 ("c1", "c1", 100, 100, 1000, 1000);
     h_medie.GetXaxis()->SetTitle("media del campione");
     h_medie.GetYaxis()->SetTitle("numero di eventi");
     h_medie.Draw();
     
     c1.Print("esercizio2.png", "png");

    delete s_singleToy;
    delete s_media;


    return 0 ;
  }
