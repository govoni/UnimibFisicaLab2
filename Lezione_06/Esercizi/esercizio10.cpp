/*
Esercizio 10: Si utilizzi il metodo hit-or-miss per stimare l’integrale sotteso ad una disrtibuzione di probabilita' Gaussiana con μ=0 e *σ=1 in un generico intervallo [a,b].
Si calcoli l'integrale contenuto entro gli intervalli [-kσ,kσ] al variare di k da 1 a 5.

c++ -o esercizio10 esercizio10.cpp 
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>


float rand_range (float min, float max)
  {
    return min + (max - min) * rand () / static_cast<float> (RAND_MAX) ;
  } 


double fgaus (double x)  
  {
    return exp (-0.5 * x * x) ; 
  }
  
void HitOrMiss (int Nrand, double g(double), double xMin, double xMax,
              double yMin, double yMax, double* risultato )
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
           
     risultato[0] = nHit * area / static_cast<double> (Nrand) ;
     risultato[1] = sqrt (varianza) ;
      
    return;       
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
  double* risultato = new double[2];
  
  int k = 1;
  
  while (k <= 5)
   {
    x_min = - k;
    x_max = k;
    HitOrMiss(N,fgaus,x_min,x_max,y_min,y_max,risultato); 
    std::cout << "Intervallo [" << x_min << " , " << x_max << "]" << std::endl;
    std::cout << "Integrale = " << risultato[0] << " +/- "  << risultato[1] << std::endl ;
    k++;                             
  }
           
  delete[] risultato;          
            
  return 0 ;
}




