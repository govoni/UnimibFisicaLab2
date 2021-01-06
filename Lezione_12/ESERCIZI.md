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
di eventi bidimensionali distribuiti come due gaussiane diverse fra loro 
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

Partendo dall'esempio che si trova in [main_01.cpp](programmi/main_01.cpp),
si generino due campionamenti di numeri pseudo casuali 
distribuiti secondo una gaussiana bidimensionale con diverse matrici di covarianza per i due campioni
e si verifichi come si comporta il discriminante di Fisher nelle varie situazioni.

![linea](../immagini/linea.png)

## Esercizio 12.8

Si scriva una libreria che definisca due funzioni in modo parametrico:
* la pdf binormale ```double binormal(double *x, double *p)``` 
  con correlazione nulla tra le  due variabili *x* ed *y* (i parametri sono quattro);
* il logaritmo del rapporto tra due pdf binormali (è il loglikelihood ratio per un singolo campionamento) 
  ```double loglike(double *x, double *p)``` 
  (i parametri sono otto: quattro per la pdf al numeratore e quattro per quella al denominatore).

![linea](../immagini/linea.png)

## Esercizio 12.9

Si scriva un programma in cui:
* i parametri delle due binormali (media e sigma per le due variabili *x* ed *y*)
  sono passati dalla linea di comando e inseriti in un array di otto elementi.
* si istanziano tre oggetti di tipo ```TF2``` di ```ROOT```
   * ```TF2 *f0 ``` è la binormale relativa all'ipotesi *H<sub>0</sub>* 
   * ```TF2 *f1 ``` è la binormale relativa all'ipotesi *H<sub>1</sub>* 
   * ```TF2 *lratio ``` è loglikelihood ratio per un singolo campionamento 
* si assegnano i valori dei parametri alle tre funzioni   
* si disegnano le tre funzioni in uno stesso ```TCanvas``` diviso in tre ```TPad```

![linea](../immagini/linea.png)  
  
## Esercizio 12.10
    
Si scriva un programma in cui si campiona una funzione binormale riempiendo due istogrammi:
* uno generando eventi pseudo-casuali mediante la funzione ```rand_TAC``` chiamata due volte
* uno usando il metodo ```GetRandom(double x,double y)``` della classe ```TF2``` 
  * includere una classe per la generazione di numeri casuali, come```TRandom3.h```
  * inizializzare nel main il seed del generatore di numeri pseudo-casuali con l'istruzione ```gRandom->SetSeed(0);```
Si faccia quindi il fit dei due istogrammi con la ```TF2``` binormale.

![linea](../immagini/linea.png)  
   
## Esercizio 12.11

Si implementi, nella libreria dell'Esercizio 12.8, una funzione che calcola il size del test:
```cpp
double sizetest(double c_alpha, TF2 *lratio, TF2 *f0, int N)
```
* ```c_alpha``` è un valore passato dal main che definisce la regione critica
* si campiona la pdf ```TF2 *f0``` un numero *N* di volte 
* si calcola quale frazione dei campionamenti ha un loglikelihood ratio inferiore a ```c_alpha```
* questo è il size del test ed è il valore restituito dalla funzione

Per provare la funzione si suggerisce di scegliere un valore di ```c_alpha```  nel range 
compreso tra il valore massimo e minimo del loglikelihood ratio (ad esempio a metà dell'intervallo) ed 
effettuare un cliclo in cui il size del test è calcolato per valori crescenti di *N* e stampato a schermo 
(o inserito in un grafico).
Questo consente di scegliere un valore di *N* che sia un compromesso tra la precisione della stima del size
e il tempo di esecuzione del programma.

![linea](../immagini/linea.png)

## Esercizio 12.12

Implementare nella lireria dell'Esercizio 12.8 la funzione che determina la BCR 
(cioè che calcola il valore di c<sub>&alpha;</sub> corrispondente al size desiderato)

 ```cpp
 double DeterminaBCR(TF2 *lratio, TF2 *f0, double alpha, TGraph *gsize)
 ```
I parametri sono: 
* le funzioni di che rappresentano il  logaritmo del rapporto 
  di likelihood e la pdf(x,y) nell'ipotesi H<sub>0</sub>
* il size scelto per il test (da aggungersi come parametro passato da linea di comando)
* il puntatore al grafico che verrà riempito con i valori del size in funzione di c<sub>&alpha;</sub>   

Nella funzione:
* un ciclo fa variare c<sub>&alpha;</sub> del valore minimo che può assumere al valore massimo, 
  incrementandolo con passo costante (anche qui potete chiedervi come ottimizzare il numero di passi)
* per ogni valore di c<sub>&alpha;</sub> si determina il size del test e si riempie il grafico
* quando il size del test è prossimo al valore desiderato &alpha; 
  (che è passato come parametro alla funzione) 
  il corrispondente valore di c<sub>&alpha;</sub> è il valore di ritorno della funzione.

![linea](../immagini/linea.png)

## Esercizio 12.13

Completare l'esercizio precedente calcolando il power del test e costruendo il grafico ROC.
Disegnare su un ```TCanvas``` la BCR, il grafico size vs. c<sub>&alpha;</sub>
e il grafico ROC.

![linea](../immagini/linea.png)

## Esercizio 12.14

Modificare l'esercizio precedente sostituendo alla binormale un'altra pdf bidimensionale 
(ad esempio ottenuta come prodotto di due pdf mono-dimensionali). 
Andrà ovviamente modificata anche la
```TF2``` che rappresenta il logaritmo del rapporto di Likelihood.  

![linea](../immagini/linea.png)

## Esercizio 12.15

Si applichi il metodo del lemma di Neyman-Pearson al caso dell'Esercizio 12.2 
e si confronti il risultato ottenuto, in termini di curve ROC, 
con i risultati ottenuti nell'Esercizio 12.5.

