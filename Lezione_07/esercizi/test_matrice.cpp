/*
c++ -o test_matrice test_matrice.cpp
*/

#include <iostream>

#include "algebra.h"

int main (int argc, char ** argv)
  {
    const int R = 3 ;
    const int C = 4 ;
    matrice<R,C> M1 ;

    for (int i = 0 ; i < R ; ++i)
      for (int j = 0 ; j < C ; ++j)
        M1.setCoord (i, j, 1.) ;

    M1.stampa () ;
    std::cout << "\n" ;

    std::cout << M1.simmetrica () << std::endl ;
        
    return 0 ;
  }
