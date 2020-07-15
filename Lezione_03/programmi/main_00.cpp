/*
c++ -o main_00 complesso.cc main_00.cpp
*/

#include <iostream>
#include <cmath>
#include "complesso.h"

int main (int argc, char ** argv)
{
  complesso numero_complesso_1 (0., 0.) ;
  complesso numero_complesso_2 (3., 4.) ;

  std::cout << numero_complesso_1.modulo () << std::endl ;
  std::cout << numero_complesso_2.modulo () << std::endl ;

  complesso numero_complesso_3 (numero_complesso_2) ;

  return 0 ;
}