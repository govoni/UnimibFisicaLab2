/*
c++ -o main_01 main_01.cpp
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std ;

// sqrt (2*pi) = 2.5066282746 
float fgaus (float x, double mean, double sigma) 
  {
    if (sigma == 0.) 
      {
        cerr << "la sigma di una gaussiana non puo' essere nulla" << endl ;
        exit (1) ;
      }
    return exp (-0.5 * (x - mean) * (x - mean) / (sigma * sigma)) / (2.5066 * sigma) ; 
  }


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----


float rand_range (float min, float max)
  {
    return min + (max - min) * rand () / static_cast<float> (RAND_MAX) ;
  } 


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----


float rand_TAC_gaus (float media, float sigma)
  {
    double xMin = media - 3 * sigma ;
    double xMax = media + 3 * sigma ;
    double yMax = 1. / (2.5066 * sigma) ;

    double x = 0. ;
    double y = 0. ; 
    do {
      x = rand_range (xMin, xMax) ;
      y = rand_range (0, yMax) ;
    } while (y > fgaus (x, media, sigma)) ;
    return x ; 
  }


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----


int main (int argc, char ** argv)
{

  if (argc < 2)
    {
      cerr << "uso: " << argv[0] << " nomeFile [numero_di_eventi]" << endl ;
      exit (1) ;
    }

  int numeroMax = 10 ;
  if (argc > 2) numeroMax = atoi (argv[2]) ;

  // parametri delle gaussiane nel sistema di riferimento
  // dove le variabili sono scorrelate
  double media_x = 1. ;
  double sigma_x = 0.8 ;
  double media_y = 2. ;
  double sigma_y = 0.15 ;

  // angolo di rotazione per il cambio del sistema di riferimento
  double theta = M_PI / 5. ;
  double c_theta = cos (theta) ;
  double s_theta = sin (theta) ;

  ofstream output_file ;
  output_file.open (argv[1], ios::out) ;

  if (!output_file.is_open ()) return 1 ;
  
  double x = 0. ;
  double y = 0. ;
  for (int i = 0 ; i < numeroMax ; ++i)
    {
      x = rand_TAC_gaus (media_x, sigma_x) ;
      y = rand_TAC_gaus (media_y, sigma_y) ;

      output_file << x * c_theta + y * s_theta
                  << " " 
                  << y * c_theta - x * s_theta
                  << "\n" ;
    }  

  output_file.close () ;

  cout << "scritti " << numeroMax << " eventi" << endl ;

  return 0 ;
}
