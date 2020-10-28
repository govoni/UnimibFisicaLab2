/*
Esercizio 02: Riempire un istogramma con eventi eventi pseudo-casuali distribuiti uniformemente fra due numeri passati da linea di comando al programma. Si utilizzi la funzione rand () come punto di partenza per l'implementazione del generatore uniforme

c++ -o esercizio02 esercizio02.cpp `root-config --glibs --cflags` 
*/

#include <cstdlib>
#include <iostream>
#include <cmath>

#include "TH1F.h"
#include "TCanvas.h"


float rand_range (float min, float max)
  {
    return min + (max - min) * rand () / static_cast<float> (RAND_MAX) ;
  }


//----------------- MAIN -----------------
int main() {

 int minimo, massimo;
 
 std::cout << "Inserisci il numero minimo" << std::endl;
 std::cin >> minimo; 
 std::cout << "Inserisci il numero massimo" << std::endl;
 std::cin >> massimo; 
 
 //Dichiarazione istogramma con limiti tra minimo e massimo
 TH1F h1("h1", "eventi pseudo-casuali (uniforme)", 100, minimo , massimo) ;
 
 //riempimento istogramma
 for (int j = 0 ; j < 1000000 ; ++j)
   h1.Fill(rand_range(minimo, massimo)); 
 
 //Disegno l'istogramma
 TCanvas c1 ;
  
 h1.GetXaxis ()->SetTitle ("numeri generati") ;
 h1.GetYaxis ()->SetTitle ("conteggi per bin") ;
 h1.Draw () ;
 c1.Print ("esercizio02.png", "png") ;


 return 0;
 
}
