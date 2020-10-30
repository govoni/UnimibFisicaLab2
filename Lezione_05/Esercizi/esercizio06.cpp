/*
Esercizio 06:Si generalizzi l'esercizio precedente scrivendo una funzione che produca questo risultato a partire da una qualunque classe scritta per generare numeri casuali.

c++ -o esercizio06 esercizio06.cpp ../../Lezione_04/Esercizi/statistiche.cc `root-config --glibs --cflags` 
*/
#include <iostream>
#include <cmath>
#include <cstdlib>

#include "TH1F.h"
#include "TCanvas.h"
#include "TGraph.h"

//includere l'header file della classe statistiche
#include "../../Lezione_04/Esercizi/statistiche.h"  
#include "generatori.h"


float fgaus (float x)
{
   return exp (-0.5 * x * x) ; 
}



//----------------- MAIN -----------------
int main(){

    int dim = 10000000;  //numero massimo di eventi
    
    float x_min = -1.;
    float x_max = 1.;
    
    //definisco i TGraph
    TGraph g_sigma ;
    TGraph g_sigmaMedia ;
    
    TGraph g_sigma_tac ;
    TGraph g_sigmaMedia_tac ;
    
    TGraph g_sigma_tcl ;
    TGraph g_sigmaMedia_tcl ;
    
    //costruisco un oggetto della classe statistiche
    statistiche* stats = new statistiche(dim);
    
    //costruisco un oggetto della classe generatori
    generatori g_generatore;
  
    //rand_range()  
    for (int N_ev = 10 ; N_ev < dim ; N_ev = N_ev * 2)
      {
        int i = 0 ;      
        while (i++ < N_ev) stats->aggiungiNumero(g_generatore.rand_range (x_min, x_max)) ;
               
        g_sigma.SetPoint (g_sigma.GetN(), N_ev, stats->dev_standard()) ;
        g_sigmaMedia.SetPoint (g_sigmaMedia.GetN (), N_ev, stats->dev_standard_media()) ;

        stats->reset();
      }
        
     //TAC
     for (int N_ev = 10 ; N_ev < dim ; N_ev = N_ev * 2)
      {
       int i = 0 ;
        while (i++ < N_ev) stats->aggiungiNumero(g_generatore.rand_TAC (fgaus,x_min, x_max, 1.)) ;
        
        g_sigma_tac.SetPoint (g_sigma_tac.GetN(), N_ev, stats->dev_standard()) ;
        g_sigmaMedia_tac.SetPoint (g_sigmaMedia_tac.GetN (), N_ev, stats->dev_standard_media()) ;    
                
        stats->reset();
      }     
        
     //TCL
     for (int N_ev = 10 ; N_ev < dim ; N_ev = N_ev * 2)
      {
       int i = 0 ;
        while (i++ < N_ev) stats->aggiungiNumero(g_generatore.rand_TCL (x_min, x_max, 20)) ;
        
        g_sigma_tcl.SetPoint (g_sigma_tcl.GetN(), N_ev, stats->dev_standard()) ;
        g_sigmaMedia_tcl.SetPoint (g_sigmaMedia_tcl.GetN (), N_ev, stats->dev_standard_media()) ;   
        
        stats->reset();                      
      }

    //rand_range
    TCanvas *c1 = new TCanvas ("c1", "c1", 100, 100, 1000, 1000) ;

    c1->Divide(2,3); //divido la finestra del canvas in caselle in cui inserire i grafici
    c1->cd(1); //mi posiziono nella prima finestra per disegnare il grafico
    gPad->SetLogx () ; //scala logaritmica per quella casella
    g_sigma.SetTitle ("Sigma rand_range") ;
    g_sigma.SetMarkerStyle (20) ;
    g_sigma.SetMarkerColor (kAzure - 1) ;
    g_sigma.SetLineColor (kGray + 1) ;
    g_sigma.SetMarkerSize (2) ;
    g_sigma.GetHistogram ()->GetXaxis ()->SetTitle ("numero di eventi nel campione") ;
    g_sigma.GetHistogram ()->GetYaxis ()->SetTitle ("deviazione standard") ;
    g_sigma.Draw ("ALP") ;
    
    c1->cd(2); //mi posiziono nella seconda finestra per disegnare il grafico 
    gPad->SetLogx () ; //scala logaritmica per quella casella
    g_sigmaMedia.SetTitle ("Sigma media rand_range") ;
    g_sigmaMedia.SetMarkerStyle (20) ;
    g_sigmaMedia.SetMarkerColor (kAzure - 1) ;
    g_sigmaMedia.SetLineColor (kGray + 1) ;
    g_sigmaMedia.SetMarkerSize (2) ;
    g_sigmaMedia.GetHistogram ()->GetXaxis ()->SetTitle ("numero di eventi nel campione") ;
    g_sigmaMedia.GetHistogram ()->GetYaxis ()->SetTitle ("deviazione standard dalla media") ;
    g_sigmaMedia.Draw ("ALP") ;
        
   //TAC        
    c1->cd(3);
    gPad->SetLogx () ; //scala logaritmica per quella casella
    g_sigma_tac.SetTitle ("Sigma TAC") ; 
    g_sigma_tac.SetMarkerStyle (20) ;
    g_sigma_tac.SetMarkerColor (kAzure - 1) ;
    g_sigma_tac.SetLineColor (kGray + 1) ;
    g_sigma_tac.SetMarkerSize (2) ;
    g_sigma_tac.GetHistogram ()->GetXaxis ()->SetTitle ("numero di eventi nel campione") ;
    g_sigma_tac.GetHistogram ()->GetYaxis ()->SetTitle ("deviazione standard") ;
    g_sigma_tac.Draw ("ALP") ;
    
    c1->cd(4); 
    gPad->SetLogx () ; //scala logaritmica per quella casella
    g_sigmaMedia_tac.SetTitle ("Sigma media TAC") ;
    g_sigmaMedia_tac.SetMarkerStyle (20) ;
    g_sigmaMedia_tac.SetMarkerColor (kAzure - 1) ;
    g_sigmaMedia_tac.SetLineColor (kGray + 1) ;
    g_sigmaMedia_tac.SetMarkerSize (2) ;
    g_sigmaMedia_tac.GetHistogram ()->GetXaxis ()->SetTitle ("numero di eventi nel campione") ;
    g_sigmaMedia_tac.GetHistogram ()->GetYaxis ()->SetTitle ("deviazione standard dalla media") ;
    g_sigmaMedia_tac.Draw ("ALP") ;
           
    //TCL        
    c1->cd(5); 
    gPad->SetLogx () ; //scala logaritmica per quella casella
    g_sigma_tcl.SetTitle ("Sigma TCL") ;
    g_sigma_tcl.SetMarkerStyle (20) ;
    g_sigma_tcl.SetMarkerColor (kAzure - 1) ;
    g_sigma_tcl.SetLineColor (kGray + 1) ;
    g_sigma_tcl.SetMarkerSize (2) ;
    g_sigma_tcl.GetHistogram ()->GetXaxis ()->SetTitle ("numero di eventi nel campione") ;
    g_sigma_tcl.GetHistogram ()->GetYaxis ()->SetTitle ("deviazione standard") ;
    g_sigma_tcl.Draw ("ALP") ;
    
    c1->cd(6);  
    gPad->SetLogx () ; //scala logaritmica per quella casella
    g_sigmaMedia_tcl.SetTitle ("Sigma media TCL") ;
    g_sigmaMedia_tcl.SetMarkerStyle (20) ;
    g_sigmaMedia_tcl.SetMarkerColor (kAzure - 1) ;
    g_sigmaMedia_tcl.SetLineColor (kGray + 1) ;
    g_sigmaMedia_tcl.SetMarkerSize (2) ;
    g_sigmaMedia_tcl.GetHistogram ()->GetXaxis ()->SetTitle ("numero di eventi nel campione") ;
    g_sigmaMedia_tcl.GetHistogram ()->GetYaxis ()->SetTitle ("deviazione standard dalla media") ;
    g_sigmaMedia_tcl.Draw ("ALP") ;
   
    c1->Print ("esercizio6.png", "png") ;
    
    delete c1;
    delete stats;
    
    return 0;
}
