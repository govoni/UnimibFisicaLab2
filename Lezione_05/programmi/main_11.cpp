/*
c++ -o main_11 `root-config --glibs --cflags` main_11.cpp
*/

#include "TH1F.h"
#include "TCanvas.h"
#include "TApplication.h"

int main (int argc, char ** argv)
  {

    TH1F istogramma ("istogramma", "istogramma", 10, -5., 5.) ;

    istogramma.Fill (2.2) ;

    TApplication theApp ("theApp", &argc, argv) ;
    TCanvas c1 ;
    istogramma.Draw ("hist") ;

    theApp.Run () ;

    return 0 ;
  }

