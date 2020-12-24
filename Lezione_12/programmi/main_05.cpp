/*
c++ -o main_05 `root-config --glibs --cflags` main_05.cpp

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>

#include "TCanvas.h"
#include "TH2F.h"

#include "../../Lezione_09/programmi/statistiche_vector.h"

using namespace std ;

TH2F * riempiIstogramma (string file_name)
{
  ifstream input_file ;
  input_file.open (file_name.c_str (), ios::in) ;

  if (!input_file.is_open ()) exit (1) ;

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

  TH2F * h_vis = new TH2F (
      (string ("h_vis") + file_name).c_str (), 
      "distribuzione 2D",
      3 * (max_x - min_x) / sigma_x, min_x, max_x, 
      3 * (max_y - min_y) / sigma_y, min_y, max_y
    ) ;

  // riempimento dell'istogramma e visualizzazione
  // ---- ---- ---- ---- ---- ---- ----  

  for (int i = 0 ; i < data_x.size () ; ++i)
    {
      h_vis->Fill (data_x.at (i), data_y.at (i)) ;
    }

  return h_vis ;
}


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 


int main (int argc, char ** argv)
{
  if (argc < 3)
    {
      cerr << "uso: " << argv[0] << " nomeFile1 nomeFile2" << endl ;
      exit (1) ;
    }

  TH2F * h_1 = riempiIstogramma (argv[1]) ;
  TH2F * h_2 = riempiIstogramma (argv[2]) ;


  TCanvas c1 ("c1", "", 500, 500) ;
  c1.DrawFrame (-0.5, -2.5, 5., 3.) ;

  h_1->SetMarkerStyle (4) ;
  h_1->SetMarkerColor (kRed) ;
  h_2->SetMarkerStyle (5) ;
  h_2->SetMarkerColor (kBlue) ;
  h_1->Draw ("P same") ;
  h_2->Draw ("P same") ;
  c1.Print ("confronto.png", "png") ;

  return 0 ;
}