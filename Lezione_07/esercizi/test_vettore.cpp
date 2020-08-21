/*
c++ -o test_vettore test_vettore.cpp
*/

#include <iostream>

#include "algebra.h"

int main (int argc, char ** argv)
  {
    vettore<2> v1 ;
    v1.setCoord (0, 3.) ;
    v1.setCoord (1, 4.) ;

    std::cout << v1.norm () << std::endl ;
    std::cout << v1.at (0) << std::endl ;
    std::cout << v1.at (-1) << std::endl ;
    std::cout << v1.at (1) << std::endl ;
    std::cout << v1.at (2) << std::endl ;

    vettore<2> v2 (v1) ;

    std::cout << v2.at (0) << std::endl ;
    std::cout << v2.at (1) << std::endl ;

    vettore<2> v3 = v1 ;

    std::cout << v3.at (0) << std::endl ;
    std::cout << v3.at (1) << std::endl ;

    return 0 ;
  }
