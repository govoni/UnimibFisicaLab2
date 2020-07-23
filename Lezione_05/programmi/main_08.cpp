/*
c++ -o main_08 main_08.cpp
*/

#include <cstdlib>
#include <iostream>
#include "stats.h"

float rand_range (float min, float max)
  {
    return min + (max - min) * rand () / static_cast<float> (RAND_MAX) ;
  } 


int main (int argc, char ** argv)
  {
    if (argc < 2) 
      {
        std::cerr << "uso del programma: " << argv[0] << " NMAX" << std::endl ;
        return 1 ;
      }

    int NMAX = atoi (argv[1]) ;
    stats statistiche ;

    for (int N = 1 ; N < NMAX ; N = N * 2)
      {
        int i = 0 ;
        while (i++ < N) statistiche.addEvent (rand_range (-3., 3.)) ;
        std::cout << N 
                  << "\t" << statistiche.getMean () 
                  << "\t" << statistiche.getSigma ()
                  << "\t" << statistiche.getSigmaMean () << "\n" ;
        statistiche.reset () ;
      }

    return 0 ;
  }
