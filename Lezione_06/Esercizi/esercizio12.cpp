/*
Esercizio 12: Si svolga l'esercizio precedente utilizzando una funzione ricorsiva.

c++ -o esercizio12 esercizio12.cpp
*/

#include <iostream>
#include <cmath>


double fcos (double x) 
  {
    return cos (x) ; 
  }


double bisezione_ricorsiva ( double g (double), double xMin, double xMax, double precision)
{   
  double xAve = 0.5 * (xMax + xMin) ;
  if ((xMax - xMin) < precision) return xAve ;
  if (g (xAve) * g (xMin) > 0.) return bisezione_ricorsiva (g, xAve, xMax, precision) ;
  else                          return bisezione_ricorsiva (g, xMin, xAve, precision) ;
}  

//----------------- MAIN -----------------
int main (int argc, char ** argv)
{
  double x_min = 0.;
  double x_max = 4.;
  double risoluzione = 0.0001;

  std::cout << "Zero della funzione = " << bisezione_ricorsiva (fcos, x_min, x_max, risoluzione) << std::endl ;
  return 0 ;
}
