/*
c++ -o esercizio06 esercizio06.cpp

Esercizio: scrivere una funzione che calcoli in maniera
           ricorsiva il fattoriale di un numero intero
           non negativo
*/

#include <iostream>

int fact_rec (int n)
{
  if (n == 0) return 1;
  return (n * fact_rec(n-1));
}

int main()
{
  int num;
  
  std::cout << "Inserisci un numero intero: ";
  std::cin >> num;
  
  std::cout << "Il numero inserito e`: " << num << std::endl;
  
  // Il fattoriale non e` definito per numeri negativi
  if (num < 0)
    {
      std::cout << "Numero negativo" << std::endl;
      return -1;
    }
  
  std::cout << "Il fattoriale del valore inserito e`: "
	    << fact_rec(num) << std::endl;
  
  return 0;
}
