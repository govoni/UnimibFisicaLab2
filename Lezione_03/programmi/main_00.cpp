/*
c++ -o main_00 complesso.cc main_00.cpp
*/

#include <iostream>
#include <cmath>
#include "complesso.h"

int main (int argc, char ** argv)
{
  // test del constructor
  complesso numero_complesso_1 (0., 0.) ;
  complesso numero_complesso_2 (3., 4.) ;

  std::cout << numero_complesso_1.modulo () << std::endl ;
  std::cout << numero_complesso_2.modulo () << std::endl ;

  // test del copy constructor
  complesso numero_complesso_3 (numero_complesso_2) ;

  // test dell'operator+
  complesso numero_complesso_4 = numero_complesso_3 + numero_complesso_2 ;
//  complesso numero_complesso_4 = numero_complesso_3.operator+ (numero_complesso_2) ;
  numero_complesso_4.stampami () ;

  // test dell'operator=
  complesso numero_complesso_5 = numero_complesso_4 + 5. ;
  numero_complesso_5.stampami () ;

  complesso numero_complesso_6 = numero_complesso_5 = numero_complesso_2 ;
  numero_complesso_5.stampami () ;
  numero_complesso_6.stampami () ;

  return 0 ;
}