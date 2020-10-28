/*
Esercizio 09: Si renda interattivo l'output del programma precedente tramite un oggetto di tipo TApplication e si provino le varie funzionalita' di interfaccia.

c++ -o esercizio09 esercizio09.cpp `root-config --glibs --cflags` 
*/

#include <cstdlib>
#include <iostream>
#include <cmath>

#include "TH2F.h"
#include "TCanvas.h"
#include "TApplication.h"


float rand_range (float min, float max)
  {
    return min + (max - min) * rand () / static_cast<float> (RAND_MAX) ;
  } 


int main (int argc, char ** argv)
  {
    TH2F h2 ("h2", "eventi pseudo-casuali uniformi", 100, -0.5, 1.5, 300, -2., 4.0) ;

    for (int j = 0 ; j < 1000000 ; ++j)
      h2.Fill (rand_range (0., 1.), rand_range (-1., 3.)) ;

    h2.GetXaxis ()->SetTitle ("numeri generati") ;
    h2.GetYaxis ()->SetTitle ("numeri generati") ;
       
    //Abilitare la funzionalità interattiva
    TApplication theApp ("theApp", &argc, argv) ;
    
    TCanvas c1 ("c1", "c1", 100, 100, 1000, 1000) ;
    h2.Draw ("LEGO") ; //finestra che voglio sia interattiva
    
    theApp.Run(); 

    return 0 ;
  }
