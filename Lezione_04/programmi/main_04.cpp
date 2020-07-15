/*
c++ -o main_04 main_04.cpp
*/

#include <cstdlib>
#include <iostream>
#include <cmath>

float fgaus (float x) 
  {
    return exp (-0.5 * x * x) ; 
  }

float rand_range (float min, float max)
  {
    return min + (max - min) * rand () / static_cast<float> (RAND_MAX) ;
  } 

float rand_TAC (float f (float), float xMin, float xMax, float yMax)
  {
    double x = 0. ;
    double y = 0. ; 
    do {
      x = rand_range (xMin, xMax) ;
      y = rand_range (0, yMax) ;
    } while (y > f (x)) ;
    return x ; 
  }

int main (int argc, char ** argv)
  {
    for (int i = 0 ; i < 5 ; ++i)
      std::cout << "indice " << i << " --> " << rand_TAC (fgaus, -1., 1., 1.) << "\n" ;

    return 0 ;
  }
