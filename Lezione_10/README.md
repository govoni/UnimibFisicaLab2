# Lezione 10: stima di parametri con il metodo dei minimi quadrati

![linea](../immagini/linea.png)

## 10.1 Introduzione

  * Il metodo dei **minimi quadrati** si basa su un principio indipendente
    rispetto a quello della massima verosimiglianza
  * Si scelgono i parametri &theta; che rendono **minima la distanza** 
    fra il modello ed i dati, 
    secondo una metrica definita dagli scarti quadratici medi

![linea](../immagini/linea.png)

### 10.1.1 Un esempio immediato

  * Per determinare la media &mu; di un insieme di misure *x<sub>i</sub>*
    si puo' minimizzare la funzione:
![Q_media](immagini/Q_media.png)

![linea](../immagini/linea.png)

### 10.1.2 Il caso *y=g(x)*

  * La stessa metrica viene spesso utilizzata
    per fare **regressioni sui dati**
  * Siano date *N* coppie di misure del tipo *(x<sub>i</sub>, y<sub>i</sub>)*,
    per le quali:
    * l'incertezza sul valore *x<sub>i</sub>* sia **nulla o trascuarbile**
    * **l'incertezza sul valore *y<sub>i</sub>*** sia &sigma;<sub>i</sub>
  * Sia data l'ipotesi che le due variabili *x<sub>i</sub>* e *y<sub>i</sub>*
    siano in **relazione fra loro secondo una funzione *g*** tale per cui *y=g(x)*
  * Si definisce la **funzione *Q(&theta;)*** come:
![Q_funzione](immagini/Q_funzione.png)

![linea](../immagini/linea.png)

### 10.1.3 La determinazione dei parametri &theta;

  * In questo caso, i parametri &theta; (che puo' essere un vettore)
    si determinano **trovando il minimo della funzione *Q(&theta;)***:
![Q_funzione](immagini/Q_derivata.png)
  * esistono diverse tecniche numeriche per trovare il minimo della funzione

![linea](../immagini/linea.png)

### 10.1.4 Le proprieta' del metodo

  * Se gli scarti di *y<sub>i</sub>* rispetto a *g(x<sub>i</sub>)*
    hanno **valore di aspettazione nullo e varianza finita e fissa**,
    cioe' non dipendente da *y*, allora 
    * il metodo dei minimi quadrati e' uno **stimatore non distorto** dei parametri &theta;
    * ed ha la **varianza minima** fra tutti gli stimatori non distorti lineari (in *y*), 
      indipendentemente dalla distribuzione di probabilita' degli scarti
  * Se gli scarti sono distribuiti secondo una distribuzione di probabilita' Gaussiana,
    il minimo della funzione *Q(&theta;)*
    e' distribuito secondo una **distribuzione di probabilia' &Chi;<sup>2</sup>**
    con *N-k* gradi di liberta',
    * dove *N* e' il **numero di coppie** *(x<sub>i</sub>, y<sub>i</sub>)*
      e *k* il **numero di parametri stimati** con i minimi quadrati

![linea](../immagini/linea.png)

## 10.2 Il caso lineare

- formulazione del caso lineare
- subito esempio della retta
- formule del Metzger

![linea](../immagini/linea.png)

## 10.3 Un esempio: il fit di una retta

- librerie di algebra matriciale
- la generazione di un set di punti
- la definizione degli oggetti: matrice H, vettore y, matrice V
- il valore centrale e la varianza del risultato

![linea](../immagini/linea.png)

## 10.4 La distribuzione di probabilita' degli stimatori

- i toy experiment
- test di bias

![linea](../immagini/linea.png)

## 10.5 Una parentesi utile: il salvataggio degli oggetti di ROOT

- salvare istogrammi in un TFile
- rileggere un TFile
- macro di ROOT

![linea](../immagini/linea.png)

## 10.6 La stima di una incertezza ignota

- dopo i tanti toy
- nel singolo fit (varianza unbiased, sigma no)

![linea](../immagini/linea.png)

## 10.5 ESERCIZI

  * Gli esercizi relativi alla lezione si trovano [qui](ESERCIZI.md)

                                                                                                               
 +--------------------------------+
 |                                | 
 | OPEN POINTS                    | 
 |                                | 
 | - estrapolazioni               | 
 | - goodness of fit              | 
 |                                | 
 +--------------------------------+

