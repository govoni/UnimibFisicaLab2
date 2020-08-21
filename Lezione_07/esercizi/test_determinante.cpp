/*
c++ -o test_determinante test_determinante.cpp
*/

#include <iostream>

#include "algebra.h"

int main (int argc, char ** argv)
  {

    // rotazione di pi/3
    // matrice<2,2> R1 ;
    // R1.setCoord (0, 0, 0.5) ;
    // R1.setCoord (0, 1, -0.866) ;
    // R1.setCoord (1, 0, 0.866) ;
    // R1.setCoord (1, 1, 0.5) ;

    matrice<3,3> R1 ;
    R1.setCoord (0, 0, 0.5) ;
    R1.setCoord (0, 1, -0.866) ;
    R1.setCoord (0, 2, 0) ;
    R1.setCoord (1, 0, 0.866) ;
    R1.setCoord (1, 1, 0.5) ;
    R1.setCoord (1, 2, 0) ;
    R1.setCoord (2, 0, 0) ;
    R1.setCoord (2, 1, 0) ;
    R1.setCoord (2, 2, 1) ;
    R1.stampa () ;

    std::cout << "determinante: " << R1.determinante () << std::endl ;
    std::cout << "quadrata:     " << R1.quadrata () << std::endl ;
    std::cout << "simmetrica:   " << R1.simmetrica () << std::endl ;
    std::cout << "rango :       " << R1.rango () << std::endl ;
    std::cout << std::endl ;

    // anti-rotazione di pi/3
    matrice<3,3> R2 ;
    R2.setCoord (0, 0, 0.5) ;
    R2.setCoord (0, 1, 0.866) ;
    R2.setCoord (0, 2, 0) ;
    R2.setCoord (1, 0, -0.866) ;
    R2.setCoord (1, 1, 0.5) ;
    R2.setCoord (1, 2, 0) ;
    R2.setCoord (2, 0, 0) ;
    R2.setCoord (2, 1, 0) ;
    R2.setCoord (2, 2, 1) ;
    R2.stampa () ;

    R2.dimensioni () ;
    std::cout << "determinante: " << R2.determinante () << std::endl ;
    std::cout << std::endl ;

    matrice<3,3> R3 = R1 * R2 ;
    R3.stampa () ;

    std::cout << "determinante: " << R3.determinante () << std::endl ;

    return 0 ;
  }
