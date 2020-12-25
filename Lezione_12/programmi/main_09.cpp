/*
c++ -o main_09 `root-config --glibs --cflags` ../../Lezione_10/programmi/algebra_2.cc fisher.cc main_09.cpp

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
#include "TGraph.h"

using namespace std ;


int main (int argc, char ** argv)
{
  if (argc < 3)
    {
      cerr << "uso: " << argv[0] << " H1.txt H0.txt" << endl ;
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
  vettore fisher = W.inversa () * (media_1 - media_2) ; 

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

  // prepara le curve ROC per tre diversi tipi di selezione
  // ---- ---- ---- ---- ---- ---- ----  

  TGraph g_ROC_x = disegnaROC (data_1.at (0), data_2.at (0), false) ;
  TGraph g_ROC_y = disegnaROC (data_1.at (1), data_2.at (1)) ;
  TGraph g_ROC_f = disegnaROC (fisher_1, fisher_2) ;

  // confronta gli intergrali delle curve ROC
  // ---- ---- ---- ---- ---- ---- ----  

  cout << "variabile x:             " << area (g_ROC_x) << endl ;
  cout << "variabile y:             " << area (g_ROC_y) << endl ;
  cout << "discriminante di Fisher: " << area (g_ROC_f) << endl ;

  // disegna le curve ROC
  // ---- ---- ---- ---- ---- ---- ----  

  g_ROC_f.SetLineWidth (2) ;

  g_ROC_x.SetLineColor (kBlue) ;
  g_ROC_x.SetLineWidth (2) ;

  g_ROC_y.SetLineColor (kRed) ;
  g_ROC_y.SetLineWidth (2) ;


  TCanvas c1 ("c1", "", 500, 500) ;
  g_ROC_f.Draw ("AL") ;
  g_ROC_x.Draw ("L") ;
  g_ROC_y.Draw ("L") ;
  c1.Print ("ROC.png", "png") ;

  return 0 ;
}