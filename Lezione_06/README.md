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
    si puo' utilizzare la classe ```stats```
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


