/*
Esercizio 03: Si riempia un istogramma con eventi pseudo-casuali con distribuzione f(x) = |sin(x)| con x definito fra 0 e 2*PI generati con la tecnica di try-and-catch. Si utilizzi la funzione rand () come punto di partenza per l'implementazione del generatore uniforme

c++ -o esercizio03 esercizio03.cpp `root-config --glibs --cflags` 
*/

#include <cstdlib>
#include <iostream>
#include <cmath>

#include "TH1F.h"
#include "TCanvas.h"


float fsin (float x) 
 {
   if (sin(x)>=0)  return sin(x);
   else  return -sin(x);
 }


float rand_range (float min, float max)
 {
    return min + (max - min) * rand () / static_cast<float> (RAND_MAX) ;
  }

   
float rand_TAC (float f (float), float xMin, float xMax, float yMax)
 {
    float x = 0. ;
    float y = 0. ; 
    do {
      x = rand_range (xMin, xMax) ;
      y = rand_range (0, yMax) ;
    } while (y > f (x)) ;
    return x ; 
}

//----------------- MAIN -----------------
int main() {
 
 float x_min = 0. ;
 float x_max = 2* M_PI; 
 
 //Dichiarazione istogramma con limiti tra x_min e x_max
 TH1F h1("h1", "try-and-catch", 100, x_min , x_max) ;

 //riempimento istogramma
 for (int j = 0 ; j < 1000000 ; ++j) 
   h1.Fill(rand_TAC(fsin, x_min, x_max, 1)); 

 //Disegno l'istogramma
 TCanvas c1 ;
  
 h1.GetXaxis ()->SetTitle ("numeri generati") ;
 h1.GetYaxis ()->SetTitle ("conteggi per bin") ;
 h1.Draw () ;
 c1.Print ("esercizio03.png", "png") ;


 return 0;
 
}
