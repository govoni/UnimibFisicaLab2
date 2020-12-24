/*
c++ -o main_02 `root-config --glibs --cflags` main_02.cpp

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

  // preparazione dell'istogramma di visualizzazione
  // ---- ---- ---- ---- ---- ---- ----  

  double max_x = *max_element (data_x.begin (), data_x.end ()) ;
  double min_x = *min_element (data_x.begin (), data_x.end ()) ;
  double max_y = *max_element (data_y.begin (), data_y.end ()) ;
  double min_y = *min_element (data_y.begin (), data_y.end ()) ;

  double sigma_x = sqrt (varianza (data_x)) ;
  double sigma_y = sqrt (varianza (data_y)) ;

  TH2F h_vis ("h_vis", "distribuzione 2D",
              10 * (max_x - min_x) / sigma_x, min_x, max_x, 
              10 * (max_y - min_y) / sigma_y, min_y, max_y) ;

  // riempimento dell'istogramma e visualizzazione
  // ---- ---- ---- ---- ---- ---- ----  

  for (int i = 0 ; i < data_x.size () ; ++i)
    {
      h_vis.Fill (data_x.at (i), data_y.at (i)) ;
    }

  TCanvas c1 ("c1", "", 500, 500) ;
  c1.DrawFrame (-1.5, -1.5, 5.5, 3.5) ;
  h_vis.Draw ("COL same") ;
  c1.Print ("visualizzazione.png", "png") ;

  return 0 ;
}