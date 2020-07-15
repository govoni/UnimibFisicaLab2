/*
c++ -o main_03 `root-config --glibs --cflags` main_03.cpp
*/

#include <cstdlib>
#include <iostream>

#include "TH1F.h"
#include "TCanvas.h"

float rand_range (float min, float max)
  {
    return min + (max - min) * rand () / static_cast<float> (RAND_MAX) ;
  } 


int main (int argc, char ** argv)
  {
    if (argc < 2)
      {
        std::cerr << "uso del programma: " << argv[0] << " numero_eventi" << std::endl ;
        exit (1) ;
      }
    int Nmax = atoi (argv[1]) ;

    TString titolo = "distribuzione uniforme, " ;
    titolo += argv[1] ;
    titolo += " eventi" ;
    TH1F h_uniforme ("h_uniforme", titolo, 50, -5., 5.) ;
    h_uniforme.GetXaxis ()->SetTitle ("x") ;

    for (int i = 0 ; i < Nmax ; ++i)
      h_uniforme.Fill (rand_range (-4., 4.)) ;

    TCanvas c1 ;
    h_uniforme.SetFillColor (kOrange + 1) ; // imposta il colore di riempimento
    h_uniforme.SetStats (0) ; // nasconde le informazioni statistiche sull'istogramma
    h_uniforme.Draw () ;
    c1.Print ("h_uniforme.png", "png") ;

    return 0 ;
  }
