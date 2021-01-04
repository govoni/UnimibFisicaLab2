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

Si scriva un programma che definisca due funzioni in modo parametrico:
* la pdf binormale ```double binormal(double *x, double *p)``` 
con correlazione nulla tra le  due variabili x ed y (i parametri sono 4);
* il logaritmo del rapporto tra due pdf binormali (è il loglikelihood ratio per un singolo campionamento) 
```double loglike(double *x, double *p)``` (i parametri sono 8, 4 per la pdf al numeratore e 4 per quella al denominatore).

Si scriva un main in cui:
* i parametri delle due binormali (media e sigma per le due variabili *x* ed *y*)
sono passati dalla command-line e inseriti in un array di 8 elementi.
* si istanziano 3 oggetti di tipo ```TF2``` di ```ROOT```
   * ```TF2 *f0 ``` è la binormale relativa all'ipotesi *H<sub>0</sub>* 
   * ```TF2 *f1 ``` è la binormale relativa all'ipotesi *H<sub>1</sub>* 
   * ```TF2 *lratio ``` è loglikelihood ratio per un singolo campionamento 
* si assegnano i valori dei parametri alle 3 funzioni   
* si disegnano le 3 funzioni in uno stesso ```Canvas()``` diviso in 3 ```Pad()```

![linea](../immagini/linea.png)  
  
## Esercizio 12.8
    
Si scriva un programma in cui si campiona una funzione binormale riempiendo due istogrammi:
* uno campionando mediante la funzione ```rand_TAC``` chiamata due volte
* uno usando il metodo ```GetRandom(double x,double y)``` della ```TF2``` 
  * includere una classe per la generazione di numeri casuali, come```TRandom3.h```
  * inizializzare nel main il seed con l'istruzione ```gRandom->SetSeed(0); ```
Si faccia quindi il fit dei due istogrammi con la ```TF2``` binormale.

![linea](../immagini/linea.png)  
   
  
## Esercizio 12.9

Si implementi, nel programma dell'esercizio 12.7, una funzione che calcola il size del test:
```cpp
double sizetest(double c_alpha, TF2 *lratio, TF2 *f0, int N)
```

* ```c_alpha``` è un valore passato dal main che definisce la regione critica
* si campiona la pdf ```TF2 *f0``` un numero *N* di volte 
* si calcola quale frazione dei campionamenti ha un loglikelihood ratio inferiore a ```c_alpha```
* questo è il size del test ed è il valore restituito dalla funzione

Per provare la funzione si suggerisce di scegliere un valore di ```c_alpha```  nel range 
compreso tra il valore massimo e minimo del loglikelihood ratio (p.es. a metà del massimo) ed 
effettuare un cliclo in cui il size del test è calcolato per valori crescenti di *N* e stampato a schermo (o inserito in un grafico).
Questo consente di scegliere un valore di *N* che sia un compromesso tra la precisione della stima del size
e il tempo di esecuzione del programma.


![linea](../immagini/linea.png)

## Esercizio 12.10
Implementare nel programma dell'esercizio 12.9 la funzione che determina la BCR 
(cioè che calcola il valore di c<sub>&alpha;</sub> corrispondente al size desiderato)

 ```cppp
 double DeterminaBCR(TF2 *lratio, TF2 *f0, double alpha, TGraph *gsize)
 ```
I parametri sono: 
* le funzioni di che rappresentano il  logaritmo del rapporto 
di likelihood e la pdf(x,y) nell'ipotesi H<sub>0<\sub>
* il size scelto per il test (da aggungersi come parametro passato dalla command-line)
* il puntatore al grafico che verrà riempito con i valori del size in funzione di c<sub>&alpha;</sub>   

Nella funzione:
* un ciclo fa variare c<sub>&alpha;</sub> del valore minimo che può assumere al valore massimo, 
incrementandolo con passo costante (anche qui potete chiedervi come ottimizzare il numero di passi ...)
* per ogni valore di c<sub>&alpha;</sub> si determina il size del test e si riempie il grafico
* quando il size del test è prossimo al valore desiderato &alpha; (che è passato come parametro alla funzione) il corrispondente 
valore di c<sub>&alpha;</sub> è restituito al main.


![linea](../immagini/linea.png)

## Esercizio 12.11

Completare l'esercizio precedente calcolando il power del test e costruendo il grafico ROC.
Disegnare su un ```Canvas()``` la BCR, il grafico size vs. c<sub>&alpha;</sub>
e il grafico ROC.

![linea](../immagini/linea.png)

## Esercizio 12.12
Modificare l'esercizio 12.11 sostituendo alla binormale un'altra pdf bidimensionale 
(p.es. ottenuta come prodotto di due pdf mono-dimensionali). Andrà ovviamente modificata anche la
```TF2``` che rappresenta il logaritmo del rapporto di likelihood.   

![linea](../immagini/linea.png)
