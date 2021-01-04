#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <vector>
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


double massimo (double a, double b) {
	if (a>b) return a;
	else return b;
	}
	
double minimo (double a, double b) {
	if (a<b) return a;
	else return b;
	}
// c++ -o BCR4  `root-config --cflags --glibs`   main_BCR_4.cpp

float fgaus (float x, double mean, double sigma) 
  {
    if (sigma == 0.) 
      {
        cerr << "la sigma di una gaussiana non puo' essere nulla" << endl ;
        exit (1) ;
      }
    return exp (-0.5 * (x - mean) * (x - mean) / (sigma * sigma)) / (2.5066 * sigma) ; 
  }


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----


float rand_range (float min, float max)
  {
    return min + (max - min) * rand () / static_cast<float> (RAND_MAX) ;
  } 


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----


float rand_TAC_gaus (float media, float sigma)
  {
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

double binormal(double *x, double *p){
	 double mux=p[0]; double sigmax=p[1];
	 double muy=p[2]; double sigmay=p[3];
	 double arg;
	 if(sigmax>0 && sigmay>0) {
	    arg= ( pow( (x[0]-mux)/sigmax,2) + pow( (x[1]-muy)/sigmay,2) );
		arg=1/(2.*acos(-1)*sigmax*sigmay)*exp(- 1./2* arg);
		}
	 else arg=1e30;
	 return arg;
	 }
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----

double loglike(double *x, double *p){
	 if(p[1]*p[3]*p[5]*p[7]==0) return 1e30; //evito divisione per zero
	 double arg = - ( pow( (x[0]-p[0])/p[1],2) + pow( (x[1]-p[2])/p[3],2) );
	 arg+= ( pow( (x[0]-p[4])/p[5],2) + pow( (x[1]-p[6])/p[7],2) );
	 return arg;
	 }
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----

double sizetest(double c_alpha, TF2 *lratio, TF2 *f0){
	int nhit=0;
	int Ntoy=60000;
	double x,y;
	for (int i=0;i<Ntoy;i++){
		f0->GetRandom2(x,y);
		if (lratio->Eval(x,y)<c_alpha) nhit++;
		}
	 return (nhit*1.)/Ntoy;
	}
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----

double DeterminaBCR(TF2 *lratio, TF2 *f0, double alpha, TGraph *gsize) {
	double x,y;
	double lratio_min=lratio->GetMinimumXY(x,y);
	double lratio_max=lratio->GetMaximumXY(x,y);
	
	cout<<"lr min "<<lratio_min<<endl;
	cout<<"lr max "<<lratio_max<<endl;
	
	int npoints=1000;
	double step=(lratio_max-lratio_min)/npoints;
	double c_alpha,size;
	double C_alpha=lratio_min;
	for (int j=0;j<npoints;j++){
		c_alpha=lratio_min+j*step;
		size=sizetest(c_alpha, lratio, f0);
	    if (size<alpha) C_alpha=c_alpha;
	    gsize->SetPoint(j,c_alpha,size);
	}
	return C_alpha;
	}

// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----

int main(int argc, char** argv){
	
	if (argc < 9)
    {
      cerr << "uso: " << argv[0] << " media0_x sigma0_x media0_y sigma0_y  media1_x sigma1_x media1_y sigma1_y SIZE" << endl ;
      cerr << "ad esempio:\n " 
           << argv[0] << "  1.  0.8  2. 0.15  2.4  0.7  2.  0.75 0.05" << endl ;
      exit (1) ;
    }

    double par[8];
    for (int i=0;i<8;i++){
		par[i]=atof(argv[i+1]);
	}
	double alpha=atof(argv[8]);

	TApplication myApp("App", NULL, NULL);

	int npar=5;
	int nsigma=3;
    double xmin=minimo(par[0]-nsigma*par[1], par[4]-nsigma*par[5]);
    double xmax=massimo(par[0]+nsigma*par[1], par[4]+nsigma*par[5]);
    double ymin=minimo(par[2]-nsigma*par[3], par[6]-nsigma*par[7]);
    double ymax=massimo(par[2]+nsigma*par[3], par[6]+nsigma*par[7]);
          
	TF2 *f0 = new TF2("f0",binormal,xmin,xmax,ymin,ymax,npar);
	f0->SetTitle("P(t|H_0)");
	f0->SetParameters(par);
	TF2 *f1 = new TF2("f1",binormal,xmin,xmax,ymin,ymax,npar);
	f1->SetTitle("P(t|H_1)");
	f1->SetParameters(par+4);
	f0->SetNpx(500);
	f0->SetNpy(500);
	f1->SetNpx(500);
	f1->SetNpy(500);
	
	TF2 *lratio = new TF2("lratio",loglike,xmin,xmax,ymin,ymax,8); 
	lratio->SetParameters(par);
	lratio->SetNpx(500);
	lratio->SetNpy(500);
	
	TCanvas c1;
	c1.Divide(3,2);
	
	c1.cd(1);
	f0->GetXaxis()->SetTitle("x");
	f0->GetYaxis()->SetTitle("y");
	f0->DrawClone("cont1z");
	
	c1.cd(2);
	f1->GetXaxis()->SetTitle("x");
	f1->GetYaxis()->SetTitle("y");
	f1->DrawClone("cont1z");
	
	c1.cd(3);
	lratio->DrawClone("cont1z");
	lratio->GetXaxis()->SetTitle("x");
	lratio->GetYaxis()->SetTitle("y");
	
	TGraph *gsize=new TGraph();
	double c_alpha=DeterminaBCR(lratio, f0, alpha, gsize);
	
	c1.cd(5);
	gsize->Draw("AP*");
	gsize->GetXaxis()->SetTitle("c_#alpha");
	gsize->GetYaxis()->SetTitle("size");
	
	c1.cd(4);
	lratio->SetMaximum(c_alpha);
	lratio->Draw("cont3");
	f1->Draw("cont1z same");
	f0->Draw("cont1z same ");
	
	double beta;
	TGraph *roc=new TGraph();
	for (int i=0;i<gsize->GetN();i++){
		beta=1-sizetest(gsize->GetPointX(i), lratio, f1);
		roc->SetPoint(i,gsize->GetPointY(i),beta);
		}
	c1.cd(6);
	roc->Draw("AP*");
	roc->GetXaxis()->SetTitle("#alpha");
	roc->GetYaxis()->SetTitle("#beta");
	
	cout<<"POWER del test "<<sizetest(c_alpha, lratio, f1)<<endl;
	myApp.Run();
	
	return 0;
}
