/*
Esercizio 11: Si determini con il metodo della bisezione lo zero della funzione g(x) = cos(x) nell'intervallo (0, 4).
Quali controlli sono stati omessi, nell'implementazione dell'algoritmo descritta nel testo della lezione, che potrebbero accelerare il risultato?

c++ -o esercizio11 esercizio11.cpp
*/

#include <iostream>
#include <cmath>


double fcos (double x) 
  {
    return cos (x) ; 
  }


double bisezione ( double g (double), double xMin, double xMax, double precision)
{
  double xAve = xMin ;
  while ((xMax - xMin) > precision)
    {
      xAve = 0.5 * (xMax + xMin) ;
      if (g (xAve) * g (xMin) > 0.) xMin = xAve ;
      else                          xMax = xAve ;
    }
  return xAve ;
}  

//----------------- MAIN -----------------
int main (int argc, char ** argv)
{
  double x_min = 0.;
  double x_max = 4.;
  double risoluzione = 0.0001;

  std::cout << "Zero della funzione = " << bisezione (fcos, x_min, x_max, risoluzione) << std::endl ;
  return 0 ;
}
