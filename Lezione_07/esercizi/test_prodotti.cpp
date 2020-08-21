/*
c++ -o test_prodotti test_prodotti.cpp
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
        if (i == j) M1.setCoord (i, j, i + 1) ;
        else        M1.setCoord (i, j, 0.) ;

    vettore<C> v ;
    v.setCoord (1, 1.) ; 

    vettore<R> w = M1 * v ;

    for (int i = 0 ; i < R ; ++i)
      {
        std::cout << w.at (i) << "\t" ;
      }
    std::cout << "\n" ;

    // ---- ---- ---- 

    // rotazione di pi/3
    matrice<2,2> R1 ;
    R1.setCoord (0, 0, 0.5) ;
    R1.setCoord (0, 1, -0.866) ;
    R1.setCoord (1, 0, 0.866) ;
    R1.setCoord (1, 1, 0.5) ;
    // anti-rotazione di pi/3
    matrice<2,2> R2 ;
    R2.setCoord (0, 0, 0.5) ;
    R2.setCoord (0, 1, 0.866) ;
    R2.setCoord (1, 0, -0.866) ;
    R2.setCoord (1, 1, 0.5) ;

    matrice<2,2> R3 = R1 * R2 ;
    R3.stampa () ;
    std::cout << R3.simmetrica () << std::endl ;

    return 0 ;
  }
