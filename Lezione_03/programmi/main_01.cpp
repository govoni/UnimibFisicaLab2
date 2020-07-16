/*
c++ -o main_01 complesso.cc main_01.cpp
*/

#include <iostream>

int main (int argc, char ** argv)
{
  const int C1 = 10 ;
  int const C1_1 = 10 ;
  const int * C2 ;
  int const * C2_2 ;
  int numero = 3 ;
  int * const C3 (& numero) ;
  int const * const C4 (& C1) ;

  return 0 ;
}