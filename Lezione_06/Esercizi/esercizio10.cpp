/*
Esercizio 10: Si utilizzi il metodo hit-or-miss per stimare l’integrale sotteso ad una disrtibuzione di probabilita' Gaussiana con μ=0 e *σ=1 in un generico intervallo [a,b].
Si calcoli l'integrale contenuto entro gli intervalli [-kσ,kσ] al variare di k da 1 a 5.

c++ -o esercizio10 esercizio10.cpp ../../Lezione_03/Esercizi/esercizio04/myarray.cc
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

#include "../../Lezione_03/Esercizi/esercizio04/myarray.h"


float rand_range (float min, float max)
  {
    return min + (max - min) * rand () / static_cast<float> (RAND_MAX) ;
  } 


double fgaus (double x)  
  {
    return exp (-0.5 * x * x) ; 
  }
  
mioArray HitOrMiss (int Nrand, double g(double), double xMin, double xMax,
                    double yMin, double yMax)
   {
     int nHit = 0;
     double area  = (xMax - xMin) * (yMax - yMin) ;
     
     for (int i = 0 ; i < Nrand ; ++i) 
      {
        double x = rand_range (xMin, xMax) ;
        double y = rand_range (yMin, yMax) ; 
        if (y < g (x)) ++nHit ; 
      }   
      
     double p = nHit / static_cast<double> (Nrand) ;
     double varianza = area * area / static_cast<double> (Nrand) * p * (1. - p) ;
           
     mioArray risultato (2) ;      
     risultato.fill (0, nHit * area / static_cast<double> (Nrand)) ;
     risultato.fill (1, sqrt (varianza)) ;
      
    return risultato ;       
   }           

//----------------- MAIN -----------------
int main (int argc, char ** argv)
{ 
  srand (time (NULL)) ;
  int N = 10000 ;
  double x_min = 0.;
  double x_max = 0. ; 
  double y_min = 0. ; 
  double y_max = 1. ;

  int k = 1;
  
  while (k <= 5)
   {
    x_min = - k;
    x_max = k;
    mioArray risultato = HitOrMiss(N,fgaus,x_min,x_max,y_min,y_max);
    std::cout << "Intervallo [" << x_min << " , " << x_max << "]" << std::endl;
    std::cout << "Integrale = " << risultato.get1 (0) << " +/- " << risultato.get1 (1) << std::endl ; 
    k++;                             
  }
                   
  return 0 ;
}




