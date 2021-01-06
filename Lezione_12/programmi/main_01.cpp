/*
c++ -o main_01 main_01.cpp

 ./main_01 dati.txt   10000 1.  0.8  2. 0.15  0.62     
 ./main_01 dati_2.txt 10000 2.2 0.25 2. 0.75  0.62
 ./main_01 dati_3.txt 10000 2.4 0.7  2. 0.75  0.62

negli esempi: dati.txt = H1
              dati_3.txt = H0

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

  if (argc < 8)
    {
      cerr << "uso: " << argv[0] << " nomeFile numero_di_eventi media_x sigma_x media_y sigma_y angolo" << endl ;
      cerr << "ad esempio:\n " 
           << argv[0] << " dati.txt 10000 1 0.8 2 0.15 0.62" << endl ;
      exit (1) ;
    }

  int numeroMax = atoi (argv[2]) ;

  // parametri delle gaussiane nel sistema di riferimento
  // dove le variabili sono scorrelate
  double media_x = atof (argv[3]) ;
  double sigma_x = atof (argv[4]) ;
  double media_y = atof (argv[5]) ;
  double sigma_y = atof (argv[6]) ;

  // angolo di rotazione per il cambio del sistema di riferimento
  double theta = atof (argv[7]) ;
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
