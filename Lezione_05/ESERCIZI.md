# Esercizi per la lezione 5

## Esercizio 5.1

Si riempia un istogramma con gli eventi generati con il generatore di numeri pseudo-casuali
lineare congruenziale, verificando che tipo di distribuzione segua.

![linea](../immagini/linea.png)

## Esercizio 5.2 

Riempire un istogramma con eventi eventi pseudo-casuali
distribuiti uniformemente fra due numeri passati da linea di comando al programma.
  * Si utilizzi la funzione ```rand ()``` come punto di partenza 
    per l'implementazione del generatore uniforme

![linea](../immagini/linea.png)

## Esercizio 5.3

Si riempia un istogramma con eventi pseudo-casuali con distribuzione 
*f(x) = |sin(x)|* con *x* definito fra *0* e *2&pi;*
generati con la tecnica di try-and-catch
  * si utilizzi la funzione ```rand ()``` come punto di partenza 
    per l'implementazione del generatore uniforme
    
![linea](../immagini/linea.png)

## Esercizio 5.4

Si riempia un istogramma con eventi pseudo-casuali con forma Gaussiana
generati con la tecnica del teorema centrale del limite,
sommando distribuzioni uniformi.
  * Si utilizzi la funzione ```rand ()``` come punto di partenza 
    per l'implementazione del generatore uniforme.
  * Si disegni la distribuzione ottenuta riempiendo diversi istogrammi,
    ciascuno corrispondente ad un numero diverso di distribuzioni uniformi sommate,
    partendo da *1* fino a *20*.

![linea](../immagini/linea.png)

## Esercizio 5.5

Si calcolino la deviazione standard e la deviazione standard della media
per una distribuzione di eventi uniforme
sfruttando il generatore di eventi pseudo-casuali sviluppato nella Lezione 4
al variare del numero di eventi generato, con andamento logaritmico.
Effettuando i calcoli delle statistiche 
con la classe ```statistiche``` sviluppata durante la Lezione 4:
  * Si mostri con un ```TGraph``` l'andamento della deviazione standard verso il numero di eventi.
  * Si mostri con un ```TGraph``` l'andamento della deviazione standard della media verso il numero di eventi.
  * Si confronti il valore ottenuto della deviazione standard con il valore atteso 
    noti gli estremi della distribuzione uniforme.  

![linea](../immagini/linea.png)

## Esercizio 5.6

Si generalizzi l'esercizio precedente scrivendo una funzione
che produca questo risultato a partire da una qualunque classe 
scritta per generare numeri casuali.


![linea](../immagini/linea.png)

## Esercizio 5.7

Si crei e riempia un ```TH2F``` che contenga una Gaussiana bidimensionale nel piano *(x,y)* 
centrata in (0., 0.) con *&sigma;<sub>x</sub> = &sigma;<sub>y</sub> = 2.*,
generata con la tecnica del teorema centrale del limite,
ricordando che una distribuzione di probabilita' Gaussiana bi-dimnesionale 
si ottiene facendo il prodotto di due distribuzioni di probabilita' Gaussiane mono-dimensionali.

![linea](../immagini/linea.png)

## Esercizio 5.8

Si crei e riempia un ```TH2F``` che contenga una distribuzione uniforme 
bidimensionale, con *x* definito fra *0.* ed *1.* 
ed *y* definito fra *-1.* e *3.*.

![linea](../immagini/linea.png)

## Esercizio 5.9

Si renda interattivo l'output del programma precedente tramite un oggetto di tipo ```TApplication```
e si provino le varie funzionalita' di interfaccia.

