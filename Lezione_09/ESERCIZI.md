# Esercizi per la lezione 9

## Esercizio 9.1

Si scriva un programma che legge i numeri salvati nel file ```dati_esponenziali.txt```
e li scriva in un ```vector<double>```.
  * Si faccia in modo che il nome del file sia passato a linea di comando.
  * Si faccia in modo che il secondo argomneto a linea di comando, opzionale,
    sia il numero massimo di numeri da leggere dal file.  

![linea](../immagini/linea.png)

## Esercizio 9.2 

Si aggiunga al programma precedente il codice sorgente che calcoli la media, il valor minimo ed il valor massimo 
dei numeri inseriti.

![linea](../immagini/linea.png)

## Esercizio 9.3

Si aggiunga al programma precedente il codice sorgente che riempia un istogramma con i numeri presenti nel ```vector```
dove sono stati trasferiti
e che visualizzi l'istogramma a schermo.
 
![linea](../immagini/linea.png)

## Esercizio 9.4

Si scriva una libreria di funzioni per determinare il parametro &tau; della distribuzione esponenziale
utilizzata per generare gli eventi presenti nel file ```dati_esponenziali.txt```,
a partire dal ```vector``` di numeri creato negli esercizi precedenti.
  * Si implementino i prototipi delle funzioni presentate a lezione.
  * Si confronti il risultato ottenuto con la media dei numeri salvati nel ```vector```.
  * Come dipende il risultato dall'intervallo inziale passato alla funzione ```sezione_aurea_max```?

![linea](../immagini/linea.png)

## Esercizio 9.5

Si modifichi la funzione ```sezione_aurea_max```,
aggiungendo la stampa a schermo dei valori degli estremi dell'intevallo considerato ad ogni iterazione,
per osservarne il restringimento durante l'esecuzione del programma.

![linea](../immagini/linea.png)

## Esercizio 9.6

Si modifichi la funzione ```loglikelihood``` in modo che calcoli il logaritmo del prodotto
dei valori della funzione di densita' di probabilita', piuttosto che la somma dei singoli logaritmi.
Come cambia il comportamento dell'algoritmo?

![linea](../immagini/linea.png)

## Esercizio 9.7

Si utilizzi il metodo della bisezione per trovare i due punti 
*&tau; - &sigma;<sub>&tau;</sub>* e *&tau; + &sigma;<sub>&tau;</sub>* 
nel caso dell'esercizio precedente.
  * Si confronti il valore di *&sigma;<sub>&tau;</sub>* ottenuto in questo modo
    con quello calcolato a partire dalla media aritmetica
    dei numeri salvati nel ```vector```.

![linea](../immagini/linea.png)

## Esercizio 9.8

Utilizzando il generatore di numeri pseudo-casuali secondo una pdf esponenziale
sviluppato nella Lezione 4, si disegni la distribuzione di probabilita' dello stimatore di &tau;
in funzione del numero di eventi a disposizione per la stima.

![linea](../immagini/linea.png)

## Esercizio 9.9

Utilizzando il generatore di numeri pseudo-casuali secondo una pdf esponenziale
sviluppato nella Lezione 4, 
si calcoli la copertura dello stimatore di &tau;
e se ne disegni il valore al variare del numero di eventi a disposizione per la stima,
riempiendo un ```TGraph``` con il numero di eventi a disposizione sull'asse orizziontale
ed il valore della copertura sull'asse verticale.
  * Si scriva tutto nel medesimo programma, 
    facendo il modo che i punti lungo l'asse orizzontale vengano campionati in modo logaritmico.

![linea](../immagini/linea.png)

## Esercizio 9.10

In regime asintotico,
la distribuzione degli scarti *(&tau; - &tau;<sub>vero</sub>) / &sigma;<sub>&tau;</sub>* 
ha forma Normale.
  * Si utilizzi il metodo dei *toy experiment* per riempire l'istogramma degli scarti, 
    dato un numero di eventi per *toy experiment*.
  * Si calcoli la media e la sigma della distribuzione degli scarti
    e se ne disegni il valore al variare del numero di eventi a disposizione per la stima,
    riempiendo un ```TGraph``` con il numero di eventi a disposizione sull'asse orizziontale
    ed il valore del parametro sull'asse verticale.




