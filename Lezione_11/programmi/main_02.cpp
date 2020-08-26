/*
c++ -o main_02 `root-config --glibs --cflags` main_02.cpp
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

float minimo (const vector<double> & v)
  {
    double min = v.at (0) ;
    for (int i = 0 ; i < v.size () ; ++i)
      if (v.at (i) < min) min = v.at (i) ;
    return min ;
  }

float massimo (const vector<double> & v)
  {
    double max = v.at (0) ;
    for (int i = 0 ; i < v.size () ; ++i)
      if (v.at (i) > max) max = v.at (i) ;
    return max ;
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
    int N_bin  = round (sqrt (v_eventi.size ()) / 2.) ; 

    TH1F h_eventi ("h_eventi", "", N_bin, min, max) ;
    for (int i = 0 ; i < v_eventi.size () ; ++i) h_eventi.Fill (v_eventi.at (i)) ;

    // preparazione del modello per il fit
    // --------------------------  

    TF1 model ("model", "expo(0) + gaus(2)", 0., 20.) ;
    model.SetLineColor (kBlue + 2) ;
    model.SetLineWidth (4) ;
    model.SetLineStyle (1) ;
    
    // determinazione dei parametri iniziali del fit
    // --------------------------  

    // prima stima dei parametri
    double N_bkg = v_eventi.size () / 2. ;
    double p0 = log (N_bkg) ;             // eventi di fondo
    double p1 = -0.5 ;                    // pendenza del fondo
    double p2 = v_eventi.size () / 2. ;   // eventi di segnale
    double p3 = 0.5 * (max - min) ;       // media del segnale
    double p4 = h_eventi.GetRMS () ;      // sigma del segnale

    // prima stima di p0 e p1 con un fit in zona di solo fondo
    TF1 fondo ("fondo", "expo(0)", 0., 20.) ;
    fondo.SetParameter (0, p0) ;
    fondo.SetParameter (1, p1) ;
    h_eventi.Fit ("fondo", "Q", "", 0., 4.) ;

    // prima stima di p2, p3 e p4 con un fit in zona di solo fondo
    TF1 segnale ("segnale", "gaus(0)", 0., 20.) ;
    segnale.SetParameter (0, p2) ;
    segnale.SetParameter (1, p3) ;
    segnale.SetParameter (2, p4) ;
    h_eventi.Fit ("segnale", "Q", "", 7., 14.) ;
  
    model.SetParameter (0, fondo.GetParameter (0)) ;
    model.SetParameter (1, fondo.GetParameter (1)) ;
    model.SetParameter (2, segnale.GetParameter (0)) ;
    model.SetParameter (3, segnale.GetParameter (1)) ;
    model.SetParameter (4, segnale.GetParameter (2)) ;

    TFitResultPtr fit_result = h_eventi.Fit ("model", "S") ;

    // bonta' del fit
    // --------------------------  
   
    int result = fit_result ;
    cout << "convergenza del fit        : " << fit_result->IsValid () << endl ;
    cout << "convergenza del fit (bis)  : " << fit_result->Status () << endl ;

    fit_result->Print () ;
    fit_result->PrintCovMatrix (cout) ;

    cout << "probabilità associata a Q2 : " << fit_result->Prob () << endl ;
    cout << "Valore di Q2               : " << fit_result->Chi2 () << endl ;
    cout << "Numero di gradi di libertà : " << fit_result->Ndf () << endl ;

    // output dei risultati
    // --------------------------  
    
    cout << endl ;
    cout.precision (3) ;
    cout << "normalizzazione del fondo  : " << exp (model.GetParameter (0)) << "\t+- " 
                                            << model.GetParError (0) * exp (model.GetParameter (0)) << endl ;
    cout << "pendenza del fondo         : " << model.GetParameter (1) << "\t+- " << model.GetParError (1) << endl ;
    cout << "normalizzazione del segnale: " << model.GetParameter (2) << "\t+- " << model.GetParError (2) << endl ;
    cout << "media del segnale          : " << model.GetParameter (3) << "\t+- " << model.GetParError (3) << endl ;
    cout << "sigma del segnale          : " << model.GetParameter (4) << "\t+- " << model.GetParError (4) << endl ;

    // matrice di covarianza dei parametri
    // --------------------------  

    cout << endl ;
    TMatrixDSym cov = fit_result->GetCovarianceMatrix () ;
    // or TMatrixDSym cov = r->GetCorrelationMatrix();
    for (int i = 0; i < cov.GetNrows () ; ++i) 
      {
        for (int j = 0; j < cov.GetNcols () ; ++j) 
          { 
            cout << cov(i,j) << "\t" ;
          }
        cout << "\n";
      }

    TCanvas c1 ("c1", "", 800, 800) ;
    c1.SetLeftMargin (0.15) ;
    h_eventi.GetXaxis ()->SetTitle ("x") ;
    h_eventi.GetYaxis ()->SetTitle ("eventi nel bin") ;
    h_eventi.SetFillColor (kOrange + 1) ;
    h_eventi.SetLineColor (kGray + 1) ;
    h_eventi.SetStats (0) ;
    h_eventi.Draw () ;
    c1.Print ("main_02.png", "png") ;

    return 0 ;
  }
