/*
c++ -o main_07 main_07.cpp
*/

#include <cstdlib>
#include <iostream>
#include "statistiche.h"

float rand_range (float min, float max)
  {
    return min + (max - min) * rand () / static_cast<float> (RAND_MAX) ;
  } 


int main (int argc, char ** argv)
  {
    statistiche s_eventi ;

    int i = 0 ;
    while (i++ < 1000) s_eventi.addEvent (rand_range (-3., 3.)) ;

    std::cout << "media               : " << s_eventi.getMean () << std::endl ;
    std::cout << "sigma               : " << s_eventi.getSigma () << std::endl ;
    std::cout << "sigma (corr)        : " << s_eventi.getSigma (true) << std::endl ;
    std::cout << "dev st. mean        : " << s_eventi.getSigmaMean () << std::endl ;
    std::cout << "dev st. mean (corr) : " << s_eventi.getSigmaMean (true) << std::endl ;

    return 0 ;
  }
