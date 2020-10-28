/*
Esercizio 04: Si riempia un istogramma con eventi pseudo-casuali con forma Gaussiana generati con la tecnica del teorema centrale del limite. sommando distribuzioni uniformi. Si utilizzi la funzione rand () come punto di partenza per l'implementazione del generatore uniforme.
Si disegni la distribuzione ottenuta riempiendo diversi istogrammi, ciascuno corrispondente ad un numero diverso di distribuzioni uniformi sommate, partendo da 1, fino a 20.

c++ -o esercizio04_v0 esercizio04_v0.cpp `root-config --glibs --cflags` 
*/

#include <cstdlib>
#include <iostream>
#include <cmath>

#include "TH1F.h"
#include "TCanvas.h"


float fgaus (float x) 
  {
    return exp (-0.5 * x * x) ; 
  }


float rand_range (float min, float max)
  {
    return min + (max - min) * rand () / static_cast<float> (RAND_MAX) ;
  } 


float rand_TCL (float xMin, float xMax, int N)
  {
    double y = 0. ; 
    for (int i = 0 ; i < N ; ++i)
      y += rand_range (xMin, xMax) ;
    y /= N ;
    return y ;
  }


//----------------- MAIN -----------------
int main() {
 
 TCanvas *c1 = new TCanvas ("c1", "c1", 100, 100, 1000, 1000) ;
 c1->Divide(5,4); //divido la finestra del canvas in 20 caselle in cui inserire un istogramma ciascuna
 
 //Dichiaro un vettore di istogrammi
 TH1F *isto_tcl[20];
 
 //uso TString per variare nome e titolo di ciascun istogramma
 TString titolo = "TCL con N=";
 TString istogramma = "isto_tcl";
 TString isto_name, titolo_isto;
      
  for (int h = 0; h < 20; ++h) { 
    isto_name = istogramma + (h+1);
    titolo_isto = titolo + (h+1);
    
    isto_tcl[h] = new TH1F (isto_name, titolo_isto , 200, -1.5, 1.5); //creo un istogramma per ciascun elemento del vettore
 
      for (int j = 0 ; j < 1000000 ; ++j) {
        isto_tcl[h]->Fill(rand_TCL(-1., 1., (h+1)));    //riempio il vettore con il valore conteggio
      }
  
  isto_tcl[h]->GetXaxis ()->SetTitle ("numeri generati") ;
  isto_tcl[h]->GetYaxis ()->SetTitle ("conteggi per bin") ;
    
}

//Disegno gli istogrammi
 for (int k = 0; k<20; k++){
   c1->cd(k+1); //mi sposto nella casella h del Canvas
   isto_tcl[k]->Draw(); //disegno l'isogramma nella casella in cui sono    
 }

 c1->Print ("esercizio04.png", "png") ;
 
for (int l = 0; l < 20; l++) 
  delete isto_tcl[l];
 
 delete c1;

 return 0;
 
}
