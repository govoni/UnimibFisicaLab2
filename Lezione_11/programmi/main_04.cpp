/*
c++ -o main_04 `root-config --glibs --cflags` main_04.cpp
*/

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <fstream>

#include "TF1.h"
#include "TH1F.h"
#include "TCanvas.h"
#include "TFitResult.h"
#include "TMatrixDSym.h"

using namespace std ;

double minimo (const vector<double> & v)
  {
    double min = v.at (0) ;
    for (int i = 0 ; i < v.size () ; ++i)
      if (v.at (i) < min) min = v.at (i) ;
    return min ;
  }

double massimo (const vector<double> & v)
  {
    double max = v.at (0) ;
    for (int i = 0 ; i < v.size () ; ++i)
      if (v.at (i) > max) max = v.at (i) ;
    return max ;
  }

double maxval (double a, double b)
  {
    if (a > b) return a ;
    return b ;
  }


int main (int argc, char ** argv)
  {

    if (argc < 2)
      {
        cout << "usage: " << argv[0] << " outputfile.txt" << endl ;
        exit (1) ;
      }

    // lettura del file di eventi
    // --------------------------  

    ifstream f_campione ;
    f_campione.open (argv[1]) ;

    vector<double> v_eventi ;
    while (true) 
      {
        double evento ; 
        f_campione >> evento ;
        if (f_campione.eof () == true) break ;
        v_eventi.push_back (evento) ;
      } 
    f_campione.close () ;

    cout << "letti " << v_eventi.size () << " eventi" << endl ;
    cout << "minimo degli eventi: " << minimo (v_eventi) << endl ;
    cout << "massimo degli eventi: " << massimo (v_eventi) << endl ;

    // preparazione e riempimento dell'istogramma 
    // --------------------------  

    double min = floor (minimo (v_eventi)) ;
    double max = ceil (massimo (v_eventi)) ;
//    int N_bin  = round (sqrt (v_eventi.size ()) / 2.) ; 
    int N_bin  = round (sqrt (v_eventi.size ())) ;
    N_bin = maxval (N_bin, 10) ;

    TH1F h_eventi ("h_eventi", "", N_bin, min, max) ;
    for (int i = 0 ; i < v_eventi.size () ; ++i) h_eventi.Fill (v_eventi.at (i)) ;

    TF1 * model = new TF1 ("model", "gaus(0)", 0., 20.) ;
    model->SetLineColor (kBlue + 2) ;
    model->SetLineWidth (4) ;
    model->SetLineStyle (1) ;

    double p0 = v_eventi.size () ;    // eventi
    double p1 = 0.5 * (max - min) ;   // media
    double p2 = h_eventi.GetRMS () ;  // sigma

    model->SetParameter (0, p0) ;
    model->SetParameter (1, p1) ;
    model->SetParameter (2, p2) ;

    TFitResultPtr fit_result_MQ = h_eventi.Fit ("model", "SQ+") ;
    h_eventi.GetFunction ("model")->SetLineColor (kRed) ;

    cout << endl ;
    cout.precision (3) ;
    cout << "probabilità associata a Q2: " << model->GetProb () << endl ;
    cout << "integrale                 : " << model->GetParameter (0) << "\t+- " << model->GetParError (0) << endl ;                                           
    cout << "media                     : " << model->GetParameter (1) << "\t+- " << model->GetParError (1) << endl ;
    cout << "sigma                     : " << model->GetParameter (2) << "\t+- " << model->GetParError (2) << endl ;

    TFitResultPtr fit_result_ML = h_eventi.Fit ("model", "SLQ+") ;

    cout << endl ;
    cout << "probabilità associata a Q2: " << model->GetProb () << endl ;
    cout << "integrale                 : " << model->GetParameter (0) << "\t+- " << model->GetParError (0) << endl ;                                           
    cout << "media                     : " << model->GetParameter (1) << "\t+- " << model->GetParError (1) << endl ;
    cout << "sigma                     : " << model->GetParameter (2) << "\t+- " << model->GetParError (2) << endl ;

    TCanvas c1 ("c1", "", 800, 800) ;
    c1.SetLeftMargin (0.15) ;
    h_eventi.GetXaxis ()->SetTitle ("x") ;
    h_eventi.GetYaxis ()->SetTitle ("eventi nel bin") ;
    h_eventi.SetFillColor (kOrange + 1) ;
    h_eventi.SetLineColor (kGray + 1) ;
    h_eventi.SetStats (0) ;
    h_eventi.Draw () ;
    c1.Print ("main_04.png", "png") ;

    return 0 ;
  }
