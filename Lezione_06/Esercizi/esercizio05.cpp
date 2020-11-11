/*
Esercizio 05: Si implementi il metodo di integrazione hit-or-miss con la funzione di esempio f(x) = sin (x).
Si scriva l'algoritmo che calcola l'integrale come una funzione esterna al programma main, facendo in modo che prenda come parametri di ingresso, oltre agli estremi lungo l'asse x e l'asse y, anche il numero di punti pseudo-casuali da generare.
Si faccia in modo che l'algoritmo ritorni un contenitore contenente due elementi: il primo elemento sia il valore dell'integrale, il secondo sia la sua incertezza.

c++ -o esercizio05 esercizio05.cpp ../../Lezione_03/Esercizi/esercizio04/myarray.cc
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


double fsin (double x) 
  {
    return sin (x) ; 
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
  double x_min = 0. ;
  double x_max = M_PI ; 
  double y_min = 0. ; 
  double y_max = 1. ;
   
  mioArray risultato = HitOrMiss(N,fsin,x_min,x_max,y_min,y_max);
  
  std::cout << "Integrale = " << risultato.get1 (0) << " +/- " << risultato.get1 (1) << std::endl ;
            
  return 0 ;
}




