/*
c++ -o main_03 `root-config --glibs --cflags` main_03.cpp
*/

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <fstream>
#include <algorithm>

#include "TF1.h"
#include "TH1F.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TString.h"
#include "TFitResult.h"
#include "TGraphErrors.h"

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

    // preparazione dei TGraph per l'andamento dei risultati
    // --------------------------

    vector<TGraphErrors *> trend_parametri ;
    for (int i = 0 ; i < 5 ; ++i) trend_parametri.push_back (new TGraphErrors ()) ;

    vector<TGraph *> trend_incertezza_par ;
    for (int i = 0 ; i < 5 ; ++i) trend_incertezza_par.push_back (new TGraph ()) ;

    TGraph g_gof ;

    TCanvas c1 ("c1", "", 800, 800) ;
    c1.SetLeftMargin (0.15) ;

    int point = 0 ;
    // ciclo su diverse dimensioni del campione
    for (int i_Nmax = v_eventi.size () ; i_Nmax > 500 ; i_Nmax /= 2)
      {
        cout << "ciclo su " << i_Nmax << " eventi" << endl ;
        double min = floor (*min_element (v_eventi.begin (), v_eventi.begin () + i_Nmax)) ;
        double max = floor (*max_element (v_eventi.begin (), v_eventi.begin () + i_Nmax)) ;
        int N_bin  = round (sqrt (i_Nmax) / 2.) ; 

        TH1F * h_eventi = new TH1F ("h_eventi", "", N_bin, min, max) ;
        for (int i = 0 ; i < i_Nmax ; ++i) h_eventi->Fill (v_eventi.at (i)) ;
        TF1 * model = new TF1 ("model", "expo(0) + gaus(2)", 0., 20.) ;
        
        // determinazione dei parametri iniziali del fit
        // --------------------------  

        double N_bkg = i_Nmax / 2. ;
        double p0 = log (N_bkg) ;             // eventi di fondo
        double p1 = -0.5 ;                    // pendenza del fondo
        double p2 = i_Nmax * 0.3 ;            // eventi di segnale
        double p3 = 0.5 * (max - min) ;       // media del segnale
        double p4 = h_eventi->GetRMS () / 2.; // sigma del segnale
    
        // prima stima di p0 e p1 con un fit in zona di solo fondo
        TF1 * fondo = new TF1 ("fondo", "expo(0)", 0., 20.) ;
        fondo->SetParameter (0, p0) ;
        fondo->SetParameter (1, p1) ;
        h_eventi->Fit ("fondo", "Q", "", 0., 4.) ;
    
        // prima stima di p2, p3 e p4 con un fit in zona di solo fondo
        TF1 * segnale = new TF1 ("segnale", "gaus(0)", 0., 20.) ;
        segnale->SetParameter (0, p2) ;
        segnale->SetParameter (1, p3) ;
        segnale->SetParameter (2, p4) ;
  
        h_eventi->Fit ("segnale", "Q", "", 7., 14.) ;

        model->SetParameter (0, fondo->GetParameter (0)) ;
        model->SetParameter (1, fondo->GetParameter (1)) ;
        model->SetParameter (2, segnale->GetParameter (0)) ;
        model->SetParameter (3, segnale->GetParameter (1)) ;
        model->SetParameter (4, segnale->GetParameter (2)) ;
        model->SetParLimits (4, 0.1, 5.) ;

        // fit dell'istogramma
        // --------------------------  
    
        TFitResultPtr fit_result = h_eventi->Fit ("model", "S") ;
    
        g_gof.SetPoint (point, i_Nmax, fit_result->Prob ()) ;
        // riempimento dei TGraphError
        for (int i = 0 ; i < 5 ; ++i) 
          {
            trend_parametri.at (i)->SetPoint (point, i_Nmax, model->GetParameter (i)) ;
            trend_parametri.at (i)->SetPointError (point, 0., model->GetParError (i)) ;
            trend_incertezza_par.at (i)->SetPoint (point, i_Nmax, model->GetParError (i)) ;
          }
        ++point ;

        TString testo = "fit_" ;
        testo += i_Nmax ;
        testo += ".png" ;
        h_eventi->Draw () ;
        c1.Print (testo, "png") ;
        
        delete model ;
        delete fondo ;
        delete segnale ;
        delete h_eventi ;  
      } // ciclo su diverse dimensioni del campione

    c1.SetLogx () ;

    TFile f_out ("main_03.root", "recreate") ;
    g_gof.SetMarkerStyle (20) ;
    g_gof.SetMarkerColor (kGray + 2) ;
    g_gof.Write ("GOF") ;

    g_gof.Draw ("AP") ;
    g_gof.GetXaxis ()->SetTitle ("numero di eventi") ;
    g_gof.GetYaxis ()->SetTitle ("p-value del fit") ;
    g_gof.Draw ("AP") ;
    c1.Print ("GOF.png", "png") ;

    for (int i = 0 ; i < 5 ; ++i) 
      {
        TString testo ;
        trend_parametri.at (i)->SetMarkerStyle (20) ;
        trend_parametri.at (i)->SetMarkerColor (kBlue + 2) ;
        trend_parametri.at (i)->Draw ("AP") ;
        trend_parametri.at (i)->GetXaxis ()->SetTitle ("numero di eventi") ;
        testo = "parametro " ;
        testo += i ;
        trend_parametri.at (i)->GetYaxis ()->SetTitle (testo) ;
        trend_parametri.at (i)->Draw ("AP") ;
        testo = "parametro_" ;
        testo += i ;
        trend_parametri.at (i)->Write (testo) ; 
        testo += ".png" ;
        c1.Print (testo, "png") ;

        c1.SetLogy () ;
        trend_incertezza_par.at (i)->SetMarkerStyle (20) ;
        trend_incertezza_par.at (i)->SetMarkerColor (kRed) ;
        trend_incertezza_par.at (i)->Draw ("AP") ;
        trend_incertezza_par.at (i)->GetXaxis ()->SetTitle ("numero di eventi") ;
        testo = "incertezza sul parametro " ;
        testo += i ;
        trend_incertezza_par.at (i)->GetYaxis ()->SetTitle (testo) ;
        trend_incertezza_par.at (i)->Draw ("AP") ;
        testo = "incertezza_" ;
        testo += i ;
        trend_incertezza_par.at (i)->Write (testo) ; 
        testo += ".png" ;
        c1.Print (testo, "png") ;
        c1.SetLogy (false) ;
      }
    f_out.Close () ;  

    return 0 ;
  }
