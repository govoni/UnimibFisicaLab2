/*
c++ -o main_00 main_00.cpp
*/

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <fstream>

#include "generazione.h"

using namespace std ;

// retta con termine noto non nullo
double g (double x)
  {
     return 3.14 + 2 * x ;
  }


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----


int main (int argc, char ** argv)
  {
    if (argc < 3)
      {
        cout << "usage: " << argv[0] << " sigma_y nomefile.txt [Npoints = 5]" << endl ;
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
