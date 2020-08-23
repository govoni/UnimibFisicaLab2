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
    per fare **regressioni sui dati**, chiamata anche *fit*
  * Siano date *N* coppie di misure indipendenti del tipo *(x<sub>i</sub>, y<sub>i</sub> )*,
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

  * Se gli scarti *&epsilon;<sub>i</sub>* di *y<sub>i</sub>* rispetto a *g(x<sub>i</sub>,&theta;)*
    hanno **valore di aspettazione nullo e varianza finita e fissa**,
    cioe' non dipendente da *y*, allora 
    * il metodo dei minimi quadrati e' uno **stimatore non distorto** dei parametri &theta;
    * ed ha la **varianza minima** fra tutti gli stimatori non distorti lineari (in *y*), 
      indipendentemente dalla distribuzione di probabilita' degli scarti
  * Se gli scarti *&epsilon;<sub>i</sub>* sono distribuiti secondo una distribuzione di probabilita' Gaussiana,
    il minimo della funzione *Q<sup>2</sup>(&theta;)*
    e' distribuito secondo una **distribuzione di probabilia' &Chi;<sup>2</sup>**
    con *N-k* gradi di liberta',
    * dove *N* e' il **numero di coppie** *(x<sub>i</sub>, y<sub>i</sub> )*
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

### 10.2.1 La formulazione matriciale

  * Nel caso generale, 
    le *N* coppie di misure *(x<sub>i</sub>, y<sub>i</sub> )* 
    e *k* parametri *&theta;<sub>j</sub>*
    si possono **rappresentare in forma vettoriale**
  * Per comodita' di scrittura,
    la determinazione del minimo della funzione *Q<sup>2</sup>(&theta;)*
    viene **svolta in forma matriciale**

![linea](../immagini/linea.png)

### 10.2.2 Le espressioni dei singoli elementi

  * Gli **ingredienti necessari**
    per la deteminazione dei parametri *&theta;<sub>j</sub>* 
    sono i seguenti:
![espressioni_mtr](immagini/espressioni_mtr.png)
  * Dove *V* e' la matrice di covarianza delle misure *y<sub>i</sub>*,
    che e' diagonale perche' le misure sono indipendenti fra loro

![linea](../immagini/linea.png)

### 10.2.3 Il valore dei parametri e della loro incertezza

  * Il risultato delle operazioni di minimizzazione e' il seguente:
![modello_lineare](immagini/modello_lineare.png)
  * *V<sup>-1</sup>* indica l'**inversa** della matrice di covarianza delle misure *y<sub>i</sub>*
  * *<sup>t</sup>H* indica la **trasposta** della matrice *H*
  * La notazione che indica il risultato dell'algoritmo dei minimi quadrati
    con un accento circonflesso sulla lettera &theta;
    sottolinea il fatto che si tratta del **risultato di una stima**

![linea](../immagini/linea.png)

## 10.3 Un esempio: il fit di una retta

  * L'implementazione di una regressione di un modello *g(x,&theta;) = &theta;<sub>1</sub>+*&theta;<sub>2</sub>x*
    in ```C++``` e' un utile esercizio di **programmazione e comprensione della statistica**
  * ... ricordando che esistono **librerie per l'analisi dati** (come ```ROOT```) con gia' implementati questi algoritmi
    * strumenti **piu' generici**: 
      implementano il metodo dei minimi quadrati sia per un modello lineare generico
      che per modelli non lineari
    * strumenti **piu' efficaci**:
      implementano algoritmi di minimizzazione tipicamente piu' potenti di quelli 
      che possiamo scrivere in una lezione  

![linea](../immagini/linea.png)

### 10.3.1 L'algebra delle matrici

  * Assumiamo di avere a disposizione una semplice libreria per lo **svolgimento di calcoli fra matrici**,
    che potete trovare qui: [algebra_2.h](programmi/algebra_2.h) e [algebra_2.cc](programmi/algebra_2.cc)
    (per scaricare o copiare il file sorgente conviene visualizzarlo in versione ```Raw```)
    * Rispetto a quella scritta per esercizio nella Lezione 7, 
      in questo caso non si utilizzano ```template```
      perche' risuta piu' comodo **decidere a *runtime*** la dimensione delle matrici

![linea](../immagini/linea.png)

### 10.3.2 Gli strumenti a disposizione

  * Una classe **```vettore```**:
    ```cpp
    class vettore 
    {
      public:
        vettore (int N) ;
        vettore (const std::vector<double> & v) ;
        vettore (const vettore & orig) ;
        vettore & operator = (const vettore & orig) ;
        ~vettore () ;
    
        void    setCoord (int i, double val) ;
        double  norm () const ;
        int     N () const ;
        double  at (int i) const ;
        void    stampa () const ;
        double  operator[] (int i) const ;
        vettore operator+ (const vettore & v) const ;
        vettore operator- (const vettore & v) const ;
        vettore operator* (double val) const ;
        double  dot (const vettore & v) const ;
    
      private:
        double * m_elementi ;
        int m_N ;
    } ;

    ```      
  * Una classe **```matrice```**:
    ```cpp
    class matrice
    {
      public:
        matrice (int R) ;
        matrice (int R, int C) ;
        matrice (const matrice & orig) ;
        matrice & operator= (const matrice & orig) ;
        ~matrice () ;
    
        void    setCoord (int i, int j, double val) ;
        double  at (int i, int j) const ;
        void    stampa () const ;
        bool    quadrata () const ;
        int     rango () const ;
        int     N_righe () const ;
        int     N_colonne () const ;
        bool    simmetrica () const ;
        void    dimensioni () const ;
        matrice minore (int r, int c) const ; // complemento algebrico
        matrice inversa () const ;
        matrice trasposta () const ;
        double  determinante () const ;
        void    operator*= (double val) ;
    
      private:
        int index (int i, int j) const ;
        int m_R ;
        int m_C ;
        double * m_elementi ;
    } ;

    ```
  * **operazioni** fra i due tipi:
    ```cpp
    vettore operator* (const matrice & M, const vettore & v) ;
    matrice operator* (const matrice & M1, const matrice & M2) ;
    ```

![linea](../immagini/linea.png)

### 10.3.3 La generazione dei punti da interpolare

  * Per svolgere l'esercizio,
    bisogna innanzitutto avere a disposizione una **collezione di dati**
  * Con un generatore di numeri pseudo-casuali,
    si possono **generare valori degli scarti *&epsilon;<sub>i</sub>***
    per ogni punto *x<sub>i</sub>*,
    tali per cui:
    *y<sub>i</sub> = g(x<sub>i</sub>, &theta;) + &epsilon;<sub>i</sub>*
  * Assumendo una **distribuzione Gaussiana** per *&epsilon;<sub>i</sub>*,
    centrata in ```0``` e con &sigma; scelta a piacere:
    ```cpp
    double g (double x)
      {
         return 3.14 + 2 * x ;
      }
    // ....
    vector<double> asse_x ;
    vector<double> asse_y ;
    for (int i_point = 0 ; i_point < N_points ; ++i_point)
      {
        double epsilon = rand_TAC_gaus (sigma) ; 
        asse_x.push_back (i_point) ;
        asse_y.push_back (g (i_point) + epsilon) ;
      }
    ```
    * In questo caso, la funzione ```rand_TAC``` e' stata modificata,
      con una implementazione **dedicata al problema**

![linea](../immagini/linea.png)

### 10.3.4 La preparazione di matrici e vettori

  * a partire dalle coppie di punti, si costruiscono:
  * la **matrice H** dei valori delle funzioni *h<sub>j<sub>(x)*
    per tutti i punti:
    ```cpp
    matrice H (Npoints, 2) ;
    for (int i = 0 ; i < Npoints ; ++i)
      {
        H.setCoord (i, 0, 1) ;
        H.setCoord (i, 1, asse_x.at (i)) ;
      }
    ```
  * il **vettore y** (con un costruttore apposito che riceve in input uno ```std::vector```:
    ```cpp
    vettore y (asse_y) ;
    ```
  * la **matrice V** di covarianza delle misure *y<sub>i</sub>*:
    ```cpp
    matrice V (Npoints) ;
    for (int i = 0 ; i < Npoints ; ++i) V.setCoord (i, i, sigma * sigma) ;
    ```

![linea](../immagini/linea.png)

### 10.3.5 La stima dei parametri &theta;

  * I calcoli per la determinazione del vettore &theta;
    e della sua varianza
    sono svolte in sequenza,
    **minimizzando il numero di singole operazioni**:
    ```cpp
    matrice V_inv = V.inversa () ;
    matrice theta_v = (H.trasposta () * V_inv * H).inversa () ;
    vettore theta = (theta_v * (H.trasposta () * V_inv)) * y ;

    ```
    * L'**inversione della matrice *V*** e' fatta una sola volta
    * La **matrice di covarianza** di &theta;,
      che entra anche nel calcolo del suo valore centrale,
      viene calcolata una sola volta

![linea](../immagini/linea.png)

### 10.3.6 La stampa del risultato

  * Sapendo che i **termini diagonali della matrice di covarianza**
    corrispondono alle varianze dei vari &theta;<sub>i</sub>,
    il risultato del fit e':
    ```cpp
    cout << "termine noto: " << theta.at (0) << " +- " << sqrt (theta_v.at (0, 0)) << endl ;
    cout << "pendenza:     " << theta.at (1) << " +- " << sqrt (theta_v.at (1, 1)) << endl ;
    ```

![linea](../immagini/linea.png)

## 10.4 Le proprieta' statistiche degli stimatori

- i toy experiment
- la visualizzazione della correlazione
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

