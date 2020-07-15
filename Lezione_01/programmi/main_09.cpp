/*
c++ -o main_09 main_09.cpp
*/

#include <iostream>

int main (int argc, char ** argv)
  {
    float R1 = 5. ;
    float R2 = 5. ;
    float R3 = R1 + R2 ;
    std::cout << R3 << std::endl ;
    R3 = R3 + 4.5 ;
    std::cout << R3 << std::endl ;
    R3 += 2.1 ;
    std::cout << R3 << std::endl ;
    return 0 ;
  }

