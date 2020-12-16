/*
 *  Lezione 11 - Esercizio 03
 *
 *  Si scriva un programma che effettui il fit degli eventi salvati nel file dati_2.txt 
 *  con il metodo della massima verosimiglianza e con il metodo dei minimi quadrati e 
 *  si confronti il risultato delle due tecniche, comparando i valori studiati 
 *  nell'esercizio 11.1 per i parametri e per la bontà del fit.
 */

// g++ -o Es03 es03.cpp `root-config --cflags --glibs`

#include <iostream>
#include <fstream>
#include <vector>

#include "TApplication.h"
#include "TFitResult.h"
#include "TH1F.h"
#include "TF1.h"

using std::cout;
using std::endl;

int main( int argc, char** argv ) {
    TApplication* app = new TApplication("App", &argc, argv);

    // Lettura file di dati
    std::ifstream dataFile("dati_2.txt");

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
    TH1F* hData = new TH1F("hData", "Es03", nBin, minValue, maxValue);

    for(size_t s = 0; s < data.size(); s++) {
        hData->Fill(data.at(s));
    }

    // Funzione di fit - minimi quadrati
    TF1* fModel = new TF1("fModel", "gausn(0)", minValue, maxValue);
    TFitResultPtr fit_MQ = hData->Fit("fModel", "RS");

    /* 
     * Funzione di fit - massima verosimiglianza
     *
     * La funzione è uguale alla precedente, si potrebbe ripetere il fit
     * usando ancora fModel
     *
     * hData->Fit("fModel", "RL");
     *
     * Creando due funzioni è possibile disegnarle entrambe allo stesso tempo
     */
    TF1* fModel_L = new TF1("fModel_L", "gausn(0)", minValue, maxValue);
    TFitResultPtr fit_ML = hData->Fit("fModel_L", "RLS");

    // Disegno istogramma e funzioni di fit
    hData->Draw();
    fModel->Draw("same");
    fModel_L->SetLineColor(kBlue);
    fModel_L->Draw("same");

    // Confronto tra i parametri
    cout.precision(3);
    cout << "Area" << endl;
    cout << "  MQ : " << fModel->GetParameter(0) << "\t+/- " << fModel->GetParError(0) << endl;
    cout << "  ML : " << fModel_L->GetParameter(0) << "\t+/- " << fModel_L->GetParError(0) << endl << endl;
    cout << "Media" << endl;
    cout << "  MQ : " << fModel->GetParameter(1) << "\t+/- " << fModel->GetParError(1) << endl;
    cout << "  ML : " << fModel_L->GetParameter(1) << "\t+/- " << fModel_L->GetParError(1) << endl << endl;
    cout << "Sigma" << endl;
    cout << "  MQ : " << fModel->GetParameter(2) << "\t+/- " << fModel->GetParError(2) << endl;
    cout << "  ML : " << fModel_L->GetParameter(2) << "\t+/- " << fModel_L->GetParError(2) << endl << endl;


    app->Run();
}
