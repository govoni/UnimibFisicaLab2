# Lezione 9: stima di parametri con il metodo della massima verosimiglianza

## Indice

  * [9.1 Introduzione](#91-introduzione)
    * [9.1.1 Un modello che descrive i dati](#911-un-modello-che-descrive-i-dati)
    * [9.1.2 Distribuzioni di probabilità](#912-distribuzioni-di-probabilità)
    * [9.1.3 La determinazione dei parametri](#913-la-determinazione-dei-parametri)
  * [9.2 La massima verosimiglianza](#92-la-massima-verosimiglianza)
    * [9.2.1 Il logaritmo della massima verosimiglianza](#921-il-logaritmo-della-massima-verosimiglianza)
    * [9.2.2 La sigma della distribuzione dei parametri stimati](#922-la-sigma-della-distribuzione-dei-parametri-stimati)
    * [9.2.3 Le proprietà degli stimatori di massima verosimiglianza](#923-le-proprietà-degli-stimatori-di-massima-verosimiglianza)
  * [9.3 Un utile intermezzo: la lettura di un *file* di testo](#93-un-utile-intermezzo-la-lettura-di-un-file-di-testo)
    * [9.3.1 L'implementazione della lettura](#931-limplementazione-della-lettura)
  * [9.4 La costruzione di una *likelihood* e la determinazione di un parametro](#94-la-costruzione-di-una-likelihood-e-la-determinazione-di-un-parametro)
    * [9.4.1 La distribuzione di probabilità e la funzione di *likelihood*](#941-la-distribuzione-di-probabilità-e-la-funzione-di-likelihood)
    * [9.4.2 La determinazione del massimo del logaritmo della *likelihood*](#942-la-determinazione-del-massimo-del-logaritmo-della-likelihood)
    * [9.4.3 L'applicazione al caso in esame](#943-lapplicazione-al-caso-in-esame)
    * [9.4.4 La sigma associata allo stimatore di &tau;](#944-la-sigma-associata-allo-stimatore-di-tau)
    * [9.4.5 L'equivalente grafico](#945-lequivalente-grafico)
    * [9.4.6 L'implementazione della funzione *h(&tau;)*](#946-limplementazione-della-funzione-htau)
    * [9.4.7 Il calcolo numerico dei punti di intersezione](#947-il-calcolo-numerico-dei-punti-di-intersezione)
    * [9.4.8 L'utilizzo nel programma principale](#948-lutilizzo-nel-programma-principale)
    * [9.4.9 Il confronto con una stima analitica](#949-il-confronto-con-una-stima-analitica)
  * [9.5 La distribuzione di probabilità degli stimatori](#95-la-distribuzione-di-probabilità-degli-stimatori)
    * [9.5.1 La generazione di un *toy experiment*](#951-la-generazione-di-un-toy-experiment)
    * [9.5.2 Il calcolo del parametro con il metodo della massima verosimiglianza](#952-il-calcolo-del-parametro-con-il-metodo-della-massima-verosimiglianza)
    * [9.5.3 Il risultato dello studio](#953-il-risultato-dello-studio)
    * [9.5.4 La copertura dell'intervallo di confidenza](#954-la-copertura-dellintervallo-di-confidenza)
  * [9.6 ESERCIZI](#96-esercizi)

![linea](../immagini/linea.png)

## 9.1 Introduzione

  * Studiamo la statistica nel **paradigma frequentista**,
    secondo il quale la probabilità è definita operativamente 
    come la frazione di volte in cui una misura ha un determinato risultato, 
    rispetto ad un totale molto grande
  * Il **risultato di un esperimento** di misura
    è uno dei possibili risultati date le configurazioni iniziali

![linea](../immagini/linea.png)

### 9.1.1 Un modello che descrive i dati

  * Un **modello** è una distribuzione di probabilità *f*
    o una legge *g* alla quale ci si aspetta che le misure obbediscano.
  * I **risultati delle misure** sono ovviamente variabili 
    rispetto alle quali il modello dipende
  * Ulteriori variabili presenti nel modello,
    che non sono misurate,
    sono dette **parametri**.

![linea](../immagini/linea.png)

### 9.1.2 Distribuzioni di probabilità

  * Dato un insieme di misure reali *x<sub>i</sub>* definite su un insieme &Omega; 
    indipendenti identicamente distribuiite,
    sappiamo che seguono una **data distribuzione di densità probabilità**, 
    indicata genericamente come *f(x, &theta;)*
  * Questo significa che *f(x<sub>i</sub>, &theta;)* è **la densità di probabilità**
    che la misura avvenga nel punto x<sub>i</sub> dell'insieme di definizione &Omega;.
  * Il **simbolo &theta;** indica che la funzione di densità di probabilità *f*
    dipende da altre variabili oltre che *x*
    * &theta; può anche essere un vettore di parametri
    * Ad esempio, una **distribuzione Gaussiana** ha due parametri aggiuntivi, &mu; e &sigma;:
![gaussian](immagini/gaussian.png)

![linea](../immagini/linea.png)

### 9.1.3 La determinazione dei parametri

  * Spesso l'obiettivo di un esperimento è la **stima dei parametri** di un modello
  * Per ottenere questo risultato, 
    si **raccolgono molti dati** *x<sub>i</sub>* e si utilizzano come input
    ad algoritmi, detti **stimatori**, che stimino i parametri di interesse
  * Le **stime** prodotte da uno stimatore **sono variabili casuali**, 
    perché tramite gli stimatori sono funzioni di numeri casuali (i dati)
    * Hanno una propria distribuzione di probabilità
![stime](immagini/stime.png)
  * Esistono programmi che svolgono il compito per noi. 
    Fra questi, ```ROOT``` contiene diversi algoritmi per farlo.
    In gergo, **l'operazione di determinazione dei parametri è chiamata *fit***,
    cioè adatattamento.

![linea](../immagini/linea.png)

## 9.2 La massima verosimiglianza

  * La tecnica della massima verosimiglianza
    si basa sull'assunto che la stima dei parametri ricercati
    corrisponda al **valore 
    che massimizza la *likelihood***,
    definita come
    il prodotto del valore della distribuzione di densità di probabilità
    calcolata per ogni misura effettuata:
![likelihood](immagini/likelihood.png)
  * La *likelihood* è funzione sia delle misure che dei parametri, 
    tuttavia si **evidenzia la dipendenza dai parametri** perché
    a misure finite i dati sono immutabili.
  * La funzione che stima i parametri dunque si ricava dall'equazione:
![maxLikelihood](immagini/maxLikelihood.png)

![linea](../immagini/linea.png)

### 9.2.1 Il logaritmo della massima verosimiglianza

  * Solitamente si utilizza il **logaritmo della funzione di *likelihood***, 
    indicato con in lettera corsiva minuscola:.
![loglikelihood](immagini/loglikelihood.png)
  * Infatti, siccome il logaritmo è una **funzione monotona crescente**,
    gli estremanti di una funzione e del suo logaritmo si trovano al medesimo posto
  * Il logaritmo di un prodotto di termini
    è uguale alla somma dei logaritmi dei singoli termini,
    quindi l'operazione di derivata del logaritmo della funzione di *likelihood*
    è **più semplice** rispetto alla 
    derivata della funzione di *likelihood*:
![maxLoglikelihood](immagini/maxLoglikelihood.png)
  * Il logaritmo di un numero è più piccolo del numero stesso
    e varia su un intervallo minore rispetto alla variabilità del numero stesso,
    quindi **operazioni con i logaritmi sono più stabili numericamente**

![linea](../immagini/linea.png)

### 9.2.2 La sigma della distribuzione dei parametri stimati

  * Sappiamo che esiste un **metodo grafico** 
    per la determinazione della sigma associata ai parametri stimati con 
    il metodo della massima verosimiglianza
  * consiste nel deteminare i punti di intersezione 
    fra la funzione di log-*likelihood* 
    e la retta orizziontale con coordinata pari al **massimo di log-*likelihood* - 0.5**
    e calcolarne la mezza distanza

![linea](../immagini/linea.png)

### 9.2.3 Le proprietà degli stimatori di massima verosimiglianza

  * Sono **consistenti**
  * Sono **asintoticamente non distorti**, 
    cioè hanno bias nullo per il numero di misure *N* che tende all'infinito
  * Sono **asintoticamente efficienti**,
    cioè hanno la varianza minima possibile 
    per il numero di misure *N* che tende all'infinito

![linea](../immagini/linea.png)

## 9.3 Un utile intermezzo: la lettura di un *file* di testo

  * Può essere comodo **salvare informazioni semplici** su file di testo,
    per poterle rileggere dai programmi di analisi dati
  * La gestione dell'accesso a file di testo in ```C++``` è **analoga
    alla scrittura a schermo e lettura da tastiera**:
    si utilizzano gli operatori di redirezione ```operator>>``` (per leggere)
    ed ```operator<<``` (per scrivere) fra un oggetto che rappresenta il file
    e le variabili

![linea](../immagini/linea.png)

### 9.3.1 L'implementazione della lettura

  * L'oggetto che rappresenta un file è di tipo ```fstream```: 
    ```ifstream``` per lettura (**input file stream**) ed
    ```ofstream``` per scrittura (**output file stream**):
    ```cpp
    #include <fstream>
    // ...
    ifstream input_file ; 
    input_file.open ("file.txt", ios::in) ;
    // ...
    vector<double> data ;
    double input_val ;
    while (true) 
      {
        input_file >> input_val ;
        if (input_file.eof () == true) break ;
        data.push_back (input_val) ;
      } 
    input_file.close () ;
    ```
    * In questo modo, una sequenza di numeri scritti nel file ```file.txt```
      vengono letti uno ad uno, **trasferendone il valore nella variabile ```input_val```**
    * Il valore della variabile, ad ogni lettura, viene aggiunto al ```vector``` chiamato ```data```
    * All'interno del file di testo,
      i valori sono seperati da spazi, tab o accapo.  
    * Al termine della lettura, il *file* viene chiuso.

![linea](../immagini/linea.png)

## 9.4 La costruzione di una *likelihood* e la determinazione di un parametro

  * Si utilizzerà l'esempio della distribuzione esponenziale
    per determinarne l'unico parametro &tau; tramite il metodo della massima verosimiglianza:
![esponenziale](immagini/esponenziale.png)
  * **Si dimostra analiticamente**
    che la media artimetica dei dati è uno stimatore del parametro &tau;,
  * si vuole in questo caso **costruire lo stimatore numerico**
    del parametro,
    come esempio di un caso generale in cui il calcolo analitico non sia possibile.

![linea](../immagini/linea.png)

### 9.4.1 La distribuzione di probabilità e la funzione di *likelihood*

  * Sia la distribuzione di densità di probabilità
    che il calcolo della *likelihood* vanno scritte in codice sorgente:
    ```cpp
    double esponenziale (double x, double tau)
      {
         if (tau == 0.) return 1. ;
         return exp (-1. * x / tau) / tau ;
      }
    ```
    * il primo ```if``` serve a **proteggere il programma** da risultati infiniti
  * il calcolo della *likelihood* avrà in ingresso
    sia i dati, che il parametro di interesse:
    ```cpp
    double loglikelihood (
      const vector<double> & data, 
      double param
    )
    {
      double result = 0. ; 
      for (int i = 0 ; i < data.size () ; ++i) result += log (esponenziale (data.at (i), param)) ;
      return result ;   
    }
    ```
    * in questo caso, 
      si calcola il logaritmo del valore della densità di probabilità in ogni punto

![linea](../immagini/linea.png)

### 9.4.2 La determinazione del massimo del logaritmo della *likelihood*

  * Si può utilizzare l'**algoritmo della sezione aurea** sviluppato durante la Lezione 6
    per trovare il massimo della log-likelihood:
    ```cpp
    double sezione_aurea_max (
      double logl (const vector<double> & , double),
      double xMin,
      double xMax,
      const vector<double> & data,
      double precision = 0.0001
    )
    ```
    * Il programma va scritto in modo che si **cerchi il massimo** di una funzione
    * I **parametri in ingresso** sono 
      la funzione di cui trovare l'estremante (```logl```),
      l'intervallo sul quale cercare il valore massimo **per il parametro &tau;**,
      il ```vector``` contenente i dati
      e la precisone alla quale arrestare il calcolo,
      per la quale c'è un valore di default.

![linea](../immagini/linea.png)

### 9.4.3 L'applicazione al caso in esame

  * Dopo aver letto un file contenente numeri distribuiti secondo una densità di probabilità esponenziale,
    che si può visualizzare con un ```TH1F``` di ```ROOT```:
![istogramma_esponenziale](immagini/istogramma_esponenziale.png)
  * Le funzioni sviluppate possono essere utilizzate 
    con i numeri salvati in un ```vector```,
    a partire da un **intervallo di ricerca del massimo scelto ragionevolmente**:
    ```cpp
    double massimo = sezione_aurea_max (loglikelihood, 0.5 * media_v, 1.5 * media_v, data) ;
    ```
  * Il risultato di questo algoritmo può essere **confrontato con la media aritmetica** 
    dei numeri, che per questa particolare distribuzione di probabilità
    è uno stimatore di &tau;:
    ```
    letti 100 eventi
    media = 5.44364
    massimo della likelihood = 5.44362
    ```

![linea](../immagini/linea.png)

### 9.4.4 La sigma associata allo stimatore di &tau;

  * Lo stimatore di &tau; è una variabile casuale, 
    cioè ha una **proria distribuzione di probabilità**
  * Dunque oltre al avere associata una stima puntuale ricavata massimizzando
    il logaritmo della verosimiglianza
    **possiede anche una sigma**
  * Si utilizza spesso un **metodo grafico** per determinare questa sigma,
    che si basa sul fatto che asintoticamente la funzione di *likelihood* rispetto ai parametri è Gaussiana,
    dunque che la funzione di *log-likelihood* è parabolica
  * Si dimostra che **si trovano i due punti *&tau; - &sigma;<sub>&tau;</sub>* e *&tau; + &sigma;<sub>&tau;</sub>***
    annullando la seguente funzione:
![metodo_grafico_equazione](immagini/metodo_grafico_equazione.png)

![linea](../immagini/linea.png)

### 9.4.5 L'equivalente grafico

  * **Disegnando la funzione *h(&tau;)*** si ottiene, 
    al variare del numero di eventi utilizzati per calcolare la funzione *log-likelihood*:
![loglikelihood_profile](immagini/loglikelihood_profile.png)
  * al crescere del numero di eventi utilizzati,
    la funzione *h(&tau;)* diventa più stretta,
    cioè **la sigma dello stimatore diminuisce**
  * al crescere del numero di eventi utilizzati,
    la funzione *h(&tau;)* diventa più simmetrica,
    cioè **assume comportamento asintotico**

![linea](../immagini/linea.png)

### 9.4.6 L'implementazione della funzione *h(&tau;)* 

  * Si può implementare la funzione *h(&tau;)*
    **a partire dalla funzione ```loglikelihood```**:
    ```cpp
    double h (
      const vector<double> & data, 
      double param,
      double max
    )
    {
      return loglikelihood (data, param) + 0.5 - loglikelihood (data, max) ;   
    }
    ```  

![linea](../immagini/linea.png)

### 9.4.7 Il calcolo numerico dei punti di intersezione

  * Si può **utilizzare il metodo della bisezione** per trovare
    *&tau; - &sigma;<sub>&tau;</sub>* e *&tau; + &sigma;<sub>&tau;</sub>*   
    ```cpp
    double bisezione (
      double h (const vector<double> & , double, double),
      double xMin,
      double xMax,
      const vector<double> & data,
      double massimo,
      double precision
    )
    {
      double xAve = xMin ;
      while ((xMax - xMin) > precision)
        {
          xAve = 0.5 * (xMax + xMin) ;
          if (h (data, xAve, massimo) * h (data, xMin, massimo) > 0.) xMin = xAve ;
          else                                                        xMax = xAve ;
        }
      return xAve ;
    }
    ```

![linea](../immagini/linea.png)

### 9.4.8 L'utilizzo nel programma principale

  * Su un intervallo relativamente ristretto intorno al massimo 
    della funzione *log-likelihood* sappiamo che
    **la funzione *h(&tau;)* ha due zeri**,
    uno a destra ed uno a sinistra del suo massimo
  * Richiamando la funzione ```bisezione``` **due volte**,
    dunque, si possono calcolare i due punti desiderati:
    ```cpp
    double zero_sx = bisezione (h, 0.5 * media_v, massimo, data, massimo) ;
    double zero_dx = bisezione (h, massimo, 1.5 * media_v, data, massimo) ;

    cout << "zero_sx = " << zero_sx << endl ;
    cout << "zero_dx = " << zero_dx << endl ;
    cout << "sigma = " << 0.5 * (zero_dx - zero_sx) << endl ;
    ```
  * L'intervallo compreso fra i due punti di intersezione ```zero_sx``` e ```zero_dx```
    è l'**intervallo di confidenza** associato allo stimatore ottenuto

![linea](../immagini/linea.png)

### 9.4.9 Il confronto con una stima analitica

  * Si sa che nel caso della distribuzione esponenziale
    la **varianza è pari al quadrato della media**
  * L'**incertezza sulla media** è pari alla incertezza sulla singola misura,
    cioè la radice della varianza,
    divisa per la radice del numero di eventi
  * Dunque l'**incertezza sullo stimatore di &tau;**, 
    indicato con il simbolo dell'accento circonflesso,
    si può in questo caso stimare come:
![sigma_calcolata](immagini/sigma_calcolata.png)
  * Si può dunque confrontare il valore ottenuto dal metodo grafico
    con quello calcolato a partire dalla media aritmetica.

![linea](../immagini/linea.png)

## 9.5 La distribuzione di probabilità degli stimatori

  * La distribuzione di probabilità degli stimatori può essere **ricostruita in modo frequentista**,
    simulando l'esperimento di raccolta degli eventi un gran numero di volte,
    con la tecnica dei *toy experiment* descritta nella Lezione 6
  * Per la generazione di un *toy experiment* bisogna ipotizzare
    il **valore vero del parametro** (```mu_true``` nel caso trattato finora)
    ed il **numero di eventi raccolto** (```numero_eventi```)
  * Per costruire la distribuzione dello stimatore di &tau;
    bisogna ripetere **due procedure** un gran numero di volte (```N_toy```):
    * **Generazione** di un toy experiment
    * **Calcolo dello stimatore** data quella generazione, come se fossero gli eventi misurati 
      (nell'esempio di questa lezione, i numeri salvati in ```dati_esponenziali.txt```)

![linea](../immagini/linea.png)

### 9.5.1 La generazione di un *toy experiment*

  * Per generare un *toy experiment* si ricorre solitamente a **numeri pseudo-casuali**,
    utilizzando algoritmi esistenti adattati al caso in esame
  * Per generare numeri pseudo-casuali secondo una distribuzione esponenziale,
    si può utilizzare la tecnica dell'**inversa della funzione cumulativa**
    sviluppata nella Lezione 4:
    ```cpp
    double rand_IFC_Exp (double mu) ;
    ```
    * La funzione **prende in input il valore vero di &tau;** e restituisce un numero pseudo-casuale
      distribuito secondo la distribuzione di probabilità esponenziale corrispondente
  * Con questo algoritmo, 
    si può riempire un ```vector``` con i numeri generati:
    ```cpp
    vector<double> data_loc ;
    for (int i_sample = 0 ; i_sample < numero_eventi ; ++i_sample)
      {
        data_loc.push_back (rand_IFC_Exp (mu_true)) ;
      } 
    ```

![linea](../immagini/linea.png)

### 9.5.2 Il calcolo del parametro con il metodo della massima verosimiglianza

  * A partire dal ```vector``` ```data_loc``` si può applicare il metodo della massima verosimiglianza
    sviluppato precedentemente, ottenendo un risultato per ogni *toy experiment*
    ```cpp
    double media_v = media (data_loc) ;
    double sigma_subsample = media_v / sqrt (data_loc.size ()) ;
    double massimo = sezione_aurea_max (loglikelihood, 0.5 * media_v, 1.5 * media_v, data_loc) ;
    ```

![linea](../immagini/linea.png)

### 9.5.3 Il risultato dello studio

  * Entrambi i passaggi sono **inseriti in un ciclo generale**,
    dove si può riempire un istogramma (o altri strumenti statistici) 
    ```cpp
    for (int i_toy = 0 ; i_toy < N_toys ; ++i_toy)
      {
        if (i_toy % 1000 == 0) cout << "running toy " << i_toy << endl ;
        // generazione di un toy experiment
        // calcolo della stima con lo stimatore della massima verosimiglianza
        h_max.Fill (massimo) ;
      }

    ```
  * Il risultato mostra chiaramente l'**evoluzione della distribuzione di probabilità**
    dello stimatore al crescere del numero di misure a disposizione:
![pdf_stimatore_2.png](immagini/pdf_stimatore_2.png)

![linea](../immagini/linea.png)

### 9.5.4 La copertura dell'intervallo di confidenza

  * Secondo la formulazione frequstista della probabilità,
    la **copertura** è la frazione di volte in cui l'intervallo 
    *&tau; - &sigma;<sub>&tau;</sub>* e *&tau; + &sigma;<sub>&tau;</sub>*
    contiene il valor vero
  * Anche questa quantità si può **verificare con il metodo dei *toy experiment***,
    calcolando per ogni *toy experiment*
    l'intervallo di confidenza associato ad uno stimatore
    e verificando la posizione del valore vero rispetto a questo intervallo
    ```cpp
    int contatore_copertura = 0 ;
    for (int i_toy = 0 ; i_toy < N_toys ; ++i_toy)
      {
        if (i_toy % 1000 == 0) cout << "running toy " << i_toy << endl ;
        // generazione di un toy experiment
        // calcolo della stima con lo stimatore della massima verosimiglianza
        double zero_sx = bisezione (h, 0.5 * media_v, massimo, data_loc, massimo) ;
        double zero_dx = bisezione (h, massimo, 1.5 * media_v, data_loc, massimo) ;
        if (mu_true > zero_sx && mu_true < zero_dx) ++contatore_copertura ;
      }
    cout << "copertura : " << static_cast<double> (contatore_copertura) / N_toys << endl ;

    ```

![linea](../immagini/linea.png)

## 9.6 ESERCIZI

  * Gli esercizi relativi alla lezione si trovano [qui](ESERCIZI.md)


