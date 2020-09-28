/*
c++ -o esercizio03 esercizio03.cpp

Esercizio: utilizzare new e delete per creare e distruggere
           una variabile double ed un array di double
*/

#include <iostream>

int main()
{
  double* valore = new double(1.5);
  std::cout << "Valore creato con la new: " << *valore << std::endl;
  delete valore;

  int dim = 5;
  double* array = new double[dim];
  for (int i = 0; i < dim; i++)
    {
      array[i] = 2.2 * i;
      std::cout << "Valore [" << i << "] dell'array creato con la new: "
		<< array[i] << std::endl;
    }
  delete [] array;
  
  return 0;
}
