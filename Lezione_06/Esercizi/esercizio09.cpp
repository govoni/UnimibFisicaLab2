/*
Esercizio 09:Si disegnino in due TGraph gli andamenti della precisione del calcolo dell'integrale, per i due algoritmi di hit-or-miss e crude-MC, in funzione del tempo di calcolo corrispondente alle varie scelte del numero totale N di eventi pseudo-casuali generati.

c++ -o esercizio09 esercizio09.cpp ../../Lezione_03/Esercizi/esercizio04/myarray.cc `root-config --glibs --cflags`
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

#include "TH1F.h"
#include "TCanvas.h"
#include "TGraph.h"

#include "../../Lezione_03/Esercizi/esercizio04/myarray.h"


float rand_range (float min, float max)
  {
    return min + (max - min) * rand () / static_cast<float> (RAND_MAX) ;
  } 


double fsin (double x) 
  {
    return sin (x) ; 
  }
  
 
mioArray CrudeMC (int Nrand, double g(double), double xMin, double xMax )
   {
     double lunghezza  = (xMax - xMin);
     double somma = 0;
     double sommaQ = 0;
     double media = 0;
     double varianza = 0;
     
     for (int i = 0; i<Nrand; i++)
     {
        double x = rand_range(xMin, xMax);
        somma += g(x);
        sommaQ += g(x)*g(x);     
     }
      
     media = somma/static_cast<double>(Nrand);
     varianza = sommaQ/static_cast<double>(Nrand) - media*media ;
                                   
     mioArray risultato_MC (2) ;      
     risultato_MC.fill (0, media*lunghezza) ;
     risultato_MC.fill (1, sqrt (varianza/static_cast<double>(Nrand)) * lunghezza) ;
      
    return risultato_MC ;       
   }  
   
mioArray HitOrMiss (int Nrand, double g(double), double xMin, double xMax,
              double yMin, double yMax)
   {
     int nHit = 0;
     double area  = (xMax - xMin) * (yMax - yMin) ;
     
     for (int i = 0 ; i < Nrand ; ++i) 
      {
        double x = rand_range (xMin, xMax) ;
        double y = rand_range (yMin, yMax) ; 
        if (y < g (x)) ++nHit ; 
      }   
      
     double p = nHit / static_cast<double> (Nrand) ;
     double varianza = area * area / static_cast<double> (Nrand) * p * (1. - p) ;
           
     mioArray risultato_HoM (2) ;      
     risultato_HoM.fill (0, nHit * area / static_cast<double> (Nrand)) ;
     risultato_HoM.fill (1, sqrt (varianza)) ;
      
    return risultato_HoM ;       
   }           
            
//----------------- MAIN -----------------
int main (int argc, char ** argv)
{ 
  srand (time (NULL)) ;
  int N = 50000 ;
  double x_min = 0. ;
  double x_max = M_PI ; 
  double y_min = 0. ; 
  double y_max = 1. ;
  double tempoCalcolo = 0.;

  TGraph g_incertezza_MC;
  TGraph g_incertezza_HoM;
  
 for (int iN = 10; iN < N; iN = iN*2)
  {  
    mioArray risultato_MC  = CrudeMC(iN,fsin,x_min,x_max); 
    mioArray risultato_HoM = HitOrMiss(iN,fsin,x_min,x_max,y_min,y_max); 
    
    tempoCalcolo = clock();   
 
    g_incertezza_MC.SetPoint (g_incertezza_MC.GetN(), iN, risultato_MC.get1 (1)) ; 
    g_incertezza_HoM.SetPoint (g_incertezza_HoM.GetN(), iN, risultato_HoM.get1 (1)) ;                             
  }
  
  TCanvas *c1 = new TCanvas ("c1", "c1", 100, 100, 1000, 1000) ;
  c1->Divide(1,2);
  c1->cd(1);
  g_incertezza_HoM.SetMarkerStyle (20) ;
  g_incertezza_HoM.SetMarkerColor (kBlue + 1) ;
  g_incertezza_HoM.SetLineColor (kBlue - 9) ;
  g_incertezza_HoM.SetMarkerSize (2) ;
  g_incertezza_HoM.SetTitle("Metodo Hit or Miss");
  g_incertezza_HoM.GetHistogram ()->GetXaxis ()->SetTitle ("tempo di calcolo") ;
  g_incertezza_HoM.GetHistogram ()->GetYaxis ()->SetTitle ("incertezza") ;
  g_incertezza_HoM.Draw ("ALP") ;
   
  c1->cd(2);
  g_incertezza_MC.SetMarkerStyle (20) ;
  g_incertezza_MC.SetMarkerColor (kRed + 1) ;
  g_incertezza_MC.SetLineColor (kRed - 9) ;
  g_incertezza_MC.SetMarkerSize (2) ;
  g_incertezza_MC.SetTitle("Metodo Crude Monte Carlo");
  g_incertezza_MC.GetHistogram ()->GetXaxis ()->SetTitle ("tempo di calcolo") ;
  g_incertezza_MC.GetHistogram ()->GetYaxis ()->SetTitle ("incertezza") ;
  g_incertezza_MC.Draw ("ALP") ;
   
  c1->Print ("esercizio9.png", "png") ;   
  delete c1;
                     
  return 0 ;
}




