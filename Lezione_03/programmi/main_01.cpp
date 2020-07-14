/*
c++ -o main_01 main_01.cpp
*/

#include <cstdlib>
#include <iostream>
#include <ctime>

int main (int arcg, char ** argv)
  {
    srand (3) ;
    for (int i = 0 ; i < 5 ; ++i)
      std::cout << "indice " << i << " --> " << rand () << "\n" ;

    std::cout << "\n" ;

    srand (time (NULL)) ;
    for (int i = 0 ; i < 5 ; ++i)
      std::cout << "indice " << i << " --> " << rand () << "\n" ;

    return 0 ;
  }
