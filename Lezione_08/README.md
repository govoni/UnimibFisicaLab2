# Lezione 8: programmazione ad oggetti: l'ereditarietà ```public```

## Indice

  * [8.1 Introduzione](#81-introduzione)
    * [8.1.1 Rappresentazione grafica](#811-rappresentazione-grafica)
    * [8.1.2 Problemi di privacy](#812-problemi-di-privacy)
  * [8.2 Implementazione dell'esempio delle forme geometriche](#82-implementazione-dellesempio-delle-forme-geometriche)
    * [8.2.1 La classe base: ```forma```](#821-la-classe-base-forma)
    * [8.2.2 Una classe derivata: ```quadrato```](#822-una-classe-derivata-quadrato)
    * [8.2.3 La classe derivata nel programma principale](#823-la-classe-derivata-nel-programma-principale)
    * [8.2.4 Un'altra classe derivata: il ```rettangolo```](#824-unaltra-classe-derivata-il-rettangolo)
    * [8.2.5 La regola is-a: una specializzazione](#825-la-regola-is-a-una-specializzazione)
  * [8.3 ereditarietà e polimorfismo](#83-ereditarietà-e-polimorfismo)
    * [8.3.1 Compatibiità fra tipi ereditariamente correlati](#831-compatibiità-fra-tipi-ereditariamente-correlati)
    * [8.3.2 Il calcolo dell'area](#832-il-calcolo-dellarea)
    * [8.3.3 *Dynamic binding*](#833-dynamic-binding)
    * [8.3.4 Implementazione del metodo ```calcola_area```](#834-implementazione-del-metodo-calcola_area)
    * [8.3.5 l'ulitizzo nel programma](#835-lulitizzo-nel-programma)
    * [8.3.6 Il distruttore di una classe virtuale](#836-il-distruttore-di-una-classe-virtuale)
  * [8.4 Le interfacce e le classi puramente virtuali](#84-le-interfacce-e-le-classi-puramente-virtuali)
    * [8.4.1 Le interfacce](#841-le-interfacce)
  * [8.5 Il polimorfismo ed i contenitori STL](#85-il-polimorfismo-ed-i-contenitori-stl)
  * [8.6 algoritmi nelle STL](#86-algoritmi-nelle-stl)
    * [8.6.1 ```std::find```](#861-stdfind)
    * [8.6.2 il risultato di ```std::find```](#862-il-risultato-di-stdfind)
    * [8.6.3 ```std::sort```](#863-stdsort)
    * [8.6.4 risultato di ```std::sort```](#864-risultato-di-stdsort)
    * [8.6.5 la relazione di ordine nell'ordinamento](#865-la-relazione-di-ordine-nellordinamento)
    * [8.6.6 un esempio di utilizzo](#866-un-esempio-di-utilizzo)
  * [8.7 Ereditarietà e ```template```](#87-ereditarietà-e-template)
  * [8.8 Un utile strumento: la lettura di un *file* di testo](#88-un-utile-strumento-la-lettura-di-un-file-di-testo)
    * [8.8.1 L'implementazione della lettura](#881-limplementazione-della-lettura)
    * [8.8.2 L'implementazione della scrittura](#882-limplementazione-della-scrittura)
    * [8.8.3 Il controllo dell'apertura di un file](#883-il-controllo-dell-apertura-di-un-file)
  * [8.8 ESERCIZI](#88-esercizi)

![linea](../immagini/linea.png)

## 8.1 Introduzione

  * nella programmazione ad oggetti,
    la **traslazione dalle funzioni ai metodi delle funzionalità** dei programmi
    produce necessariamente una proliferazione di classi
    per svolgere i compiti dei programmi
  * spesso succede che classi simili **implentino comportamenti comuni**
    insieme a comportamenti specifici per ciascuna di esse  
  * il meccanismo dell'ereditarietà permette di **evitare di reimplementare comportamenti comuni**,
    definendoli soltanto una volta per una **classe base**,
    facendo in modo che vengano ereditati da diverse **classi derivate**
  * le classi derivate, dunque, **adattano ed estendono comportamenti generali** 
    definiti nella classe base

![linea](../immagini/linea.png)

### 8.1.1 Rappresentazione grafica

  * il meccanismo di ereditarietà ```public``` introduce una **gerarchia fra classi**:
    ogni classe derivata è un caso particolare della classe base.
    Questo concetto è noto come la **regola is-a**.
    ![gerarchia](immagini/gerarchia.png)

![linea](../immagini/linea.png)

### 8.1.2 Problemi di privacy

  * nelle classi, 
    i membri ed i metodi sono divisi in parte ```public``` e parte ```private```:
    **come funziona l'accesso** nel caso dell'ereditarietà?  
  * i membri e metodi ```public``` delle classi base **sono accessibili** alle classi derivate
  * i membri e metodi ```private``` delle classi base **non sono accessibili** alle classi derivate
  * esiste una terza catergoria: 
    i membri e metodi ```protected``` delle classi base **non sono accessibili al di fuori** della classe base,
    **restando accessibili alle classi derivate**.

![linea](../immagini/linea.png)

## 8.2 Implementazione dell'esempio delle forme geometriche 

![linea](../immagini/linea.png)

### 8.2.1 La classe base: ```forma```

  * la **classe base** per le forme geometriche ha un contenuto molto semplice:
    ```cpp
    class forma
    { 
      public:
        
        forma (double area = -1.) : m_area (area) {} ;
        ~forma () {} ;
        double area () const { return m_area ; } ;
    
      protected:  
    
        double m_area ;
    
    } ;

    ```
    * il membro ```m_area``` è ```protected``` perché sia accessibile
      anche alle classi derivate
    * in questo caso non ci sono ```private```, ma si potrebbero mettere  
  * un oggetto di tipo ```forma``` può essere istanziato in un programma ```C++``` 
    ```cpp
    forma forma_base ;
    cout << forma_base.area () << endl ;
    ```

![linea](../immagini/linea.png)

### 8.2.2 Una classe derivata: ```quadrato```

  * La sintassi per definire una **classe derivata pubblicamente** è la seguente:
    ```cpp
    class quadrato : public forma 
    {
      public:
    
        quadrato (double lato = 1.) :
          m_lato (lato),
          forma (lato * lato) {}
    
        double lato () const { return m_lato ; }
        void cambia_lato (double lato) 
          {
            m_lato = lato ;
            m_area = m_lato * m_lato ;
            return ;
          } ;
    
        ~quadrato () {} ;
    
      private:  
    
        double m_lato ;
    
    } ;

    ```
    * il membro ```m_lato``` è **dichiarato ```private```** 
      perché nella progettazione della struttura di ereditarietà 
      non ci sono classi derivate che debbano accedervi
    * i metodi specifici della classe quadrato   
      **si aggiungono** a quelli della classe base
    * il membro **```m_area``` è accessibile** anche dalla classe ```quadrato```  

![linea](../immagini/linea.png)

### 8.2.3 La classe derivata nel programma principale

  * nella funzione ```main```, 
    o in qualunque altra funzione dove venga utilizzato,
    per un oggetto di tipo ```quadrato``` si possono chiamare i metodi pubblici
    **sia della classe base che di quella derivata**:
    ```cpp
    quadrato forma_quadrata (3.) ;
    cout << "area: " << forma_quadrata.area () << endl ;
    cout << "lato: " << forma_quadrata.lato () << endl ;
    forma_quadrata.cambia_lato (4.) ;
    cout << "area: " << forma_quadrata.area () << endl ;
    ```
  * la consistenza delle informazioni (ad esempio, che l'area sia calcolata correttamente)
    dipende dalla **bontà dell'implementazione**

![linea](../immagini/linea.png)

### 8.2.4 Un'altra classe derivata: il ```rettangolo```

  * da una medesima classe base possono ereditare **diverse classi derivate**:
    ```cpp
    class rettangolo : public forma 
    {
      public:
    
        rettangolo (double lato_o = 1., double lato_v = 1.) :
          m_lato_o (lato_o),
          m_lato_v (lato_v),
          forma (lato_o * lato_v) {}
    
        double lato_o () const { return m_lato_o ; }
        double lato_v () const { return m_lato_v ; }
    
        void cambia_lato_o (double lato) 
          {
            m_lato_o = lato ;
            m_area = m_lato_o * m_lato_v ;
            return ;
          } 
    
        void cambia_lato_v (double lato) 
          {
            m_lato_v = lato ;
            m_area = m_lato_o * m_lato_v ;
            return ;
          }
    
        ~rettangolo () {} ;
    
      private:  
    
        double m_lato_o ;
        double m_lato_v ;
    
    } ;
  
    ```
  * in questo caso, **sono necessari più metodi e più membri**
    per descrivere le proprietà del rettangolo

![linea](../immagini/linea.png)

### 8.2.5 La regola is-a: una specializzazione

  * L'ereditarietà delle funzionalità delle classi base nelle classi derivate
    è un aspetto importante della progettazione del codice sorgente
    e **riguarda il comportamento** di una classe
  * ad esempio, per il ```C++``` un quadrato **non** è una specilizzazione di un rettangolo,
    nonostante dal punto di vista geometrico il quadrato sia un rettangolo con lati uguali
    * ad un rettangolo si può modificare la lunghezza di un lato e rimane un rettangolo,
      mentre se si modifica la lunghezza di un lato di un quadrato,
      la forma geometrica **diventa un rettangolo generico**
  * quindi la classe ```quadrato``` **non è una specializzazione** della classe ```rettangolo```,
    perché non tutte le funzioni di ```rettangolo``` possono essere applicate a ```quadrato```

![linea](../immagini/linea.png)

## 8.3 ereditarietà e polimorfismo

  * quando due o più classi 
    sono inserite in una gerarchia ereditaria,
    un puntatore alla classe base
    può essere utilizzato per **referenziare anche oggetti 
    delle classi derivate**
  * questo è possibile dal fatto che la memoria dove sono salvati gli oggetti
    viene utilizzata a fette (**memory slicing**), 
    in modo che regioni separate della memoria corrispondano
    a parti differenti dell'oggetto considerato:
    ![memory_slicing](immagini/memory_slicing.png)
    * nello spazio occupato in memoria dall'oggetto ```quadrato```,
      la prima sezione (gialla) **contiene la parte ```forma```** dell'oggetto,
    * la seconda (arancione) contiene **ciò che serve in più per realizzare il ```poligono regolare```**,
    * la terza (rossa) contiene **ciò che serve in più rispetto al ```poligono regolare```
      per realizzare il ```quadrato```**
  * in questo modo, noto l'indirizzo della cella iniziale 
    a seconda del tipo da considerare il ```C++``` è in grado di ricostruire
    l'oggetto corrispondente    

![linea](../immagini/linea.png)

### 8.3.1 Compatibiità fra tipi ereditariamente correlati

  * Il *memory slicing* significa che sia lecito assegnare il puntatore di una classe derivata
    a **quello di una classe base**, 
    senza incorrere il problemi di accesso alla memoria:
    ```cpp
    quadrato forma_quadrata (3.) ;
    forma * puntatore = & forma_quadrata ;
    ```
  * Chiaramente l'opposto non è ammissibile,
    perché l'oggetto ```quadrato``` occupa più posto in memoria dell'oggetto ```forma```

![linea](../immagini/linea.png)

### 8.3.2 Il calcolo dell'area

  * Nell'implementazione delle funzioni ```rettangolo::cambia_lato_o (double)```, 
    ```rettangolo::cambia_lato_o (double)```, ```quadrato::cambia_lato (double)``` 
    l'area della forma geometrica **è stata ricalcolata**,
    perché sono state modificate le caratteristiche geometriche della forma
  * E' naturale **aggiungere un metodo ```calcola_area```** per tutte le forme geometriche,
    in modo che per ciascuna di esse il calcolo venga fatto sempre allo stesso modo
  * E' anche naturale immaginare che questo metodo sia parte della classe ```forma```, 
    perché esiste per ogni classe derivata, 
    e venga poi **reimplementato** da ogni classe derivata

![linea](../immagini/linea.png)

### 8.3.3 *Dynamic binding*

  * A partire da un puntatore ad una classe base,
    il ```C++``` è in grado di **comprendere dinamicamente 
    di che tipo sia l'oggetto** referenziato dal puntatore
    ed applicare il metodo corretto
  * Per ottenere questo comportamento,
    è necessario definire i metodi da reimplementare 
    con la parola chiave ```virtual```  

![linea](../immagini/linea.png)

### 8.3.4 Implementazione del metodo ```calcola_area```

  * **Nella classe base**, la funzione ```calcola_area``` non ha informazioni sufficienti 
    per fare alcun conto, quindi è implementata in modo banale in ```forma```:
    ```cpp
    virtual double calcola_area () { return -1. ; } 
    ```
    * La parola chiave ```virtual``` anticipa al compilatore  
      che le classi derivate **potrebbero reimplementare questo metodo**
      e che bisogna scegliere quella giusta in fase di esecuzione,
      a seconda del tipo effettivo di ciascun puntatore
  * **Nella classe derivata** la funzione viene reimplementata 
    con le informazioni necessarie, ad esempio per ```quadrato```:
    ```cpp
    virtual double calcola_area () 
      { 
        m_area = m_lato * m_lato ; 
        return m_area ; 
      }
    ```

![linea](../immagini/linea.png)

### 8.3.5 l'ulitizzo nel programma

  * Con questo accorgimento, grazie al *dynamic binding* 
    il programma **riconosce durante l'esecuzione**
    il tipo di oggetto da considerare.
  * Le seguenti istruzioni:
    ```cpp
    quadrato forma_quadrata (3.) ;
    forma * puntatore = & forma_quadrata ;   
    cout << puntatore->calcola_area () << endl ;
    ```
    restituiranno a schermo il valore ```9```, invece che ```-1```.

![linea](../immagini/linea.png)

### 8.3.6 Il distruttore di una classe virtuale

  * Il *dynamic binding* si intreccia con il fatto che un puntatore potrebbe venire **allocato dinamicamente**,
    quindi poi distrutto con l'operatore ```delete```
  * Se l'operatore ```delete``` viene chiamato su un puntatore alla classe base,
    per essere certi che venga chiamato anche il distruttore della classe derivata
    è necessario **dichiarare sempre il distruttore di tipo ```virtual```**
    quando si utilizzi il polimorfismo

![linea](../immagini/linea.png)

## 8.4 Le interfacce e le classi puramente virtuali

  * Una classe base in ```C++``` può essere utilizzata
    soltanto **per definire i comportamenti** di un insieme di classi derivate,
    deputanto l'implementazione alle classi derivate.
  * Chiaramente, una classe senza implementazione **non può essere utilizzata**
    per definire oggetti, 
    perché il tipo è incompleto.
  * Una classe di questo genere è detta ```puramente virtuale```.

![linea](../immagini/linea.png)

### 8.4.1 Le interfacce

  * La definizione di una classe puramente virtuale
    che detti i comportamenti delle classi derivate
    viene spesso utilizzata per garantire che oggetti definiti all'esterno di un programma
    o di una libreria
    **abbiano comportamenti compatibili** con il programma o la libreria stessi.
  * Le classi puramente virtuali 
    dalle quali si eredita il comportamento desiderato sono dette **interfacce**.

![linea](../immagini/linea.png)

## 8.5 Il polimorfismo ed i contenitori STL

![linea](../immagini/linea.png)

  * il comportamento polimorfico di una catena di ereditarietà
    permette di **riempire contenitori STL con un insieme eterogeneo** di oggetti
  * infatti, un contenitore di puntatori ad oggetti di una classe base
    può essere **riempito con i puntatori ad oggetti di diverse classi derivate**
    ed il ```C++``` capisce *run-time* quale funzione interpellare  
    ```cpp
    map<string, forma *> m_forme ; 
    
    forma forma_base ;
    m_forme["base"] = & forma_base ; 
    quadrato forma_quadrata (3.) ;
    m_forme["quadrato"] = & forma_quadrata ; 
      rettangolo forma_rettangolare (3., 2.) ;
    m_forme["rettangolo"] = & forma_rettangolare ; 

    for (map<string, forma *>::const_iterator it = m_forme.begin () ;
         it != m_forme.end () ;
         ++it)
      cout << it->first << " ha area " << it->second->calcola_area () << endl ;
  
    ```

![linea](../immagini/linea.png)

## 8.6 algoritmi nelle STL

  * insieme a strumenti per contenere informazioni, 
    le STL offrono **algoritmi per maneggiarle**
  * due operazoni importanti per maneggiare contenitori
    sono la **ricerca di un elemento al suo interno** e
    l'**ordinamento del suo contenuto**
  * gli algoritmi diventano disponibili
    ** includendo l'*header file* ```algorithm```**  

![linea](../immagini/linea.png)

### 8.6.1 ```std::find```

  * il prototipo di questo algoritmo è il seguente:
    ```cpp
    template <class InputIterator, class T>
    InputIterator find (InputIterator first, InputIterator last, const T& val);
    ```
  * trova il **primo elemento** all'interno di un contenitore uguale a ```val```,
    nell'intervallo delimitato da due iteratori ```[first, last)```
    * per cercare su **tutto un contenitore** si passano come argomenti i suoi ```begin ()``` ed ```end ()```
  * utilizza l'**```operator==``` definito per il tipo ```T```** per la ricerca
    * deve essere definito!

![linea](../immagini/linea.png)

### 8.6.2 il risultato di ```std::find```

  * restituisce l'**iteratore** al primo elemento trovato uguale a ```val```
    * se **non trova nulla**, restituisce l'iteratore alla fine del contenitore
  ```cpp
  vector<float> v ;
  for (int i = 0 ; i < 10 ; ++i) v.push_back (0.5 * i) ;

  vector<float>::iterator risultato = 
    find (v.begin (), v.end (), 3.5) ;

  if (risultato != v.end ()) cout << "trovato " << *risultato << endl ;
  ```

![linea](../immagini/linea.png)

### 8.6.3 ```std::sort```

  * esistono **due prototipi** per l'algoritmo di ordinamento
  * quello comunemente utilizzato funziona similmente a ```find```,
    perché agisce su un contenitore **tramite i suoi iteratori**:
    ```cpp
    template <class RandomAccessIterator>
    void sort (RandomAccessIterator first, RandomAccessIterator last);
    ```
  * utilizza l'**```operator<``` definito per il tipo ```T```** 
    per ordinare in modo crescente il contenitore
    * deve essere definito!
  * per ordinare **tutto un contenitore** si passano 
    come argomenti i suoi ```begin ()``` ed ```end ()```

![linea](../immagini/linea.png)

### 8.6.4 risultato di ```std::sort```

  * a partire da un ```vector``` riempito in questo modo:
    ```
    3, 2, 10, -1
    ```
  * la chiamata dell'algoritmo ```sort```:
    ```cpp
    sort (v.begin (), v.end ()) ;
    ```
    produce il seguente effetto sul contenuto del ```vector```:
    ```
    -1, 2, 3, 10
    ```

![linea](../immagini/linea.png)

### 8.6.5 la relazione di ordine nell'ordinamento

  * esiste un secondo prototipo di ```sort```,
    che permette di **indicare la funzione da usare
    per ordinare** il contenitore 
    ```cpp
    template <class RandomAccessIterator, class Compare>
    void sort (RandomAccessIterator first, RandomAccessIterator last, Compare comp) ;
    ```
  * ```comp``` può essere una funzione o una classe
    * nel caso sia una **funzione**, 
      deve prendere in **input** (per copia o referenza) due argomenti del tipo 
      contenuto nel contenitore e restituire in **output** un tipo compatibile con un ```bool```.
    * nel caso sia una **classe**,
      deve contenere un ```operator()``` che prenda in **input** (per copia o referenza) 
      due argomenti del tipo contenuto nel contenitore 
      e restituisca in **output** un tipo compatibile con un ```bool```.

![linea](../immagini/linea.png)

### 8.6.6 un esempio di utilizzo

  * supponiamo di voler ordinare il vettore visto in precedenza
    **anteponendo i numeri pari a quelli dispari**.
    La funzione che deve sostituire la relazione di ```<``` è:
    ```cpp
    bool confronto (int i, int j) 
      { 
        if (i % 2 == 0) 
          {
            if (j % 2 != 0) return true ;
            else return (i < j) ;
          }
        else
          {
            if (j % 2 == 0) return false ;
            else return (i < j) ;
          }
      }
    ```
  * In questo modo, la seguente chiamata:
    ```cpp
    sort (v.begin (), v.end (), confronto) ;
    ```
    restituisce:
    ```
    2, 10, -1, 3
    ```

![linea](../immagini/linea.png)

## 8.7 Ereditarietà e ```template```

  * L'ereditarietà e la programmazione ```template``` sono due tecniche
    che permettono di implementare il polimorfismo nel ```C++```
  * Entrambe le tecniche permettono infatti di **generalizzare il medesimo comportamento
    per diversi tipi**, senza necessariamente dover scrivere più volte lo stesso codice sorgente  
  * oltre al vantaggio pratico legato al tempo di scrittura dei programmi,
    questo comporta che le funzionalità vengono implementate meno volte,
    **rendendo più difficile commettere errori** 
    e produrre programmi inconsistenti
  * le due tecniche sono complementari:
    mentre l'ereditarietà comporta polimorfismo **durante l'esecuzione del programma**,
    la programmazione template lo implementa **durante la compilazione**

![linea](../immagini/linea.png)

## 8.8 Un utile strumento: la lettura di un *file* di testo

  * Può essere comodo **salvare informazioni semplici** su file di testo,
    per poterle rileggere dai programmi di analisi dati
  * La gestione dell'accesso a file di testo in ```C++``` è **analoga
    alla scrittura a schermo e lettura da tastiera**:
    si utilizzano gli operatori di redirezione ```operator>>``` (per leggere)
    ed ```operator<<``` (per scrivere) fra un oggetto che rappresenta il file
    e le variabili

![linea](../immagini/linea.png)

### 8.8.1 L'implementazione della lettura

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
    * la condizione ```input_file.eof () == true``` **non può essere controllata direttamente
      dall'istruzione ```while```**, 
      perché l'ultima operazione di lettura riconosce la fine del file,
      senza leggere contenuto utile.

![linea](../immagini/linea.png)

### 8.8.2 L'implementazione della scrittura

  * In questo caso,
    si utilizza la classe ```ofstream``` per produrre un file che contiene numeri:
    ```cpp
    #include <fstream>
    // ...
    ofstream output_file ;
    output_file.open ("example.txt", ios::out) ;
    
    for (int i = 0 ; i < 10 ; ++i)
      {
        output_file << i << "\n" ;
      }  

    output_file.close () ;
    ```
    * l'**operatore di redirezione** ```<<``` funziona come nel caso di ```std::cout```, 
      con il file come destilazione della redirezione, 
      invece dello schermo
      * tutto ciò che si può scrivere a schermo può essere scritto in un file
    * **l'opzione ```ios::out```** passata al metodo ```ofstream::open``` 
      indica che il file con nome ```"example.txt"``` viene aperto per scrittura
      * se il file non esiste, viene creato
      * se il file esiste, viene sovrascritto, perdendo il contenuto del file precendente
    * aprendo il file con opzione ```ios::app```, invece,
      il file viene aperto e predisposto perché la scrittura avvenga 
      **in coda al contenuto già presente nel file**

![linea](../immagini/linea.png)

### 8.8.3 Il controllo dell'apertura di un file

  * Per controllare se un file sia effettivamente stato aperto,
    si può utilizzare il metodo ```is_open```:
    ```cpp
    if (myfile.is_open ()) 
      { 
        /* istruzioni da eseguire */ 
      }
    ```

![linea](../immagini/linea.png)

## 8.9 ESERCIZI

  * Gli esercizi relativi alla lezione si trovano [qui](ESERCIZI.md)


