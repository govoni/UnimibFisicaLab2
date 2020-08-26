/*
c++ -o main_01 `root-config --glibs --cflags` main_01.cpp
*/

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <fstream>

#include "TF1.h"
#include "TH1F.h"
#include "TCanvas.h"

using namespace std ;


int main (int argc, char ** argv)
  {

    if (argc < 3)
      {
        cout << "usage: " << argv[0] << " outputfile.txt N_events" << endl ;
        exit (1) ;
      }

    double N_bkg = 100. ;
    double p0 = log (N_bkg) ; // eventi di fondo
    double p1 = -0.2 ;        // pendenza del fondo
    double p2 = 30. ;         // eventi di segnale
    double p3 = 10. ;         // media del segnale
    double p4 = 2. ;          // sigma del segnale

    // The total is the sum of the three, each has 3 parameters
    TF1 model ("model", "expo(0) + gaus(2)", 0., 20.) ;
    model.SetParameter (0, p0) ;
    model.SetParameter (1, p1) ;
    model.SetParameter (2, p2) ;
    model.SetParameter (3, p3) ;
    model.SetParameter (4, p4) ;

    TH1F h_campione ("h_campione", "", 100, 0., 20.) ;

    ofstream f_campione ;
    f_campione.open (argv[1]) ;
    int N_eventi = atoi (argv[2]) ;

    for (int i = 0 ; i < N_eventi ; ++i)
      {
        double event = model.GetRandom () ; 
        f_campione << event << "\n" ;
        h_campione.Fill (event) ;
      }
    f_campione.close () ;

    TCanvas c1 ("c1", "", 800, 800) ;
    c1.SetLeftMargin (0.15) ;
    h_campione.GetXaxis ()->SetTitle ("x") ;
    h_campione.GetYaxis ()->SetTitle ("eventi nel bin") ;
    h_campione.SetFillColor (kOrange + 1) ;
    h_campione.SetLineColor (kGray + 1) ;
    h_campione.SetStats (0) ;
    h_campione.Draw () ;
    c1.Print ("sample.png", "png") ;

    return 0 ;
  }
