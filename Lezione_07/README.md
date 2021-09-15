# Lezione 7: programmazione ```template``` e Standard Template Library

## Indice

  * [7.1 introduzione](#71-introduzione)
    * [7.1.1 ripasso: l'*overloading* delle funzioni](#711-ripasso-loverloading-delle-funzioni)
    * [7.1.2 se potessimo lavorare meno...](#712-se-potessimo-lavorare-meno)
  * [7.2 funzioni ```template```](#72-funzioni-template)
    * [7.2.1 definizione di una funzione ```template```](#721-definizione-di-una-funzione-template)
    * [7.2.2 utilizzo di una fuzione ```template```](#722-utilizzo-di-una-fuzione-template)
    * [7.2.3 attenzione ai dettagli](#723-attenzione-ai-dettagli)
    * [7.2.4 ```template``` e compilazione](#724-template-e-compilazione)
  * [7.3 classi ```template```](#73-classi-template)
    * [7.3.1 definizione di una classe ```template```](#731-definizione-di-una-classe-template)
    * [7.3.2 implementazione di una classe ```template```](#732-implementazione-di-una-classe-template)
    * [7.3.3 utilizzo di una classe ```template```](#733-utilizzo-di-una-classe-template)
  * [7.4 ```template``` multipli](#74-template-multipli)
  * [7.5 la specializzazione dei ```template```](#75-la-specializzazione-dei-template)
  * [7.6 ```template``` su valori di variabili intere](#76-template-su-valori-di-variabili-intere)
  * [7.7 ordine nelle librerie: i ```namespace```](#77-ordine-nelle-librerie-i-namespace)
    * [7.7.1 un ```namespace``` familiare: ```std```](#771-un-namespace-familiare-std)
  * [7.8 Le Standard Template Library](#78-le-standard-template-library)
    * [7.8.1 Programmazione a diversi livelli](#781-programmazione-a-diversi-livelli)
  * [7.9 Contenitori STL](#79-contenitori-stl)
    * [7.9.1 Una sequenza di elementi: ```std::vector```](#791-una-sequenza-di-elementi-stdvector)
    * [7.9.2 La lettura di un ```std::vector```](#792-la-lettura-di-un-stdvector)
    * [7.9.3 Il riempimento di un ```std::vector```](#793-il-riempimento-di-un-stdvector)
    * [7.9.4 ```std::vector``` ed array](#794-stdvector-ed-array)
    * [7.9.5 l'iterazione sugli elementi di un ```std::vector```](#795-literazione-sugli-elementi-di-un-stdvector)
    * [7.9.6 ```std::vector``` di oggetti](#796-stdvector-di-oggetti)
    * [7.9.7 Un contenitore associativo di elementi: ```std::map```](#797-un-contenitore-associativo-di-elementi-stdmap)
    * [7.9.8 Il riempimento di una ```std::map```](#798-il-riempimento-di-una-stdmap)
    * [7.9.9 La lettura di una ```std::map```](#799-la-lettura-di-una-stdmap)
  * [7.10 ```std::string```](#710-stdstring)
    * [7.10.1 operazioni con stringhe](#7101-operazioni-con-stringhe)
    * [7.10.2 ricerca di sotto-elementi in una ```string```](#7102-ricerca-di-sotto-elementi-in-una-string)
    * [7.10.3 ```string``` e caratteri](#7103-string-e-caratteri)
  * [7.11 ESERCIZI](#711-esercizi)

![linea](../immagini/linea.png)

## 7.1 introduzione

![linea](../immagini/linea.png)

### 7.1.1 ripasso: l'*overloading* delle funzioni

  * in ```C++```, una funzione o un operatore vengono identificati univocamente
    dall'insieme di **nome e tipi in ingresso**,
  * quindi è possibile **utilizzare lo stesso nome** per operatori o funzioni
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
  * durante l'esecuzione di un programma, il ```C++``` è in grado di **scegliere
    la funzione corretta** da utilizzare

![linea](../immagini/linea.png)

### 7.1.2 se potessimo lavorare meno...

  * nonostante le due funzioni abbiano la medesima implementazione,
    è stato necessario **scriverle entrambe**
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
    * la parola chiave ```typename``` può essere sempre sostituita dalla parola chiave ```class```

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
  * questo significa che non si può separare la compilazione del ```main``` program
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
  * la compilazione è solitamente **lunga**
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
    per indicare che la classe è ```template```
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
    è templata al momento della definizione di ogni oggetto:
    ```cpp
    SimpleArray<int> contenitore (10) ;
    for (int i = 0 ; i < 10 ; ++i)
      contenitore[i] = 2 * i ;
    ```

![linea](../immagini/linea.png)

## 7.4 ```template``` multipli

  * E' possibile templare una funzione o una classe su **più di un tipo**
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

  * talvolta può succedere che,
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
    è una specializzazione della funzione templata ```somma```

![linea](../immagini/linea.png)

## 7.6 ```template``` su valori di variabili intere

  * oltre che su tipi di variabili,
    si può templare una funzione o una classe
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
    e questo ```vettore``` si potrebbe utilizzare così:
    ```cpp
    vettore<2> v1 ;
    v1.setCoord (0, 3.) ;
    v1.setCoord (1, 4.) ;
    std::cout << v1.norm () << std::endl ;
    ```
  * essendo la classe templata,
    il valore di *N* è noto al **momento della compilazione**,
    quindi è lecito utilizzare l'allocazione automatica della memoria
    per definire l'array ```elementi```

![linea](../immagini/linea.png)

## 7.7 ordine nelle librerie: i ```namespace```

  * Al crescere delle dimensioni di una libreria,
    può essere comodo incorporarne gli strumenti (siano essi classi o funzioni)
    all'interno di un **contenitore**,
    che permetta di identificarne la provenienza
  * Un ```namespace``` fornisce questa possibilità
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
  * si può istruire il compilatore a **cercare automaticamente** uno strumento
    all'interno di un determinato ```namespace```,
    evitando così di indicarlo esplicitamente:
    ```cpp
    using namespace std ;
    int main (int argc, char ** argv)
      {
        //...
        cout << "per scrivere questo messaggio non ho bisogno di std::" << endl ;
      }

    ```
  * è buona norma **non** invocare ```using namespace std ;``` all'interno di **header file**,
    perché avrebbe effetto in tutti i programmi che includono quell'header

![linea](../immagini/linea.png)

## 7.8 Le Standard Template Library

  * La generalità di strumenti garantita dalla programmazione ```template```
    viene grandemente utilizzata per creare **librerie di utilizzo generale**,
    scritte da esperti e che non è quindi necessario reimplementare
  * Le **Standard Template Library (STL)** offrono diversi tipi di strumenti:
    algoritmi, contenitori, funzioni, iteratori.
  * come nel caso di ```ROOT```,
    per utilizzare uno strumento STL bisogna **includerne l'header**.
  * A differenza di ```ROOT```,
    questa libreria è già inclusa nel ```C++``` standard,
    quindi **non è necessario aggiungere opzioni** al comando di compilazione

![linea](../immagini/linea.png)

### 7.8.1 Programmazione a diversi livelli

  * Si intende solitamente come **livello della programmazione**    
    la distanza concettuale fra il codice sorgente ed il linguaggio macchina:
    più le istruzioni scritte in un programma fanno uso di librerie esistenti,
    più è alto il livello di programmazione.
  * Diversi livelli di programmazione richiedono una diversa comprensione
    degli strumenti utilizzati.
  * Tipicamente, **a basso livello** è necessario prevedere quali problemi potrebbero sorgere
    nell'utilizzo dell'hardware del calcolatore.  
    Ad esempio, bisogna controllare che l'accesso ad un array avvenga
    tramite un indice con valore positivo minore della dimensione dell'array.
  * Ad **alto livello**, invece,
    si assume solitamente che l'interazione con l'hardware sia ben gestita dalle librerie,
    mentre è necessario comprendere la loro logica ed il loro comportamento,
    per utilizzarle al meglio.

![linea](../immagini/linea.png)

## 7.9 Contenitori STL

  * I diversi contenitori delle STL
    sono **dedicati a diversi utilizzi**,
    in funzione del tipo di salvataggio necessario
    e della frequenza di accesso ad ogni oggetto
  * noi ne studiamo due molto utilizzati,
    a titolo esempificativo
  * documentazione più esaustiva si trova in internet,
    ad esempio [qui](https://justinmeiners.github.io/sgi-stl-docs)  

![linea](../immagini/linea.png)

### 7.9.1 Una sequenza di elementi: ```std::vector```

  * La classe [```vector```](https://www.cplusplus.com/reference/vector/vector/), che appartiene al namespace ```std```,
    è templata sul tipo di oggetto che contiene.
  * Un **```vector``` viene creato** vuoto (```v_1```),
    oppure composto da *N* elementi con il medesimo valore (```v_2```),
    oppure a partire da un altro ```vector``` (```v_3```):
    ```cpp
    vector<double> v_1 ;
    vector<double> v_2 (5, 0.) ;
    vector<double> v_3 (v_2) ;
    ```

![linea](../immagini/linea.png)

### 7.9.2 La lettura di un ```std::vector```

  * Gli **elementi esistenti di un ```vector```** sono accessibli con l'```operator[]```,
    oppure con il metodo ```vector::at (int)```:
    ```cpp
    cout << "elemento 1 di v_2 " << v_2[1] << endl ;
    cout << "elemento 1 di v_2 " << v_2.at (1) << endl ;
    ```
    * il primo metodo funziona esattamente come per un array,
      quindi può creare **problemi di gestione della memoria**
    * il secondo metodo controlla la validità dell'indice rispetto alla dimensione del ```vector```
      e **produce un errore di esecuzione**
      nel caso in cui l'indice non indichi un elemento del ```vector```:
      ```
      libc++abi.dylib: terminating with uncaught exception of type std::out_of_range: vector
      Abort trap: 6
      ```

![linea](../immagini/linea.png)

### 7.9.3 Il riempimento di un ```std::vector```

  * Ad un ```vector``` possono essere **aggiunti elementi alla fine** del suo contenuto,
    con il metodo ```vector::push_back (T element)```:
    ```cpp
    cout << v_1.size () << endl ;
    v_1.push_back (3.) ;
    cout << v_1.size () << endl ;
    ```
    * il metodo ```vector::size ()``` restituisce il **numero di elementi** contenuti nel vector
    * similmente,
      si può **eliminare l'ultimo elemento** di un ```vector```
      con il metodo ```vector::pop_back ()```:
    ```cpp
    v_1.pop_back () ;
    cout << v_1.size () << endl ;
    ```

![linea](../immagini/linea.png)

### 7.9.4 ```std::vector``` ed array

  * un ```vector``` **contiene un array** di elementi e fornisce l'interfaccia di accesso
    e modifica
  * per accedere direttamente all'array, è sufficiente **dereferenziare il primo elemento** del ```vector```:
    ```cpp
    double * array_3 = & v_3.at (0) ;
    cout << "elemento 2 di v_3 " << array_3[2] << endl ;
    ```

![linea](../immagini/linea.png)

### 7.9.5 l'iterazione sugli elementi di un ```std::vector```

  * per **iterare sugli elementi di un ```vector```**,
    si può utilizzare una sintassi analoga a quella che si userebbe per un array:
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
    * di conseguenza, ```*it``` è l'elemento contenuto in quell'elemento del ```vector```  
    * il metodo **vector::begin ()**
      restituisce l'iteratore al **primo elemento** del ```vector```
    * il metodo **vector::end ()** restituisce l'interatore alla locazione di memoria
      **successiva all'ultimo elemento** del ```vector```,
      dunque il ciclo non avviene se ```it``` è uguale a ```v_3.end ()```
    * gli iteratori **hanno una propria algebra**,
      per cui la differenza fra iteratori dello stesso contenitore  
      indica il numero di elementi che intercorrono fra loro  

![linea](../immagini/linea.png)

### 7.9.6 ```std::vector``` di oggetti

  * il comportamento dei tipi di default dei ```C++``` è sempre ben regolato
  * gli strumenti ```template``` possono essere utilizzati **con un qualunque tipo**,
    dunque è necessario che l'implementazione degli oggetti
    garantisca il buon funzionamento delle librerie STL
  * in particolare, è necessario che siano definiti il *copy constructor* e l'operatore di assegnazione
    per il tipo ```T```

![linea](../immagini/linea.png)

### 7.9.7 Un contenitore associativo di elementi: ```std::map```

  * Una [```map```](http://www.cplusplus.com/reference/map/map/)
    delle STL funziona **come un elenco telefonico**:
    contiene una lista di valori (i numeri di telefono)
    associati ad una chiave per ordinarli (cognomi e nomi),
    dunque è templata su due argomenti:
    ```cpp
    map <int, double> mappa_di_esempio ;
    ```
  * Per ogni chiave esiste **un solo valore** contenuto nella ```map```
  * Il primo argomento (la chiave) **deve essere ordinabile**,
    cioè deve esistere l'```operator<``` per quel tipo o classe
  * La ```map``` è un **contenitore ordinato**,
    cioè gli elementi al suo interno su susseguono
    secondo la relazione d'ordine che esiste per le chiavi

![linea](../immagini/linea.png)

### 7.9.8 Il riempimento di una ```std::map```

  * Il modo più semplice per riempire una ```map```
    è utilizzare l'```operator[]```,
    che ha un comportamento duplice:
    se l'elemento corripondente ad una data chiave non esiste,
    viene creato, altrimenti viene restituito l'elemento esistente:
    ```cpp
    mappa_di_esempio[5] = 5.5 ;
    mappa_di_esempio[3] = 3.3 ;
    mappa_di_esempio[5] = 4.1 ;
    mappa_di_esempio[12] = 7.8 ;
    ```
    * In questo caso,
      le prime due righe definiscono due nuovi elementi,
      mentre la terza **sovrascrive** l'elemento associato alla chiave ```5```
  * Per gli oggetti sui quali si templa una ```map``` devono aver definti
    un operatore di assgnazione ed un *copy constructor*

![linea](../immagini/linea.png)

### 7.9.9 La lettura di una ```std::map```

  * per accedere ad un **singolo elemento esistente** in una ```map```
    si utilizza l'```operator[]```
  * ogni elemento della ```map``` è tecnicamente una **coppia di oggetti**,
    definita nelle STL come ```std::pair```,
    che è templata sui due stessi tipi della ```map```
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

## 7.10 ```std::string```

  * il ```C++``` offre uno strumento **dedicato alla gestione delle stringhe di caratteri**,
    con il tipo [```string```](https://www.cplusplus.com/reference/string/string/)
    ```cpp
    #include <string>
    using namespace std ;
    int main (int argc, char ** argv)
      {
        string s_1 ;
        return 0 ;
      }    
    ```
    * anche in questo caso, non sono necessarie opzioni di compilazione per usare la libreria ```string```

![linea](../immagini/linea.png)

### 7.10.1 operazioni con stringhe

  * La **somma** di due ```string``` restituisce la concatenazione del contenuto dei due oggetti sommati:
    ```cpp
    s_1 = "nel mezzo del cammin" ;
    string s_2 = " di nostra vita" ;
    string s_3 = s_1 + s_2 ;
    cout << s_3 << endl ;
    ```
  * Il metodo ```string::length ()``` resituisce il **numero di caratteri** che compongono la ```string```
    sul quale viene invocato
  * L'uguaglianza fra due ```string``` si può verificare con l'```operator==()```.  

![linea](../immagini/linea.png)

### 7.10.2 ricerca di sotto-elementi in una ```string```

  * In una ```string``` si possono **cercare sotto-```string```**:
    ```cpp
    int posizione = s_3.find (s_4) ;
    cout << "La parola \"" << s_4
         << "\" inizia al carattere " << posizione
         << " della frase: \"" << s_3
         << "\"\n" ;
    ```
    * In caso la sotto-```string``` non venga trovata,
      il metodo ```string::find``` ritorna *-1*.
    * Per **scrivere a schermo le virgolette**,
      devono essere precedute dal carattere ```\```
      quando poste all'interno di una stringa,
      per non confondere il simbolo con la fine della stringa stessa  

![linea](../immagini/linea.png)

### 7.10.3 ```string``` e caratteri

  * Una ```string``` contiene anche il **carattere che ne determina la fine**,
    dunque ```'A'``` è diverso da ```"A"```:
    * ```'A'``` è un **singolo carattere**, salvato il memoria come tale, occupa 1 byte in memoria.
    * ```"A"``` è una **stringa** composta da un carattere,
      occupa 8 byte in memoria in formato ```C```
      e di più in formato ```string```,
      per via della struttura interna della classe ```string```
      ```cpp
      char A = 'A' ;
      cout << sizeof (A) << endl ;

      string S = "A" ;
      cout << sizeof (S.c_str ()) << endl ;
      cout << sizeof (S) << endl ;   
      ```
    * Per compatibilità con funzioni implementate con lo stile ```C```,
      il metodo ```string::c_str ()``` restituisce il **vettore di caratteri**
      con il contenuto della variabile di tipo ```string```
  * In generale è preferibile **utilizzare ```string``` invece di ```char []```** nonappena possibile,
    per via della migliore gestione della memoria,
    oltre che per i diversi strumenti di manipolazione delle stringhe
    disponibili per la classe ```string```.

![linea](../immagini/linea.png)

## 7.11 ESERCIZI

  * Gli esercizi relativi alla lezione si trovano [qui](ESERCIZI.md)
