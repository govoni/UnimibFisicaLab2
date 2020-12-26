/*
c++ -o main_07 `root-config --glibs --cflags` ../../Lezione_10/programmi/algebra_2.cc fisher.cc main_07.cpp

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>

#include "../../Lezione_09/programmi/statistiche_vector.h"
#include "../../Lezione_10/programmi/algebra_2.h"
#include "fisher.h"

#include "TCanvas.h"
#include "TH2F.h"

using namespace std ;


int main (int argc, char ** argv)
{
  if (argc < 3)
    {
      cerr << "uso: " << argv[0] << " nomeFile1 nomeFile2" << endl ;
      exit (1) ;
    }

  // legge gli input e calcola le matrici delle covarianze
  // ---- ---- ---- ---- ---- ---- ----  

  vector<vector<double> > data_1 ;
  leggiFile (data_1, argv[1]) ;
  matrice cov_1 = determinaCovarianza (data_1) ;

  vector<vector<double> > data_2 ;
  leggiFile (data_2, argv[2]) ;
  matrice cov_2 = determinaCovarianza (data_2) ;

  // determina le media dei campioni
  // ---- ---- ---- ---- ---- ---- ----  

  vettore media_1 (2) ;
  media_1.setCoord (0, media (data_1.at (0))) ;
  media_1.setCoord (1, media (data_1.at (1))) ;

  vettore media_2 (2) ;
  media_2.setCoord (0, media (data_2.at (0))) ;
  media_2.setCoord (1, media (data_2.at (1))) ;

  // calcola i coefficienti del discriminante di Fisher
  // ---- ---- ---- ---- ---- ---- ----  

  matrice W = cov_1 + cov_2 ;
  vettore fisher = W.inversa () * (media_2 - media_1) ; 

  cout << "vettore di Fisher: " << endl ;
  fisher.stampa () ;

  // calcola il valore del discriminante di fisher per ciascun sample
  // ---- ---- ---- ---- ---- ---- ----  

  vector<double> fisher_1 ;
  for (int i = 0 ; i < data_1.at (0).size () ; ++i)
    {
      fisher_1.push_back (
        data_1.at (0).at (i) * fisher.at (0) + 
        data_1.at (1).at (i) * fisher.at (1)
      ) ;
    }

  vector<double> fisher_2 ;
  for (int i = 0 ; i < data_2.at (0).size () ; ++i)
    {
      fisher_2.push_back (
        data_2.at (0).at (i) * fisher.at (0) + 
        data_2.at (1).at (i) * fisher.at (1)
      ) ;
    }

  // confronta visivamente le distribuzioni 1D in x, y e per il discriminante di Fisher
  // ---- ---- ---- ---- ---- ---- ----  

  TCanvas c1 ("c1", "", 500, 500) ;
  TH1F * h_1_x = riempiIstogramma (data_1.at (0), "h_1_x") ;
  TH1F * h_2_x = riempiIstogramma (data_2.at (0), "h_2_x") ;

  plotComparison (h_1_x, h_2_x, c1, "compare_x.png", "x") ;

  TH1F * h_1_y = riempiIstogramma (data_1.at (1), "h_1_y") ;
  TH1F * h_2_y = riempiIstogramma (data_2.at (1), "h_2_y") ;

  plotComparison (h_1_y, h_2_y, c1, "compare_y.png", "y") ;

  TH1F * h_1_f = riempiIstogramma (fisher_1, "h_1_f") ;
  TH1F * h_2_f = riempiIstogramma (fisher_2, "h_2_f") ;

  plotComparison (h_1_f, h_2_f, c1, "compare_f.png", "fisher") ;

  delete h_1_x ;
  delete h_2_x ;
  delete h_1_y ;
  delete h_2_y ;
  delete h_1_f ;
  delete h_2_f ;

  return 0 ;
}