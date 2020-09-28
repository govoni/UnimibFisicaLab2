/*
c++ -o esercizio04 esercizio04.cpp

Esercizio: scrivere un programma che richieda all'utente di inserire un numero
           intero e che sappia riconoscere se il numero e` pari o dispari (utilizzare
           l'operatore %, implementando due funzioni che stampino a schermo messaggi
           diversi nei due casi)
*/

#include <iostream>

// Dichiarazione dei prototipi delle funzioni
void dispari (int a);
void pari    (int a);

int main ()
{
  int i = 0;
  do
    {
      std::cout << "Scrivi un numero (digitare un numero negativo per uscire) : ";
      std::cin >> i;
      if (i%2 == 0) pari(i);
      else dispari(i);
    }
    while (i > 0);
  return 0;
}

// Definizione delle funzioni
void dispari (int a)
{
  std::cout << "Il numero e` dispari" << std::endl;
}

void pari (int a)
{
  std::cout << "Il numero e` pari" << std::endl;
}
