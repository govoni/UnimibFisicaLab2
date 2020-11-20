/*
c++ -o main_04 `root-config --glibs --cflags` funzioni.cc main_04.cpp

Testo:
  Utilizzando il generatore di numeri pseudo-casuali secondo una pdf esponenziale sviluppato nella 
  Lezione 4, si disegni la distribuzione di probabilita' dello stimatore di τ in funzione del numero 
  di eventi a disposizione per la stima.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

#include "TH1F.h"
#include "TCanvas.h"
#include "TApplication.h"

#include "statistiche_vector.h"
#include "funzioni.h"

using namespace std ;

int main (int argc, char ** argv)
  {

    if (argc < 2)
      {
        cerr << "uso: " << argv[0] << " mu_true numero_di_eventi [numero_di_toy = 10000]" << endl ;
        exit (1) ;
      }

    double mu_true = atof (argv[1]) ;
    int numero_eventi = atoi (argv[2]) ;

    int N_toys = 10000 ;
    if (argc > 3) N_toys = atoi (argv[3]) ;

    TApplication theapp ("theapp", 0, 0) ;

    TH1F h_max (
        "h_max", "max likelihood distribution", 
        N_toys / 100, 
        mu_true - 3 * mu_true / sqrt (numero_eventi),
        mu_true + 3 * mu_true / sqrt (numero_eventi)
      ) ;

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
        h_max.Fill (massimo) ;
      }

    h_max.SetLineColor (kGray) ;
    h_max.SetFillColor (kOrange + 1) ;
    h_max.GetXaxis ()->SetTitle ("stimatore di #tau") ;
    h_max.GetYaxis ()->SetTitle ("conteggi per bin") ;    
    TCanvas c1 ;
    c1.SetLeftMargin (0.10) ; 
    h_max.Draw () ;
    c1.Update();
    theapp.Run () ;

    return 0 ;
}
