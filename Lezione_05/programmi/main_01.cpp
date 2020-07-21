/*
c++ -o main_01 `root-config --glibs --cflags` main_01.cpp
*/

#include "TH1F.h"

int main (int argc, char ** argv)
  {
    TH1F istogramma ("istogramma", "istogramma", 10, -5., 5.) ;

    istogramma.Fill (2.2) ;

    return 0 ;
  }
