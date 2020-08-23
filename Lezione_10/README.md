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
  * Siano date *N* coppie di misure indipendenti del tipo *(x<sub>i</sub>, y<sub>i</sub>)*,
    per le quali:
    * l'incertezza sul valore *x<sub>i</sub>* sia **nulla o trascuarbile**
    * **l'incertezza sul valore *y<sub>i</sub>*** sia &sigma;<sub>i</sub>
  * Sia data l'ipotesi che le due variabili *x<sub>i</sub>* e *y<sub>i</sub>*
    siano in **relazione fra loro secondo una funzione *g*** tale per cui *y=g(x,&theta;)*
  * Si definisce la **funzione *Q<sup>2</sup>(&theta;)*** come:
![Q_funzione](immagini/Q_funzione.png)

![linea](../immagini/linea.png)

### 10.1.3 La determinazione dei parametri &theta;

  * In questo caso, i parametri &theta; (che puo' essere un vettore)
    si determinano **trovando il minimo della funzione *Q(&theta;)***:
![Q_funzione](immagini/Q_derivata.png)
  * esistono diverse tecniche numeriche per trovare il minimo della funzione

![linea](../immagini/linea.png)

### 10.1.4 Le proprieta' del metodo

  * Se gli scarti di *y<sub>i</sub>* rispetto a *g(x<sub>i</sub>,&theta;)*
    hanno **valore di aspettazione nullo e varianza finita e fissa**,
    cioe' non dipendente da *y*, allora 
    * il metodo dei minimi quadrati e' uno **stimatore non distorto** dei parametri &theta;
    * ed ha la **varianza minima** fra tutti gli stimatori non distorti lineari (in *y*), 
      indipendentemente dalla distribuzione di probabilita' degli scarti
  * Se gli scarti sono distribuiti secondo una distribuzione di probabilita' Gaussiana,
    il minimo della funzione *Q<sup>2</sup>(&theta;)*
    e' distribuito secondo una **distribuzione di probabilia' &Chi;<sup>2</sup>**
    con *N-k* gradi di liberta',
    * dove *N* e' il **numero di coppie** *(x<sub>i</sub>, y<sub>i</sub>)*
      e *k* il **numero di parametri stimati** con i minimi quadrati

![linea](../immagini/linea.png)

## 10.2 Il caso lineare

  * Nel caso in cui la funzione *g(x)* sia **lineare nei parametri &theta;**,
    le equazioni di minimizzazione possono essere risolte analiticamente
![g_lineare](immagini/g_lineare.png)
  * Un esempio di funzione lineare e' **la retta 
    *g(x,&theta;) = &theta;<sub>1</sub>+*&theta;<sub>2</sub>x***:
    * *h<sub>1</sub>(x) = 1*
    * *h<sub>2</sub>(x) = x*
  * Un altro esempio di funzione lineare e' **una parabola 
    *g(x,&theta;) = *&theta;<sub>1</sub> + *&theta;<sub>2</sub>x + *&theta;<sub>3</sub>x<sup>2</sup>***:
    * *h<sub>1</sub>(x) = 1*
    * *h<sub>2</sub>(x) = x*
    * *h<sub>3</sub>(x) = x<sup>2</sup>*

![linea](../immagini/linea.png)

## 10.2.1 La formulazione matriciale

  * Nel caso generale, 
    le *N* coppie di misure *(x<sub>i</sub>, y<sub>i</sub>)* 
    e *k* parametri *&theta;<sub>j</sub>*
    si possono **rappresentare in forma vettoriale**
  * Per comodita' di scrittura,
    la determinazione del minimo della funzione *Q<sup>2</sup>(&theta;)*
    viene **svolta in forma matriciale**

![linea](../immagini/linea.png)

## 10.2.2 Le espressioni dei singoli elementi

  * Gli **ingredienti necessari**
    per la deteminazione dei parametri *&theta;<sub>j</sub>* 
    sono i seguenti:
![espressioni_mtr](immagini/espressioni_mtr.png)
  * Dove *V* e' la matrice di covarianza delle misure *y<sub>i</sub>)*,
    che e' diagonale perche' le misure sono indipendenti fra loro

![linea](../immagini/linea.png)

## 10.2.3 Il valore dei parametri e della loro incertezza

  * Il risultato delle operazioni di minimizzazione e' il seguente:
![modello_lineare](immagini/modello_lineare.png)
  * *V<sup>-1</sup>* indica l'**inversa** della matrice di covarianza delle misure *y<sub>i</sub>)*
  * *<sup>t</sup>H* indica la **trasposta** della matrice *H*
  * La notazione che indica il risultato dell'algoritmo dei minimi quadrati
    con un accento circonflesso sulla lettera &theta;
    sottolinea il fatto che si tratta del **risultato di una stima**

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

