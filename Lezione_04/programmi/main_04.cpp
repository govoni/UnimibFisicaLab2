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

float rand_TCL (float xMin, float xMax, int N = 10)
  {
    double y = 0. ; 
    for (int i = 0 ; i < N ; ++i)
      y += rand_range (xMin, xMax) ;
    y /= N ;
    return y ;
  }

int main (int argc, char ** argv)
  {
    for (int i = 0 ; i < 5 ; ++i)
      std::cout << "indice " << i << " --> " << rand_TCL (-1., 1., 10) << "\n" ;

    return 0 ;
  }
