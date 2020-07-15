/*
c++ -o main_16 libreria.cc main_16.cpp
*/

#include <iostream>
#include "libreria.h"


int main (int argc, char ** argv)
  {
  
    for (int i = 0 ; i < 5 ; ++i)
      {
        std::cout << "il doppio di " << i << " vale: " << raddoppia (i) << std::endl ;
      }
    return 0 ;
  }



