/*
 *  Lezione 11 - Esercizio 01
 *
 *  Si scriva un programma che effettui il fit degli eventi salvati nel file dati.txt, 
 *  utilizzando gli algoritmi di ROOT ed il modello descritto nella Lezione.
 *
 *      -   Si abbia cura di determinare l'intervallo di definizione ed il binning dell'istogramma 
 *          utilizzato per il fit a partire dagli eventi medesimi, scrivendo algoritmi appropriati 
 *          che determinino il minimo ed il massimo fra i dati ed una stima ragionevole del numero 
 *          di bin da utilizzare.
 *      -   Si determinino i valori iniziali dei parametri del fit con le tecniche descritte a lezione.
 *      -   Si stampi a schermo il risultato del fit, includendo un test di bontà del fit.
 *      -   Si disegni l'istogramma con il modello fittato sovrapposto.
 */

// g++ -o Es01 es01.cpp `root-config --cflags --glibs`

#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>

#include "TStyle.h"
#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TF1.h"
#include "TFitResult.h"

using std::cout;
using std::endl;

int main( int argc, char** argv ) {

    TApplication* app = new TApplication("App", &argc, argv);

    // Lettura file di dati
    std::ifstream dataFile("dati.txt");

    // Valore minimo e massimo letto nel file
    double minValue = 1e10;
    double maxValue = -1e10;

    double val;
    std::vector<double> data;
    while(true) {
        dataFile >> val;
        if( dataFile.eof() )
            break;
        data.push_back(val);    

        // Aggiornare minimo e massimo
        if( val < minValue )
            minValue = val;
        if( val > maxValue )
            maxValue = val;
    }
    dataFile.close();

    // Istogramma 
    int nBin = data.size()/50;
    TH1F* hData = new TH1F("hData", "Es01", nBin, minValue, maxValue);

    for(size_t s = 0; s < data.size(); s++) {
        hData->Fill(data.at(s));
    }

    /*
     *  ==========================
     *      Parametri iniziali
     *  ==========================
     */

    // Esponenziale
    TF1* fExp = new TF1("fExp", "expo(0)", 0, 5);
    fExp->SetLineColor(kBlue);
    hData->Fit("fExp", "RQ");

    // Gaussiana
    TF1* fGaus = new TF1("fGaus", "gaus(0)", 6, 14);
    fGaus->SetLineColor(kBlue);
    hData->Fit("fGaus", "RQ");

    /*
     *  ==========================
     *      Modello completo
     *  ==========================
     */
    TF1* fModel = new TF1("fModel", "expo(0) + gausn(2)", minValue, maxValue);

    // Primi due parametri: esponenziale
    fModel->SetParameter(0, fExp->GetParameter(0));
    fModel->SetParameter(1, fExp->GetParameter(1));
    // Altri parametri: gaussiana
    fModel->SetParameter(2, fGaus->GetParameter(0));
    fModel->SetParameter(3, fGaus->GetParameter(1));
    fModel->SetParameter(4, fGaus->GetParameter(2));

    // Assegno dei nomi ai parametri della funzione
    fModel->SetParName(0, "Norm. exp.");
    fModel->SetParName(1, "Pendenza exp.");
    fModel->SetParName(2, "Area segnale");
    fModel->SetParName(3, "Media segnale");
    fModel->SetParName(4, "Sigma segnale");

    // Fit
    TFitResultPtr fitResult = hData->Fit("fModel", "RQS");

    /*
     *  ==========================
     *      Stampa a schermo del risultato
     *  ==========================
     */


    // Controllo qualità del fit
    bool fitValid = fitResult->IsValid();
    if( fitValid ) {
        cout << "Il fit ha avuto successo" << endl;
    } else {
        cout << "Il fit è fallito!" << endl;
    }

    double chi = fitResult->Chi2();
    double prob = fitResult->Prob();

    cout << "Chi2 associato al fit: " << chi << endl;
    cout << "Probabilità: " << prob << endl;

    if( prob < 0.05 ) {
        cout << "Il fit ha una probabilità < 5%!" << endl;
    }

    // Stampa dei parametri del fit
    double evFondo = exp( fModel->GetParameter(0) );
    double errEvFondo = fModel->GetParError(0) * evFondo;

    cout.precision(3);
    cout << "Eventi di fondo    : " << evFondo << "\t+/- " << errEvFondo << endl;
    cout << "Pendenza del fondo : " << fModel->GetParameter(1) << "\t+/- " << fModel->GetParError(1) << endl;
    cout << "Eventi di segnale  : " << fModel->GetParameter(2) << "\t+/- " << fModel->GetParError(2) << endl;
    cout << "Media del segnale  : " << fModel->GetParameter(3) << "\t+/- " << fModel->GetParError(3) << endl;
    cout << "Sigma del segnale  : " << fModel->GetParameter(4) << "\t+/- " << fModel->GetParError(4) << endl;

    /*
     *  Disegna l'istogramma
     *
     *  La funzione viene automaticamente associata all'istogramma che si è fittato,
     *  quindi viene già sovrapposta nel plot.
     *  Se si volesse disegnare una funzione (per esempio, una delle due funzioni
     *  usate per stimare i parametri):
     *
     *  fExp->Draw("same");
     */
    // Stampa i risultati del fit anche sul canvas
    gStyle->SetOptFit(1111);

    hData->GetXaxis()->SetTitle("x");
    hData->GetYaxis()->SetTitle("Conteggi");

    hData->Draw();

    app->Run();
}
