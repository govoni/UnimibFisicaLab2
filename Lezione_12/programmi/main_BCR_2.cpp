#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include "TStyle.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TGraph.h"
#include "TF1.h"
#include "TF2.h"
#include "TH2F.h"
#include "TApplication.h"
#include "TRandom3.h"
using namespace std;

// c++ -o BCR2  `root-config --cflags --glibs`   main_BCR_2.cpp


float fgaus (float x, double mean, double sigma) {
    if (sigma == 0.) {
		cerr << "la sigma di una gaussiana non puo' essere nulla" << endl ;
        exit (1) ;
      }
    return exp (-0.5 * (x - mean) * (x - mean) / (sigma * sigma)) / (2.5066 * sigma) ; 
  }
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----

float rand_range (float min, float max){
    return min + (max - min) * rand () / static_cast<float> (RAND_MAX) ;
  } 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----
float rand_TAC_gaus (float media, float sigma){
    double xMin = media - 3 * sigma ;
    double xMax = media + 3 * sigma ;
    double yMax = 1. / (2.5066 * sigma) ;
    double x = 0. ;
    double y = 0. ; 
    do {
      x = rand_range (xMin, xMax) ;
      y = rand_range (0, yMax) ;
    } while (y > fgaus (x, media, sigma)) ;
    return x ; 
  }
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----
double massimo (double a, double b) {
	if (a>b) return a;
	else return b;
	}
	
double minimo (double a, double b) {
	if (a<b) return a;
	else return b;
	}	
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----
double binormal(double *x, double *p){
	 double mux=p[0]; double sigmax=p[1];
	 double muy=p[2]; double sigmay=p[3];
	 double arg;
	 if(sigmax>0 && sigmay>0) {
	    arg= ( pow( (x[0]-mux)/sigmax,2) + pow( (x[1]-muy)/sigmay,2) );
		arg=1/(2.*acos(-1)*sigmax*sigmay)*exp(- 1./2* arg);
		}
	 else arg=1e30;
	 return arg*p[4]; //ho aggiunto la normalizzazione
	 }
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----
double loglike(double *x, double *p){
	 if(p[1]*p[3]*p[5]*p[7]==0) return 1e30; //evito divisione per zero
	 double arg = - ( pow( (x[0]-p[0])/p[1],2) + pow( (x[1]-p[2])/p[3],2) );
	 arg+= ( pow( (x[0]-p[4])/p[5],2) + pow( (x[1]-p[6])/p[7],2) );
	 return arg;
	 }
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----
int main(int argc, char** argv){
	
	if (argc < 4)
    {
      cerr << "uso: " << argv[0] << " media0_x sigma0_x media0_y sigma0_y  " << endl ;
      cerr << "ad esempio:\n " 
           << argv[0] << "  1.  0.8  2. 0.15" << endl ;
      exit (1) ;
    }

    double par[5];
    for (int i=0;i<4;i++){
		par[i]=atof(argv[i+1]);
	}
    par[4]=1; //questa è la normalizzazione della pdf
    
	TApplication myApp("App", NULL, NULL);

	
	gRandom->SetSeed(0);
	
	int npar=5;
	int nsigma=3;
    double xmin=par[0]-nsigma*par[1];
    double xmax=par[0]+nsigma*par[1];
    
    double ymin=par[2]-nsigma*par[3];
    double ymax=par[2]+nsigma*par[3];
    
    
	TF2 *f0 = new TF2("f0",binormal,xmin,xmax,ymin,ymax,npar);
	f0->SetTitle("P(t|H_0)");
	f0->SetParameters(par);
	f0->SetNpx(200);
	f0->SetNpy(200);
	
	int nbin=15;
	TH2F *h2A=new TH2F("h2A","h2A",nbin,xmin,xmax,nbin,ymin,ymax);
	TH2F *h2B=new TH2F("h2B","h2B",nbin,xmin,xmax,nbin,ymin,ymax);
	
	double x,y;
	
	int Nev=10000;

	for (int i = 0 ; i < Nev ; ++i){
      x = rand_TAC_gaus (par[0], par[1]) ;
      y = rand_TAC_gaus (par[2], par[3]) ;

	  h2A->Fill(x,y);
      f0->GetRandom2(x,y);
      h2B->Fill(x,y);
    }
	
	TCanvas c1;
	c1.Divide(3,1);
	
	
	c1.cd(1);
	f0->GetXaxis()->SetTitle("x");
	f0->GetYaxis()->SetTitle("y");
	f0->DrawClone("cont1z");
	
	gStyle->SetOptFit(11111);
	c1.cd(2);
	h2A->GetXaxis()->SetTitle("x");
	h2A->GetYaxis()->SetTitle("y");
	h2A->SetMarkerStyle(2);
	h2A->Draw("colz");
	h2A->Fit("f0","L ");
	cout<<"RandTAC "<<f0->GetProb()<<endl;
	
	c1.cd(3);
	h2B->GetXaxis()->SetTitle("x");
	h2B->GetYaxis()->SetTitle("y");
	h2B->SetMarkerStyle(2);
	h2B->Draw("colz");
	h2B->Fit("f0"," L +");
	cout<<"GetRandom "<<f0->GetProb()<<endl;


	
	myApp.Run();
	
	return 0;
}
