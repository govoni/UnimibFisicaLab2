/*
c++ -o main_01 algebra_2.cc main_01.cpp
*/

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

#include "algebra_2.h"

using namespace std ;


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----


int main (int argc, char ** argv)
  {
    if (argc < 2)
      {
        cout << "usage: " << argv[0] << " nomefile.txt [Npoints = tutti]" << endl ;
        exit (1) ;
      }

    // lettura del file di input
    // -------------------------

    ifstream input_file ;
    input_file.open (argv[1]) ;
    vector<double> asse_x ;
    vector<double> asse_y ;
    while (true) 
      {
        double dummy_x = 0. ; 
        double dummy_y = 0. ; 
        input_file >> dummy_x ;
        input_file >> dummy_y ;
        if (input_file.eof () == true) break ;
        asse_x.push_back (dummy_x) ;
        asse_y.push_back (dummy_y) ;
      } 
    input_file.close () ;

    int Npoints = asse_x.size () ; 
    if (argc > 2) Npoints = atoi (argv[2]) ;

    // creazione delle matrici del metodo dei minimi quadrati
    // -------------------------

    matrice H (Npoints, 2) ;
    for (int i = 0 ; i < Npoints ; ++i)
      {
        H.setCoord (i, 0, 1) ;
        H.setCoord (i, 1, asse_x.at (i)) ;
      }
    vettore y (Npoints) ;
    for (int i = 0 ; i < Npoints ; ++i) y.setCoord (i, asse_y.at (i)) ;

    // ipotesi: incertezza costante su tutti i valori
    matrice V (Npoints) ;
    for (int i = 0 ; i < Npoints ; ++i) V.setCoord (i, i, 1.) ;

    matrice blocco = (H.trasposta () * (V * H)).inversa () * (H.trasposta () * V.inversa ()) ;
    //Metzger, cap. 8.5.2, eq. 8.112
    vettore theta = blocco * y ;
    cout << "parametri risultanti dai mimimi quadrati: \n" ;
    theta.stampa () ;
    //Metzger, cap. 8.5.2, eq. 8.113
    matrice theta_v = blocco * V * blocco.trasposta () ;
    cout << "matrice di covarianza dei parametri risultanti dai mimimi quadrati: \n" ;
    theta_v.stampa () ;

    return 0 ;
  }
