/*
c++ -o main_07 main_07.cpp
*/

#include <iostream>

int main (int argc, char ** argv)
  {
    int numero_intero = 4 ;
    float numero_razionale = (float) numero_intero ;

    float secondo_razionale = static_cast<float> (numero_intero) ;

    return 0 ;
  }

