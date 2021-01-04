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

// c++ -o BCR3  `root-config --cflags --glibs`   main_BCR_3.cpp

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
double sizetest(double c_alpha, TF2 *lratio, TF2 *f0, int Ntoy){
	int nhit=0;
	double x,y;
	for (int i=0;i<Ntoy;i++){
		f0->GetRandom2(x,y);
		if (lratio->Eval(x,y)<c_alpha) nhit++;
		}
	 return (nhit*1.)/Ntoy;
	}
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----

int main(int argc, char** argv){
	
	if (argc < 8)
    {
      cerr << "uso: " << argv[0] << " media0_x sigma0_x media0_y sigma0_y  media1_x sigma1_x media1_y sigma1_y" << endl ;
      cerr << "ad esempio:\n " 
           << argv[0] << "  1.  0.8  2. 0.15  2.4  0.7  2.  0.75" << endl ;
      exit (1) ;
    }

    double par[8];
    for (int i=0;i<8;i++){
		par[i]=atof(argv[i+1]);
	}

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
	f1->SetNpx(200);
	f1->SetNpy(200);
	
	TF2 *lratio = new TF2("lratio",loglike,xmin,xmax,ymin,ymax,8); 
	lratio->SetParameters(par);
	lratio->SetNpx(1000);
	lratio->SetNpy(1000);
	
	double x,y;
	double lratio_min=lratio->GetMinimumXY(x,y);
	double lratio_max=lratio->GetMaximumXY(x,y);
	
	cout<<"lr min "<<lratio_min<<endl;
	cout<<"lr max "<<lratio_max<<endl;
    
    double c_alpha=lratio_max/2;
    double size;
    int Ntoys;
    TGraph *gra=new TGraph();
	for (int i=0;i<100;i++){
		Ntoys=100+1000*i;
		size=sizetest(c_alpha, lratio, f0, Ntoys);
		gra->SetPoint(i,Ntoys,size);
		cout<<Ntoys<<" "<<size<<endl;
		}
	
	
	TCanvas c1;
	c1.Divide(2,2);
	
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
	
	c1.cd(4);
	gra->Draw("A*");
	
	myApp.Run();
	
	return 0;
}
