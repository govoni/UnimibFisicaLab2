/*
Esercizio 16: Si svolgano i due esercizi precedenti cercando il massimo di una funzione a scelta.

c++ -o esercizio16 esercizio16.cpp
*/

#include <iostream>
#include <cmath>


double fsin (double x)
{
  return sin(2*x);

} 

double sezioneAurea_max (double g (double),double x0, double x1, double precision)
{
  double r = 0.618;
  double x2 = 0;
  double x3 = 0; 
  double larghezza = fabs(x1-x0);
   
  while (larghezza > precision)
    {        
        x2 = x0 + r * (x1 - x0) ;
        x3 = x0 + (1. - r) * (x1 - x0);  
    
      if (g(x3) < g(x2) ) 
       {  //restringo l'intervallo tennedo fisso uno dei due estremi e spostando l'altro        
          x0 = x3;
          x1 = x1;         
        }            
      else 
          { //restringo l'intervallo tennedo fisso uno dei due estremi e spopstando l'altro
             x1 = x2;
             x0 = x0;          
          }
          
        larghezza = fabs(x1-x0) ;            
    } 
                                 
  return (x0+x1)/2. ;
}


double sezioneAurea_max_ricorsiva (double g (double),double x0, double x1, double precision)
{
  double r = 0.618;
  double x2 = x0 + r * (x1 - x0) ;
  double x3 = x0 + (1. - r) * (x1 - x0); 
  double larghezza = fabs(x1-x0);
  
  if (larghezza < precision)   return (x0+x1)/2. ;    
  if (g(x3) < g(x2) )          return sezioneAurea_max_ricorsiva(g,x3,x1,precision);
  else                         return sezioneAurea_max_ricorsiva(g,x0,x2,precision); 
}


//----------------- MAIN -----------------
int main (int argc, char ** argv)
{
  double x_min = 0.;
  double x_max = 2*M_PI;  
  double risoluzione = 0.0001;
  
  std::cout << "Massimo della funzione " << sezioneAurea_max (fsin, x_min, x_max, risoluzione) << std::endl;
  std::cout << "Massimo della funzione usando la funzione ricorsiva " << sezioneAurea_max_ricorsiva (fsin, x_min, x_max, risoluzione) << std::endl;
  
 return 0;
 } 





