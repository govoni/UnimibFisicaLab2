#ifndef fisher_h
#define fisher_h

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>

#include "TH2F.h"
#include "TCanvas.h"

#include "../../Lezione_10/programmi/algebra_2.h"

/**
 lettura di file di testo contenente eventi 2D
 e trascrizione in un vector di vector.
 Il vector esterno contiene due elementi, 
 che sono a loro volta un vector<double>,
 ciascuno dei quali contiene il valore di una delle due variabili
*/
void leggiFile (std::vector<std::vector<double> > & data, std::string nome_file) ;

/**
 disegno in un istogramma bidimensionale del contenuto di un campione 2D,
 accessibile nel formato di vector<vector<double> > 
*/
TH2F * riempiIstogramma (const std::vector<std::vector<double> > & data, std::string histo_name) ;

/**
 calcolo di uno stimatore della matrice di covarianza di un campione 2D
 accessibile nel formato di vector<vector<double> > 
 con il metodo della sostituzione
*/
matrice determinaCovarianza (const std::vector<std::vector<double> > & data) ;

/**
 riempimento di un istogramma monodimensionale del contenuto di un campione 1D
 accessibile nel formato di vector<double> 
*/
TH1F * riempiIstogramma (const std::vector<double> & data, std::string histo_name) ;

/**
 disegno sovrapposto di due istogrammi 1D e stampa su file immagine,
 facendo in modo che gli istogrammi siano entrambi completamente visibili 
 nell'immagine
*/
void plotComparison (TH1F * h_1, TH1F * h_2, TCanvas & c1, std::string nome_file) ;


#endif