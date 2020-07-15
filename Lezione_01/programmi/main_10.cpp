/*
c++ -o main_10 main_10.cpp
*/

#include <iostream>

int main (int argc, char ** argv)
  {
    int num = 5 ;
    ++num ;
    std::cout << num << std::endl ;
    --num ;
    std::cout << num << std::endl ;

    std::cout << "--------" << std::endl ;

    int num1 = 5 ;
    std::cout << ++num1 << std::endl ;
    int num2 = 5 ;
    std::cout << num2++ << std::endl ;
    std::cout << num2 << std::endl ;


    std::cout << "--------" << std::endl ;

    int num3 = 5 ;
    std::cout << --num3 << std::endl ;
    int num4 = 5 ;
    std::cout << num4-- << std::endl ;
    std::cout << num4 << std::endl ;

    return 0 ;
  }

