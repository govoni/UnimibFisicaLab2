/*
Esercizio 08: Si crei e riempia un TH2F che contenga una distribuzione uniforme bidimensionale, con x definito fra 0. ed 1. ed y definito fra -1. e 3..

c++ -o esercizio08 esercizio08.cpp `root-config --glibs --cflags` 
*/

#include <cstdlib>
#include <iostream>
#include <cmath>

#include "TH2F.h"
#include "TCanvas.h"


float rand_range (float min, float max)
  {
    return min + (max - min) * rand () / static_cast<float> (RAND_MAX) ;
  } 


int main ()
  {
    TCanvas c1 ("c1", "c1", 100, 100, 1000, 1000) ;

    TH2F h2 ("h2", "eventi pseudo-casuali uniformi", 100, -0.5, 1.5, 300, -2., 4.0) ;

    for (int j = 0 ; j < 1000000 ; ++j)
      h2.Fill (rand_range (0., 1.), rand_range (-1., 3.)) ;

    h2.GetXaxis ()->SetTitle ("numeri generati") ;
    h2.GetYaxis ()->SetTitle ("numeri generati") ;
    h2.Draw ("LEGO") ; 

    c1.Print ("esercizio08.png", "png") ;

    return 0 ;
  }
