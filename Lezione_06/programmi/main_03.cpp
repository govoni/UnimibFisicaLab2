/*
c++ -o main_03 main_03.cpp
*/

#include <cstdlib>
#include <iostream>
#include <cmath>


float rand_range (float min, float max)
  {
    return min + (max - min) * rand () / static_cast<float> (RAND_MAX) ;
  } 


double fsin (double x) 
  {
    return 1. + sin (x) ; 
  }

bool isBelow (double g (double), double xMin, double xMax,
              double yMin, double yMax)
  {
    double x = rand_range (xMin, xMax) ;
    double y = rand_range (yMin, yMax) ; 
    if (y < g (x)) return true ; 
    return false ;
  }


int main (int argc, char ** argv)
{
 
  srand (time (NULL)) ;
  int N = 10000 ;
  int nHit = 0 ;
  double xMin = 0. ;
  double xMax = 2*M_PI ; 
  double yMin = 0. ; 
  double yMax = 2. ;

  for (int i = 0 ; i < N ; ++i) 
    {
      if (isBelow (fsin, xMin, xMax, yMin, yMax) == true) ++nHit ; 
    }

  double Area     = (xMax - xMin) * (yMax - yMin) ;
  double Integral = nHit * Area / static_cast<double> (N) ;
  double p        = nHit / static_cast<double> (N) ;
  double Var      = Area * Area / static_cast<double> (N) * p * (1. - p) ;
  double StdDev   = sqrt (Var) ;
  
  std::cout << "Integral = " << Integral
            << " +/- "       << StdDev << std::endl ;
  return 0 ;
}
