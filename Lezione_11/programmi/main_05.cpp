/*
c++ -o main_05 `root-config --glibs --cflags` main_05.cpp
*/

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <fstream>

#include "TF1.h"
#include "TH1F.h"
#include "TGraph.h"
#include "TCanvas.h"
#include "TFitResult.h"
#include "TMatrixDSym.h"
#include "TGraphErrors.h"

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

template <class disegno>
void drawComparison (TCanvas & c1, disegno & d1, disegno & d2, TString variabile)
  {
    d1.SetMarkerStyle (20) ;
    d2.SetMarkerStyle (4) ;

    d1.SetMarkerColor (kBlue) ;
    d2.SetMarkerColor (kRed) ;

    d1.Draw ("AP") ;
    d1.GetXaxis ()->SetTitle ("numero di eventi") ;
    d1.GetYaxis ()->SetTitle (variabile) ;
    d1.Draw ("AP") ;
    d2.Draw ("P same") ;
    c1.Print (variabile + ".png", "png") ;
    return ;
  }


int main (int argc, char ** argv)
  {

    if (argc < 2)
      {
        cout << "usage: " << argv[0] << " inputfile.txt" << endl ;
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

    TGraphErrors g_p0_MQ ;
    TGraphErrors g_p1_MQ ;
    TGraphErrors g_p2_MQ ;
    TGraphErrors g_p0_ML ;
    TGraphErrors g_p1_ML ;
    TGraphErrors g_p2_ML ;

    int point = 0 ;
    // ciclo su diverse dimensioni del campione
    for (int i_Nmax = v_eventi.size () ; i_Nmax > 10 ; i_Nmax /= 2)
      {

        double min = floor (minimo (v_eventi)) ;
        double max = ceil (massimo (v_eventi)) ;
        int N_bin  = round (sqrt (i_Nmax)) ;
        N_bin = maxval (N_bin, 10) ;
    
        TH1F * h_eventi = new TH1F ("h_eventi", "", N_bin, min, max) ;
        for (int i = 0 ; i < i_Nmax ; ++i) h_eventi->Fill (v_eventi.at (i)) ;
    
        // preparazione del modello per il fit
        // --------------------------  
    
        TF1 * model = new TF1 ("model", "gaus(0)", 0., 20.) ;
        model->SetLineColor (kBlue + 2) ;
        model->SetLineWidth (4) ;
        model->SetLineStyle (1) ;

        double p0 = i_Nmax ;                  // eventi
        double p1 = 0.5 * (max - min) ;       // media
        double p2 = h_eventi->GetRMS () / 2.; // sigma

        model->SetParameter (0, p0) ;
        model->SetParameter (1, p1) ;
        model->SetParameter (2, p2) ;
    
        TFitResultPtr fit_result_MQ = h_eventi->Fit ("model", "SQ+") ;
        h_eventi->GetFunction ("model")->SetLineColor (kRed) ;

        g_p0_MQ.SetPoint (point, i_Nmax, model->GetParameter (0)) ;
        g_p0_MQ.SetPointError (point, 0., model->GetParError (0)) ;
        g_p1_MQ.SetPoint (point, i_Nmax, model->GetParameter (1)) ;
        g_p1_MQ.SetPointError (point, 0., model->GetParError (1)) ;
        g_p2_MQ.SetPoint (point, i_Nmax, model->GetParameter (2)) ;
        g_p2_MQ.SetPointError (point, 0., model->GetParError (2)) ;

        TFitResultPtr fit_result_ML = h_eventi->Fit ("model", "SLQ+") ;

        g_p0_ML.SetPoint (point, i_Nmax, model->GetParameter (0)) ;
        g_p0_ML.SetPointError (point, 0., model->GetParError (0)) ;
        g_p1_ML.SetPoint (point, i_Nmax, model->GetParameter (1)) ;
        g_p1_ML.SetPointError (point, 0., model->GetParError (1)) ;
        g_p2_ML.SetPoint (point, i_Nmax, model->GetParameter (2)) ;
        g_p2_ML.SetPointError (point, 0., model->GetParError (2)) ;
        
        h_eventi->GetXaxis ()->SetTitle ("x") ;
        h_eventi->GetYaxis ()->SetTitle ("eventi nel bin") ;
        h_eventi->SetFillColor (kOrange + 1) ;
        h_eventi->SetLineColor (kGray + 1) ;

        TString testo = "fit_" ;
        testo += point ;
        testo += ".png" ;
        h_eventi->Draw () ;
        c1.Print (testo, "png") ;

        delete h_eventi ;
        delete model ;
        ++point ;
      } // ciclo su diverse dimensioni del campione

    c1.SetLogx () ;

    drawComparison (c1, g_p0_MQ , g_p0_ML , "p0") ;
    drawComparison (c1, g_p1_MQ , g_p1_ML , "p1") ;
    drawComparison (c1, g_p2_MQ , g_p2_ML , "p2") ;

    return 0 ;
  }
