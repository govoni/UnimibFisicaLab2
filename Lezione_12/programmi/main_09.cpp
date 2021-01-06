/*
c++ -o main_09 `root-config --glibs --cflags` ../../Lezione_10/programmi/algebra_2.cc fisher.cc main_09.cpp
./main_09 dati.txt dati_3.txt

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
#include "TFile.h"
#include "TH2F.h"
#include "TGraph.h"
#include "TLegend.h"
#include "TLine.h"

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
  vettore fisher = W.inversa () * (media_2 - media_1) ; 

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

  TGraph g_ROC_x = disegnaROC (data_1.at (0), data_2.at (0)) ;
  TGraph g_ROC_y = disegnaROC (data_1.at (1), data_2.at (1), false) ;
  TGraph g_ROC_f = disegnaROC (fisher_1, fisher_2) ;

  // confronta gli intergrali delle curve ROC
  // ---- ---- ---- ---- ---- ---- ----  

  cout << "variabile x:             " << area (g_ROC_x) << endl ;
  cout << "variabile y:             " << area (g_ROC_y) << endl ;
  cout << "discriminante di Fisher: " << area (g_ROC_f) << endl ;

  // disegna le curve ROC
  // ---- ---- ---- ---- ---- ---- ----  

  g_ROC_f.SetLineWidth (2) ;

  g_ROC_x.SetLineColor (kCyan+2) ;
  g_ROC_x.SetLineWidth (2) ;

  g_ROC_y.SetLineColor (kGreen+2) ;
  g_ROC_y.SetLineWidth (2) ;

  TCanvas c1 ("c1", "", 500, 500) ;

  TLegend * legend = new TLegend (0.5, 0.7, 0.9, 0.9) ;
  legend->AddEntry (&g_ROC_f, "fisher", "l") ;
  legend->AddEntry (&g_ROC_x, "x"     , "l") ;
  legend->AddEntry (&g_ROC_y, "y"     , "l") ;

  g_ROC_f.Draw ("AL") ;
  g_ROC_x.Draw ("L") ;
  g_ROC_y.Draw ("L") ;
  legend->Draw();
  c1.Print ("ROC.png", "png") ;


  TH2F * h_1 = riempiIstogramma (data_1, "h_1", 250) ;
  TH2F * h_2 = riempiIstogramma (data_2, "h_2", 250) ;

  TH1F * bkg = c1.DrawFrame (-0.5, -2.5, 5., 3.) ;
  bkg->SetXTitle ("x") ;
  bkg->SetYTitle ("y") ;

  h_1->SetMarkerStyle (4) ;
  h_1->SetMarkerColor (kRed) ;
  h_1->SetLineColor (kRed) ;
  h_2->SetMarkerStyle (5) ;
  h_2->SetMarkerColor (kBlue) ;
  h_2->SetLineColor (kBlue) ;
  h_1->Draw ("P same") ;
  h_2->Draw ("P same") ;

  // assumendo che la migliore separazione non sia lungo la direzione verticale, 
  // cioè che media_1 e media_2 non abbiano la stessa x

  double m = fisher.at (1) / fisher.at (0) ;
  double c = media_1.at (1) - media_1.at (0) * m ;

  TLine line (-0.5, -0.5 * m + c, 5., 5. * m + c) ;
  line.SetLineWidth (2) ;
  line.SetLineColor (kBlack) ;
  line.Draw ("same") ;

  c1.Print ("confronto_fisher.png", "png") ;

  TFile f_out ("main_09.root", "recreate") ;
  g_ROC_f.Write ("g_ROC_f") ;
  g_ROC_x.Write ("g_ROC_x") ;
  g_ROC_y.Write ("g_ROC_y") ;
  f_out.Close () ;

  delete bkg ;

  delete h_1 ;
  delete h_2 ;


  return 0 ;
}