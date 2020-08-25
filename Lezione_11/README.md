# Lezione 11: fit di distribuzioni binnate con ```ROOT```

![linea](../immagini/linea.png)

## 11.1 Introduzione

  * I metodi dei minimi quadrati e della massima verosimiglianza
    possono essere **applicati anche al caso di istrogrammi**,
    cioè di distribuzioni binnate, 
    dove si voglia fittare una funzione alla distribuzione dei conteggi nei bin:
![histo](immagini/histo.png)
  * In questo caso, il contenuto di ogni bin è un numero di eventi *n<sub>i</sub>*
  * Se il numero di bin e il numero medio di eventi in ciascuno di essi non è piccolo,
    si può assumere che la variabile casuale *n<sub>i</sub>* segua
    una **statistica di Poisson**
![poisson](immagini/poisson.png)

![linea](../immagini/linea.png)

### 11.1.1 L'applicazione del metodo dei minimi quadrati

  * Nel caso dei minimi quadrati, 
    la funzione ***Q<sup>2</sup>(&theta;)*** è solitamente la seguente (formulazione di Neyman):
![mq](immagini/mq.png)
  * Il valore di *y<sub>i</sub>* della lezione scorsa è **costituito da *n<sub>i</sub>*** 
  * L'**incertezza su *n<sub>i</sub>*** è data dalla sua radice quadrata,
    secondo la statistica di Poisson
  * Il valore di *x<sub>i</sub>* è il **centro del bin corrispondente**
  * Il numero di bin dell'istogramma è *N*

![linea](../immagini/linea.png)

### 11.1.2 L'applicazione del metodo della massima verosimiglianza

  * Nel caso della massima verosimiglianza, 
    si assume che in ogni bin i conteggi seguano una **distribuzione di probabilità Poissoniana**
    con valore atteso *&mu; = f(x<sub>i</sub>, &theta;)*:
![mq](immagini/ml.png)

![linea](../immagini/linea.png)

### 11.1.3 La scelta fra le due tecniche

  * Nel caso di **pochi conteggi** presenti nei bin,
    * bin senza conteggi non contribuiscono al fit nel caso dei minimi quadrati, 
      nonostante l'assenza di eventi sia un'informazione importante
    * consigliato utilizzare il metodo della **massima verosimiglianza**
  * Nel caso di **molti conteggi** presenti nei bin,
    i due metodi sono equivalenti
    e spesso il metodo dei **minimi quadrati** è computazionalmente più semplice

![linea](../immagini/linea.png)

## 11.2 Un esercizio di regressione

  * Supponiamo di **raccogliere eventi** lungo una variabile *x* 
    e di voler determinare i parametri della distribuzione di probabilità della variabile
  * Assumiamo che questo modello abbia una forma data 
    da una **distribuzione di fondo esponenziale sommata ad una di segnale gaussiana**:
![modello_formula](immagini/modello_formula.png)
  * **Graficamente**, 
    il modello ha un andamento descrescente che risale quando il termine Gaussiano diventa imporante,
    come mostrato in figura:
![modello](immagini/modello.png)
    * la **linea continua** mostra il modello totale
    * mentre le **due linee tratteggiate** mostrano i
      due termini della somma,
      che si possono pensare come un **picco di segnale
      sovrapposto ad un fondo lentamente decrescente**

![linea](../immagini/linea.png)

### 11.2.1 La lettura dei dati

  * Supponiamo di aver **raccolto 10,000 eventi**,
    che si trovano salvati nel file [dati.txt](programmi/dati.txt)
  * Quando si visualizzano gli eventi in un istogramma,
    siccome si tratta di un esperimento di conteggio
    il **contenuto di ogni bin fluttua** in maniera stocastica:
![distribuzioni](immagini/distribuzioni.png)
    * Nel caso di 10,000 eventi le fluttuazioni relative
      sono molto più accentuate del caso con 10,000,000 di eventi,
      come ci si aspetta
    
![linea](../immagini/linea.png)

### 11.2.2 La determinazione dei parametri &\theta;

  * Per **determinare i parametri &\theta;** si utilizza tipicamente 
    il metodo dei minimi quadrati o della massima verosimiglianza
  * In entrambi i casi, bisogna trovare l'estremante di una funzione 
    * con **molti parametri**
    * in presenza di **fluttuazioni statistiche**
  * In questa lezione si ricorrerà agli **[algoritmi disponibili in ```ROOT```](https://root.cern.ch/root/htmldoc/guides/users-guide/FittingHistograms.html)**
    per poter trattare un problema sofisticato

![linea](../immagini/linea.png)

### 11.2.3 Il fit di un istogramma in ```ROOT```

  * Per poter effettuare il fit, 
    e' necessario definire il modello funzionale nel linguaggio di ```ROOT```
  * Una funzione si rappresenta con un oggetto di tipo ```TF1```:  
    ```cpp
    TF1 segnale ("segnale", "gaus(0)",0., 20.) ;
    segnale.SetParameter (0, p2) ;
    segnale.SetParameter (1, p3) ;
    segnale.SetParameter (2, p4) ;
    ```
    * In questo caso, la funzione sfrutta l'implementazione interna di ```ROOT``` della **Gaussiana**
    * La funzione è definita **sull'intervallo ```0., 20```**
    * La ```gaus``` ha **tre parametri**, perché per fittare un istogramma non normalizzato
      anche l'integrale della funzione è un parametro libero
    * L'indice del primo parametro è ```0```, come indicato fra parentesi in ```gaus(0)```
    * Il metodo ```TF1::SetParameter``` permette di **assegnare valori** ai parametri

![linea](../immagini/linea.png)

### 11.2.4 Il fondo ed il modello completo

   * Analogamente, 
     la distribuzione di probabilità del rumore di fondo è:
     ```cpp
     TF1 fondo ("fondo", "expo(0)", 0., 20.) ;
     ```
   * Il modello totale, 
     indipendente dai primi due, è:  
     ```cpp
     TF1 model ("model", "expo(0) + gaus(2)", 0., 20.) ;
     ```
     * In questo caso, l'indice dei parametri della Gaussiana inizia da ```2```

![linea](../immagini/linea.png)

### 11.2.5 Il fit del modello ai dati

  * L'**operazione di fit** viene effettuata con il seguente comando, 
    che invoca il metodo dei **minimi quadrati**:
    ```cpp
    TFitResultPtr fit_result = h_eventi.Fit ("model", "S") ;
    ```
  * Dopo il fit, 
    la funzione con nome ```"model"``` ha i propri **parametri adattati all'istogramma**
  * L'oggetto ```TFitResultPtr``` contiene i **risultati del fit**
  * **Difficilmente il fit ha successo autonomamente**,
    perché a causa del gran numero di parametri &theta; e delle fluttuazioni 
    stocastiche del contenuto dei bin 
    il programma non riesce a trovare il minimo giusto della funzione *Q<sup>2</sup>*

![linea](../immagini/linea.png)

### 11.2.6 Come aiutare ```ROOT``` a trovare il minimo giusto

  * Per facilitare il fit,
    è molto efficace dare a ```ROOT``` un **punto di partenza non distante dal risultato finale**,
    basandosi sulla conoscenza del problema:
    * I parametri &theta<sub>0<sub>; e &theta<sub>2<sub>; 
      sono l'integrale delle due funzioni di segale e fondo, 
      quindi sono **legati all'integrale dell'istogramma**:
      ```cpp
      double N_bkg = v_eventi.size () / 2. ;
      double p0 = log (N_bkg) ;             // eventi di fondo
      double p2 = v_eventi.size () / 2. ;   // eventi di segnale
      model.SetParameter (0, p0) ;
      model.SetParameter (1, p1) ;
      ```
    * L'esponenziale e' sicuramente **decrescente**:  
      ```cpp
      double p1 = -0.5 ;                    // pendenza del fondo
      ```
    * Il **massimo della Gaussiana** si trova circa a metà dell'intervallo:
      ```cpp
      double p3 = 0.5 * (max - min) ;       // media del segnale
      ```
    * La **larghezza della Gaussiana** è in qualche modo correlata alla sigma dell'istogramma:
      ```cpp
      double p4 = h_eventi.GetRMS () ;      // sigma del segnale
      ```

![linea](../immagini/linea.png)

### 11.2.6 Come maneggiare meno parametri alla volta

  * Talvolta anche partendo da valori ragionevoli dei parametri 
    **il fit non converge** all'estremante cercato
  * In questo caso, 
    può essere d'aiuto identificare una regione dello spettro di *x* 
    dove soltanto **un sottoinsieme dei parametri è rilevante**
![modello_regioni](immagini/modello_regioni.png)

![linea](../immagini/linea.png)

### 11.2.7 I parametri dell'esponenziale dalla regione esponenziale

  * Un **fit parziale** soltanto sull'intervallo ```0., 4.```
    con la dsitribuzione di probabilita' del solo fondo
    permette di calcolare una stima preliminare di &theta<sub>0</sub>; e &theta<sub>1</sub>;
    ```cpp
    TF1 fondo ("fondo", "expo(0)", 0., 20.) ;
    fondo.SetParameter (0, p0) ;
    fondo.SetParameter (1, p1) ;
    h_eventi.Fit ("fondo", "Q", "", 0., 4.) ;
    ```
  * Un **fit parziale** soltanto sull'intervallo ```7., 14.```
    con la dsitribuzione di probabilita' del solo segnale
    permette di calcolare una stima preliminare di &theta<sub>0</sub>; e &theta<sub>1</sub>;
    ```cpp
    TF1 segnale ("segnale", "gaus(0)", 0., 20.) ;
    segnale.SetParameter (0, p2) ;
    segnale.SetParameter (1, p3) ;
    segnale.SetParameter (2, p4) ;
    h_eventi.Fit ("segnale", "Q", "", 7., 14.) ;
    ```

![linea](../immagini/linea.png)

### 11.2.8 Il fit finale

  * Dopo aver **impostato i parametri** iniziali della funzione ```"model"```
    con i valori ricavati in precedenza,
    si effettua il fit finale:
    ```cpp
    model.SetParameter (0, fondo.GetParameter (0)) ;
    model.SetParameter (1, fondo.GetParameter (1)) ;
    model.SetParameter (2, segnale.GetParameter (0)) ;
    model.SetParameter (3, segnale.GetParameter (1)) ;
    model.SetParameter (4, segnale.GetParameter (2)) ;    

    TFitResultPtr fit_result = h_eventi.Fit ("model", "S") ;
    ```




  
    // prima stima di p2, p3, p4 bloccando i coefficienti del fondo



  - prima il fit giusto e completo con il metodo del chi2 e ML
    - rem come ottenere la matrice di covarianza
  - poi casi speciali
    - statistica piu' bassa => test del chi2 non vale più
    - andamento risultato vs statistica totale => TGraphErrors e fit di quello
    - (andamento risultato vs. numero di bin)
  - ricavare il valore dei parametri da sideband?
  - https://root.cern.ch/root/htmldoc/guides/users-guide/FittingHistograms.html



![mq](immagini/modello.png)
![mq](immagini/modello_formula.png)
![mq](immagini/distribuzioni.png)


![linea](../immagini/linea.png)

## 11.7 ESERCIZI

  * Gli esercizi relativi alla lezione si trovano [qui](ESERCIZI.md)
