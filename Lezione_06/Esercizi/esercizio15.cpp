/*
Esercizio 15: Si svolga l'esercizio precedente utilizzando una funzione ricorsiva.

c++ -o esercizio15 esercizio15.cpp
*/

#include <iostream>
#include <cmath>


double funz (double x)
{
  return (x*x + 7.3*x + 4);

} 

double sezioneAurea_ricorsiva (double g (double),double x0, double x1, double precision)
{
  double r = 0.618;
  double x2 = x0 + r * (x1 - x0) ;
  double x3 = x0 + (1. - r) * (x1 - x0); 
  double larghezza = fabs(x1-x0);
  
  if (larghezza < precision)   return (x0+x1)/2. ;    
  if (funz (x3) > funz (x2) )  return sezioneAurea_ricorsiva(g,x3,x1,precision);
  else                         return sezioneAurea_ricorsiva(g,x0,x2,precision);   
}

//----------------- MAIN -----------------
int main (int argc, char ** argv)
{
  double x_min = - 10.;
  double x_max = 10.;
  double risoluzione = 0.0001;
  
  std::cout << "Minimo della funzione " << sezioneAurea_ricorsiva (funz, x_min, x_max, risoluzione) << std::endl;
  
 return 0;
 } 





