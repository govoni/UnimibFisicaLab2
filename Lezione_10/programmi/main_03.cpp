/*
c++ -o main_03 `root-config --glibs --cflags` main_03.cpp
*/

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

#include "TH1F.h"
#include "TCanvas.h"
#include "TFile.h"

using namespace std ;

// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----

int main (int argc, char ** argv)
  {

    TH1F h_test ("h_test", "istogramma di test", 10, 0., 10) ;
    h_test.Fill (5.3) ;

    TFile f_out ("main_03.root", "recreate") ;
    h_test.Write () ;
    f_out.Close () ;

    return 0 ;
  }
