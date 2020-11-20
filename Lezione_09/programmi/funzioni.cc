#include "funzioni.h"
#include <cmath>
#include <iostream>

using namespace std ;

double esponenziale (double x, double tau)
{
   if (tau == 0.) return 1. ;
   return exp (-1. * x / tau) / tau ;
}


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 


double loglikelihood (
  const vector<double> & data, 
  double param
)
{
  double result = 0. ; 
  for (int i = 0 ; i < data.size () ; ++i) result += log (esponenziale (data.at (i), param)) ;
  return result ;   
}

// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 


double loglikelihoodprod (
  const vector<double> & data, 
  double param
)
{
  double result = 1. ; 
  for (int i = 0 ; i < data.size () ; ++i) result *= esponenziale (data.at (i), param) ;
  return log(result) ;   
}


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
  

double sezione_aurea_max (
  double logl (const vector<double> & , double),
  double xMin,
  double xMax,
  const vector<double> & data,
  double precision
)
{
  double x_2 = xMin ;
  double x_3 = xMax ;
  while ((xMax - xMin) > precision)
    {
      x_2 = xMin + (xMax - xMin) * 0.618 ;
      x_3 = xMin + (xMax - xMin) * 0.382 ;

      if (logl (data, x_3) < logl (data, x_2)) xMin = x_3 ;
      else                                     xMax = x_2 ;
    }
  return 0.5 * (xMax + xMin) ;
}


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 


double h (
  const vector<double> & data, 
  double param,
  double max
)
{
  return loglikelihood (data, param) + 0.5 - loglikelihood (data, max) ;   
}


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
  

double bisezione (
  double h (const vector<double> & , double, double),
  double xMin,
  double xMax,
  const vector<double> & data,
  double massimo,
  double precision
)
{
  double xAve = xMin ;
  while ((xMax - xMin) > precision)
    {
      xAve = 0.5 * (xMax + xMin) ;
      if (h (data, xAve, massimo) * h (data, xMin, massimo) > 0.) xMin = xAve ;
      else                                                        xMax = xAve ;
    }
  return xAve ;
}


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
  

double rand_range (double min, double max)
{
  return min + (max - min) * rand () / RAND_MAX ;
}


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
  

// generazione numeri casuali con il metodo dell'inversa della funzione cumulativa
double rand_IFC_Exp (double mu)
{
  double y = rand_range (0., 1.) ;
  double x = -mu * log (1 - y) ;
  return x ;
}
