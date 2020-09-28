/*
c++ -o esercizio03 esercizio03.cpp
 
Esercizio: scrivere un programma che chieda all'utente di inserire un intero a scelta
           tra 1 e 2, e restituisca a terminale il valore inserito, o un messaggio di
           errore in caso di inserimento di altri interi
*/

#include <iostream>

int main ()
{
  // Legge un numero intero e stampo il suo valore in lettere usando uno switch
  int x;
  std::cout << "Digita un numero intero x a scelta tra 1 e 2: " << std::endl;
  std::cin >> x;
  if (x == 1)
    {
      std::cout << "x vale UNO" << std::endl;
    }
  else if (x == 2)
    {
      std::cout << "x vale DUE" << std::endl;
    }
  else
    {
      std::cout << "x non vale ne' UNO, ne' DUE" << std::endl;
    }
  
  return 0;
}
