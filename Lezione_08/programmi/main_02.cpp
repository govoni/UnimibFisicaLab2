/*
c++ -o main_02 main_02.cpp
*/

#include <iostream>
#include "forme_polim.h"

using namespace std ;

int main (int argc, char ** argv)
{
  quadrato forma_quadrata (3.) ;
  forma * puntatore = & forma_quadrata ;
   
  cout << "area " << puntatore->calcola_area () << endl ;

  return 0 ;
}
