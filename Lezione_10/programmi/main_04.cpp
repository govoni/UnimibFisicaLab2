/*
c++ -o main_04 `root-config --glibs --cflags` algebra_2.cc main_04.cpp
*/

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

#include "TH1F.h"
#include "TCanvas.h"
#include "TH2F.h"
#include "TFile.h"

#include "algebra_2.h"
#include "generazione.h"

// retta con termine noto non nullo
double g (double x)
  {
     return 3.14 + 2 * x ;
  }

using namespace std ;


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----


int main (int argc, char ** argv)
  {
    if (argc < 4)
      {
        cout << "usage: " << argv[0] << " sigma_y N_points Ntoys" << endl ;
        exit (1) ;
      }

    double sigma  = atof (argv[1]) ;
    int N_points  = atoi (argv[2]) ;
    int N_toys    = atoi (argv[3]) ;

    // istogrammi per il disegno dei risultati del fit

    TH1F h_scarti ("h_scarti", "scarti", 200, 0., 5 * N_points) ;
    TH1F h_varianza ("h_varianza", "varianza calcolata", 50, 0., 10 * sigma) ;
    TH1F h_sigma ("h_sigma", "sigma calcolata", 50, 0., 3 * sigma) ;

    // generazione dei toy experiment e calcolo del fit per ciascuno di essi
    // ----------------------------------------

    //loop over toys
    for (int i_toy = 0 ; i_toy < N_toys ; ++i_toy)
      {
        vector<double> asse_x ;
        vector<double> asse_y ;

        // generare il sample
        // --------------------

        for (int i_point = 0 ; i_point < N_points ; ++i_point)
          {
            double epsilon = rand_TAC_gaus (sigma) ; 
            asse_x.push_back (i_point) ;
            asse_y.push_back (g (i_point) + epsilon) ;
          }

        // trovare i parametri
        // --------------------

        matrice H (N_points, 2) ;
        for (int i_point = 0 ; i_point < N_points ; ++i_point)
          {
            H.setCoord (i_point, 0, 1) ;
            H.setCoord (i_point, 1, asse_x.at (i_point)) ;
          }
        vettore y (asse_y) ;
        matrice V (N_points) ;
        for (int i_point = 0 ; i_point < N_points ; ++i_point) 
          V.setCoord (i_point, i_point, 1.) ;
    
        matrice V_inv = V.inversa () ;
        matrice theta_v = (H.trasposta () * V_inv * H).inversa () ;
        vettore theta = (theta_v * (H.trasposta () * V_inv)) * y ;

        // calcolo la somma degli scarti quadratici normalizzati per l'incertezza
        double Q2min = (y - H * theta).dot (V_inv * (y - H * theta)) ;
        h_scarti.Fill (Q2min) ;

        double varianza = Q2min / (N_points - 2) ;
        h_varianza.Fill (varianza) ;
        h_sigma.Fill (sigma) ;

      } //loop over toys

    cout << "sigma = "
         << sqrt (h_scarti.GetMean () / (N_points - 2))
         << endl ;
         
    TCanvas c1 ("c1", "", 800, 800) ;
    c1.SetRightMargin (0.15) ;
    h_scarti.Draw ("hist") ;
    c1.Print ("scarti.png", "png") ;
 
    TFile f_out ("main_04.root", "recreate") ;
    h_scarti.Write () ;
    h_sigma.Write () ;
    h_varianza.Write () ;
    f_out.Close () ;

    return 0 ;
  }
