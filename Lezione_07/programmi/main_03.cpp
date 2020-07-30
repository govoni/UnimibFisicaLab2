/*
c++ -o main_03 main_03.cpp
*/

#include <iostream>
#include "simpleArray.h"

int main (int argc, char ** argv)
  {
    SimpleArray<int> contenitore (atoi (argv[1])) ;
    for (int i = 0 ; i < atoi (argv[1]) ; ++i)
      {
        contenitore[i] = 2 * i ;
      }

    for (int i = 0 ; i < atoi (argv[1]) ; ++i)
      {
        std::cout << i << "\t" << contenitore[i] << "\n" ;
      }

    return 0 ;
  }
