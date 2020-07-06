/*
c++ -o main_19 main_19.cpp
*/

#include <iostream>

#define quadrato(a) a*a

int main (int argc, char ** argv)
  {
  
    double numero = 3. ;
    double risposta = quadrato (numero + 1.) ;
  
    std::cout << "Il quadrato di " << numero + 1. 
              << " vale " << risposta << "\n" ;
    return 0 ;
  }

