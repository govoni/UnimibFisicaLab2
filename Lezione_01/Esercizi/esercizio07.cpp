/*
c++ -o esercizio07 esercizio07.cpp

Esercizio: scrivere un programma per calcolare la media aritmetica di una serie di
           numeri inseriti da tastiera. L'introduzione di un valore particolare
           pari a "0" indica il termine del caricamento dei dati
*/

#include <iostream>

#define N_ENTRIES 10

double Media (float array[], int N)
{
  double somma = 0.;
  for (int i = 0; i < N; i++)
    {
      somma += array[i];
    }
  return somma/N;
}

double Varianza (float array[], int N)
{
  double somma  = 0.;
  double somma2 = 0.;
  for (int i = 0; i < N; i++)
    {
      somma += array[i];
      somma2 += array[i]*array[i];
    }
  double media = somma/N;
  double var   = somma2/N - media * media;
  var *= N/(N-1);
  return var;
}

int main()
{
  float numeri[N_ENTRIES];
  float num;
	
  std::cout << "Inserisci " << N_ENTRIES << " numeri a caso:" << std::endl;
		
  for (int i = 0; i < N_ENTRIES; i++)
    {
      std::cout << "Numero " << i+1 << " = ";
      std::cin >> num;
      numeri[i] = num;
    }

  double media    = Media (numeri,N_ENTRIES);
  double varianza = Varianza (numeri,N_ENTRIES);

  std::cout << "\nLa media e` "<< media << std::endl;
  std::cout << "La varianza (un-biased) e` " << varianza << std::endl;

  return 0;
}
