/*
c++ -o main_04 main_04.cpp
*/

#include <cstdlib>
#include <iostream>
#include <cmath>


double func (double x) 
  {
    return cos (x) ; 
  }


double bisezione (
  double g (double),
  double xMin,
  double xMax,
  double precision = 0.0001
)
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


int main (int argc, char ** argv)
{
  std::cout << "Zero della funzione = " << bisezione (func, 0., 4.) << std::endl ;
  return 0 ;
}
