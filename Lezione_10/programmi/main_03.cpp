/*
c++ -o main_03 algebra_2.cc main_03.cpp
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
    if (argc < 3)
      {
        cout << "usage: " << argv[0] << " sigma_y nomefile.txt" << endl ;
        exit (1) ;
      }

    // lettura del file di input
    // -------------------------

    double sigma = atof (argv[1]) ;
    ifstream input_file ;
    input_file.open (argv[2]) ;
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

    int N_points = asse_x.size () ; 

    // creazione delle matrici del metodo dei minimi quadrati
    // -------------------------

    matrice H (N_points, 2) ;
    for (int i = 0 ; i < N_points ; ++i)
      {
        H.setCoord (i, 0, 1) ;
        H.setCoord (i, 1, asse_x.at (i)) ;
      }
    vettore y (asse_y) ;

    // ipotesi: incertezza costante su tutti i valori
    matrice V (N_points) ;
    for (int i = 0 ; i < N_points ; ++i) V.setCoord (i, i, 1.) ;

    // calcolo dei parametri di interesse
    // -------------------------

    matrice V_inv = V.inversa () ;
    //Metzger, cap. 8.5.2, eq. 8.116
    matrice theta_v = (H.trasposta () * V_inv * H).inversa () ;
    //Metzger, cap. 8.5.2, eq. 8.112
    vettore theta = (theta_v * (H.trasposta () * V_inv)) * y ;
    cout << "parametri risultanti dai mimimi quadrati: \n" ;
    theta.stampa () ;

    //Metzger, cap. 8.5.2, eq. 8.117
    double Q2min = (y - H * theta).dot (V_inv * (y - H * theta)) ;
    //Metzger, cap. 8.5.2, eq. 8.118
    double sigmaSq_calc = Q2min / (N_points - 2) ;
    cout << "varianza dei valori iniziali: " << sigmaSq_calc << endl ;
 
    theta_v *= sigmaSq_calc ;
    cout << "matrice di covarianza dei parametri risultanti dai mimimi quadrati: \n" ;
    theta_v.stampa () ;
    cout << "termine noto: " << theta.at (0) << " +- " << sqrt (theta_v.at (0, 0)) << endl ;
    cout << "pendenza:     " << theta.at (1) << " +- " << sqrt (theta_v.at (1, 1)) << endl ;

    return 0 ;
  }
