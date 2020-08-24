# Esercizi per la lezione 10

## Esercizio 10.1

Si scriva un programma che generi una sequenza di coppie di misure indipendenti *(x<sub>i</sub>, y<sub>i</sub> )*,
generate in modo che, per ogni x<sub>i</sub>,
*y<sub>i</sub> = g (x<sub>i</sub>, &theta;) + &epsilon;<sub>i</sub>*, 
essendo *&epsilon;<sub>i</sub>* numeri pseudo-casuali distribuiti secondo una distribuzione di probabilita' Gaussiana
centata in ```0``` e con sigma arbitraria.
  * Si utilizzi come funzione *g* la retta: *g(x,&theta;) = &theta;<sub>1</sub>+&theta;<sub>2</sub>x*
  * Si faccia in modo che il programma legga da linea di comando il valore della sigma della Gaussiana
    ed il numero di coppie da generare.

![linea](../immagini/linea.png)

## Esercizio 10.2 

Si aggiunga al programma precedente un algoritmo di regressione lineare che,
a partire dai punti generati,
determini una stima dei parametri *&theta;<sub>1</sub>* e *&theta;<sub>2</sub>* con il metodo dei minimi quadrati,
utilizzando l'espressione analitica tipica del caso lineare.
  * A scelta 
    si sfruttino la libreria algebrica esistente [algebra_2.h](programmi/algebra_2.h) 
    e [algebra_2.cc](programmi/algebra_2.cc),
    si implementi la propria libreria,
    oppure se ne trovi una equivanente utilizzabile.
  * Si scriva a schermo il risultato della regressione, 
    sia in termini di valore centrale che di incertezza.
  * Fino a che numero di coppie di punti genrati
    l'algoritmo funziona in tempi ragionevoli?

![linea](../immagini/linea.png)

## Esercizio 10.3

Si risolva il medesimo problema per il caso parabolico 
*g(x,&theta;) = &theta;<sub>1</sub>+&theta;<sub>2</sub>x+&theta;<sub>3</sub>x<sup>2</sup>*.

![linea](../immagini/linea.png)

## Esercizio 10.4

Si inserisca il processo di generazione di coppie di eventi pseudo-casuali 
in un ciclo di simulazione di *toy experiment*.
  * Si generi la distribuzione di densita' di probabilita' delle stime *&theta;<sub>1</sub>* e *&theta;<sub>2</sub>*
    e si verifichi se il loro stimatore sia o meno distorto.
  * Si generi la distribuzione di densita' di probabilita' di *Q<sup>2</sup><sub>min</sub>*
  * Si salvino tutti questi istogrammi in un file di tipo ```.root```
  * Si confronti la distribuzione di *Q<sup>2</sup><sub>min</sub>* con la distribuzione di probabilita'
    *f(x) = &Chi;<sup>2</sup>(x, N-k)*, essendo *N* il numero di punti *x<sub>i</sub>, y<sub>i</sub> )*
    e *k* il numero di parametri *&theta;<sub>j</sub>* ricavati dal fit.

![linea](../immagini/linea.png)

## Esercizio 10.5

Si ripeta l'esercizio precedente utilizzando una distribuzione di probabilita' uniforme
per generare gli scarti *&epsilon;<sub>i</sub>*.
  * Si determini se lo stimatore dei parametri *&theta;<sub>j</sub>* sia o meno distorto.
  * Si confronti la distribuzione di *Q<sup>2</sup><sub>min</sub>* con la distribuzione di probabilita'
    *f(x) = &Chi;<sup>2</sup>(x, N-k)*, essendo *N* il numero di punti *x<sub>i</sub>, y<sub>i</sub> )*
    e *k* il numero di parametri *&theta;<sub>j</sub>* ricavati dal fit.

![linea](../immagini/linea.png)

## Esercizio 10.6

Si modifichi il risultato dell'Esercizio 10.4 in modo che il fit venga effettuato utilizzando
una matrice unitaria in vece della matrice di covarianza dei valori *y<sub>i</sub>*
e si determini quindi il valore della loro sigma 
a partire dall'ipotesi che gli scarti siano distribuiti secondo una densita' di probabilita' Gaussiana.

