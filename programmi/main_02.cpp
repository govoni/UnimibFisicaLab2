/*
c++ -o main_02 main_02.cpp
*/

#include <iostream>

int main (int arcg, char ** argv)
  {
    std::cout << "42" << std::endl ;
    std::cout << "ecco il nome dell'eseguibile: " << argv[0] << std::endl ;
    return 0 ;
  }
