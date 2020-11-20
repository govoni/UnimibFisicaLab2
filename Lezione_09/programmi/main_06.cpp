/*
c++ -o main_06 `root-config --glibs --cflags` funzioni.cc main_06.cpp

Testo:
    In regime asintotico, la distribuzione degli scarti (τ - τvero) / στ ha forma Normale.

    Si utilizzi il metodo dei toy experiment per riempire l'istogramma degli scarti, dato un numero di eventi per toy experiment.
    Si calcoli la media e la sigma della distribuzione degli scarti e se ne disegni il valore al variare del numero di eventi a 
    disposizione per la stima, riempiendo un TGraph con il numero di eventi a disposizione sull'asse orizziontale ed il valore 
    del parametro sull'asse verticale.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

#include "TH1F.h"
#include "TCanvas.h"
#include "TApplication.h"
#include "TGraph.h"

#include "statistiche_vector.h"
#include "funzioni.h"

using namespace std ;

int main (int argc, char ** argv)
  {

    if (argc < 2)
      {
        cerr << "uso: " << argv[0] << " mu_true numero_di_eventi [numero_di_estrazioni = 10000]" << endl ;
        exit (1) ;
      }

    double mu_true = atof (argv[1]) ;

    int numero_eventi = 10000;
    if (argc > 2) numero_eventi = atoi (argv[2]) ;

    std::vector<int> N_toys_vec = {50, 100, 1000, 10000} ;

    TApplication theapp ("theapp", 0, 0) ;

    TGraph g;
    g.SetMarkerStyle(8);
    g.SetLineStyle(9);
    g.SetTitle(";Ntoys;(#tau - #hat{#tau})/#hat{#sigma_{#tau}}");

    std::vector<TH1F> histos;

    
    for(int idx = 0; idx < N_toys_vec.size(); ++idx)
      {
        int N_toys = N_toys_vec.at(idx);

        std::string h_name = "N_toy " + std::to_string(N_toys);

        TH1F h(
            h_name.c_str(), h_name.c_str(), 
            sqrt(N_toys), 
            -2,
            2
        ) ;

        h.SetLineColor(kBlue);
        h.SetFillColor(0);
        h.SetLineWidth(2);
        h.GetXaxis()->SetTitle("(#hat{#tau} - #tau) / #sigma_{#tau}");
        h.GetYaxis()->SetTitle("Events per bin");

        std::vector<double> pulls;

        for (int i_toy = 0 ; i_toy < N_toys ; ++i_toy)
        {
            if (i_toy % 1000 == 0) cout << "running toy " << i_toy << endl ;
            vector<double> data_loc ;
            for (int i_sample = 0 ; i_sample < numero_eventi ; ++i_sample)
            {
                data_loc.push_back (rand_IFC_Exp (mu_true)) ;
            } 

            double media_v = media (data_loc) ;
            double sigma_subsample = media_v / sqrt (data_loc.size ()) ;
            
            double pull = (mu_true - media_v) / sigma_subsample;
            pulls.push_back(pull);
            h.Fill(pull);
        }

        g.SetPoint(idx, N_toys, media(pulls));
        histos.push_back(h);

      }

    TCanvas c1 ;
    c1.Divide(2,2 , 0.0001, 0.0001);
    c1.SetLeftMargin (0.10) ; 
    for(int i = 0; i < N_toys_vec.size(); ++i){
        c1.cd(i+1);
        histos.at(i).Draw("hist");
    };
    c1.Update();

    TCanvas c2 ;
    c2.SetLogx();
    c2.SetLeftMargin (0.10) ; 
    g.Draw("APL");
    c2.Update();

    theapp.Run () ;

    return 0 ;
}
