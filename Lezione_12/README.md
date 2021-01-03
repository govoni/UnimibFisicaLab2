# Lezione 12: Test di Ipotesi

![linea](../immagini/linea.png)

## 12.1 Introduzione
    
  * si hanno N campionamenti IID di una *pdf(x)* con *x* variabile mono o pluri-dimensionale, si vuole:
    * valutare la validità di un'ipotesi *H<sub>0</sub>* relativa alla *pdf(x)* 
    * confrontare l'ipotesi *H<sub>0</sub>* con l'ipotesi alternativa H<sub>1</sub>, entrambe relative alla *pdf(x)*
  * le ipotesi si dividono in:
	* semplici, che non prevedono stima di parametri
	* composte, che prevedono dapprima di stimare i parametri e poi di effettuare il test
  * in questa lezione consideriamo il caso di ipotesi semplici
 ![linea](../immagini/linea.png)

## 12.1.1 Regione Critica, Size e Power
  * un test di ipotesi prevede di:
	* costruire una statistica *t* usando i campionamenti 
	* scartare l'ipotesi H<sub>0</sub> quando *t* cade nella regione del sample space che 
      chiamiamo **regione critica**
	 
   * il test è caratterizzato da due parametri: 
     * &alpha; è la probabilità che l'ipotesi H<sub>0</sub> venga scartata quando è vera: è il **size** del test
     * &beta; è la probabilità  che l'ipotesi H<sub>0</sub> viene accettata quando è vera H<sub>1</sub>: 
      (1-&beta;) è il **power** del test   
   * la regione critica non è univocamente determinabile dal size del test 
  * **la regione critica che massimizza il power del test, una volta fissato il suo size, è la Best Critical Region (BCR)**
![linea](../immagini/linea.png)

## 12.1.2 Il test del Chi-Quadro
   * il test del chi-quadro analizza una singola ipotesi *H<sub>0</sub>*
     * i parametri sono stimati preventivamente ed il test usa il valore stimato
     * la statistica *t* è una variabile mono-dimensionale che segue la distribuzione del chi-quadro
     * la regione critica è data da *t* > *t*<sub>cut</sub>
     * il size è l'integrale della distribuzione chi-quadro per *t* > *t*<sub>cut</sub> 
   * in approccio frequentista chiamiamo **Confidence Level** il size: 
   è la probabilità che il test dia esito positivo quando l'ipotesi è vera. 
   
![linea](../immagini/linea.png)

## 12.1.3 Il Metodo del discriminante di Fischer  
   * sono dati N campionamenti IID di una *pdf(x)* e si vuole determinare se provengono dalla 
      *pdf(x| H<sub>0</sub>)* o dalla *pdf(x| H<sub>1</sub>)*
   * il metodo del determinante di Fischer prevede di:
     * costruire una statistica *t* che sia una funzione lineare dei campionamenti
     * accettare l'ipotesi se t < *t*<sub>cut</sub>
     * *t*<sub>cut</sub> identifica la regione critica e size e power del test
     
![linea](../immagini/linea.png)

## 12.1.4 Il Metodo del rapporto di Likelihood 
   * sono dati N campionamenti IID di una *pdf(x)* e si vuole determinare se provengono dalla 
      *pdf(x| H<sub>0</sub>)* o dalla *pdf(x| H<sub>1</sub>)*   
   * il metodo del rapporto di Likelihood prevede di:
      * usare come statistica del test il rapporto
![formulaLikeRatio](./immagini/Formula_LikelihoodRatio.png)
      * accettare l'ipotesi se il rapporto è < *t*<sub>cut</sub> 
      * *t*<sub>cut</sub> identifica la regione critica e size e power del test
   * nel caso di ipotesi semplici questa procedura produce, a parità di size, il test con il power più alto
      la regione critica in questo caso si chiama **Best Critical Region** o  BCR
      
![linea](../immagini/linea.png)

## 12.2 Decorrelazione lineare di variabili

  * Dato un campione di *N* misure (*x*<sub>i</sub>, *y*<sub>i</sub>) indipendenti ed identicamente distribuite,
    in generale la variabile *x* può essere **linearmente correlata con la variabile *y***,
    cioè la covarianza &sigma;<sub>xy</sub> calcolata fra le due variabili può essere diversa da zero.
  * In questo caso,
    la matrice di covarianza associata al modello che descrive la misura, cioè alla popolazione,
    non è diagonale:
    ![covarianza](immagini/covarianza.png)

![linea](../immagini/linea.png)

### 12.2.1 Un cambio di coordinate

  * Siccome la covarianza descrive il livello di correlazione lineare che sussiste fra due variabili,
    esiste sempre un cambio di variabili nello spazio delle fasi del campione
    tale per cui **le variabili trasformate siano non correlate fra di loro**
    ![rotazione](immagini/rotazione.png)

![linea](../immagini/linea.png)

### 12.2.2 Una rotazione della matrice di covarianza

  * Nel nuovo sistema di riferimento,
    la **matrice delle covarianze risulta quindi diagonale**
  * Questo non ci stupisce, 
    perché essendo simmetrica la matrice delle covarianze è sempre diagonalizzabile
  * Una trasformazione unitaria che diagonalizzi la matrice delle covarianze è **una rotazione di un angolo &theta;**
  * Data una matrice simmetrica 2x2:
    ![matrice2x2](immagini/matrice_simmetrica.png)
  * l'angolo di rotazione si calcola come:
    ![angoloSimm](immagini/theta_matrice_simmetrica.png)
  * che per il caso della matrice delle covarianze diventa:
    ![angoloCov](immagini/theta_matrice_covarianze.png)

![linea](../immagini/linea.png)

### 12.2.3 La rotazione delle variabili

  * Noto l'angolo di rotazione &theta;, la matrice di rotazione associata è:
    ![rotazioneMatrice](immagini/rotazione_matrice.png)
  * Che corrisponde al cambio di variabili:
    ![rotazioneSistema](immagini/rotazione_sistema.png)
    
![linea](../immagini/linea.png)

## 12.3 Un esempio di implementazione di decorrelazione

  * Sia dato il campione di *N* misure (*x*<sub>i</sub>, *y*<sub>i</sub>) sotto forma di un *file* di testo.
  * Dopo aver trasferito i valori contenuti nel *file* in due ```vector```, 
    si può **calcolare la matrice delle covarianze sul campione**
    ed utilizzare i valori ottenuti 
    come stimatori della matrice delle covarianze del modello,
    utilizzando la tecnica della sostituzione per il calcolo di stimatori.
  * A partire dalla matrice così ottenuta, 
    si può quindi **calcolare l'angolo di rotazione e trasformare le variabili**

![linea](../immagini/linea.png)

### 12.3.1 La lettura del file di testo

  * Si esegue secondo le istruzioni già studiate durante la [Lezione 9](../Lezione_09/README.md),
    prestando attenzione al fatto che **le coppie di valori (*x*<sub>i</sub>, *y*<sub>i</sub>) 
    sono scritte una per riga**:
    ```cpp
    // apertura del file di testo
    double input_x ;
    double input_y ;
    while (true) 
      {
        input_file >> input_x ;
        input_file >> input_y ;
        if (input_file.eof () == true) break ;
        data_x.push_back (input_x) ;
        data_y.push_back (input_y) ;
      } 
    input_file.close () ;
    ```

![linea](../immagini/linea.png)

### 12.3.2 La costruzione della matrice delle covarianze

  * I **termini sulla diagonale** della matrice delle covarianze 
    sono la varianza di ciascuna variabile:
    ```cpp
    #include "../../Lezione_09/programmi/statistiche_vector.h"
    // ...
    double V_xx = varianza (data_x) ;
    double V_yy = varianza (data_y) ;
    ```
  * Dove la funzione che calcola la varianza utilizza
    una ben nota formula:
    ```cpp
    template <class T>
    T varianza (const std::vector<T> & input_v) 
    {
      T somma = 0 ;
      T sommaSq = 0 ;
      for (int i = 0 ; i < input_v.size () ; ++i) 
        {
          somma += input_v.at (i) ;
          sommaSq += input_v.at (i) * input_v.at (i) ;
        }  
      return sommaSq / static_cast<float> (input_v.size ()) - 
             (somma / static_cast<float> (input_v.size ()) * somma / static_cast<float> (input_v.size ())) ;
    }
    ```

![linea](../immagini/linea.png)

### 12.3.3 Il calcolo delle covarianze

  * La covarianza è definita come:
    ![covarianzaDef](immagini/covarianza_definizione.png)
  * e può essere stimata sul campione come:
    ![covarianzaSti](immagini/covarianza_stimatore.png)
  * Il programma che implementa lo stimatore, dunque,
    esegue i seguenti calcoli:
    ```cpp
    double M_x = media (data_x) ;
    double M_y = media (data_y) ;
  
    double V_xy = 0. ;
    for (int i = 0 ; i < data_x.size () ; ++i)
      {
        V_xy += (data_x.at (i) - M_x) * (data_y.at (i) - M_y) ;
      }
    V_xy /= data_x.size () ;
    ```
![linea](../immagini/linea.png)

### 12.3.4 L'angolo di rotazione ed il cambio di variabili

  * Nota la matrice di covarianza, si può quindi **calcolare l'angolo di rotazione**:
    ```cpp
    double theta = 0.5 * atan (2 * V_xy / (V_xx - V_yy)) ;
    double c_theta = cos (theta) ;
    double s_theta = sin (theta) ;
    ```
  * E quindi l'effettivo cambio di variabili:
    ```cpp
    vector<double> data_x_dec ;
    vector<double> data_y_dec ;
    for (int i = 0 ; i < data_x.size () ; ++i)
      {
        data_x_dec.push_back (data_x.at (i) * c_theta + data_y.at (i) * s_theta) ; 
        data_y_dec.push_back (data_y.at (i) * c_theta - data_x.at (i) * s_theta) ; 
      }
    ```  
    
![linea](../immagini/linea.png)

## 12.4 Il discriminante di Fisher

  * Costruire una **combinazione lineare** delle variabili che caratterizzano gli eventi di interesse
    che serva per separare due ipotesi *H<sub>0</sub>* ed *H<sub>1</sub>*
  * Nel caso bidimensionale, dato un campione di eventi (*x*<sub>i</sub>, *y*<sub>i</sub>)
    1. **determinare la statistica di test** *t(x,y)* da utilizzare per separare le due ipotesi
    2. **usare la statistica di test** per distinguere le due ipotesi:

|  |  |
| --------------- | ------- |
| *H<sub>0</sub>* | *t(x,y) < t<sub>cut</sub>*  |
| *H<sub>1</sub>* | *t(x,y) >= t<sub>cut</sub>* |

![linea](../immagini/linea.png)

### 12.4.1 La determinazione della direzione del discriminante

  * La statistica di test è una *combinazione lineare* delle variabili che caratterizzano ogni evento:
![fisher_kD](./immagini/fisher_kD.png)
  * che nel caso bidimnesionale diventa:
![fisher_2D](./immagini/fisher_2D.png)
  * Il discriminante di Fisher è la determinazione dei coefficienti *f<sub>x</sub>* ed *f<sub>y</sub>*,
    cioè del vettore ***f***,
    tramite la seguente equazione:
![fisher](./immagini/fisher.png)
  * dove: 
    * ***&mu;<sub>0</sub>*** e ***&mu;<sub>1</sub>*** rappresentano la media attesa
      nel caso di ipotesi *H<sub>0</sub>* ed *H<sub>1</sub>* rispettivamente
    * *W* è la somma delle matrici delle covarianze *V<sub>0</sub>* e *V<sub>1</sub>*
      per le ipotesi *H<sub>0</sub>* ed *H<sub>1</sub>* rispettivamente:
![Wmtr](./immagini/Wmtr.png)

![linea](../immagini/linea.png)

### 12.4.2 Due modelli da confrontare

  * Le medie ***&mu;<sub>i</sub>*** e le matrici delle covarianze *V<sub>i</sub>*
    possono essere determinate **a partire da campioni simulati** di eventi
    generati secondo due modelli *H<sub>0</sub>* ed *H<sub>1</sub>*.
![confronto](./immagini/confronto.png)

![linea](../immagini/linea.png)

### 12.4.3 Il calcolo delle matrici di covarianza

  * Supponendo che gli eventi simulati siano contenuti in due ```vector<vector<double> >```,
    le **matrici delle covarianze** possono essere calcolate:
    ```cpp
    #include "../../Lezione_10/programmi/algebra_2.h"
    // ...
    vector<vector<double> > data_1 ;
    // riempimento del vector
    matrice cov_1 = determinaCovarianza (data_1) ;
    ```
    * dove la funzione ```determinaCovarianza``` richiama le funzioni
      già definite in precedenza per il calcolo dei singoli elementi
      della matrice delle covarianze

![linea](../immagini/linea.png)

### 12.4.4 Il calcolo delle medie

  * **La media** lungo la direzione *x* e *y* può altrettanto essere calcolata:
    ```cpp
    #include "../../Lezione_09/programmi/statistiche_vector.h"
    #include "../../Lezione_10/programmi/algebra_2.h"
    // ...
    vettore media_1 (2) ;
    media_1.setCoord (0, media (data_1.at (0))) ;
    media_1.setCoord (1, media (data_1.at (1))) ;
  
    vettore media_2 (2) ;
    media_2.setCoord (0, media (data_2.at (0))) ;
    media_2.setCoord (1, media (data_2.at (1))) ;

    ```    

![linea](../immagini/linea.png)

### 12.4.5 Il calcolo della direzione del discriminante di Fisher

  * Con queste informazioni a disposizione,
    si può **determinare il vettore *f***:
    ```cpp

    matrice W = cov_1 + cov_2 ;
    vettore fisher = W.inversa () * (media_2 - media_1) ; 
    ```
  * Il vettore ***f*** corrisponde alla direzione di proiezione ottimale degli eventi
    lungo la quale separare le due ipotesi:
![confronto_fisher](./immagini/confronto_fisher.png)

![linea](../immagini/linea.png)

## 12.5 L'utilizzo della statistica di test

### 12.5.1 Il calcolo della statistica di test per i due campioni

  * Per ogni evento che compone i due modelli si può quindi **calcolare
    il valore della statistica di test** *t<sub>i</sub> = t(x<sub>i</sub>,y<sub>i</sub>)*:
    ```cpp
    vector<double> fisher_1 ;
    for (int i = 0 ; i < data_1.at (0).size () ; ++i)
      {
        fisher_1.push_back (
          data_1.at (0).at (i) * fisher.at (0) + 
          data_1.at (1).at (i) * fisher.at (1)
        ) ;
      }
    ```
  * ed analogamente per il secondo campione, generando anche ```vector<double> fisher_2```

![linea](../immagini/linea.png)

### 12.5.2 La visualizzazione dell'informazione disponibile

  * A questo punto,
    i due campioni sono **descritti da tre variabili**: *x*, *y* e *t*,
    dove la terza è una combinazione lineare delle prime due.
  * La **distribuzione delle tre variabili** mostra ad occhio nudo la separazione
    delle distribuzioni di *H<sub>0</sub>* ed *H<sub>1</sub>*
    in ciascuna delle tre direzioni:
![shapes](./immagini/shapes.png)
  * dove **gli istogrammi sono stati riempiti** a partire dal ```vector<double>```
    corrispondente a ciascuna variabile:
    ```cpp
    double max_x = *max_element (data.begin (), data.end ()) ;
    double min_x = *min_element (data.begin (), data.end ()) ;
    double sigma_x = sqrt (varianza (data)) ;
    int Nbins = 5 * (max_x - min_x) / sigma_x ;
  
    TH1F * h_vis = new TH1F (
        histo_name.c_str (), "distribuzione 1D",
        Nbins, min_x, max_x
      ) ;
  
    for (int i = 0 ; i < data.size () ; ++i)
      {
        h_vis->Fill (data.at (i)) ;
      }  
    ```

![linea](../immagini/linea.png)

### 12.5.3 Il comportamento del test di ipotesi

  * Per **determinare il comportamento del test di ipotesi** basato sulla statistica di test *t(x,y)*
    si può valutare l'effetto della selezione con soglia *t<sub>cut</sub>*
    con la frazione di falsi positivi &beta; 
    e quella di falsi negativi &alpha;:
![shape_fisher](./immagini/shape_fisher.png)

![linea](../immagini/linea.png)

### 12.5.4 La curva ROC

  * L'andamento di &beta; in funzione di &alpha; al variare del valore di *t<sub>cut</sub>*
    è detto **curva ROC**:
![ROC_f](./immagini/ROC_f.png)

![linea](../immagini/linea.png)

### 12.5.5 L'algoritmo di costruzione

  * Per calcolarlo,
    bisogna **scorrere i possibli valori di *t<sub>cut</sub>***
  * Per semplificare i conteggi,
    come prima cosa si **ordinano** i due ```vector<double>``` da confrontare
    in maniera crescente:  
    ```cpp
    sort (fisher_1.begin (), fisher_1.end ()) ;
    sort (fisher_2.begin (), fisher_2.end ()) ;
    ```
    * questa operazione modifica l'ordinamento nel campione, 
      quindi se l'ordinamento va preservato meglio è **fare una copia
      dei ```vector<double>```** per lavorarci
  * Poi si determinano il **minimo ed il massimo valore per *t<sub>cut</sub>***
    in funzione dei valori assunti dagli eventi:
    ```cpp
    double taglio_min_f = *fisher_1.begin () ;
    if (*fisher_2.begin () < taglio_min_f) taglio_min_f = *fisher_2.begin () ;
  
    double taglio_max_f = *fisher_1.rbegin () ;
    if (*fisher_2.rbegin () > taglio_max_f) taglio_max_f = *fisher_2.rbegin () ;
    ```
    * sfruttando il fatto che i due ```vector<double>``` sono stati ordinati

![linea](../immagini/linea.png)

### 12.5.6 Il riempimento della curva

  * Si decide con che **passo** scorrere la variabile *t<sub>cut</sub>*
    ```cpp
    double risoluzione = 10 * (taglio_max_f - taglio_min_f) / fisher_1.size () ;
    ```
  * Si riempie un ```TGrraph``` di ```ROOT``` con la **successione dei punti
    *(&alpha;<sub>i</sub>, &beta;<sub>i</sub>)*** calcolati a partire da ciascun *t<sub>i</sub>*:
    ```cpp
    TGraph g_ROC_f ;
  
    int contatore_1 = 0 ;
    int contatore_2 = 0 ;
    for (double taglio = taglio_min_f ; taglio < taglio_max_f ; taglio += risoluzione)
      {
        // conta il numero di eventi sotto soglia per ogni campione
        // (ricordando che i due campioni sono stati ordinati)
        for ( ; contatore_1 < fisher_1.size () ; ++contatore_1)
          if (fisher_1.at (contatore_1) > taglio) break ;
        for ( ; contatore_2 < fisher_2.size () ; ++contatore_2)
          if (fisher_2.at (contatore_2) > taglio) break ;
        g_ROC_f.SetPoint (g_ROC_f.GetN (), 
            static_cast<double> (contatore_2) / fisher_2.size (),
            1. - static_cast<double> (contatore_1) / fisher_1.size ()
          ) ;
      }

    ```

![linea](../immagini/linea.png)

### 12.5.7 Il confronto con le altre variabili

  * Così come si è fatto per la variabile *t*, 
    il criterio di selezione per determinare se rigettare o meno l'ipotesi *H<sub>0</sub>*
    si sarebbe potuto **applicare anche alle variabili *x* o *y***
  * Per confrontare l'efficacia delle varie selezioni,
    si possono **sovrapporre le curve ROC** nei tre casi:
![ROC](./immagini/ROC.png)
  * Alternativamente, si può **confrontare l'area sottesa** alle singole curve ROC:
    ```cpp
    variabile x:             0.12
    variabile y:             0.17
    discriminante di Fisher: 0.09
    ```
    * In questo frangente, 
      l'area sottesa ad un ```TGraph``` è stata calcolata con il [metodo dei trapezi](https://it.wikipedia.org/wiki/Regola_del_trapezio)

![linea](../immagini/linea.png)

## 12.5 Il Teorema di Neyman-Pearson

  * si usa una statistica **t** per confrontare l'ipotesi H<sub>0</sub> 
  con l'ipotesi alternativa H<sub>1</sub>
  * le due ipotesi sono semplici (non prevedono stima di parametri)
  * l'ipotesi H<sub>0</sub> è scartata quanto **t** cade nella regione del sample space che 
  chiamiamo **regione critica**
  * il test è caratterizzato da due parametri: 
     * &alpha; è la probabilità che H<sub>0</sub> sia vera ma l'ipotesi venga scartata: è il **size** del test
     * &beta; è la probabilità che sia vera H<sub>1</sub>  ma l'ipotesi H<sub>0</sub> viene accettata: 
      (1-&beta;) è il **power** del test
  * **la regione critica che massimizza il power del test, una volta fissato il suo size, è la BCR**

![linea](../immagini/linea.png)  

## 12.5.1 Best Critical Region (BCR)
     
  * i dati sono un set di N campionamenti **x<sub>1</sub> ... x<sub>N</sub>** in un sample space &Omega;
  * a un set di campionamenti associo due likelihood differenti:
     * L(x<sub>1</sub> ... x<sub>N</sub> | H<sub>0</sub>) se vale l'ipotesi H<sub>0</sub>
     * L(x<sub>1</sub> ... x<sub>N</sub> | H<sub>1</sub>) se vale l'ipotesi H<sub>1</sub>
  * la Best Critical Region è quel sottoinsieme di &Omega; definito dalla condizione:
 
  ![condizioneBCR](./immagini/condizioneBCR.png)
  * un set di campionamenti appartiene alla BCR se il suo likelihood ratio è inferiore a un 
    valore c<sub>&alpha;</sub> che dipende dal size &alpha; scelto
![linea](../immagini/linea.png)
  
## 12.5.2 Determinazione di di c<sub>&alpha;</sub>  
  * la condizione che determina c<sub>&alpha;</sub> è che il size del test valga &alpha;
   ![c_alpha](./immagini/c_alpha.png)
  * il size è la probabilità associata a quei campionamenti estratti dalla
    pdf(x | H<sub>0</sub>) che soddisfano la condizione BCR

![linea](../immagini/linea.png) 

## 12.5.3 Esempio: Due Ipotesi semplici distinte da una media differente
 
  * scriviamo una funzione binormale pdf(x,y) con correlazione nulla tra 
  le due variabili x ed y e la stessa media &mu; e varianza &sigma;
  
  ```cpp
  double binormal(double *x, double *p){
	 double sigma=p[0];
	 double mu=p[1];
	 double arg;
	 if(sigma>0) 
		arg=1/(2.*acos(-1)*sigma*sigma)*exp(- 1./(2.*sigma*sigma)*((x[0]-mu)*(x[0]-mu)+(x[1]-mu)*(x[1]-mu))); 
	 else arg=1e30;
	 return arg;
	 }
   ```

   * definiamo due funzioni di ```ROOT``` che descrivono le due ipotesi:
     * H<sub>0</sub>: &mu;=2 &sigma;=1  la pdf è pdf(x,y | H<sub>0</sub>)
     * H<sub>1</sub>: &mu;=3 &sigma;=1  la pdf è pdf(x,y | H<sub>1</sub>)
     
   ```cpp
    int npar=2;
	double sigma=1;
	double mu0=2; //H_0
	double mu1=3; //H_1
    double min=-1,max=5;
	TF2 *f0 = new TF2("f0",binormal,min,max,min,max,npar);
	f0->SetTitle("P(t|H_0)");
	f0->SetParameters(sigma,mu0);
	TF2 *f1 = new TF2("f1",binormal,min,max,min,max,npar);
	f1->SetTitle("P(t|H_1)");
	f1->SetParameters(sigma,mu1); 
   ```
    
![linea](../immagini/linea.png)

## 12.5.4 Il rapporto di Likelihood per un singolo campionamento

   * se la pdf(x,y) è campionata una sola volta, la statistica usata per il test è il campionamento stesso
   * il rapporto di likelihood è:
   
![Likeratio](./immagini/LikeRatio.png)

   * il suo logaritmo è 
   
![logLikeratio](./immagini/logLikeRatio.png)

   * possiamo costruire una ```TF2``` che rappresenta  log(&lambda;(x,y)) usando la modalità inline:
   
   ```cpp
   TF2 *lratio = new TF2("lratio","(((x-[1])**2+(y-[1])**2)-((x-[0])**2+(y-[0])**2))",min,max,min,max);
   ```
![linea](../immagini/linea.png)
  
## 12.5.5 Disegnamo le due pdf e il rapporto di likelihood per un singolo campionamento

 * disegnamo le due pdf(x,y) e il logaritmo del likelihood ratio ln &lambda;(x,y)
 
  
     ```cpp
    TCanvas c1;
    c1.Divide(3,2);
    c1.cd(1);
    f1->GetXaxis()->SetTitle("x");
    f1->GetYaxis()->SetTitle("y");
    f1->DrawClone("cont1z");
    f0->DrawClone("cont1z same ");
    c1.cd(2);
    lratio->DrawClone("cont1z");
    lratio->GetXaxis()->SetTitle("x");
    lratio->GetYaxis()->SetTitle("y");
    ```
![binormali](./immagini/binormal.png)


![linea](../immagini/linea.png)

## 12.5.6 BCR per un campionamento
 
  * il sample space coincide con il piano (x,y), quindi la BCR sarà una regione di questo piano definita dalla condizione:

 ![linea](./immagini/condizioneBCRloglambda.png)

  * per determinare il c<sub>&alpha;</sub> che corrisponde al size &alpha; 
  scelto dobbiamo:
    * costruire la funzione che calcola il size al variare di c<sub>&alpha;</sub>
    * invertire la funzione per determinare c<sub>&alpha;</sub> dato il size 

![linea](../immagini/linea.png)

## 12.5.7 Funzione che calcola il size

 * scriviamo una funzione che dato un mumero c<sub>&alpha;</sub> calcola il corrispondente size del test
 * va campionata la pdf(x,y | H<sub>0</sub>)
 
   * la binormale ha correlazione nulla, pertanto è data dal prodotto di due gaussiane 
   (correlazione=0 in questo caso implica indipendenza), la generazione di una coppia (x,y) può usare 
   la funzione ```rand_TAC``` scritta per una gaussiana, chiamandola due volte
   
   * in alternativa si può usare il metodo ```GetRandom(double x,double y)``` della ```TF2``` 
    (l'inizializzazione del seed si fa nel main con l'istruzione ```gRandom->SetSeed(0); ```)
   
    ```cpp
    double sizetest(double c_alpha, TF2 *lratio, TF2 *f0){
	  int nhit=0;
	  int Ntoy=100000;
	  double x,y;
	  for (int i=0;i<Ntoy;i++){
	  	f0->GetRandom2(x,y);
	  	if (lratio->Eval(x,y)<c_alpha) nhit++;
	  	}
	   return (nhit*1.)/Ntoy;
     }
     ```
![linea](../immagini/linea.png)

## 12.5.8 Andamento del size in funzione di c<sub>&alpha;</sub> e BCR

  * scriviamo una funzione che 
     * usa la funzione ```sizetest()``` per costruire un ```TGraph * gsize``` con l'andamento di &alpha; in funzione di c<sub>&alpha;</sub> usando la funzione ```sizetest``` 
     * restituisce il valore approssimato di c<sub>&alpha;</sub> che corrisponde al size &alpha; passato in ingresso 
   * la funzione deve:
      * trovare gli estremi entro i quali far variare c<sub>&alpha;</sub>
      ```cpp
      double lratio_min=lratio->GetMinimum();
      double lratio_max=lratio->GetMaximum();
      ```
      
      * variare c<sub>&alpha;</sub> dal minimo dell'intervallo al massimo e per ogni valore 
    calcolare il size del test usando ```sizetest()```
      * riempire un grafico con i valori c<sub>&alpha;</sub> - size e restituire il valore 
    c<sub>&alpha;</sub> che meglio si avvicina al size prescelto  


![linea](../immagini/linea.png)


## 12.5.9 Disegno BCR

 * nel main del programma possiamo disegnare la regione BCR:
 ```cpp
    lratio->SetMaximum(c_alpha);
	lratio->Draw("cont3");
	f1->Draw("cont1z same");
	f0->Draw("cont1z same ");
 ```
 
 * l'istruzione ```lratio->SetMaximum(c\_alpha);``` consente di disegnare quella porzione della funzione 
   ```lratio``` che è minore di c<sub>&alpha;</sub>

![BCRdraw](./immagini/BCR.png)

  * il power del test può essere calcolato usando la funzione ```sizetest()``` 
  a cui viene passata la forma della pdf prevista dall'ipotesi H<sub>1</sub>
  
  ```cpp
  cout<<"power "<<sizetest(c_alpha, lratio, f1)<<endl;
  ```
![linea](../immagini/linea.png)

## 12.5.10 Disegno curva ROC
  * possiamo disegnare l'andamento 
  * possiamo inoltre costruire il grafico che rappresenta la curva &beta; vs. &alpha; (detta curva ROC)
  ```cpp
  TGraph *gba=new TGraph();
  for (int i=0;i<gsize->GetN();i++){
	beta=1-sizetest(gsize->GetPointX(i),lratio, f1);
	gba->SetPoint(i,gsize->GetPointY(i),beta);
	}
  gba->Draw("AP*");
  gba->GetXaxis()->SetTitle("#alpha");
  gba->GetYaxis()->SetTitle("#beta");
  ```
![BCRdraw](./immagini/SIZE.png)
  
  
![linea](../immagini/linea.png)
## 12.6 ESERCIZI

  * Gli esercizi relativi alla lezione si trovano [qui](ESERCIZI.md)


