/*
c++ -o main_03 `root-config --glibs --cflags` algebra_2.cc main_03.cpp
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

//    TH1F h_sigma ("h_sigma", "sigma calcolata", 50, 0., 2 * sigma) ;
    TH1F h_scarti ("h_scarti", "scarti", 200, 0., 5 * N_points) ;

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
        for (int i = 0 ; i < N_points ; ++i)
          {
            H.setCoord (i, 0, 1) ;
            H.setCoord (i, 1, asse_x.at (i)) ;
          }
        vettore y (asse_y) ;
        matrice V (N_points) ;
        for (int i = 0 ; i < N_points ; ++i) V.setCoord (i, i, 1.) ;
    
        matrice V_inv = V.inversa () ;
        matrice theta_v = (H.trasposta () * V_inv * H).inversa () ;
        vettore theta = (theta_v * (H.trasposta () * V_inv)) * y ;

        // calcolo la somma degli scarti quadratici normalizzati per l'incertezza
        double Q2min = (y - H * theta).dot (V_inv * (y - H * theta)) ;
        h_scarti.Fill (Q2min) ;

      } //loop over toys

    // cout << sigma << " " 
    //      << h_sigma.GetMean () << " += " << h_sigma.GetRMS () / sqrt (N_toys) 
    //      << " " << h_sigma.GetBinCenter (h_sigma.GetMaximumBin ())
    //      << endl ;

    cout << "sigma = "
         << sqrt (h_scarti.GetMean () / (N_points - 2))
         << endl ;
         
// PG FIXME da capire quest'ultimo passaggio
        // double sigmaSq_calc = Q2min / (N_points - 2) ; //PG il -2 sembra dare un numero biasato!
        // h_sigma.Fill (sqrt (sigmaSq_calc)) ;

    // h_sigma.Draw ("hist") ;
    // c1.Print ("sigma_calc.png", "png") ;
 
    TCanvas c1 ("c1", "", 800, 800) ;
    c1.SetRightMargin (0.15) ;
    h_scarti.Draw ("hist") ;
    c1.Print ("scarti.png", "png") ;
 
    TFile f_out ("main_03.root", "recreate") ;
//    h_sigma.Write () ;
    h_scarti.Write () ;
    f_out.Close () ;




    return 0 ;
  }
