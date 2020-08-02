/*
c++ -o main_00 main_00.cpp
*/

#include <iostream>
#include "forme.h"

using namespace std ;

int main (int argc, char ** argv)
{
  forma forma_base ;
  cout << "area: " << forma_base.area () << endl ;

  quadrato forma_quadrata (3.) ;
  cout << "area: " << forma_quadrata.area () << endl ;
  cout << "lato: " << forma_quadrata.lato () << endl ;
  forma_quadrata.cambia_lato (4.) ;
  cout << "area: " << forma_quadrata.area () << endl ;

   
  rettangolo forma_rettangolare (2., 3.) ;
  cout << "area: " << forma_rettangolare.area () << endl ;
   
  return 0 ;
}
