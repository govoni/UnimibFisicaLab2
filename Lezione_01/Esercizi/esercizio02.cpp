/*
c++ -o esercizio02 esercizio02.cpp

Esercizio: scrivere un programma che scrive a terminale
           la radice quadrata di 2, il cubo di 2 il seno di pigreco/4
*/

#include <iostream>
#include <cmath>

// La libreria cmath contiene, tra le altre cose, le funzioni per eseguire radice quadrata, elevamento a potenza e calcoli trigonometrici

int main ()
{
  double due = 2;
  double radice_due = sqrt(due);
  std::cout << "La radice quadrata di due e` : " << radice_due << std::endl;
  
  double due_al_cubo = pow(2., 3);
  std::cout << "Il cubo di 2 e` : " << due_al_cubo << std::endl;
  
  double sin_45 = sin(M_PI/4.);
  std::cout << "Il seno di pi/4 e` :  " << sin_45  << std::endl;
  
  return 0;
}
