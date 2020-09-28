/*
c++ -o esercizio05 esercizio05.cpp

Esercizio: rifare l’esercizio su media/varianza realizzando un'unica funzione
           che calcola entrambe (fare uso di puntatori/referenze)
*/

#include <iostream>

#define DIM 10

void DataAnalysis(double* data, int dim, double& mean, double& var)
{
  for (int i = 0; i < dim; i++)
    {
      mean += data[i];
      var  += data[i]*data[i];
    }
  
  mean = mean / dim;
  var = (var/dim - mean*mean) * dim / (dim-1);
}

int main (int argc, char** argv)
{

  int dim = DIM;
  double* data = new double[dim];
  double mean;
  double var;

  for (int i = 0; i < dim; i++)
    {
      data[i] = i;
    }

  DataAnalysis(data, dim, mean, var);
  std::cout << "Sample mean: " << mean << "\tSample variance: " << var << std::endl;
  
  delete[] data;
  
  return 0;
}
