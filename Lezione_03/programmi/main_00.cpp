/*
c++ -o main_00 main_00.cpp
*/

#include <cstdlib>
#include <iostream>

int main (int arcg, char ** argv)
  {

    for (int i = 0 ; i < 5 ; ++i)
      std::cout << "indice " << i << " --> " << rand () << "\n" ;

    std::cout << "\nRAND_MAX: " << RAND_MAX << std::endl ;

    return 0 ;
  }
