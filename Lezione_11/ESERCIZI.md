# Esercizi per la lezione 11

## Esercizio 11.1

Si scriva un programma che effettui il fit degli eventi salvati nel file [dati.txt](programmi/dati.txt),
utilizzando gli algoritmi di ```ROOT``` ed il modello descritto nella Lezione.
  * Si abbia cura di determinare l'intervallo di definizione ed il binning dell'istogramma utilizzato per il fit
    a partire dagli eventi medesimi,
    scrivendo algoritmi appropriati che determinino il minimo ed il massimo fra i dati
    ed una stima ragionevole del numero di bin da utilizzare.
  * Si determinino i valori iniziali dei parametri del fit 
    con le tecniche descritte a lezione.
  * Si stampi a schermo il risultato del fit,
    includendo un test di bontà del fit.
  * Si disegni l'istogramma con il modello fittato sovrapposto.  

![linea](../immagini/linea.png)

## Esercizio 11.2 

Utilizzando il programma [main_01.cpp](programmi/main_01.cpp),
si generi un file ```dati_2.txt``` contenente 10 milioni di eventi.

![linea](../immagini/linea.png)

## Esercizio 11.3
 
Si scriva un programma che,
a partire dal file ```dati_2.txt```, 
effettui il fit dell'Esercizio 1 al variare del numero di eventi considerato.
  * Si faccia in modo che il numero di eventi considerato vari tramite un ciclo,
    secondo una ragione logaritmica.
  * Si scrivano gli algoritmi di determinazione del numero di bin dell'istogramma
    e della determinazione dei valori iniziali dei parametri.
    in modo che siano funzionali per tutti i valori del numero di eventi considerato.
  * Si riempia, per ogni parametro *&theta;<sub>j</sub>* del modello,
    un ```TGraph``` contenente il valore delle incertezze su quel parametro,
    in funzione del numero di eventi considerato nel fit.
  * Si riempia, per ogni parametro *&theta;<sub>j</sub>* del modello, 
    un ```TGraphErrors``` contenente il valore del parametro relativo 
    in funzione del numero di eventi considerato nel fit,
    avente come incertezza orizzontale ```0``` e verticale
    quella sul parametro desulta dal fit.
  * Si riempiano i grafici soltanto nel caso in cui il fit abbia avuto convergenza
    e sia considerato accettabile con un test di bontà del fit.  
  * Si visualizzino i tutti i ```TGraph``` e ```TGraphErrors```.
  * Si salvino tutti i ```TGraph``` e ```TGraphErrors``` in un file di tipo ```.root```.  

![linea](../immagini/linea.png)

## Esercizio 11.4

![linea](../immagini/linea.png)

## Esercizio 11.5

![linea](../immagini/linea.png)

## Esercizio 11.6

