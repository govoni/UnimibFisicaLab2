/*
c++ -o main_01 main_01.cpp
*/

#include <iostream>
#include "forme.h"

using namespace std ;

int main (int argc, char ** argv)
{
  quadrato forma_quadrata (3.) ;
  forma * puntatore = & forma_quadrata ;
   
  return 0 ;
}
