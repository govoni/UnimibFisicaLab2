# Esercizi per la lezione 6

## Esercizio 6.1

Si scriva un programma che, fissato un numero *NMAX*,
generi *NToys* toy experiment, 
ciascuno contenente un campione di *NMAX* eventi che seguano una distribuzione a scelta
e ne calcoli la media.

![linea](../immagini/linea.png)

## Esercizio 6.2 

Si aggiunga al programma precedente un oggetto di tipo ```TH1F```
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

Si implementi il metodo di integrazione crude-MC
con la funzione di esempio *f(x) = sin (x)*.
  * Si scriva l'algoritmo che calcola l'integrale come una funzione esterna al programma ```main```,
    facendo in modo che prenda come parametri di ingresso,
    oltre agli estremi lungo l'asse *x*,
    anche il numero di punti pseudo-casuali da generare.
  * Si faccia in modo che l'algoritmo ritorni un contenitore contenente due elementi:
    il primo elemento sia il valore dell'integrale,
    il secondo sia la sua incertezza.

![linea](../immagini/linea.png)

## Esercizio 6.8

Si inserisca il calcolo dell'integrale dell'esercizio precedente in un ciclo che,
al variare del numero *N* di punti generati, mostri il valore dell'integrale
e della sua incertezza.
  * Si utilizzi un ```TGraph``` per disegnare gli andamenti del valore dell'integrale
    e della sua incertezza, al variare di *N* con ragione logaritmica.
  * Si sovrapponga questo ```TGraph``` a quello ottenuto dallo svolgimento dell'Esercizio 6.6.

![linea](../immagini/linea.png)

## Esercizio 6.9

Si disegnino in due ```TGraph``` gli andamenti della precisione del calcolo dell'integrale,
per i due algoritmi di hit-or-miss e crude-MC, in funzione del tempo di calcolo 
corrispondente alle varie scelte del numero totale *N* di eventi pseudo-casuali generati.

![linea](../immagini/linea.png)

## Esercizio 6.10

Si utilizzi il metodo hit-or-miss per stimare l’integrale sotteso 
ad una disrtibuzione di probabilita' Gaussiana con *&mu;=0* e *&sigma;=1
in un generico intervallo *[a,b]*.
  * Si calcoli l'integrale contenuto entro gli intervalli *[-k&sigma;,k&sigma;]*
    al variare di k da *1* a *5*.

![linea](../immagini/linea.png)

## Esercizio 6.11

Si determini con il metodo della bisezione lo zero della funzione *g(x) = cos(x)*
nell'intervallo *(0, 4)*.
  * Quali controlli sono stati omessi, 
    nell'implementazione dell'algoritmo descritta nel testo della lezione,
    che potrebbero accelerare il risultato?

![linea](../immagini/linea.png)

## Esercizio 6.12

Si svolga l'esercizio precedente utilizzando una funzione ricorsiva.
  * Quale delle due implementazioni e' piu' rapida?

![linea](../immagini/linea.png)

## Esercizio 6.13

Si implementi una funzione che calcola il fattoriale di un numero 
utilizzando una funzione ricorsiva.

![linea](../immagini/linea.png)

## Esercizio 6.14

Si determini con il metodo della sezione aurea il minimo della funzione *g(x) = x<sup>2</sup> + 7.3x + 4*
nell'intervallo *(-10, 10)*.

![linea](../immagini/linea.png)

## Esercizio 6.15

Si svolga l'esercizio precedente utilizzando una funzione ricorsiva.
  * Quale delle due implementazioni e' piu' rapida?

![linea](../immagini/linea.png)

## Esercizio 6.16

Si svolgano i due esercizi precedenti cercando il massimo di una funzione a scelta.






