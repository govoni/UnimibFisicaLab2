/*
c++ -o main_00 `root-config --glibs --cflags` main_00.cpp
*/

#include "TH1F.h"

int main (int argc, char ** argv)
  {
    TH1F istogramma ("istogramma", "titolo", 10, -5., 5.) ;

    return 0 ;
  }
