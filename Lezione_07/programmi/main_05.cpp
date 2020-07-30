/*
c++ -o main_05 main_05.cpp
*/

#include <iostream>
#include "somma.h"

template<>
float somma (float a, float b)
  {
    std::cout << "SOMMA DI FLOAT" << std::endl ;
    return a + b ;
  }

int main (int argc, char ** argv)
  {
    int i_a = 1 ;
    int i_b = 2 ;
    double d_a = 1 ;
    double d_b = 2 ;
    float f_a = 1 ;
    float f_b = 2 ;

    std::cout << "somma di interi " << somma (i_a, i_b) << std::endl ;
    std::cout << "somma di double " << somma (d_a, d_b) << std::endl ;
    std::cout << "somma di float "  << somma (f_a, f_b) << std::endl ;

    return 0 ;
  }
