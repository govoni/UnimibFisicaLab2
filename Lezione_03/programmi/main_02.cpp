/*
c++ -o main_02 main_02.cpp
*/

#include <cstdlib>
#include <iostream>

float rand_range (float min, float max)
  {
    return min + (max - min) * rand () / static_cast<float> (RAND_MAX) ;
  } 


int main (int arcg, char ** argv)
  {
    for (int i = 0 ; i < 5 ; ++i)
      std::cout << "indice " << i << " --> " << rand () << "\n" ;

    std::cout << "\n" ;

    return 0 ;
  }
