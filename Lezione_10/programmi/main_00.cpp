/*
c++ -o main_00 main_00.cpp
*/

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std ;

// media sempre zero
// non normalizzata, cosi' il massimo in zero vale sempre 1
double fgaus (double x, double sigma) 
  {
    return exp (-0.5 * x * x / (sigma * sigma)) ; 
  }


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----


double rand_range (double min, double max)
  {
    return min + (max - min) * rand () / static_cast<double> (RAND_MAX) ;
  } 


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----


double rand_TAC_gaus (double sigma)
  {
    double x = 0. ;
    double y = 0. ; 
    do {
      x = rand_range (-5 * sigma, 5 * sigma) ;
      y = rand_range (0, 1.) ;
    } while (y > fgaus (x, sigma)) ;
    return x ; 
  }


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----


// retta con termine noto non nullo
double g (double x)
  {
     return 2 * x + 3.14 ;
  }


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----


int main (int argc, char ** argv)
  {
    if (argc < 3)
      {
        cout << "usage: " << argv[0] << " incertezza_y nomefile.txt [Npoints = 5]" << endl ;
        exit (1) ;
      }
    double sigma = fabs (atof (argv[1])) ;

    ofstream output_file ;
    output_file.open (argv[2]) ;

    int Npoints = 5 ; 
    if (argc > 3) Npoints = atoi (argv[3]) ;
    for (int i = 0 ; i < Npoints ; ++i)
      {
        double epsilon = rand_TAC_gaus (sigma) ; 
        output_file << i << " " << g (i) + epsilon << "\n" ;
      }

    output_file.close () ;

    return 0 ;
  }
