/*
c++ -o main_03 `root-config --glibs --cflags` main_03.cpp
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

    double p0 = 30. ; // integrale
    double p1 = 10. ; // media
    double p2 = 2. ;  // sigma

    TF1 * model = new TF1 ("model", "gaus(0)", 0., 20.) ;
    model->SetParameter (0, p0) ;
    model->SetParameter (1, p1) ;
    model->SetParameter (2, p2) ;

    TH1F h_campione ("h_campione", "", 100, 0., 20.) ;

    ofstream f_campione ;
    f_campione.open (argv[1]) ;
    int N_eventi = atoi (argv[2]) ;

    for (int i = 0 ; i < N_eventi ; ++i)
      {
        double event = model->GetRandom () ; 
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
    c1.Print ("gauss.png", "png") ;

    delete model ;
    return 0 ;
  }
