/*
c++ -o esercizio02 esercizio02.cpp

Esercizio: dichiarare un puntatore e poi cercare di assegnargli direttamente
           un valore numerico. Cosa succede? Perchè?
*/

#include <iostream>

int main()
{
  int* pointer;
  
  pointer = 5;
  std::cout << "Valore scritto in pointer: " << pointer << std::endl;

  return 0;
}
