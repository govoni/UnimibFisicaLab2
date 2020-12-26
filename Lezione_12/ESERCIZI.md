# Esercizi per la lezione 12

## Esercizio 12.1

A partire dalla collezione di eventi salvati nel file [dati.txt](programmi/dati.txt):
  * si implementi un programma che trovi un cambio di variabile che decorreli linearmente le variabili *x* ed *y*
    a partire dalla matrice di correlazione del campione;
  * si utilizzi la classe ```TH2F``` di ```ROOT``` per visualizzare la distribuzione bidimensionale
    dei dati prima e dopo la decorrelazione.

![linea](../immagini/linea.png)

## Esercizio 12.2 

Si utilizzi il programma [main_01.cpp](programmi/main_01.cpp) per creare due campioni 
di eventi bidimensionali distribuiti come due gaussiane 
e scriverli ciascuno su un file di testo.

![linea](../immagini/linea.png)

## Esercizio 12.3

Si scriva un programma che determini il vettore ***f*** utilizzato per la costruzione del test statistico
del discriminante di Fisher e lo si applichi ai campioni generati nell'Esercizio 12.2.
 
![linea](../immagini/linea.png)

## Esercizio 12.4

Si riempiano gli istogrammi delle variabili *x* ed *y* dei due campioni generati all'Esercizio 12.2 e,
sfruttando il codice sorgente scritto nell'Esercizio 12.3, si riempia l'istogramma della variabile *t*.
Si disegnino i tre istogrammi per poi farne un confronto grafico.

![linea](../immagini/linea.png)

## Esercizio 12.5

Si costruisca la curva ROC per la separazione delle ipotesi corrispondenti ai due campioni generati all'Esercizio 12.2,
nei tre casi in cui la separazione sia fatta con la variabile *x*, *y* o *t*.

![linea](../immagini/linea.png)

## Esercizio 12.6

Si determini l'area sottesa dalle tre curve ROC costruite nell'esercizio 12.5.
