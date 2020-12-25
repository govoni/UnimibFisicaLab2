/*
c++ -o main_06 `root-config --glibs --cflags` ../../Lezione_10/programmi/algebra_2.cc fisher.cc main_06.cpp

NB qui le opzioni di compilazione di ROOT servono perché nella libreria fisher.h
   sono utilizzate anche classi di ROOT.
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

  vector<vector<double> > data_1 ;
  leggiFile (data_1, argv[1]) ;
  matrice cov_1 = determinaCovarianza (data_1) ;

  vector<vector<double> > data_2 ;
  leggiFile (data_2, argv[2]) ;
  matrice cov_2 = determinaCovarianza (data_2) ;

  cov_1.stampa () ;
  cout << endl ;
  cov_2.stampa () ;

  return 0 ;
}