/*
c++ -o main_03 `root-config --glibs --cflags` main_03.cpp
*/

#include "TH1F.h"
#include "TCanvas.h"

int main (int argc, char ** argv)
  {
    TH1F istogramma ("istogramma", "titolo", 10, -5., 5.) ;

    istogramma.Fill (2.2) ;
    istogramma.Fill (2.1) ;
    istogramma.Fill (-1.4) ;

    TCanvas c1 ;
    istogramma.SetFillColor (kOrange + 1) ;
    istogramma.GetXaxis ()->SetTitle ("asse x") ;
    istogramma.GetYaxis ()->SetTitle ("conteggi per bin") ;
    istogramma.Draw () ;
    c1.Print ("esempio.png", "png") ;

    return 0 ;
  }
