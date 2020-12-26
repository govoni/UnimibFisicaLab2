/*
c++ -o main_05 `root-config --glibs --cflags`  ../../Lezione_10/programmi/algebra_2.cc fisher.cc main_05.cpp

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>

#include "TCanvas.h"
#include "TH1F.h"
#include "TH2F.h"

#include "../../Lezione_09/programmi/statistiche_vector.h"

using namespace std ;
#include "fisher.h"


int main (int argc, char ** argv)
{
  if (argc < 3)
    {
      cerr << "uso: " << argv[0] << " nomeFile1 nomeFile2" << endl ;
      exit (1) ;
    }

  vector<vector<double> > data_1 ;
  leggiFile (data_1, argv[1]) ;
  TH2F * h_1 = riempiIstogramma (data_1, "h_1", 250) ;
  vector<vector<double> > data_2 ;
  leggiFile (data_2, argv[2]) ;
  TH2F * h_2 = riempiIstogramma (data_2, "h_2", 250) ;

  TCanvas c1 ("c1", "", 500, 500) ;
  TH1F * bkg = c1.DrawFrame (-0.5, -2.5, 5., 3.) ;
  bkg->SetXTitle ("x") ;
  bkg->SetYTitle ("y") ;

  h_1->SetMarkerStyle (4) ;
  h_1->SetMarkerColor (kRed) ;
  h_2->SetMarkerStyle (5) ;
  h_2->SetMarkerColor (kBlue) ;
  h_1->Draw ("P same") ;
  h_2->Draw ("P same") ;
  c1.Print ("confronto.png", "png") ;

  delete bkg ;

  delete h_1 ;
  delete h_2 ;

  return 0 ;
}