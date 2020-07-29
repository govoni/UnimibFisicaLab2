# Esercizi per la lezione 6

## Esercizio 6.1

Si scriva un programma che, fissato *NMAX* numero di eventi di un campione,
generi *NToys* toy experiment di quel campione e ne calcoli la media.

![linea](../immagini/linea.png)

## Esercizio 6.2 

Si Aggiunge al programma precedente un oggetto di tipo ```TH1F```
che visualizzi la distribuzione delle medie al variare dei toy experiment.

![linea](../immagini/linea.png)

## Esercizio 6.3

Si utilizzi la classe ```statistiche``` sviluppata durante la Lezione 4
per confrontare la deviazione standard della media calcolata per ogni singolo toy
con la deviazione standard del campione delle medie.
    
![linea](../immagini/linea.png)

## Esercizio 6.4

Si utilizzino due ```TGraph``` per confrontare l'evoluzione 
della deviazione standard della media calcolata per ogni singolo toy
con la deviazione standard del campione delle medie
al variare del numero di eventi generati in un singolo toy experiment.

![linea](../immagini/linea.png)

## Esercizio 6.5

Si implementi il metodo di integrazione hit-or-miss
con la funzione di esempio *f(x) = sin (x)*.
  * Si scriva l'algoritmo che calcola l'integrale come una funzione esterna al programma ```main```,
    facendo in modo che prenda come parametri di ingresso,
    oltre agli estremi lungo l'asse *x* e l'asse *y*,
    anche il numero di punti pseudo-casuali da generare.
  * Si faccia in modo che l'algoritmo ritorni un contenitore contenente due elementi:
    il primo elemento sia il valore dell'integrale,
    il secondo sia la sua incertezza.

![linea](../immagini/linea.png)

## Esercizio 6.6

Si inserisca il calcolo dell'integrale dell'esercizio precedente in un ciclo che,
al variare del numero *N* di punti generati, mostri il valore dell'integrale
e della sua incertezza.
  * Si utilizzi un ```TGraph``` per disegnare gli andamenti del valore dell'integrale
    e della sua incertezza, al variare di *N* con ragione logaritmica.

![linea](../immagini/linea.png)

## Esercizio 6.7


![linea](../immagini/linea.png)

## Esercizio 6.8


![linea](../immagini/linea.png)

## Esercizio 6.9
