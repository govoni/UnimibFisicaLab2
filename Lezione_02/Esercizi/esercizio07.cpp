/*
c++ -o esercizio07 esercizio07.cpp

Esercizio: riscrivere la creaVettore senza fare uso dell'istruzione return
*/

#include <iostream>


// ##########################
// # Solution with pointers #
// ##########################
void creaVettore (int dim, int** array)
{
  *array = new int[dim];
}


// ############################
// # Solution with references #
// ############################
// void creaVettore (int dim, int*& array)
// {
//   array = new int[dim];
// }


int main()
{
  int dim = 0;
  std::cout << "Insert the dimension of the array: ";
  std::cin >> dim;

  if (dim < 0)
  {
    std::cout << "Negative number: " << dim << std::endl;
    return -1;
  }

  
  // ###################################
  // # Dynamic allocation of the array #
  // ###################################
  int* vec;

  
  // ##########################
  // # Solution with pointers #
  // ##########################
  creaVettore(dim,&vec);

  
  // ############################
  // # Solution with references #
  // ############################
  // creaVettore(dim,vec);

  
  // Fill the array
  for (int i = 0; i < dim; i++)
    {
      vec[i] = i+1;
    }

  // Print the elements of the array
  for (int i = 0; i < dim; i++)
    {
      std::cout << "Content of the cell " << i << " : " << vec[i] << std::endl;
    }

  delete[] vec;

  return 0;
}
