/*
c++ -o esercizio05 esercizio05.cpp

Esercizio: scrivere una funzione che calcoli il
           fattoriale di un numero intero non negativo
*/

#include <iostream>

int fact_val (int n)
{
  if (n == 0 || n == 1) return 1;

  int fattoriale = 1;
  for(int i = 1; i <= n; i++)
    {
      fattoriale *= i;
    }
  
  return fattoriale;
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
	    << fact_val(num) << std::endl;
  
  return 0;
}
