/*
c++ -o main_05 funzioni.cc main_05.cpp
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

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

    int contatore_copertura = 0 ;
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

    cout << "copertura : " << static_cast<double> (contatore_copertura) / N_toys << endl ;
    return 0 ;
}
