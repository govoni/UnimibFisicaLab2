/*
c++ -o main_04 `root-config --glibs --cflags` main_04.cpp
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

#include "TCanvas.h"
#include "TH2F.h"

#include "../../Lezione_09/programmi/statistiche_vector.h"

using namespace std ;

int main (int argc, char ** argv)
{
  if (argc < 2)
    {
      cerr << "uso: " << argv[0] << " nomeFile" << endl ;
      exit (1) ;
    }

  // lettura dei dati dal file di input
  // ---- ---- ---- ---- ---- ---- ----  

  ifstream input_file ;
  input_file.open (argv[1], ios::in) ;

  if (!input_file.is_open ()) return 1 ;

  double input_x ;
  double input_y ;
  vector<double> data_x ;
  vector<double> data_y ;
  while (true) 
    {
      input_file >> input_x ;
      input_file >> input_y ;
      if (input_file.eof () == true) break ;
      data_x.push_back (input_x) ;
      data_y.push_back (input_y) ;
    } 
  input_file.close () ;

  // calcolo della matrice delle covarianze
  // ---- ---- ---- ---- ---- ---- ----  

  double V_xx = varianza (data_x) ;
  double V_yy = varianza (data_y) ;
  double M_x = media (data_x) ;
  double M_y = media (data_y) ;

  double V_xy = 0. ;
  for (int i = 0 ; i < data_x.size () ; ++i)
    {
      V_xy += (data_x.at (i) - M_x) * (data_y.at (i) - M_y) ;
    }
  V_xy /= data_x.size () ;

  // angolo di rotazione che diagonalizza la matrice delle covarianze
  double theta = 0.5 * atan (2 * V_xy / (V_xx - V_yy)) ;
  double c_theta = cos (theta) ;
  double s_theta = sin (theta) ;

  // decorrelazione delle variabili
  // ---- ---- ---- ---- ---- ---- ----  

  vector<double> data_x_dec ;
  vector<double> data_y_dec ;
  for (int i = 0 ; i < data_x.size () ; ++i)
    {
      data_x_dec.push_back (data_x.at (i) * c_theta + data_y.at (i) * s_theta) ; 
      data_y_dec.push_back (data_y.at (i) * c_theta - data_x.at (i) * s_theta) ; 
    }

  // visualizzazione delle variabili decorrelate
  // ---- ---- ---- ---- ---- ---- ----  

  double max_x = *max_element (data_x_dec.begin (), data_x_dec.end ()) ;
  double min_x = *min_element (data_x_dec.begin (), data_x_dec.end ()) ;
  double max_y = *max_element (data_y_dec.begin (), data_y_dec.end ()) ;
  double min_y = *min_element (data_y_dec.begin (), data_y_dec.end ()) ;

  double sigma_x = sqrt (varianza (data_x_dec)) ;
  double sigma_y = sqrt (varianza (data_y_dec)) ;

  cout << sigma_x << endl ;
  cout << sigma_y << endl ;

  TH2F h_vis ("h_vis", "distribuzione 2D",
              5 * (max_x - min_x) / sigma_x, min_x, max_x, 
              5 * (max_y - min_y) / sigma_y, min_y, max_y) ;

  // riempimento dell'istogramma e visualizzazione
  // ---- ---- ---- ---- ---- ---- ----  

  for (int i = 0 ; i < data_x_dec.size () ; ++i)
    {
      h_vis.Fill (data_x_dec.at (i), data_y_dec.at (i)) ;
    }

  TCanvas c1 ("c1", "", 500, 500) ;
  c1.DrawFrame (-2., 1.0, 4., 3.0) ;

  h_vis.Draw ("COL same") ;
  c1.Print ("visualizzazione_dec.png", "png") ;

  delete bkg ;

  return 0 ;
}