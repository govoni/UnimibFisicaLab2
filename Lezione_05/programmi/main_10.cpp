/*
c++ -o main_10 `root-config --cflags --glibs` main_10.cpp
*/

#include <cstdlib>
#include <iostream>
#include <cmath>

#include "TH2F.h"
#include "TCanvas.h"

float fgaus (float x) 
  {
    return exp (-0.5 * x * x) ; 
  }

float rand_range (float min, float max)
  {
    return min + (max - min) * rand () / static_cast<float> (RAND_MAX) ;
  } 

float rand_TCL (float xMin, float xMax, int N = 10)
  {
    double y = 0. ; 
    for (int i = 0 ; i < N ; ++i)
      y += rand_range (xMin, xMax) ;
    y /= N ;
    return y ;
  }

int main (int argc, char ** argv)
  {
    TCanvas c1 ("c1", "c1", 100, 100, 1000, 1000) ;

    TH2F h2 ("h2", "eventi pseudo-casuali Gaussiani", 200, -1.5, 1.5, 200, -1.5, 1.5) ;

    for (int j = 0 ; j < 1000000 ; ++j)
      h2.Fill (rand_TCL (-1., 1., 10), rand_TCL (-1., 1., 10)) ;

    h2.GetXaxis ()->SetTitle ("numeri generati") ;
    h2.GetYaxis ()->SetTitle ("numeri generati") ;
    h2.Draw ("LEGO") ;

    c1.Print ("Gaussian2D.png", "png") ;

    return 0 ;
  }
