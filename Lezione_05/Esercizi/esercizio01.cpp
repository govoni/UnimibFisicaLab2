/*
Esercizio 01: Si riempia un istogramma con gli eventi generati con il generatore di numeri pseudo-casuali lineare congruenziale, verificando che tipo di distribuzione segua.

c++ -o esercizio01 esercizio01.cpp `root-config --glibs --cflags` 
*/

#include <iostream>

#include "TH1F.h"
#include "TCanvas.h"

const int A =  214013;
const int C =  2531011;
const int M =  2147483647;

void rand(int &x){
    x = (A* x + C)%M;
    return;
}

//----------------- MAIN -----------------
int main() {

 int num = 0;

 //Dichiarazione istogramma con limiti tra 0 e M
 TH1F h1("h1", "eventi pseudo-casuali (lineare congruenziale)", 10000, 0., 2147483647) ;
 
 //riempimento istogramma
 for (int j = 0 ; j < 10000000 ; ++j)
 {
   rand(num);
   h1.Fill(num); 
 }

 //Disegno l'istogramma
 TCanvas c1 ;
  
 h1.GetXaxis ()->SetTitle ("numeri generati") ;
 h1.GetYaxis ()->SetTitle ("conteggi per bin") ;
 h1.Draw () ;
 c1.Print ("esercizio01.png", "png") ;


 return 0;
 
}
