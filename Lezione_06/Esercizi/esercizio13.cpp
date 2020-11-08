/*
Esercizio 13: Si implementi una funzione che calcola il fattoriale di un numero utilizzando una funzione ricorsiva.

c++ -o esercizio13 esercizio13.cpp
*/

#include <iostream>
#include <cmath>

int fattoriale (int n)
{
  if (n == 0) return 1;
  return (n * fattoriale(n-1));
}

//----------------- MAIN -----------------
int main()
{
  int num = 6;
    
  if (num < 0)
    {
      std::cout << "Numero negativo,il fattoriale non è definito" << std::endl;
      return -1;
    }
  
  std::cout << "Il fattoriale  e`: " << fattoriale (num) << std::endl;
  
  return 0;

}
