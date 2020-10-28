/*
Esercizio 07: si crei e riempia un TH2F che contenga una Gaussiana bidimensionale nel piano (x,y) centrata in (0., 0.) con σx = σy = 2., generata con la tecnica del teorema centrale del limite, ricordando che una distribuzione di probabilita' Gaussiana bi-dimnesionale si ottiene facendo il prodotto di due distribuzioni di probabilita' Gaussiane mono-dimensionali.

c++ -o esercizio07 esercizio07.cpp `root-config --glibs --cflags` 
*/

#include <cstdlib>
#include <iostream>
#include <cmath>

#include "TH2F.h"
#include "TCanvas.h"

float fgaus (float x) 
  {
    return (float(1)/sqrt(8.*M_PI)) * exp ((-0.5 * x * x)/4);
  }

float rand_range (float min, float max)
  {
    return min + (max - min) * rand () / static_cast<float> (RAND_MAX) ;
  } 

float rand_TCL (float xMin, float xMax, int N = 20)
  {
    double y = 0. ; 
    for (int i = 0 ; i < N ; ++i)
      y += rand_range (xMin, xMax) ;
    y /= N ;
    return y ;
  }

int main ()
  {
    TCanvas c1 ("c1", "c1", 100, 100, 1000, 1000) ;

    TH2F h2 ("h2", "eventi pseudo-casuali Gaussiani", 200, -1.5, 1.5, 200, -1.5, 1.5) ;

    for (int j = 0 ; j < 1000000 ; ++j)
      h2.Fill (rand_TCL (-1., 1., 10), rand_TCL (-1., 1., 10)) ;

    h2.GetXaxis ()->SetTitle ("numeri generati") ;
    h2.GetYaxis ()->SetTitle ("numeri generati") ;
    h2.Draw ("LEGO") ;

    c1.Print ("esercizio07.png", "png") ;

    return 0 ;
  }
