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


TH2F * riempiIstogramma (const vector<vector<double> > & data, string histo_name)
{
  // preparazione dell'istogramma
  // ---- ---- ---- ---- ---- ---- ----  

  double max_x = *max_element (data.at (0).begin (), data.at (0).end ()) ;
  double min_x = *min_element (data.at (0).begin (), data.at (0).end ()) ;
  double max_y = *max_element (data.at (1).begin (), data.at (1).end ()) ;
  double min_y = *min_element (data.at (1).begin (), data.at (1).end ()) ;

  double sigma_x = sqrt (varianza (data.at (0))) ;
  double sigma_y = sqrt (varianza (data.at (1))) ;

  TH2F * h_vis = new TH2F (
      histo_name.c_str (), 
      "distribuzione 2D",
      3 * (max_x - min_x) / sigma_x, min_x, max_x, 
      3 * (max_y - min_y) / sigma_y, min_y, max_y
    ) ;

  // riempimento dell'istogramma
  // ---- ---- ---- ---- ---- ---- ----  

  for (int i = 0 ; i < data.at (0).size () ; ++i)
    {
      h_vis->Fill (data.at (0).at (i), data.at (1).at (i)) ;
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

  vector<vector<double> > data_1 ;
  leggiFile (data_1, argv[1]) ;
  TH2F * h_1 = riempiIstogramma (data_1, "h_1") ;
  vector<vector<double> > data_2 ;
  leggiFile (data_2, argv[2]) ;
  TH2F * h_2 = riempiIstogramma (data_2, "h_2") ;


  TCanvas c1 ("c1", "", 500, 500) ;
  c1.DrawFrame (-0.5, -2.5, 5., 3.) ;

  h_1->SetMarkerStyle (4) ;
  h_1->SetMarkerColor (kRed) ;
  h_2->SetMarkerStyle (5) ;
  h_2->SetMarkerColor (kBlue) ;
  h_1->Draw ("P same") ;
  h_2->Draw ("P same") ;
  c1.Print ("confronto.png", "png") ;

  delete h_1 ;
  delete h_2 ;

  return 0 ;
}