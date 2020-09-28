/*
c++ -o esercizio04 esercizio04.cpp

Esercizio: realizzare una funzione che risolve un’equazione di secondo grado: ax2 + bx + c = 0
*/

#include <iostream>
#include <cmath>

bool solve2ndDegree(double* par, double* x)
// equation: ax^2 + bx + c
// par[0] = a
// par[1] = b
// par[2] = c
// x[0] = x_low
// x[1] = x_high
// if determinant < 0: return false
//               else: return true
{
  double a = par[0];
  double b = par[1];
  double c = par[2];

  double det = b*b - 4.*a*c;
  if (det < 0)
    {
      std::cout << "Negative determinant: " << det << std::endl;
      return false;
    }
  
  double x_low  = (-b - sqrt(det)) / (2.*a);
  double x_high = (-b + sqrt(det)) / (2.*a);
  x[0] = x_low;
  x[1] = x_high;
  
  return true;
}

int main (int argc, char** argv)
{

  double par[3];
  double x[2];
  par[0] = 1;
  par[1] = 2;
  par[2] = 3;
  
  bool solved = solve2ndDegree(par,x);
  
  if (solved == true)
    std::cout << "Equation solved. x1 = " << x[0] << " x2 = " << x[1] << std::endl;
  else
    std::cout << "Equation not solved" << std::endl;
  
  return 0;
}
