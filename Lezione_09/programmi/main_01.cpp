/*
c++ -o main_01 `root-config --cflags --glibs` main_01.cpp

Testo 2:
  Si aggiunga al programma precedente il codice sorgente che calcoli la media, 
  il valor minimo ed il valor massimo dei numeri inseriti.

Testo 3:
  Si aggiunga al programma precedente il codice sorgente che riempia un istogramma 
  con i numeri presenti nel vector dove sono stati trasferiti e che visualizzi l'istogramma a schermo.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

#include "TH1F.h"
#include "TCanvas.h"
#include "TApplication.h"

#include "statistiche_vector.h"

using namespace std ;

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

    cout << "letti " << data.size () << " eventi" << endl ;

    double media_v = media (data) ;
    cout << "media = " << media_v << endl ; 

    TApplication theapp ("theapp", NULL, NULL) ;
    TH1F h_data ("h_data", "", 100, 0., 5 * media_v) ;
    h_data.SetFillColor (kOrange + 1) ;
    h_data.GetXaxis ()->SetTitle ("asse x") ;
    h_data.GetYaxis ()->SetTitle ("conteggi per bin") ;    
    TCanvas c1 ;

    for (int i = 0 ; i < data.size () ; ++i) h_data.Fill (data.at (i)) ;

    h_data.Draw () ;

    c1.Update();
    c1.Draw();
    theapp.Run () ;


    return 0 ;
}
