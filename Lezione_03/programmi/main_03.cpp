/*
c++ -o main_03 `root-config --glibs --cflags` main_03.cpp
*/

#include <cstdlib>
#include <iostream>

#include "TH1F.h"

float rand_range (float min, float max)
  {
    return min + (max - min) * rand () / static_cast<float> (RAND_MAX) ;
  } 


int main (int argc, char ** argv)
  {
    if (argc < 2)
      {
        std::cerr << "uso del programma: " << argv[0] << " numero_eventi" << std::endl ;
      }
    int Nmax = atoi (argv[1]) ;

    TH1F h_uniforme ("h_uniforme", "distribuzione uniforme", 50, -5., 5.) ;

    for (int i = 0 ; i < Nmax ; ++i)
      h_uniforme.Fill (rand_range (-4., 4.)) ;

    return 0 ;
  }
