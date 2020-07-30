# Lezione 6: esempi di applicazione di sequenze pseudo-casuali ed esempi di calcolo numerico

  * le sequenze di numeri pseudo-casuali
    sono molto spesso utilizzate
    per **simulare il comportamento statistico di un esperimento** di misura,
    o per **eseguire integrazioni numeriche**

![linea](../immagini/linea.png)

## 6.1 la riproduzione simulata di un esperimento: i *toy experiment*

  * secondo il paradigma frequentista della statistica,
    le incertezze di una misura si ricavano dalla sua distribuzione di densita' di probabilita',
    assumendo che l'esperimento utilizzato per compiere quella misura
    sia **ripetuto un grande numero di volte**
  * operativamente, 
    l'esperimento che porta al risultato finale di una misura e' unico,
    dunque alcuni comportamenti statistici
    si possono **solamente simulare** 
  * la simulazione di un esperimento di misura e' detta **toy experiment**

![linea](../immagini/linea.png)

## 6.1.1 la precisione sulla media di una misura

  * per determinare la precisione sulla media di una campione,
    quindi,
    e' necessario effettuare la generazione del campione molte volte,
    per vedere la distribuzione dei valori della media:
    ```cpp
    // loop sui toy experiment
    stats s_singleToy ;
    stats s_tot ;
    for (int iToy = 0 ; iToy < NToys ; ++iToy)
      {
        int i = 0 ;
        // il loop seguente e' un singolo toy experiment
        while (i++ < NMAX) s_singleToy.addEvent (rand_range (-3., 3.)) ;
        s_tot.addEvent (s_singleToy.getMean ()) ;
        s_singleToy.reset () ;
      } // loop sui toy experiment
    ```
    * **NOTA BENW**: l'oggetto ```s_singleToy``` viene vuotato al termine di ogni toy experiment
  * mentre l'oggetto ```s_singleToy``` raccoglie le **statistiche di ogni singolo toy experiment**
    e viene utilizzato per calcolarne la media,
    l'oggetto ```s_tot``` raccoglie il campione dei valori delle medie 
    per tutti i toy experiment

![linea](../immagini/linea.png)

## 6.1.2 la visualizzazione della distribuzione delle medie

  * la media delle misure e' una funzione di variabili casuali,
    quindi e' una **variabile casuale** a sua volta
  * la sua distribuzione di probabilita' si ottiene **per campionamento** con i toy experiment,
    ad esempio riempiendo un istogramma all'interno del ciclo sui toy:
    ```cpp

    TH1F h_medie ("h_medie", "distribuzione delle medie", 41, -0.5, 0.5) ;
    // loop sui toy experiment
    for (int iToy = 0 ; iToy < NToys ; ++iToy)
      {
        int i = 0 ;
        // il loop seguente e' un singolo toy experiment
        while (i++ < NMAX) s_singleToy.addEvent (rand_range (-3., 3.)) ;
        h_medie.Fill (s_singleToy.getMean ()) ;
    ```
  ![medie](immagini/medie_toys.png)

![linea](../immagini/linea.png)

## 6.1.3 il confronto con la deviazione standard della media

  * la **deviazione standard della media** per singolo toy,
    essendo l'incertezza associata alla media delle misure,
    deve quindi corrispondere
    alla **deviazione standard** del campione delle medie
  * per controllare questa corrispondenza,
    si puo' utilizzare la classe ```statistiche```
    ```cpp
    stats s_singleToy ;
    stats s_tot ;
    stats s_incertezzaMedia ;
    // loop sui toy experiment
    for (int iToy = 0 ; iToy < NToys ; ++iToy)
      {
        int i = 0 ;
        // il loop seguente e' un singolo toy experiment
        while (i++ < NMAX) s_singleToy.addEvent (rand_range (-3., 3.)) ;
        s_tot.addEvent (s_singleToy.getMean ()) ;
        s_incertezzaMedia.addEvent (s_singleToy.getSigmaMean ()) ;
        s_singleToy.reset () ;
      } // loop sui toy experiment
    ```
    che produce come risultato:
    ```
    media delle deviazioni standard della media per i singoli toy: 0.0773579 
    deviazione standard della distribuzione delle medie dei singoli toy: 0.0774481 
    ```

![linea](../immagini/linea.png)

## 6.2 integrazione con numeri pseudo-casuali

  * le sequenze di numeri pseudo-casuali possono essere utilizzate efficacemente
    anche per **calcolare aree** sottese da funzioni
  * i metodi che sfruttano numeri pseudo-casuali prendono il nome di tecniche **Monte Carlo**,
    derivando questa definizione dall'omonimo casino',
    regno della dea bendata
  * l'utilizzo di queste tecniche in fisica e' **molto vasto**,
    ad esempio nel calcolo di integrali in meccanica quantistica e teoria quantistica dei campi,
    per la simulazione di apparati di misura, et cetera
    
![linea](../immagini/linea.png)

### 6.2.1 prerequisiti

  * studiamo il caso di integrazione di **funzioni mono-dimensionali positive, continue 
    e definite su un intervallo compatto e connesso**
    (quindi finite su tutto l'insieme di definizione)
  * sia data come esempio la funzione *g(x) = sin(x) + 1* definita sull'intevallo *(0, &pi;)*
    * per questa funzione sappiamo calcolare l'integrale in forma analitica,
      pari a *2&pi;*

  ![integrale](immagini/integrale.png)

![linea](../immagini/linea.png)

### 6.2.2 il metodo hit-or-miss

  * l'**algoritmo hit-or-miss** si comporta in modo simile alla generazione di numeri pseudo-casuali
    con la tecnica try-and-catch
  * si generano *N* coppie numeri pseudo-casuali nel piano che contiene il disegno della funzione
    e si conta il **numero di eventi** *n<sub>hit</sub>* che cascano nell'area sottesa dalla funzione 
  ![integrale_RP](immagini/integrale_random_points.png)
  * di conseguenza, se *A* e' l'area del rettangolo dove sono stati generati gli eventi 
    ed *m* ed *M* gli estremi di integrazione:
  ![integrale_HOM](immagini/integrale_HOM_2.png)

![linea](../immagini/linea.png)

### 6.2.3 la precisione del metodo

  * non si possono generare infiniti numeri pseudo-casuali, 
    dunque il **risultato sara' approssimato**:
  ![integrale_HOM](immagini/integrale_HOM_real_3.png)
  * la quantita' *I* e' il *risultato dell'integrale* per il metodo hit-or-miss
  * essendo funzione di numeri pseudo-casuali, e' a sua volta un **numero pseudo-casuale**
  * ha un valore atteso ed una varianza
    quest'ultima e' **l'incetezza numerica** nel calcolo dell'integrale
    * *A* ed *N* sono **noti senza incertezza**
    * *n<sub>hit</sub>* ha invece **distribuzione binomiale**,
      associando al successo il fatto che un punto generato si trovi sotto la funzione da integrare,
      con **probabilita' *p = n<sub>hit</sub> / N***

![linea](../immagini/linea.png)

### 6.2.4 l'incertezza numerica del metodo hit-or-miss

  * **valore di aspettazione e varianza** di *I* quindi, 
    dati *N* numeri pseudo-casuali geneati,
    sono quindi:
  ![integrale_HOM](immagini/integrale_HOM_exp_var.png)
  * di conseguenza, 
    l'incertezza numerica sul calcolo dell'integrale
    e' data dalla **radice della varianza**

![linea](../immagini/linea.png)

### 6.2.5 l'implementazione del metodo hit-or-miss

  * anche in questo caso, 
    si tratta di **generare numeri pseudo-casuali** sul piano
    entro *(0, 2&pi;)* sull'asse *x* e *(0, 2)* sull'asse *y*
    e contare quante coppie di punti stiano sotto la funzione da integrare:
    ```cpp
    int N = 10000 ;
    int nHit = 0 ;
    double xMin = 0. ;
    double xMax = 2*M_PI ; 
    double yMin = 0. ; 
    double yMax = 2. ;

    for (int i = 0 ; i < N ; ++i) 
      {
        if (isBelow (fsin, xMin, xMax, yMin, yMax) == true) ++nHit ; 
      }
    ```
    dove:
    ```cpp
    bool isBelow (double g (double), double xMin, double xMax,
                  double yMin, double yMax)
      {
        double x = rand_range (xMin, xMax) ;
        double y = rand_range (yMin, yMax) ; 
        if (y < g (x)) return true ; 
        return false ;
      }
    ```
  * a partire da n<sub>hit</sub>, quindi, si possono calcolare il valore dell'integrale 
    e la sua incertezza.

![linea](../immagini/linea.png)

### 6.2.4 il metodo del *crude Monte Carlo*

  * L'agoritmo *crude Monte Carlo* 
    sfrutta le proprieta' del **valore di aspettazione** di una funzione
  * dato un insieme di numeri pseudo-casuali *x<sub>i</sub>* 
    generati secondo una distribuzione di probabilita' uniforme *f(x)*, 
    il **valore di aspettazione della funzione *g(x)***
    risulta essere:
    ![integrale_crude](immagini/integrale_crude.png)
    per definizione della distribuzione di probabilita' uniforme
  * *E[g(x)]* e' stimabile con la **media dei valori *g(x<sub>i</sub>)***
    e la varianza di *g(x)* e' stimabile con la 
    **deviazione standard della media dei valori *g(x<sub>i</sub>)***,
    che si calcola a partire dalla varianza *V[g(x)]*
  * dunque si puo' calcolare una stima dell'integrale di *g(x)* e della sua incertezza:
    ![integrale_crude_res](immagini/integrale_crude_res.png)

![linea](../immagini/linea.png)

## 6.3 aree positive o negative: alla ricerca degli zeri di una funzione

  * se una funzione ha anche una **parte negativa**,
    gli algoritmi di calcolo dell'integrale devono tenerne conto
    dividendo le regioni da integrare in positiva e negativa
  * esistono tecniche per **trovare gli zeri** di una funzione  
  * ipotesi sempici:
    * funzione *g(x)* **continua definita su un intervallo compatto e connesso** *[x<sub>0</sub>, x<sub>1</sub>]*
    * la funzione ha **un solo zero** nell'intervallo
    * agli estremi dell'intervallo, i valori della funzione **hanno segno opposto**
    ![integrale_crude_res](immagini/funzione_con_zero.png)

![linea](../immagini/linea.png)

### 6.3.1 il metodo della bisezione

  * il programma non vede la funzione nella sua interezza,
    quindi l'unico modo che ha per determinare dove sia lo zero 
    e' **stimare la funzione in singoli punti**
  * date le ipotesi iniziali,
    lo zero della funzione si trova sicuramente fra due punti tali per cui
    la funzione **assume valore con segno opposto** fra questi due punti  
  * la tecnica della bisezione **restringe iterativamente questo intervallo**  
    fino a che non diventa piu' piccolo di una risoluzione fissata
    ![integrale_crude_res](immagini/bisezione.png)

![linea](../immagini/linea.png)

### 6.3.2 una impoementazione dell'algoritmo di bisezione

  * ad ogni iterazione,
    si calcola il **punto medo dell'intervallo** che contiene lo zero
    e si decide se lo zero stia alla sua destra o alla sua sinistra
    ```cpp
    double bisezione (
      double g (double),
      double xMin,
      double xMax,
      double precision = 0.0001
    )
    {
      double xAve = xMin ;
      while ((xMax - xMin) > precision)
        {
          xAve = 0.5 * (xMax + xMin) ;
          if (g (xAve) * g (xMin) > 0.) xMin = xAve ;
          else                          xMax = xAve ;
        }
      return xAve ;
    }  
    ```

![linea](../immagini/linea.png)

### 6.3.3 una impoementazione dell'algoritmo di bisezione in modo ricorsivo

  * l'algoritmo di bisezione effettua ripetutamente la **stessa operazione**
    in maniera ricorsiva
  * questo comportamento si puo' anche implementare in ```C++```, 
    scrivendo una **funzione ricorsiva**,
    cioe' che invoca se stessa:  
    ```cpp
    double bisezione_ricorsiva (
      double g (double),
      double xMin,
      double xMax,
      double precision = 0.0001
    )
    {
      double xAve = 0.5 * (xMax + xMin) ;
      if ((xMax - xMin) < precision) return xAve ;
      if (g (xAve) * g (xMin) > 0.) return bisezione_ricorsiva (g, xAve, xMax, precision) ;
      else                          return bisezione_ricorsiva (g, xMin, xAve, precision) ;
    }  
    ```

  | attenzione |
  | -------- |

  * in ogni funzione ricorsiva, devono essere presenti **due elementi**:
    * l'**invocazione della funzione** stessa
    * la **condizione di uscita** dalla sequenza di auto-invocazioni

![linea](../immagini/linea.png)

## 6.4 informazioni necessarie: gli estremi di una funzione

  * il metodo di hit-or-miss necessita della **conoscenza del valore massimo e minimo**
    che assume *g(x)* sull'intervallo di integrazione
  * in generale,
    l'identificazione di massimi e minimi di una funzione
    e' un problema 


  * Per trovare il minimo di una funzione servono abbastanza punti da capirne la pendenza, 
    quindi se ne cercano quattro, che determinano tre intervalli
  * L'intervallo si stringe eliminando il tratto dove il minimo di sicuro non c'e'.
  * Come per la trisezione, all'iterazione successiva si considera [0,r] se
    f(1-r) < f(r) viceversa si sceglie l'intervallo [1-r,1]
    All'iterazione successiva si vuole “riciclare” uno dei punti considerati in
    quella precedente, perciò si impone la condizione:

https://virgilio.mib.infn.it/~chiesa/labinfo/


![linea](../immagini/linea.png)

- metodi di integrazione
  - vegas algorithm?
- determinazione degli zeri di una funzione
- determinazione dei massimi di una funzione

- connettere zeri, massimi e minimi al problema dell'integrazione
  - determinare gli zeri = trovare se ci sono tratti negativi per integrare differentemente parti positive
    e parti negative
  - determinare i massimi e i minimi = potrebbe essere un modo per fare importance sampling grezzo,
    cioe' inscatolare in box piccole vari sotto-intervalli di integrazione  

![linea](../immagini/linea.png)


## 6.1  

### 6.1.1 

  | vantaggi |
  | -------- |


![linea](../immagini/linea.png)

## 6.X ESERCIZI

  * Gli esercizi relativi alla lezione si trovano [qui](ESERCIZI.md)


