/*
c++ -o main_05 main_05.cpp
*/

#include <cstdlib>
#include <iostream>
#include <cmath>


double func (double x) 
  {
    return cos (x) ; 
  }


double bisezione_ricorsiva (
  double f (double),
  double xMin,
  double xMax,
  double precision = 0.0001
)
{
  double xAve = 0.5 * (xMax + xMin) ;
  if ((xMax - xMin) < precision) return xAve ;
  if (f (xAve) * f (xMin) > 0.) return bisezione_ricorsiva (f, xAve, xMax, precision) ;
  else                          return bisezione_ricorsiva (f, xMin, xAve, precision) ;
}  


int main (int argc, char ** argv)
{
  std::cout << "Zero della funzione = " << bisezione_ricorsiva (func, 0., 4.) << std::endl ;
  return 0 ;
}
