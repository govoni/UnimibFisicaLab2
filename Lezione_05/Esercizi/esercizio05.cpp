/*
Esercizio 05: Si calcolino la deviazione standard e la deviazione standard della media per una distribuzione di eventi uniforme sfruttando il generatore di eventi pseudo-casuali sviluppato nella Lezione 4 al variare del numero di eventi generato, con andamento logaritmico. Effettuando i calcoli delle statistiche con la classe statistiche sviluppata durante la Lezione 4:
Si mostri con un TGraph l'andamento della deviazione standard verso il numero di eventi.
Si mostri con un TGraph l'andamento della deviazione standard della media verso il numero di eventi.
Si confronti il valore ottenuto della deviazione standard con il valore atteso noti gli estremi della distribuzione uniforme.

c++ -o esercizio05 esercizio05.cpp ../../Lezione_04/Esercizi/statistiche.cc `root-config --glibs --cflags` 
*/
#include <iostream>
#include <cmath>
#include <cstdlib>

#include "TH1F.h"
#include "TCanvas.h"
#include "TGraph.h"

//includere l'header file della classe statistiche
#include "../../Lezione_04/Esercizi/statistiche.h"  


float rand_range (float min, float max)
  {
    return min + (max - min) * rand () / static_cast<float> (RAND_MAX) ;
  } 



//----------------- MAIN -----------------
int main(){

    int dim = 1000000;  //numero massimo di eventi
    
    float x_min = -5.;
    float x_max = 5.;
    
    //definisco i TGraph
    TGraph g_sigma ;
    TGraph g_sigmaMedia ;
    TGraph g_sigma_teorica ;
    TGraph g_sigmaMedia_teorica ;
    
    //costruisco un oggetto della classe statistiche
    statistiche* stats = new statistiche(dim);
    
    //Deviazione standard teorica: sqrt((1/12 * (b-a)^2))
    float sigma_teorica = 0;
    
    //Deviazione standard della media: sigma_teorica/sqrt(N)
    float sigmaMedia_teorica = 0;
    
    for (int N_ev = 10 ; N_ev < dim ; N_ev = N_ev * 2)
      {
        int i = 0 ;
        while (i++ < N_ev)  stats->aggiungiNumero(rand_range(x_min, x_max));
        
        sigma_teorica = sqrt((float(1)/12))*(x_max - x_min);
        sigmaMedia_teorica = sigma_teorica/sqrt(N_ev);
       
        g_sigma.SetPoint (g_sigma.GetN(), N_ev, stats->dev_standard()) ;
        g_sigma_teorica.SetPoint (g_sigma_teorica.GetN(), N_ev, sigma_teorica);
        g_sigmaMedia.SetPoint (g_sigmaMedia.GetN (), N_ev, stats->dev_standard_media()) ;
        g_sigmaMedia_teorica.SetPoint (g_sigmaMedia_teorica.GetN (), N_ev, sigmaMedia_teorica) ;

        stats->reset();
      }

    TCanvas c1 ("c1", "c1", 100, 100, 1000, 1000) ;
    c1.SetLogx () ; //scala logaritmica

    g_sigma.SetMarkerStyle (20) ;
    g_sigma.SetMarkerColor (kAzure - 1) ;
    g_sigma.SetLineColor (kGray + 1) ;
    g_sigma.SetMarkerSize (2) ;
    g_sigma.GetHistogram ()->GetXaxis ()->SetTitle ("numero di eventi nel campione") ;
    g_sigma.GetHistogram ()->GetYaxis ()->SetTitle ("deviazione standard") ;
    g_sigma.Draw ("ALP") ;
    
    g_sigma_teorica.SetMarkerStyle (20) ;
    g_sigma_teorica.SetMarkerColor (kRed - 4) ;
    g_sigma_teorica.SetLineColor (kRed - 8) ;
    g_sigma_teorica.SetMarkerSize (1.5) ;
    g_sigma_teorica.Draw ("LPSAME") ; //Disegno i valori teorici nello stesso grafico in modo da confrontarli
    
    c1.Print ("esercizio5_sigma.png", "png") ;

    //Disegno Sigma Media
    TCanvas c2 ("c2", "c2", 100, 100, 1000, 1000) ;
    c2.SetLogx () ; //scala logaritmica

    g_sigmaMedia.SetMarkerStyle (20) ;
    g_sigmaMedia.SetMarkerColor (kAzure - 1) ;
    g_sigmaMedia.SetLineColor (kGray + 1) ;
    g_sigmaMedia.SetMarkerSize (2) ;
    g_sigmaMedia.GetHistogram ()->GetXaxis ()->SetTitle ("numero di eventi nel campione") ;
    g_sigmaMedia.GetHistogram ()->GetYaxis ()->SetTitle ("deviazione standard dalla media") ;
    g_sigmaMedia.Draw ("ALP") ;
    
    g_sigmaMedia_teorica.SetMarkerStyle (20) ;
    g_sigmaMedia_teorica.SetMarkerColor (kRed - 4) ;
    g_sigmaMedia_teorica.SetLineColor (kRed - 8) ;
    g_sigmaMedia_teorica.SetMarkerSize (1.5) ;
    g_sigmaMedia_teorica.Draw ("LPSAME") ; //Disegno i valori teorici nello stesso grafico in modo da confrontarli
       
    c2.Print ("esercizio5_sigmaMedia.png", "png") ;

    delete stats;
    
    return 0;
}
