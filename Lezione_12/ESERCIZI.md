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
![linea](../immagini/linea.png)

## Esercizio 12.7

Si scriva un programma che definisca una funzione binormale ```double binormale (double* x, double* y)``` 
con correlazione nulla tra le  due variabili :
* si utilizzi la classe ```TF2``` di ```ROOT``` per disegnare la funzione
* si estraggano N coppie di numeri casuali che seguano la distribuzione 
  binormale usando il metodo previsto dall'esercizio 12.5
* si riempia un istogramma di tipo ```TH2F```, lo si disegni e ne si faccia il fit con la funzione
  binormale
![linea](../immagini/linea.png)  
  
## Esercizio 12.8
    
Si ripeta l'esercizio precedente usando il metodo ```GetRandom(double x,double y)``` della ```TF2``` 
come descritto nella seconda parte della lezione:
* includere una classe per la generazione di numeri casuali, come```TRandom3.h```
* inizializzare nel main il seed con l'istruzione ```gRandom->SetSeed(0); ```)

![linea](../immagini/linea.png)  
  
## Esercizio 12.9

Scrivere un programma in cui nel main sono definite:
* due funzioni di tipo ```TF2``` che rappresentano due differenti pdf(x,y)
  * ```TF2 * f0``` sarà quella relativa all'ipotesi H<sub>0<\sub>
  * ```TF2 * f1``` sarà quella relativa all'ipotesi H<sub>1<\sub>
* una funzione ```TF2``` che rappresenta il logaritmo del rapporto di likelihood tra 
le due pdf nel caso di un singolo campionamento 
(quindi è la differenza tra i logaritmi delle due pdf)

Disegnare le due pdf in un ```Canvas``` e il rapporto di likelihood in un secondo ```Canvas```.

![linea](../immagini/linea.png)  
  
## Esercizio 12.10

Implementare nel programma precedente:
* il calcolo dei valore massimo e minimi della funzione ```lratio``` nell'insieme su cui è definita
* la funzione ```double sizetest(double c_alpha, TF2 *lratio, TF2 *f0)``` 
che calcola il size di un test così fatto:
  * il test è basato su un singolo campionamento della pdf(x,y)
  * la regione critica è quella per cui il logaritmo del rapporto di likelihood 
    è minore di  c<sub>&alpha;</sub> 
* stampare a schermo il valore del size

![linea](../immagini/linea.png)

## Esercizio 12.11
Completare il programma dell'esercizio 12.10 implementando la funzione che determina la BCR
 ```double DeterminaBCR(TF2 *lratio, TF2 *f0, double alpha, TGraph *gsize)'''
I parametri sono: 
* le funzioni di che rappresentano il  logaritmo del rapporto 
di likelihood e la pdf(x,y) nell'ipotesi H<sub>0<\sub>
* il size scelto per il test
* il puntatore al grafico che verrà riempito con i valori del size in funzione di c<sub>&alpha;</sub>   
Un ciclo fa variare c<sub>&alpha;</sub> del valore minimo che può assumere al valore massimo, incrementandolo con passo costante. Per ogni valore determina il size del test e riempie quindi il grafico.
Infine restituisce il valore di c<sub>&alpha;</sub>, tra quelli campionati, che ha un size prossimo al valore desiderato.
