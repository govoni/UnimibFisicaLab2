#include "funzioni.h"
#include <cmath>
#include <iostream>

using namespace std ;

double esponenziale (double x, double tau)
  {
     if (tau == 0.) return 1. ;
//     cout << "EXP: " << x << "\t" << tau << " " << exp (-1. * x) << endl ;
     return exp (-1. * x / tau) / tau ;
  }


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 


double loglikelihood (
  const vector<double> & data, 
  double param
)
{
  // double result = 1. ; 
  // for (int i = 0 ; i < data.size () ; ++i) result *= esponenziale (data.at (i), param) ;
  // return log (result) ;   
  double result = 0. ; 
  for (int i = 0 ; i < data.size () ; ++i) result += log (esponenziale (data.at (i), param)) ;
  return result ;   
}


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
  

double bisezione (
  double g (double),
  double xMin,
  double xMax,
  double precision
)
{
  double xAve = xMin ;
  while ((xMax - xMin) > precision)
    {
      xAve = 0.5 * (xMax + xMin) ;
      if (g (xAve) * g (xMin) > 0.) xMin = xAve ;
      else                          xMax = xAve ;
    }
  return xAve ;
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

      // cout << xMin << "\t: " 
      //      << x_3  << "\t: " 
      //      << x_2  << "\t: " 
      //      << xMax << "\t: "       
      //      << endl ;  

      // cout << logl (data, xMin) << "\t: "  
      //      << logl (data, x_3)  << "\t: " 
      //      << logl (data, x_2)  << "\t: " 
      //      << logl (data, xMax) << "\t: "  
      //      << "\n    -------------" << endl ;  

      if (logl (data, x_3) < logl (data, x_2)) xMin = x_3 ;
      else                                     xMax = x_2 ;
    }
  return 0.5 * (xMax + xMin) ;
}