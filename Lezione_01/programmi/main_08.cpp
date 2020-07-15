/*
c++ -o main_08 main_08.cpp
*/

#include <iostream>

int main (int argc, char ** argv)
  {
    int numero = 5 ;

    numero = 6 ;

    std::cout << (numero = 7) << std::endl ;
    int numero_due = numero = 8 ;
    std::cout << numero_due << std::endl ;

    return 0 ;
  }

