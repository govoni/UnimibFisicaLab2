/*
c++ -o main_07 `root-config --glibs --cflags` ../../Lezione_10/programmi/algebra_2.cc main_07.cpp

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>

#include "../../Lezione_09/programmi/statistiche_vector.h"
#include "../../Lezione_10/programmi/algebra_2.h"

#include "TCanvas.h"
#include "TH2F.h"

using namespace std ;


void leggiFile (vector<vector<double> > & data, string nome_file)
{
  ifstream input_file ;
  input_file.open (nome_file.c_str (), ios::in) ;

  if (!input_file.is_open ()) exit (1) ;

  double input_x ;
  double input_y ;
  vector<double> v ;
  data.push_back (v) ;
  data.push_back (v) ;
  while (true) 
    {
      input_file >> input_x ;
      input_file >> input_y ;
      if (input_file.eof () == true) break ;
      data.at (0).push_back (input_x) ;
      data.at (1).push_back (input_y) ;
    } 
  input_file.close () ;
  return ;
} 


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 


matrice determinaCovarianza (const vector<vector<double> > & data)
{

  if (data.size () < 2) exit (1) ;
  // calcolo della matrice delle covarianze
  // ---- ---- ---- ---- ---- ---- ----  

  double V_xx = varianza (data.at (0)) ;
  double V_yy = varianza (data.at (1)) ;
  double M_x = media (data.at (0)) ;
  double M_y = media (data.at (1)) ;

  double V_xy = 0. ;
  for (int i = 0 ; i < data.at (0).size () ; ++i)
    {
      V_xy += (data.at (0).at (i) - M_x) * (data.at (1).at (i) - M_y) ;
    }
  V_xy /= data.at (0).size () ;

  matrice covarianza (2) ;
  covarianza.setCoord (0, 0, V_xx) ;
  covarianza.setCoord (1, 1, V_yy) ;
  covarianza.setCoord (0, 1, V_xy) ;
  covarianza.setCoord (1, 0, V_xy) ;

  return covarianza ;
}


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 


TH1F * riempiIstogramma (const vector<double> & data, string histo_name)
{
  // preparazione dell'istogramma
  // ---- ---- ---- ---- ---- ---- ----  

  double max_x = *max_element (data.begin (), data.end ()) ;
  double min_x = *min_element (data.begin (), data.end ()) ;

  double sigma_x = sqrt (varianza (data)) ;

  TH1F * h_vis = new TH1F (
      histo_name.c_str (), 
      "distribuzione 1D",
      5 * (max_x - min_x) / sigma_x, min_x, max_x
    ) ;

  // riempimento dell'istogramma
  // ---- ---- ---- ---- ---- ---- ----  

  for (int i = 0 ; i < data.size () ; ++i)
    {
      h_vis->Fill (data.at (i)) ;
    }

  return h_vis ;
}


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 


void plotComparison (TH1F * h_1, TH1F * h_2, TCanvas & c1, string nome_file)
{
  double y_max = 0. ;
  if (h_1->GetBinContent (h_1->GetMaximumBin ()) > y_max)
    y_max = h_1->GetBinContent (h_1->GetMaximumBin ()) ;
  if (h_2->GetBinContent (h_2->GetMaximumBin ()) > y_max)
    y_max = h_2->GetBinContent (h_2->GetMaximumBin ()) ;

  double x_min = h_1->GetXaxis ()->GetXmin () ;
  double x_max = h_1->GetXaxis ()->GetXmax () ;

  if (h_2->GetXaxis ()->GetXmin () < x_min) x_min = h_2->GetXaxis ()->GetXmin () ;
  if (h_2->GetXaxis ()->GetXmax () > x_max) x_max = h_2->GetXaxis ()->GetXmax () ;

  c1.DrawFrame (x_min, 0, x_max, y_max * 1.1) ;

  h_1->SetLineColor (kRed) ;
  h_1->SetLineWidth (2) ;
  h_2->SetLineColor (kBlue) ;
  h_2->SetLineWidth (2) ;

  h_1->Draw ("hist same") ;
  h_2->Draw ("hist same") ;
  c1.Print (nome_file.c_str (), "png") ;
  return ;
}


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 


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
  vettore fisher = W.inversa () * (media_1 - media_2) ; 

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


  // confronta visivamente le distribuzioni 1D in x e y
  // ---- ---- ---- ---- ---- ---- ----  

  TCanvas c1 ("c1", "", 500, 500) ;
  TH1F * h_1_x = riempiIstogramma (data_1.at (0), "h_1_x") ;
  TH1F * h_2_x = riempiIstogramma (data_2.at (0), "h_2_x") ;

  plotComparison (h_1_x, h_2_x, c1, "compare_x.png") ;

  TH1F * h_1_y = riempiIstogramma (data_1.at (1), "h_1_y") ;
  TH1F * h_2_y = riempiIstogramma (data_2.at (1), "h_2_y") ;

  plotComparison (h_1_y, h_2_y, c1, "compare_y.png") ;

  TH1F * h_1_f = riempiIstogramma (fisher_1, "h_1_f") ;
  TH1F * h_2_f = riempiIstogramma (fisher_2, "h_2_f") ;

  plotComparison (h_1_f, h_2_f, c1, "compare_f.png") ;

  delete h_1_x ;
  delete h_2_x ;
  delete h_1_y ;
  delete h_2_y ;
  delete h_1_f ;
  delete h_2_f ;

  return 0 ;
}