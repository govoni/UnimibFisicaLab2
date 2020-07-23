/*
c++ -o main_07 main_07.cpp
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
    stats statistiche ;

    int i = 0 ;
    while (i++ < 1000) statistiche.addEvent (rand_range (-3., 3.)) ;

    std::cout << "media               : " << statistiche.getMean () << std::endl ;
    std::cout << "sigma               : " << statistiche.getSigma () << std::endl ;
    std::cout << "sigma (corr)        : " << statistiche.getSigma (true) << std::endl ;
    std::cout << "dev st. mean        : " << statistiche.getSigmaMean () << std::endl ;
    std::cout << "dev st. mean (corr) : " << statistiche.getSigmaMean (true) << std::endl ;

    return 0 ;
  }
