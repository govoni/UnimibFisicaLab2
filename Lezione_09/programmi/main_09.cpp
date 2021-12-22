/*
c++ -o main_09 `root-config --glibs --cflags` funzioni.cc main_09.cpp

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

#include "statistiche_vector.h"
#include "funzioni.h"

#include "TF1.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TApplication.h"
#include "TH1F.h"

using namespace std ;


/**
 x   - is the paramter of the likelihood
 par - an array with its size as first element, y of the maximum - 1 as second,
       followed by the samples
 */
double ll_forTF1 (double * x, double * par)
{
  double result = 0. ; 
  for (int i = 0 ; i < par[0] ; ++i) 
    {      
      result += log (esponenziale (par[i+2], x[0])) ;
    }  
  return (result - par[1]) ;
}


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----


/**
 par[0] = number of events
 par[1] = sum of events
*/
double ll_expl (double * x, double * par)
{
  double result = 0. ; 
  return -1 * par[0] * log (x[0]) - par[1] / x[0] ;
}


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----


int main (int argc, char ** argv)
  {

    if (argc < 2)
      {
        cerr << "uso: " << argv[0] << " nomeFile [numero_di_eventi]" << endl ;
        exit (1) ;
      }

    ifstream input_file ; 
    input_file.open (argv[1], ios::in) ;

    int numeroMax = -1 ;
    if (argc > 2) numeroMax = atoi (argv[2]) ;

    vector<double> data ;
    double input_val ;
    while (true) 
      {
        input_file >> input_val ;
        if (input_file.eof () == true) break ;
        data.push_back (input_val) ;
        if (numeroMax > 0 && data.size () == numeroMax) break ;
      } 
    input_file.close () ;
    vector<double> data_forTF1 ;
    data_forTF1.push_back (data.size ()) ;
    data_forTF1.push_back (0.) ;
    data_forTF1.insert (data_forTF1.end (), data.begin (), data.end ()) ;

    double media_v = media (data) ;
    TCanvas c1 ("c1", "", 1000, 1000) ;
    TH1F * bkg = c1.DrawFrame (max (0.1, media_v/2.), -0.25, 1.5 * media_v, 0.7) ;   
    vector<TF1 *> v_ll ;

    vector<double> ll_err ;
    vector<double> N_evt ;
    vector<double> asymm ;
    vector<double> max ;

    int index = 0 ;
    // ciclo sul numero massimo di eventi
    for (int Nmax = data.size () ; Nmax >= 10  ; Nmax /= 2)
      {
        data.resize (Nmax) ;
        data_forTF1.resize (Nmax + 2) ;
        data_forTF1.at (0) = data.size () ;
        data_forTF1.at (1) = 0. ;

        double massimo = sezione_aurea_max (loglikelihood, 0.5 * media_v, 1.5 * media_v, data) ;
        double zero_sx = bisezione (h, 0.5 * media_v, massimo, data, massimo) ;
        double zero_dx = bisezione (h, massimo, 1.5 * media_v, data, massimo) ;

        data_forTF1.at (1) = ll_forTF1 (&massimo, &data_forTF1[0]) - 0.5 ;

        TString name = "f_ll_" ;
        name += Nmax ;
        TF1 * f_ll = new TF1 (name, ll_forTF1, 0.1, 3 * media_v, data_forTF1.size ()) ;
        f_ll->SetParameters (&data_forTF1[0]) ;
        v_ll.push_back (f_ll) ;
        f_ll->SetLineColor (kAzure + index) ;
        f_ll->SetNpx (1000) ;
        f_ll->Draw ("L same") ;

        N_evt.push_back (Nmax) ;
        ll_err.push_back (0.5 * (zero_dx - zero_sx)) ;
        asymm.push_back ((zero_dx - massimo)  / (massimo - zero_sx)) ;
        max.push_back (massimo) ;

        ++index ;
      } // ciclo sul numero massimo di eventi

    c1.Print ("loglikelihood.png", "png") ;


    return 0 ;
}
