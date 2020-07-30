/*
c++ -o main_04 main_04.cpp
*/

#include <iostream>

template <typename T1, typename T2>
T2 somma (T1 a, T2 b)
  {
    return a + b ;
  }


int main (int argc, char ** argv)
  {
    int i_a = 1 ;
    double d_b = 2.1 ;

    std::cout << "somma di interi " << somma (i_a, d_b) << std::endl ;

    return 0 ;
  }
