# Lezione 7: programmazione ```template``` e Standard Template Library

![linea](../immagini/linea.png)

## 7.1 introduzione

![linea](../immagini/linea.png)

### 7.1.1 ripasso: l'*overloading* delle funzioni
  
  * in ```C++```, una funzione o un operatore vengono identificati univocamente
    dall'insieme di **nome e tipi in ingresso**,
  * quindi e' possibile **utilizzare lo stesso nome** per operatori o funzioni 
    con tipi in ingresso differenti:  
    ```cpp
    int somma (int a, int b)
      {
        return a + b ;
      }

    double somma (double a, double b)
      {
        return a + b ;
      }
    ```
  * durante l'esecuzione di un programma, il ```C++``` e' in grado di **scegliere 
    la funzione corretta** da utilizzare

![linea](../immagini/linea.png)

### 7.1.1 se potessimo lavorare meno...

  * nonostante le due funzioni abbiano la medesima implementazione,
    e' stato necessario **scriverle entrambe**
  * la programmazione ```template``` mira ad **evitare di riscrivere per tipi diversi**
    funzioni che hanno identica implementazione
  
![linea](../immagini/linea.png)

## 7.2 funzioni ```template```

![linea](../immagini/linea.png)

### 7.2.1 definizione di una funzione ```template```

  * la parola chiave ```template```, traducibile in italiano come modello,
    introduce il concetto di tipo generico
  * dunque, per definire una funzione ```somma``` che valga per un tipo qualunue
    si scrive
    ```cpp
    template <typename T>
    T somma (T a, T b)
      {
        return a + b ;
      }
    ```
    * ```<typename T>``` **definisce il nome** scelto in questo caso per indicare il tipo generico  
    * ```T somma (T a, T b)``` indica il **prototipo**: la funzione legge due variabili di tipo ```T``` 
      e restituisce una variabile di tipo ```T```
    * la parola chiave ```typename``` puo' essere sempre sostituita dalla parola chiave ```class```

![linea](../immagini/linea.png)

### 7.2.2 utilizzo di una fuzione ```template```

  * in fase di compilazione, 
    il ```C++``` **implementa e compila tutti i prototipi necessari**,
    in funzione di come viene chiamata la funzione
  * i **due casi seguenti** inducono la creazione e compilazione della funzione ```somma```
    per tipi ```int``` 
    ```cpp
    std::cout << "somma di interi    " << somma (i_a, i_b) << std::endl ;
    std::cout << "somma di interi    " << somma<int> (i_a, i_b) << std::endl ;
    std::cout << "somma di razionali " << somma (d_a, d_b) << std::endl ;
    ```  
    * nel primo caso, il ```C++``` **capisce implicitamente** che tipo utilizzare
    * nel secondo caso, il termine ```<int>``` **forza** il ```C++``` ad utilizzare la funzione ```somma```
      implementata (templata) sul tipo ```int```

![linea](../immagini/linea.png)

### 7.2.3 attenzione ai dettagli

  * l'implementazione della funzione ```somma``` **deve essere corretta** 
    per tutti i tipi sui quali viene templata
  * la funzione viene implementata **esattamente per i tipi indicati**,
    quindi comportamenti ibridi, se hanno successo,
    sono dovuti a casting impliciti effettuati dal ```C++```,
    come nei casi seguenti:
    ```cpp
    std::cout << "somma di razionali " << somma<double> (i_a, i_b) << std::endl ;
    std::cout << "somma ibrida       " << somma<double> (i_a, d_b) << std::endl ;
    ```    

![linea](../immagini/linea.png)

### 7.2.4 ```template``` e compilazione

  * la risoluzione dei template avviene **in fase di compilazione** del programma
  * questo significa che non si puo' separare la compilazione del ```main``` program 
    da quella delle funzioni
  * quindi tutti gli strumenti ```template```,
    se vengono scritti in un file separato,
    vanno implementati all'interno dell'```header```
    ```cpp
    #ifndef somma_h
    #define somma_h
    
    template <typename T>
    T somma (T a, T b)
      {
        return a + b ;
      }
    
    #endif
    ```
  * durante la compilazione di strumenti ```template``` il ```C++``` 
    porta a termine un **controllo sintattico accurato**
  * la compilazione e' solitamente **lunga**
  * **pochi errori** di scrittura possono tradursi in lunghe lamntele del compilatore
    * cercate sempre **il primo errore** di compilazione!

![linea](../immagini/linea.png)

## 7.3 classi ```template```

  * come le funzioni,
    anche le **classi** possono essere ```template```
  * classi ```template``` sono un ottimo modo per **sviluppare strumenti generici**,
    ad esempio un array che abbia il numero degli elementi definito a runtime
    e che possa contenere qualunque tipo di oggetto

![linea](../immagini/linea.png)

### 7.3.1 definizione di una classe ```template```

  * esempio dell'array a dimensione impostata a runtime
  * come si potrebbe fargli aumentare dimensione, se serve?

![linea](../immagini/linea.png)

### 7.3.2 implementazione di una classe ```template```

  * anche in questo caso si utilizza la **parola chiave ```template```**
    per indicare che la classe e' ```template``` 
  * e la **parola chiave ```typename```** per definire il nome del tipo generico
    da utilizzare nella scrittura della classe
    ```cpp
    template <typename T> 
    class SimpleArray {
    public:
      // Costruttore
      SimpleArray (const int & elementsNum) { /* implementazione */ }
      // Distruttore
      ~SimpleArray () { /* implementazione */ } 
      T & element (const int& i)  { /* implementazione */ }
      // Overloading di operator[]
      T & operator[] (const int& i) { /* implementazione */ }
    
    private:
    
      int elementsNum_p;
      T * elements_p;
    } ;
    ```

![linea](../immagini/linea.png)

### 7.3.3 utilizzo di una classe ```template```

  * quando la classe ```SimpleArray``` viene utilizzata,
    bisogna **indicare esplicitamente il tipo** sul quale 
    e' templata al momento della definizione di ogni oggetto:
    ```cpp
    SimpleArray<int> contenitore (10) ;
    for (int i = 0 ; i < 10 ; ++i)
      contenitore[i] = 2 * i ;
    ```

![linea](../immagini/linea.png)

## 7.4 ```template``` multipli

  * E' possibile templare una funzione o una classe su **piu' di un tipo**
  * Ad esempio, si potrebbe templare la funzione ```somma```
    su due tipi differenti:
    ```cpp
    template <typename T1, typename T2>
    T2 somma (T1 a, T2 b)
      {
        return a + b ;
      }
    ```

![linea](../immagini/linea.png)

## 7.5 la specializzazione dei ```template```

  * talvolta puo' succedere che, 
    per taluni tipi particolari,
    l'**implementazione di una funzione templata
    debba essere diversa** 
    da quella prevista per la maggioranza dei tipi
  * costruire una implementazione specifica per un determinato tipo
    si chiama **specializzazione** di un ```template```:
    ```cpp
    template<>
    float somma (float a, float b)
      {
        std::cout << "SOMMA DI FLOAT" << std::endl ;
        return a + b ;
      }
    ```  
  * il preambolo ```template<>``` segnala al ```C++``` che questa implementazione
    e' una specializzazione della funzione templata ```somma```

![linea](../immagini/linea.png)

## 7.6 ```template``` su valori di variabili intere

  * oltre che su tipi di variabili,
    si puo' templare una funzione o una classe
    anche **sul valore di una variabile intera**
  * ad esempio,
    se si volessero definire elementi di uno spazio vettoriale
    con dimensione finita, 
    la **dimensione dei vettori** potrebbe essere templata:
    ```cpp
    template <int N> 
    class vettore 
    {
      public:
        vettore () { /* implementazione */ }
        void setCoord (int i, double val) { /* implementazione */ }
        double norm () { /* implementazione */ }
    
      private:
        float elementi[N] ;
    } ;

    ```
    e questo ```vettore``` si potrebbe utilizzare cosi':
    ```cpp
    vettore<2> v1 ;
    v1.setCoord (0, 3.) ;
    v1.setCoord (1, 4.) ;
    std::cout << v1.norm () << std::endl ;
    ```
  * essendo la classe templata, 
    il valore di *N* e' noto al **momento della compilazione**,
    quindi e' lecito utilizzare l'allocazione automatica della memoria
    per definire l'array ```elementi```

![linea](../immagini/linea.png)

## 7.7 ordine nelle librerie: i ```namespace```

  * Al crescere delle dimensioni di una libreria,
    puo' essere comodo incorporarne gli strumenti (siano essi classi o funzioni)
    all'interno di un **contenitore**,
    che permetta di identificarne la provenienza
  * Un ```namespace``` fornisce questa possibilita'
  * si potrebbe ad esempio raggruppare le varie funzioni ```somma``` 
    nel modo seguente:
    ```cpp
    namespace ops
    {
      template <typename T>
      T somma (T a, T b) { /* implementazione */ }
        
      template<>
      float somma (float a, float b) { /* implementazione */ }
      
      template <typename T1, typename T2>
      T2 somma (T1 a, T2 b) { /* implementazione */ }
    }
    ```
  * per poter usare le funzioni definite all'interno di un ```namespace```,
    bisogna utilizzare l'operatore di risoluzione di *scope*: ```operator::```:
    ```cpp
    std::cout << "somma di interi    " << ops::somma (i_a, i_b) << std::endl ;
    std::cout << "somma di razionali " << ops::somma (d_a, d_b) << std::endl ;
    ```

![linea](../immagini/linea.png)

### 7.7.1 un ```namespace``` familiare: ```std```

  * gli **strumenti standard** di ```C++``` sono definiti all'interno del ```namespace``` ```std```
    (ad esempio ```std::cout```)
  * si puo' istruire il compilatore a **cercare automaticamente** uno strumento
    all'interno di un determinato ```namespace```, 
    evitando cosi' di indicarlo esplicitamente:
    ```cpp
    using namespace std ;
    int main (int argc, char ** argv)
      {
        //...
        cout << "per scrivere questo messaggio non ho bisogno di std::" << endl ; 
      }

    ```
  * e' buona norma **non** invocare ```using namespace std ;``` all'interno di **header file**,
    perche' avrebbe effetto in tutti i programmi che includono quell'header

![linea](../immagini/linea.png)

## 7.9 Le Standard Template Library

  * La generalita' di strumenti garantita dalla programmazione ```template```
    viene grandemente utilizzata per creare **librerie di utilizzo generale**,
    scritte da esperti e che non e' quindi necessario reimplementare
  * Le **Standard Template Library (STL)** offrono diversi tipi di strumenti:
    algoritmi, contenitori, funzioni, iteratori.
  * come nel caso di ```ROOT```,
    per utilizzare uno strumento STL bisogna **includerne l'header**. 
  * A differenza di ```ROOT```, 
    questa libreria e' gia' inclusa nel ```C++``` standard,
    quindi **non e' necessario aggiungere opzioni** al comando di compilazione

![linea](../immagini/linea.png)

### 7.9.1 Programmazione a diversi livelli

  * Si intende solitamente come **livello della programmazione**    
    la distanza concettuale fra il codice sorgente ed il linguaggio macchina:
    piu' le istruzioni scritte in un programma fanno uso di librerie esistenti,
    piu' e' alto il livello di programmazione.
  * Diversi livelli di programmazione richiedono una diversa comprensione
    degli strumenti utilizzati.
  * Tipicamente, **a basso livello** e' necessario prevedere quali problemi potrebbero sorgere
    nell'utilizzo dell'hardware del calcolatore.  
    Ad esempio, bisogna controllare che l'accesso ad un array avvenga
    tramite un indice con valore positivo minore della dimensione dell'array.
  * Ad **alto livello**, invece,
    si assume solitamente che l'interazione con l'hardware sia ben gestita dalle librerie,
    mentre e' necessario comprendere la loro logica ed il loro comportamento,
    per utilizzarle al meglio.

![linea](../immagini/linea.png)

## 7.10 Contenitori STL

  * I diversi contenitori delle STL 
    sono **dedicati a diversi utilizzi**,
    in funzione del tipo di salvataggio necessario 
    e della frequenza di accesso ad ogni oggetto
  * noi ne studiamo due molto utilizzati,
    a titolo esempificativo
  * documentazione piu' esaustiva si trova in internet,
    ad esempio [qui](https://justinmeiners.github.io/sgi-stl-docs)  

![linea](../immagini/linea.png)

### 7.10.1 Una sequenza di elementi: ```std::vector```

  * La classe ```vector```, che appartiene al namespace ```std```, 
    e' templata sul tipo di oggetto che contiene.
  * Un **```vector``` viene creato** vuoto (```v_1```), 
    oppure composto da *N* elementi con il medesimo valore (```v_2```),
    oppure a partire da un altro ```vector``` (```v_3```):
    ```cpp
    vector<double> v_1 ;
    vector<double> v_2 (5, 0.) ;
    vector<double> v_3 (v_2) ;
    ```

![linea](../immagini/linea.png)

### 7.10.2 La lettura di un ```std::vector```

  * Gli **elementi esistenti di un ```vector```** sono accessibli con l'```operator[]```,
    oppure con il metodo ```vector::at (int)```:
    ```cpp
    cout << "elemento 1 di v_2 " << v_2[1] << endl ;
    cout << "elemento 1 di v_2 " << v_2.at (1) << endl ;
    ```
    * il primo metodo funziona esattamente come per un array, 
      quindi puo' creare **problemi di gestione della memoria**
    * il secondo metodo controlla la validita' dell'indice rispetto alla dimensione del ```vector```
      e **produce un errore di esecuzione**
      nel caso in cui l'indice non indichi un elemento del ```vector```:
      ```
      libc++abi.dylib: terminating with uncaught exception of type std::out_of_range: vector
      Abort trap: 6
      ```

![linea](../immagini/linea.png)

### 7.10.3 Il riempimento di un ```std::vector```

  * Ad un ```vector``` possono essere **aggiunti elementi alla fine** del suo contenuto, 
    con il metodo ```vector::push_back (T element)```:
    ```cpp
    cout << v_1.size () << endl ;
    v_1.push_back (3.) ; 
    cout << v_1.size () << endl ;
    ```
    * il metodo ```vector::size ()``` restituisce il **numero di elementi** contenuti nel vector
    * similmente,
      si puo' **eliminare l'ultimo elemento** di un ```vector```
      con il metodo ```vector::pop_back ()```:
    ```cpp
    v_1.pop_back () ; 
    cout << v_1.size () << endl ;
    ```

![linea](../immagini/linea.png)

### 7.10.4 ```std::vector``` ed array

  * un ```vector``` **contiene un array** di elementi e fornisce l'interfaccia di accesso
    e modifica
  * per accedere direttamente all'array, e' sufficiente **dereferenziare il primo elemento** del ```vector```:
    ```cpp
    double * array_3 = & v_3.at (0) ;
    cout << "elemento 2 di v_3 " << array_3[2] << endl ;
    ```

![linea](../immagini/linea.png)

### 7.10.5 l'iterazione sugli elementi di un ```std::vector```

  * per **iterare sugli elementi di un ```vector```**, 
    si puo' utilizzare una sintassi analoga a quella che si userebbe per un array:
    ```cpp
    for (int i = 0 ; i < v_3.size () ; ++i)
      cout << "elemento " << i << ": " << v_3.at (i) << "\n" ;
    ```
  * alternativamente, si possono utilizzare altri strumenti STL, 
    gli iteratori:
    ```cpp
    for (vector<double>::const_iterator it = v_3.begin () ;
         it != v_3.end () ;
         ++it)
      cout << "elemento " << it - v_3.begin () << ": " << *it << "\n" ;
    ```
    * un **iteratore** si comporta come puntatore ad un elemento di un contenitore
      con in aggiunta metodi per spostarsi ad elementi contigui del contenitore
    * di conseguenza, ```*it``` e' l'elemento contenuto in quell'elemento del ```vector```  
    * il metodo **vector::begin ()** 
      restituisce l'iteratore al **primo elemento** del ```vector```
    * il metodo **vector::end ()** restituisce l'interatore alla locazione di memoria
      **successiva all'ultimo elemento** del ```vector```,
      dunque il ciclo non avviene se ```it``` e' uguale a ```v_3.end ()```
    * gli iteratori **hanno una propria algebra**, 
      per cui la differenza fra iteratori dello stesso contenitore  
      indica il numero di elementi che intercorrono fra loro  

![linea](../immagini/linea.png)

### 7.10.6 ```std::vector``` di oggetti

  * il comportamento dei tipi di default dei ```C++``` e' sempre ben regolato
  * gli strumenti ```template``` possono essere utilizzati **con un qualunque tipo**,
    dunque e' necessario che l'implementazione degli oggetti 
    garantisca il buon funzionamento delle librerie STL
  * in particolare, e' necessario che siano definiti il *copy constructor* e l'operatore di assegnazione
    per il tipo ```T```

![linea](../immagini/linea.png)

### 7.10.7 Un contenitore associativo di elementi: ```std::map```

  * Una ```map``` delle STL funziona **come un elenco telefonico**:
    contiene una lista di valori (i numeri di telefono)
    associati ad una chiave per ordinarli (cognomi e nomi),
    dunque e' templata su due argomenti:
    ```cpp
    map <int, double> mappa_di_esempio ;
    ```
  * Per ogni chiave esiste **un solo valore** contenuto nella ```map```
  * Il primo argomento (la chiave) **deve essere ordinabile**,
    cioe' deve esistere l'```operator<``` per quel tipo o classe
  * La ```map``` e' un **contenitore ordinato**,
    cioe' gli elementi al suo interno su susseguono 
    secondo la relazione d'ordine che esiste per le chiavi

![linea](../immagini/linea.png)

### 7.10.8 Il riempimento di una ```std::map```

  * Il modo piu' semplice per riempire una ```map```
    e' utilizzare l'```operator[]```, 
    che ha un comportamento duplice:
    se l'elemento corripondente ad una data chiave non esiste, 
    viene creato, altrimenti viene restituito l'elemento esistente:
    ```cpp
    mappa_di_esempio[5] = 5.5 ;
    mappa_di_esempio[3] = 3.3 ;
    mappa_di_esempio[5] = 4.1 ;
    mappa_di_esempio[12] = 7.9 ;
    ```
    * In questo caso, 
      le prime due righe definiscono due nuovi elementi,
      mentre la terza **sovrascrive** l'elemento associato alla chiave ```5```
  * Per gli oggetti sui quali si templa una ```map``` devono aver definti 
    un operatore di assgnazione ed un *copy constructor*

![linea](../immagini/linea.png)

### 7.10.9 La lettura di una ```std::map```

  * per accedere ad un **singolo elemento esistente** in una ```map```
    si utilizza l'```operator[]```
  * ogni elemento della ```map``` e' tecnicamente una **coppia di oggetti**,
    definita nelle STL come ```std::pair```,
    che e' templata sui due stessi tipi della ```map```
  * la classe ```pair``` ha due membri pubblici, chiamati **```first``` e ```second```**, 
    che corrispodono al primo e secondo elemento della coppia rispettivamente    
  * per **iterare su una ```map```** si utilizza l'iteratore STL corrispondente:
    ```cpp
    for (map<int, double>::const_iterator it = mappa_di_esempio.begin () ;
         it != mappa_di_esempio.end () ;
         ++it)
      {
        cout << "elemento " << it->first
             << "\t-> "     << it->second << endl ;
      }    

    ```
    * l'iteratore ```it``` si comporta, all'interno del ciclo,
      come un puntatore al ```pair``` corrispondente ad ogni elemento della ```map```

![linea](../immagini/linea.png)

## 7.11 ```std::string```

![linea](../immagini/linea.png)

## 7.12 algoritmi nelle STL

![linea](../immagini/linea.png)

### 7.12.1 ```std::sort```

![linea](../immagini/linea.png)

### 7.12.2 unary operators

![linea](../immagini/linea.png)

### 7.12.3 ordinamento al contrario

![linea](../immagini/linea.png)

### 7.12.4 find

![linea](../immagini/linea.png)

## 7.13 ESERCIZI

  * Gli esercizi relativi alla lezione si trovano [qui](ESERCIZI.md)


