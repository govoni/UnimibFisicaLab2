/*
c++ -o main_12 main_12.cpp
*/

#include <iostream>

int main (int argc, char ** argv)
  {
    bool A = true ;
    bool B = false ;

    std::cout << "A and B: " << (A && B) << std::endl ;
    std::cout << "A or B : " << (A || B) << std::endl ;
    std::cout << "not A  : " << (!A) << std::endl ;

    return 0 ;

  }

