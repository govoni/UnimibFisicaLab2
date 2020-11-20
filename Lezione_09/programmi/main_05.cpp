/*
c++ -o main_05 funzioni.cc main_05.cpp `root-config --glibs --cflags`

Testo:
  Utilizzando il generatore di numeri pseudo-casuali secondo una pdf 
  esponenziale sviluppato nella Lezione 4, si calcoli la copertura dello 
  stimatore di τ e se ne disegni il valore al variare del numero di eventi 
  a disposizione per la stima, riempiendo un TGraph con il numero di 
  eventi a disposizione sull'asse orizziontale ed il valore della copertura 
  sull'asse verticale.

  Si scriva tutto nel medesimo programma, facendo il modo che i punti lungo 
  l'asse orizzontale vengano campionati in modo logaritmico.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

#include "TGraph.h"
#include "TCanvas.h"
#include "TApplication.h"

#include "statistiche_vector.h"
#include "funzioni.h"

using namespace std ;

int main (int argc, char ** argv)
  {

    if (argc < 2)
      {
        cerr << "uso: " << argv[0] << " mu_true [numero_di_toy = 10000]" << endl ;
        exit (1) ;
      }

    double mu_true = atof (argv[1]) ;
    int N_toys = 10000 ;
    if (argc > 2) N_toys = atoi (argv[2]) ;

    std::vector<int> evt_vec = {10, 100, 1000};

    TApplication theapp ("theapp", 0, 0) ;

    TGraph g;
    g.SetMarkerStyle(8);
    g.SetLineStyle(9);
    g.SetTitle(";Numero estrazioni;Copertura");


    for(int idx = 0; idx < evt_vec.size(); ++idx)
      {
        int contatore_copertura = 0 ;
        int numero_eventi = evt_vec.at(idx);

        cout << "Numero estrazioni per toy: " << numero_eventi << endl;
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
            double massimo = sezione_aurea_max (loglikelihood, 0.5 * media_v, 1.5 * media_v, data_loc) ;
            double zero_sx = bisezione (h, 0.5 * media_v, massimo, data_loc, massimo) ;
            double zero_dx = bisezione (h, massimo, 1.5 * media_v, data_loc, massimo) ;
            if (mu_true > zero_sx && mu_true < zero_dx) ++contatore_copertura ;
          }
        g.SetPoint(idx,numero_eventi,contatore_copertura);
      }

    TCanvas c1 ;
    c1.SetLeftMargin (0.10) ; 
    g.Draw ("APL") ;
    c1.Update();
    theapp.Run () ;

    return 0 ;
}
