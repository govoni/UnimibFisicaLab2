/*
c++ -o esercizio06 esercizio06.cpp

Esercizio: scrivere un programma che, dato un array di n interi,
           lo ordini dal piu` piccolo al piu` grande

L'algoritmo qui riportato e` chiamato "bubble sort", ed ha una
complessita` media, o equivalentemente un tempo di esecuzione
medio, che scala come O(n^2). Un algoritmo che ha complessita`
media inferiore, O(n*log(n)), e` per esempio il "quick sort"
*/

#include <iostream>

#define DIM 10

void SortArray(double* myArray, int dim)
{
  bool flag = true;
  
  for (int i = 1; (i < dim && flag == true); i++)
    {
      flag = false;
            
      for (int j = 0; j < (dim - i); j++)
      	{
      	  if (myArray[j+1] < myArray[j])
      	    { 
      	      int temp     = myArray[j];
      	      myArray[j]   = myArray[j+1];
      	      myArray[j+1] = temp;

      	      flag = true;
      	    }
      	}
    }
}

int main (int argc, char** argv)
{
  double* data = new double[DIM];
  
  std::cout << "Un-sorted values: " << std::endl;
  for (int i = 0; i < DIM; i++)
    {
      data[i] = DIM-i;
      std::cout << "Val " << i << " = " << data[i] << std::endl;
    }

  SortArray(data, DIM);
  std::cout << "\nSorted values: " << std::endl;
  for (int i = 0; i < DIM; i++)
    {
      std::cout << "Val " << i << " = " << data[i] << std::endl;
    }
 
  delete[] data;  
  return 0;
}
