/*
 *  Lezione 11 - Esercizio 4
 *
 * Si inserisca il codice sorgente dell'esercizio precedente in un ciclo che effettui il confronto 
 * al variare del numero di eventi considerato per il fit, da 20 a 10000, con andamento regolare 
 * in scala logaritmica.

 *      -   Si utilizzino diversi TGraphErrors per disegnare l'andamento dei parametri e delle 
 *          loro incertezze al variare del numero di eventi, per i due tipi di stimatore.
 *      -   Quale stimatore risulta meno distorto, a bassa statistica?
 */

// g++ -o Es04 es04.cpp `root-config --cflags --glibs`

#include <iostream>
#include <fstream>
#include <vector> 
#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TGraphErrors.h"
#include "TF1.h"
#include "TFitResult.h"

using std::cout;
using std::endl;

int main( int argc, char** argv ) {
    TApplication* app = new TApplication("App", &argc, argv);

    // Grafici per i tre parametri dell'istogramma
    TGraphErrors* gArea = new TGraphErrors();
    TGraphErrors* gMedia = new TGraphErrors();
    TGraphErrors* gSigma = new TGraphErrors();
    TGraphErrors* gArea_L = new TGraphErrors();
    TGraphErrors* gMedia_L = new TGraphErrors();
    TGraphErrors* gSigma_L = new TGraphErrors();

    // Modello da cui estrarre per generare l'istogramma
    double minValue = 0;
    double maxValue = 20;
    TF1* fOriginal = new TF1("fOriginal", "gaus(0)", minValue, maxValue);
    // Integrale, media, sigma
    fOriginal->SetParameters(30, 10, 2);

    // Variazione del numero di eventi nell'istogramma
    TH1F* hData;
    TF1 *fModel, *fModel_L;
    for(int i = 1; i <= 30; i++) {
        // Facendo crescere in modo regolare l'esponente si hanno
        // punti equispaziati in scala logaritmica
        double ex = 1. + 0.1*i;
        int nEvents = pow(10, ex);

        int nBin = 30;
        hData = new TH1F("hData", "Es04", nBin, minValue, maxValue);

        // Riempio l'istogramma generando da una gaussiana
        for( int ev = 0; ev < nEvents; ev++ )  {
            double event = fOriginal->GetRandom();
            hData->Fill(event);
        }

        // Funzioni di fit

        fModel = new TF1("fModel", "gausn(0)", minValue, maxValue);
        fModel_L = new TF1("fModel_L", "gausn(0)", minValue, maxValue);

        // Fit dell'istogramma
        // L'opzione 0 (zero) fa in modo che il fit non venga disegnato
        hData->Fit("fModel", "R0Q");
        hData->Fit("fModel_L", "RL0Q");

        // Riempio i tre TGraphErrors per ogni fit
        gArea->SetPoint(i-1, nEvents, fModel->GetParameter(0));
        gArea->SetPointError(i-1, 0, fModel->GetParError(0));

        gMedia->SetPoint(i-1, nEvents, fModel->GetParameter(1));
        gMedia->SetPointError(i-1, 0, fModel->GetParError(1));

        gSigma->SetPoint(i-1, nEvents, fModel->GetParameter(2)); gSigma->SetPointError(i-1, 0, fModel->GetParError(2)); 
        gArea_L->SetPoint(i-1, nEvents, fModel_L->GetParameter(0));
        gArea_L->SetPointError(i-1, 0, fModel_L->GetParError(0));

        gMedia_L->SetPoint(i-1, nEvents, fModel_L->GetParameter(1));
        gMedia_L->SetPointError(i-1, 0, fModel_L->GetParError(1));

        gSigma_L->SetPoint(i-1, nEvents, fModel_L->GetParameter(2));
        gSigma_L->SetPointError(i-1, 0, fModel_L->GetParError(2));


        // A ogni step del ciclo ricordarsi di rimuovere istogramma e funzioni
        delete hData;
        delete fModel;
        delete fModel_L;
    }

    // Disegno i TGraphErrors
    TCanvas* cG = new TCanvas("cG", "Es04", 1600, 600);
    cG->Divide(3, 1);

    /*
     *  Area
     */
    cG->cd(1);
    // MQ
    gArea->SetMarkerStyle(7);
    gArea->SetMarkerColor(kBlack);
    gArea->SetLineColor(kBlack);
    gArea->GetXaxis()->SetTitle("Numero conteggi");
    gArea->GetYaxis()->SetTitle("Area");
    gArea->Draw("ap");
    gPad->SetLogx();

    // ML
    gArea_L->SetMarkerStyle(7);
    gArea_L->SetMarkerColor(kRed);
    gArea_L->SetLineColor(kRed);
    gArea_L->Draw("p,same");

    /*
     *  Media
     */
    cG->cd(2);
    // MQ
    gMedia->SetMarkerStyle(7);
    gMedia->SetMarkerColor(kBlack);
    gMedia->SetLineColor(kBlack);
    gMedia->GetXaxis()->SetTitle("Numero conteggi");
    gMedia->GetYaxis()->SetTitle("Media");
    gMedia->Draw("ap");
    gPad->SetLogx();

    // ML
    gMedia_L->SetMarkerStyle(7);
    gMedia_L->SetMarkerColor(kRed);
    gMedia_L->SetLineColor(kRed);
    gMedia_L->Draw("p,same");

    /*
     *  Sigma
     */
    cG->cd(3);
    // MQ
    gSigma->SetMarkerStyle(7);
    gSigma->SetMarkerColor(kBlack);
    gSigma->SetLineColor(kBlack);
    gSigma->GetXaxis()->SetTitle("Numero conteggi");
    gSigma->GetYaxis()->SetTitle("Sigma");
    gSigma->Draw("ap");
    gPad->SetLogx();

    // ML
    gSigma_L->SetMarkerStyle(7);
    gSigma_L->SetMarkerColor(kRed);
    gSigma_L->SetLineColor(kRed);
    gSigma_L->Draw("p,same");

    app->Run();
}
