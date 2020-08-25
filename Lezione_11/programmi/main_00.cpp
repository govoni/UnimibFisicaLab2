/*
c++ -o main_00 `root-config --glibs --cflags` main_00.cpp
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
    model.SetLineColor (kBlue + 2) ;
    model.SetLineWidth (4) ;
    model.SetLineStyle (1) ;

    // The total is the sum of the three, each has 3 parameters
    TF1 segnale ("segnale", "gaus(0)", 0., 20.) ;
    segnale.SetParameter (0, p2) ;
    segnale.SetParameter (1, p3) ;
    segnale.SetParameter (2, p4) ;
    segnale.SetLineColor (kBlue) ;
    segnale.SetLineWidth (2) ;
    segnale.SetLineStyle (7) ;

    // The total is the sum of the three, each has 3 parameters
    TF1 fondo ("fondo", "expo(0)", 0., 20.) ;
    fondo.SetParameter (0, p0) ;
    fondo.SetParameter (1, p1) ;
    fondo.SetLineColor (kGray + 2) ;
    fondo.SetLineWidth (2) ;
    fondo.SetLineStyle (7) ;

    TCanvas c1 ("c1", "", 800, 800) ;
    c1.SetLeftMargin (0.15) ;
    TH1F * bkg = c1.DrawFrame (0, 0, 20, 1.05 * N_bkg) ;
    bkg->GetXaxis ()->SetTitle ("x") ;
    bkg->GetYaxis ()->SetTitle ("f(x)") ;
    segnale.Draw ("same") ;
    fondo.Draw ("same") ;
    model.Draw ("same") ;
    c1.Print ("model.png", "png") ;
 

    // ofstream output_file ;
    // output_file.open (argv[2]) ;

    // int Npoints = 5 ; 
    // if (argc > 3) Npoints = atoi (argv[3]) ;
    // for (int i = 0 ; i < Npoints ; ++i)
    //   {
    //     double epsilon = rand_TAC_gaus (sigma) ; 
    //     output_file << i << " " << g (i) + epsilon << "\n" ;
    //   }

    // output_file.close () ;

    return 0 ;
  }
