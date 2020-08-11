# Lezione 9: stima di parametri con il metodo della massima verosimiglianza

![linea](../immagini/linea.png)

## 9.1 Introduzione

  * Studiamo la statistica nel **paradigma frequentista**,
    secondo il quale la probabilita' e' definita operativamente 
    come la frazione di volte in cui una misura ha un determinato risultato, 
    rispetto ad un totale molto grande
  * Il **risultato di un esperimento** di misura
    e' uno dei possibili risultati date le configurazioni iniziali

![linea](../immagini/linea.png)

### 9.1.1 Un modello che descrive i dati

  * Un **modello** e' una distribuzione di probabilita' *f*
    o una legge *g* alla quale ci si aspetta che le misure obbediscano.
  * I **risultati delle misure** sono ovviamente variabili 
    rispetto alle quali il modello dipende
  * Ulteriori variabili presenti nel modello,
    che non sono misurate,
    sono dette **parametri**.

![linea](../immagini/linea.png)

### 9.1.2 Distribuzioni di probabilita'

  * Dato un insieme di misure reali *x<sub>i</sub>* definite su un insieme &Omega; 
    indipendenti identicamente distribuiite,
    sappiamo che seguono una **data distribuzione di densita' probabilita'**, 
    indicata genericamente come *f(x, &theta;)*
  * Questo significa che *f(x<sub>i</sub>, &theta;)* e' **la densita' di probabilita'**
    che la misura avvenga nel punto x<sub>i</sub> dell'insieme di definizione &Omega;.
  * Il **simbolo &theta;** indica che la funzione di densita' di probabilita' *f*
    dipende da altre variabili oltre che *x*
    * &theta; puo' anche essere un vettore di parametri
    * Ad esempio, una **distribuzione Gaussiana** ha due parametri aggiuntivi, &mu; e &sigma;:
![gaussian](immagini/gaussian.png)

![linea](../immagini/linea.png)

### 9.1.3 La determinazione dei parametri

  * Spesso l'obiettivo di un esperimento e' la **stima dei parametri** di un modello
  * Per ottenere questo risultato, 
    si **raccolgono molti dati** *x<sub>i</sub>* e si utilizzano come input
    ad algoritmi, detti **stimatori**, che stimino i parametri di interesse
  * Le **stime** prodotte da uno stimatore **sono variabili casuali**, 
    perche' tramite gli stimatori sono funzioni di numeri casuali (i dati)
    * Hanno una propria distribuzione di probabilita'
![stime](immagini/stime.png)
  * Esistono programmi che svolgono il compito per noi. 
    Fra questi, ```ROOT``` contiene diversi algoritmi per farlo.
    In gergo, **l'operazione di determinazione dei parametri e' chiamata *fit***,
    cioe' adatattamento.

![linea](../immagini/linea.png)

## 9.2 La massima verosimiglianza

  * La tecnica della massima verosimiglianza
    si basa sull'assunto che la stima dei parametri ricercati
    corrisponda al **valore 
    che massimizza la likelihood**,
    definita come
    il prodotto del valore della distribuzione di densita' di probabilita'
    calcolata per ogni misura effettuata:
![likelihood](immagini/likelihood.png)
  * La likelihood e' funzione sia delle misure che dei parametri, 
    tuttavia si **evidenzia la dipendenza dai parametri** perche'
    a misure finite i dati sono immutabili.
  * La funzione che stima i parametri dunque si ricava dall'equazione:
![maxLikelihood](immagini/maxLikelihood.png)

![linea](../immagini/linea.png)

### 9.2.1 Il logaritmo della massima verosimiglianza

  * Solitamente si utilizza il **logaritmo della funzione di likelihood**, 
    indicato con in lettera corsiva minuscola:.
![loglikelihood](immagini/loglikelihood.png)
  * Infatti, siccome il logaritmo e' una **funzione monotona crescente**,
    gli estremanti di una funzione e del suo logaritmo si trovano al medesimo posto
  * Il logaritmo di un prodotto di termini
    e' uguale alla somma dei logaritmi dei singoli termini,
    quindi la ricerca degli estremanti del logaritmo della funzione di likelihood
    e' **computazionalmente piu' semplice** rispetto alla 
    ricerca degli estremanti della funzione di likelihood:
![maxLoglikelihood](immagini/maxLoglikelihood.png)

![linea](../immagini/linea.png)

### 9.2.2 Le proprieta' degli stimatori di massima verosimiglianza

  * Sono **consistenti**
  * Sono **asintoticamente non distorti**, 
    cioe' hanno bias nullo per il numero di misure *N* che tende all'infinito
  * ono **asintoticamente efficienti**,
    cioe' hanno la varianza minima possibile 
    per il numero di misure *N* che tende all'infinito

![linea](../immagini/linea.png)

### 9.3


![linea](../immagini/linea.png)

### 9.1.2 Diversi campioni 

  * insieme di eventi, distribuzione non binnata
  * insieme di eventi, distribuzione binnata
  * relazione fra coppie di eventi *(x<sub>i</sub>, y<sub>i</sub>)* con relazione attesa *y = f(x, &theta;)*

![linea](../immagini/linea.png)

### 9.X.Y Tabella riassuntiva 

![linea](../immagini/linea.png)

## 9.8 ESERCIZI

  * Gli esercizi relativi alla lezione si trovano [qui](ESERCIZI.md)


