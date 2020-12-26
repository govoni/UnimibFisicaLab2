/*
c++ -o main_08 `root-config --glibs --cflags` ../../Lezione_10/programmi/algebra_2.cc fisher.cc main_08.cpp

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>

#include "../../Lezione_09/programmi/statistiche_vector.h"
#include "../../Lezione_10/programmi/algebra_2.h"
#include "fisher.h"

#include "TCanvas.h"
#include "TH2F.h"
#include "TGraph.h"

using namespace std ;


int main (int argc, char ** argv)
{
  if (argc < 3)
    {
      cerr << "uso: " << argv[0] << " H1.txt H0.txt" << endl ;
      exit (1) ;
    }

  // legge gli input e calcola le matrici delle covarianze
  // ---- ---- ---- ---- ---- ---- ----  

  vector<vector<double> > data_1 ;
  leggiFile (data_1, argv[1]) ;
  matrice cov_1 = determinaCovarianza (data_1) ;

  vector<vector<double> > data_2 ;
  leggiFile (data_2, argv[2]) ;
  matrice cov_2 = determinaCovarianza (data_2) ;

  // determina le media dei campioni
  // ---- ---- ---- ---- ---- ---- ----  

  vettore media_1 (2) ;
  media_1.setCoord (0, media (data_1.at (0))) ;
  media_1.setCoord (1, media (data_1.at (1))) ;

  vettore media_2 (2) ;
  media_2.setCoord (0, media (data_2.at (0))) ;
  media_2.setCoord (1, media (data_2.at (1))) ;

  // calcola i coefficienti del discriminante di Fisher
  // ---- ---- ---- ---- ---- ---- ----  

  matrice W = cov_1 + cov_2 ;
  vettore fisher = W.inversa () * (media_2 - media_1) ; 

  // calcola il valore del discriminante di fisher per ciascun sample
  // ---- ---- ---- ---- ---- ---- ----  

  vector<double> fisher_1 ;
  for (int i = 0 ; i < data_1.at (0).size () ; ++i)
    {
      fisher_1.push_back (
        data_1.at (0).at (i) * fisher.at (0) + 
        data_1.at (1).at (i) * fisher.at (1)
      ) ;
    }

  vector<double> fisher_2 ;
  for (int i = 0 ; i < data_2.at (0).size () ; ++i)
    {
      fisher_2.push_back (
        data_2.at (0).at (i) * fisher.at (0) + 
        data_2.at (1).at (i) * fisher.at (1)
      ) ;
    }

  // disegna la curva ROC per una selezione basata sul valore di fisher
  // dove la selezione è fisher_discriminant < soglia 
  // ---- ---- ---- ---- ---- ---- ----  

  // NB questa operazione modifica l'ordinamento nel campione, 
  //    quindi se l'ordinamento va preservato meglio è fare una copia
  //    dei vector per lavorarci
  sort (fisher_1.begin (), fisher_1.end ()) ;
  sort (fisher_2.begin (), fisher_2.end ()) ;

  // determinazione del massimo e del minimo valore assunti dai due campioni

  double taglio_min_f = *fisher_1.begin () ;
  if (*fisher_2.begin () < taglio_min_f) taglio_min_f = *fisher_2.begin () ;

  double taglio_max_f = *fisher_1.rbegin () ;
  if (*fisher_2.rbegin () > taglio_max_f) taglio_max_f = *fisher_2.rbegin () ;

  // determinazione del passo di scorrimento della selezione

  double risoluzione = 10 * (taglio_max_f - taglio_min_f) / fisher_1.size () ;

  // riempimento della curva ROC

  TGraph g_ROC_f ;

  int contatore_1 = 0 ;
  int contatore_2 = 0 ;
  for (double taglio = taglio_min_f ; taglio < taglio_max_f ; taglio += risoluzione)
    {
      // conta il numero di eventi sotto soglia per ogni campione
      // (ricordando che i due campioni sono stati ordinati)
      for ( ; contatore_1 < fisher_1.size () ; ++contatore_1)
        if (fisher_1.at (contatore_1) > taglio) break ;
      for ( ; contatore_2 < fisher_2.size () ; ++contatore_2)
        if (fisher_2.at (contatore_2) > taglio) break ;
      g_ROC_f.SetPoint (g_ROC_f.GetN (), 
          static_cast<double> (contatore_2) / fisher_2.size (),
          1. - static_cast<double> (contatore_1) / fisher_1.size ()
        ) ;
    }

  g_ROC_f.GetHistogram ()->SetXTitle ("#alpha") ;
  g_ROC_f.GetHistogram ()->SetYTitle ("#beta") ;

  // disegna la curva ROC
  // ---- ---- ---- ---- ---- ---- ----  

  TCanvas c1 ("c1", "", 500, 500) ;
//  g_ROC_f.SetLineColor (kRed) ;
  g_ROC_f.SetLineWidth (2) ;
  g_ROC_f.Draw ("AL") ;
  c1.Print ("ROC_f.png", "png") ;

  return 0 ;
}