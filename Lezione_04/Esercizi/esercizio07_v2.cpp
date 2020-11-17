/*
c++ -o testCentrale testCentrale.cpp `root-config --cflags --glibs`
*/

#include <iostream>

#include "TApplication.h"
#include "TCanvas.h"
#include "TH1D.h"
#include "TString.h"

#define NTOY 10000
#define MAXEXTR 20
#define NHISTO  20

double rand_range(const double min, const double max)
{
  return min + (max - min) * (rand() / static_cast<double>(RAND_MAX));
}

int main()
{
  srand(10);

  TApplication myApp("myApp", NULL, NULL);

  TCanvas c0("c0","c0", 10, 10, 700, 500);
  c0.Divide(4,5);

  // ############################
  // # CONST INTERNAL VARIABLES #
  // ############################
  const double min = -10;
  const double max =  10;
  const int nBins  = 100;

  TH1D arrHisto[NHISTO];
  for (unsigned int i = 0; i < NHISTO; i++)
    {
      TString myStr = "h";
      myStr += i;
      std::cout << "Histo name : " << myStr << std::endl;
      arrHisto[i] = TH1D(myStr, myStr, nBins, -5, 5);
    }

  // #############
  // # MEGA LOOP #
  // #############
  for (unsigned int k = 0; k < NHISTO; k++)
    for (unsigned int i = 0; i < NTOY; i++)
      {
        double avg  = 0;
        double sum2 = 0;
        unsigned int nExtr = (k+1) * MAXEXTR / NHISTO;
        for (unsigned int j = 0; j < nExtr; j++)
          {
            double val = rand_range(min, max);
            avg  += val;
            sum2 += val*val;
          }
        avg  /= nExtr;
        sum2 /= (nExtr * nExtr);
        // Var[x] = E[x^2] - E^2[x]
        // Var[x] = E[x^2]
        // z  = (avg - MEAN) / SIGMA
        arrHisto[k].Fill(avg / sqrt(sum2));
      }

  // #################
  // # VISUALIZATION #
  // #################
  for (unsigned int i = 0; i < NHISTO; i++)
    {
      c0.cd(i+1);
      arrHisto[i].Draw();
    }

  c0.Modified();
  c0.Update();

  myApp.Run();
  return 0;
}
