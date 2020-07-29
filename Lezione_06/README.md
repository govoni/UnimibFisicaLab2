# Lezione 6: esempi di applicazione di sequenze pseudo-casuali

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
  * sia data come esempio la funzione *f(x) = sen(x) + 1* definita sull'intevallo *(0, &pi;)*
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
  ![integrale_HOM](immagini/integrale_HOM.png)

![linea](../immagini/linea.png)

### 6.2.3 la precisione del metodo

  * non si possono generare infiniti numeri pseudo-casuali, 
    dunque il **risultato sara' approssimato**:
  ![integrale_HOM](immagini/integrale_HOM_real_2.png)


![linea](../immagini/linea.png)

- metodi di integrazione
  - metodo MC hit-or-miss
  - metodo "crude MC"
  - incetezze statistiche associate ai due metodi
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


