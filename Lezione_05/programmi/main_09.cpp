/*
c++ -o main_09 `root-config --glibs --cflags` main_09.cpp
*/

#include <cstdlib>
#include <iostream>
#include "TH1F.h"
#include <TGraph.h>
#include <TCanvas.h>
#include "statistiche.h"

float rand_range (float min, float max)
  {
    return min + (max - min) * rand () / static_cast<float> (RAND_MAX) ;
  } 


int main (int argc, char ** argv)
  {
    if (argc < 2) 
      {
        std::cerr << "uso del programma: " << argv[0] << " NMAX" << std::endl ;
        return 1 ;
      }

    int NMAX = atoi (argv[1]) ;
    statistiche s_eventi ;

    TGraph g_sigma ;
    TGraph g_sigmaMedia ;
    for (int N = 10 ; N < NMAX ; N = N * 2)
      {
        int i = 0 ;
        while (i++ < N) s_eventi.addEvent (rand_range (-3., 3.)) ;

        g_sigma.SetPoint (g_sigma.GetN (), N, s_eventi.getSigma ()) ;
        g_sigmaMedia.SetPoint (g_sigmaMedia.GetN (), N, s_eventi.getSigmaMean ()) ;

        s_eventi.reset () ;
      }

    TCanvas c1 ("c1", "c1", 100, 100, 1000, 1000) ;
    c1.SetLogx () ;

    g_sigma.SetMarkerStyle (20) ;
    g_sigma.SetMarkerColor (kAzure - 1) ;
    g_sigma.SetLineColor (kGray + 1) ;
    g_sigma.SetMarkerSize (2) ;
    g_sigma.GetHistogram ()->GetYaxis ()->SetRangeUser (0., 2.) ;
    g_sigma.GetHistogram ()->GetXaxis ()->SetTitle ("numero di eventi nel campione") ;
    g_sigma.GetHistogram ()->GetYaxis ()->SetTitle ("deviazione standard") ;
    g_sigma.Draw ("ALP") ;
    c1.Print ("sigmaTrend.png", "png") ;

    g_sigmaMedia.SetMarkerStyle (20) ;
    g_sigmaMedia.SetMarkerColor (kAzure - 1) ;
    g_sigmaMedia.SetLineColor (kGray + 1) ;
    g_sigmaMedia.SetMarkerSize (2) ;
    g_sigmaMedia.GetHistogram ()->GetXaxis ()->SetTitle ("numero di eventi nel campione") ;
    g_sigmaMedia.GetHistogram ()->GetYaxis ()->SetTitle ("deviazione standard dalla media") ;
    g_sigmaMedia.Draw ("ALP") ;
    c1.Print ("sigmaMediaTrend.png", "png") ;


    return 0 ;
  }
