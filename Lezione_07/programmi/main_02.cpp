/*
c++ -o main_02 main_02.cpp
*/

#include <iostream>
#include "somma.h"

int main (int argc, char ** argv)
  {
    int i_a = 1 ;
    int i_b = 2 ;

    std::cout << "somma di interi " << somma (i_a, i_b) << std::endl ;

    return 0 ;
  }
