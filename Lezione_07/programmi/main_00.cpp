/*
c++ -o main_00 main_00.cpp
*/

#include <iostream>

int somma (int a, int b)
  {
    return a + b ;
  }

double somma (double a, double b)
  {
    return a + b ;
  }

int main (int argc, char ** argv)
  {
    int i_a = 1 ;
    int i_b = 2 ;
    double d_a = 5. ;
    double d_b = 7. ;

    std::cout << "somma di interi    " << somma (i_a, i_b) << std::endl ;
    std::cout << "somma di razionali " << somma (d_a, d_b) << std::endl ;

    return 0 ;
  }
