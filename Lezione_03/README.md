# Lezione 3: programmazione ad oggetti, le classi

## Indice

  * [3.1 La generalizzazione del concetto di tipo](#31-la-generalizzazione-del-concetto-di-tipo)
    * [3.1.1 Uno sguardo ravvicinato ai tipi predefiniti in ```C++```](#311-uno-sguardo-ravvicinato-ai-tipi-predefiniti-in-c)
    * [3.1.2 Un esempio: i numeri complessi](#312-un-esempio-i-numeri-complessi)
    * [3.1.3 Se i numeri complessi fossero un tipo di ```C++```](#313-se-i-numeri-complessi-fossero-un-tipo-di-c)
  * [3.2 Si può fare! La classe dei numeri complessi](#32-si-può-fare-la-classe-dei-numeri-complessi)
    * [3.2.1 La definizione della classe (il file ```complesso.h```)](#321-la-definizione-della-classe-il-file-complessoh)
    * [3.2.2 un primo esempio di utilizzo](#322-un-primo-esempio-di-utilizzo)
    * [3.2.3 I membri di una classe](#323-i-membri-di-una-classe)
    * [3.2.4 I metodi di una classe](#324-i-metodi-di-una-classe)
    * [3.2.5 Il campo ```private```](#325-il-campo-private)
    * [3.2.6 Il campo ```public```](#326-il-campo-public)
    * [3.2.7 L'implementazione della classe (il file ```complesso.cc```)](#327-limplementazione-della-classe-il-file-complessocc)
    * [3.2.8 Un membro implicito di ogni classe: l'oggetto stesso](#328-un-membro-implicito-di-ogni-classe-loggetto-stesso)
  * [3.3 Funzioni speciali di una classe](#33-funzioni-speciali-di-una-classe)
    * [3.3.1 Il costruttore](#331-il-costruttore)
    * [3.3.2 La lista di inizializzazione](#332-la-lista-di-inizializzazione)
    * [3.3.3 overloading del costruttore](#333-overloading-del-costruttore)
    * [3.3.4 Il costruttore di default](#334-il-costruttore-di-default)
    * [3.3.5 Il costruttore di copia, o copy constructor](#335-il-costruttore-di-copia-o-copy-constructor)
    * [3.3.6 Il distruttore](#336-il-distruttore)
  * [3.4 La ridefinizione di operatori, overloading](#34-la-ridefinizione-di-operatori-overloading)
    * [3.4.1 L'operatore di assegnazione per tipi predefiniti](#341-loperatore-di-assegnazione-per-tipi-predefiniti)
    * [3.4.2 L'operatore di assegnazione per una classe](#342-loperatore-di-assegnazione-per-una-classe)
    * [3.4.3 L'operatore di somma](#343-loperatore-di-somma)
    * [3.4.4 Definizione al di fuori della classe](#344-definizione-al-di-fuori-della-classe)
  * [3.5 L'attributo ```const```](#35-lattributo-const)
    * [3.5.1 Esempi di utilizzo di ```const``` con i tipi predefiniti](#351-esempi-di-utilizzo-di-const-con-i-tipi-predefiniti)
    * [3.5.2 Oggetti definiti ```const```](#352-oggetti-definiti-const)
  * [3.6 Classi e puntatori](#36-classi-e-puntatori)
  * [3.7 ESERCIZI](#37-esercizi)

![linea](../immagini/linea.png)

## 3.1 La generalizzazione del concetto di tipo

  * secondo la programmazione **object oriented**,
    le funzionalità di un programma vanno associate all'informazione che processano,
  * così come per ogni tipo predefinito (```int```, ```float```, et cetera)
    esistono gli operatori che ne gestiscono i comportamenti
  * in ```C++``` questo paradigma è realizzato attraveso 
    il concetto di **classe, che è una generalizzazione del tipo**,
    mentre gli **oggetti sono la generalizzazione delle variabili**

![linea](../immagini/linea.png)

### 3.1.1 Uno sguardo ravvicinato ai tipi predefiniti in ```C++```

  * un qualunque tipo predefinito è caratterizzato da una serie di **proprietà**:
  * funzioni per la **gestione della memoria**:
    * allocazione dello spazio nella RAM quando una variabile viene definita
    * liberazione dello spazio RAM quando una variabile cessa di esistere
  * **operatori** per maneggiare le variabili

![linea](../immagini/linea.png)

### 3.1.2 Un esempio: i numeri complessi

  * **costrutti più sofisticati** dei tipi predefiniti non godono di queste proprietà
  * un numero complesso è rappresentato da due numeri reali,
    che un ```C++``` si possono scrivere come:
    ```cpp
    double num_parteReale ;
    double num_parteImmaginaria ;
    ```
  * senza fare uso di classi, le operazioni tipiche dei numeri complessi
    vanno **implementate sotto forma di funzioni**:
    * calcolo del modulo e della fase
    * somma di numeri complessi
    * moltiplicazione per un numero reale
  * ad esempio:
    ```cpp
    double modulo (double real, double imag)
      {
        return sqrt(real * real + imag * imag) ;
      }
    ```
      
![linea](../immagini/linea.png)

### 3.1.3 Se i numeri complessi fossero un tipo di ```C++```

  * le operazioni per gestire i numeri complessi sono
    praticamente **associate soltanto a loro**
  * risulterebbe molto più comodo se fosse possibile 
    **definire un numero complesso** e associare ad esso le operazioni che lo riguardano:
    * migliore **gestione del programma**
    * **proprietà** simili a quelle dei tipi predefiniti
    * mogliore **solidità del design del codice sorgente**, 
      perché migliora la consistenza del codice
      e le possibilità di controllo di errori logici

![linea](../immagini/linea.png)

## 3.2 Si può fare! La classe dei numeri complessi

  * una classe è di fatto la **definizione di un nuovo tipo**:
    il caso ideale per la costruzione di una libreria, 
    con un file header (```.h```) ed uno di implementazione (```.cc```)

![linea](../immagini/linea.png)

### 3.2.1 La definizione della classe (il file ```complesso.h```)

  * ecco come si definisce in ```C++```
    ```cpp
    class complesso
    {
    public: 
      complesso (double r, double i) ;
      ~complesso () ;
    
      double modulo () ;      
      double fase () ;      

    private:
      double m_real ;
      double m_imag ;
    } ;
    ```   
  | attenzione |
  | ---------- |

  * dopo la chiusura della parentesi graffa **c'è un punto e virgola! ```} ;```**

![linea](../immagini/linea.png)

### 3.2.2 un primo esempio di utilizzo

  * in un qualunque punto del codice sorgente,
    si può quindi creare un numero complesso:
    ```cpp
    complesso numero_complesso_1 (0., 0.) ;
    complesso numero_complesso_2 (3., 4.) ;
    ```
  * in questo esempio ```complesso``` è la classe (il nuovo tipo),
    mentre ```numero_complesso_1``` e ```numero_complesso_2```
    sono due **oggetti**

![linea](../immagini/linea.png)

### 3.2.3 I membri di una classe

  * le variabili definite all'interno della definizione della classe
    sono dette **membri della classe**:
    ```cpp
    double m_real ;
    double m_imag ;
    ```
  * ogni volta che viene creato un oggetto di una classe,
    viene creata una nuova istanza dei membri della classe
    associata a quell'oggetto,
    quindi **ogni oggetto ha le proprie variabili membro** corrispondenti
  * i membri possono essere di tipo predefinito, 
    oppure **a loro volta oggetti** di una classe
  * è buona regola di programmazione **identificare i membri in modo simbolico**,
    ad esempio con il prefisso ```m_```  

![linea](../immagini/linea.png)

### 3.2.4 I metodi di una classe

  * le funzioni che sono definite all'interno di una classe sono chiamate **metodi** della classe
  * hanno automaticamente **accesso ai membri** dell'oggetto sul quale operano
    e si invocano su un oggetto utilizzando il nome dell'oggetto
    seguito da un punto e dal nome del metodo:
    ```cpp
    numero_complesso_1.modulo ()
    ```
  * i metodi **possono avere argomenti**, 
    ad esempio uno di essi potrebbe moltiplicare il numero complesso 
    per un numero reale:
    ```cpp
    numero_complesso_1.dilata (double fattore_di_scala)
    ```

![linea](../immagini/linea.png)

### 3.2.5 Il campo ```private```

  * i metodi di una classe **fungono da interfaccia** fra i membri di un oggetto
    ed il codice sorgente dove l'oggetto è definito
  * è talvolta auspicabile che i membri possano essere modificati 
    **soltanto attraverso i metodi**, 
    per evitare che subiscano operazioni
    che compromettano la funzionalità dell'oggetto nel suo insieme
  * tutti i metodi ed i membri definiti **dopo la parola chiave ```private```**
    sono accessibili solo per i metodi della loro classe
  * se non si indica nulla, tutto il contenuto di una classe è ```private```

![linea](../immagini/linea.png)

### 3.2.6 Il campo ```public```

  * i metodi ed i membri definiti **dopo la parola chiave ```public```**
    sono accessibili nel codice sorgente al di fuori della classe
    (ad esempio nella funzione ```main```)
    tramite la sintassi del ```.```:
    ```cpp
    numero_complesso_1.modulo ()
    ```
  * solitamente, i **membri** di una classe sono ```private```, 
    mentre i suoi **metodi** sono ```public```
  * se si definisce una classe con l'identificativo ```struct``` invece di ```class```,
    se non si indica nulla tutto il contenuto della classe è ```public```

![linea](../immagini/linea.png)

### 3.2.7 L'implementazione della classe (il file ```complesso.cc```)

  * i metodi di una classe possono essere **implementati** 
    direttamente nello scope di definizione 
  * solitamente, tuttavia, questo succede **in un file separato**,
    dove vanno associati alla classe che li contiene, ad esempio:
    ```cpp
    #include "complesso.h"
    double complesso::modulo ()
      {
        return sqrt (m_real * m_real + m_imag * m_imag) ;
      }    
    ```
  * il nome di ogni metodo è preceduto dal nome della classe, 
    separato dall'operatore di scope resolution ```::``` 

![linea](../immagini/linea.png)

### 3.2.8 Un membro implicito di ogni classe: l'oggetto stesso

  * per ogni classe, 
    è sempre definito il **puntatore all'oggetto corrente**,
    rappresentato dal simbolo **```this```**
    ```cpp
    void
    complesso::stampami ()
    {
      std::cout << this->m_real << " + " << this->m_imag << "i" << std::endl ;
      return ;
    }
    ```
  * il ```.``` che si usa per accedere a membri e metodi di un oggetto
    viene **sostituito da ```->``` per i puntatori ad oggetti**

![linea](../immagini/linea.png)

## 3.3 Funzioni speciali di una classe

  * oltre a quelle che servono per maneggiare le variabili, 
    ogni tipo predefinito possiede funzioni dedicate alla 
    **creazione ed alla distruzione delle variabili**
  * in una classe,
    queste funzioni **vanno implementate**  

![linea](../immagini/linea.png)

### 3.3.1 Il costruttore

  * **crea l'oggetto** al momento della sua definizione,
    inizializzando i membri dell'oggetto:
    ```cpp
    complesso::complesso (double r, double i):
      m_real (r),
      m_imag (i)
      {
        std::cout << "costruzione di un numero complesso" << std::endl ;
      }
    ```
  * le variabili di **tipi predefiniti** vengono create dal costruttore corrispondente
  * oggetti di altre classi vengono **creati dal costruttore corrispondente**   
  * il costruttore **non ha tipo di ritorno**
  * nello scope del costruttore si possono eseguire istruzioni
    (in questo esempio c'è una stampa a schermo, che in realtà è scomodo:
     nessuno vuole un programma troppo petulante)
  * questo è un buon posto dove **allocare dinamicamente la memoria**, se necessario   

![linea](../immagini/linea.png)

### 3.3.2 La lista di inizializzazione

  * tutti i membri di una classe vengono creati **prima dell'inizio** dello scope del costruttore
  * la sequenza:
    ```cpp
    m_real (r),
    m_imag (i)
    ```
    è detta **lista di inizializzazione**
  * ottimizza l'uso della memoria: inizializza ciascun membro al valore fra parentesi
    al momento della creazione del membro
  * l'**ordine delle variabili** deve essere il medesimo della loro definizione
    all'interno della classe  
  * se non si mettesse la lista di inizializzazione,
    bisognerebbe inizializzare le variabili nello scope del costruttore,
    spendendo più tempo di esecuzione:
    ```cpp
    complesso::complesso (double r, double i):
      {
        m_real = r ;
        m_imag = i ;
        std::cout << "costruzione di un numero complesso" << std::endl ;
      }
    ```

![linea](../immagini/linea.png)

### 3.3.3 overloading del costruttore

  * una classe può possedere **più di un costruttore**,
    a patto che ciascuno prenda argomenti diversi
  * ad esempio, si può definire un costruttore che abbia come input soltanto 
    un numero reale:  
    ```cpp
    complesso::complesso (double r):
      m_real (r),
      m_imag (0.)
      {
        std::cout << "costruzione di un numero complesso" << std::endl ;
      }
    ```

![linea](../immagini/linea.png)

### 3.3.4 Il costruttore di default

  * un costruttore senza argomenti di input è chiamato **costruttore di default**:
    ```cpp
    complesso::complesso ():
      m_real (0.),
      m_imag (0.)
      {
        std::cout << "costruzione di un numero complesso" << std::endl ;
      }
    ```
  * se una classe non ha il costruttore, 
    il compilaore spesso **definisce un costruttore di default** vuoto

![linea](../immagini/linea.png)

### 3.3.5 Il costruttore di copia, o copy constructor

  * è naturale immaginare di costruire un oggetto nuovo
    copiando il contenuto di uno esistente:
    ```cpp
    complesso::complesso (const complesso & orig):
      m_real (orig.m_real),
      m_imag (orig.m_imag)
      {}
    ```
  * una classe ha sempre accesso a tutti i membri 
    di tutti gli oggetti di quella classe 
    se vengono passati come argomenti di una funzione,
    quindi **il copy constructor ha accesso ai membri ```private```
    dell'oggetto ```orig```**
    * esiste una eccezione a questa regola,
      che vedremo quando parleremo di ereditarietà
  * l'oggetto ```orig``` viene passato:
    * **per referenza** per ragioni di velocità
    * **con l'attributo const** per garantire che non venga modificato  
  * anche in questo caso, **non c'è tipo di ritorno**

![linea](../immagini/linea.png)

### 3.3.6 Il distruttore

  * al termine della vita di un oggetto, cioè al momento in cui va out of scope, 
    la memoria che occupa va liberata
  * i suoi membri di tipi predefiniti del ```C++``` allocati automaticamente
    vengono distrutti automaticamente
  * la memoria allocata dinamicamente va ripulita esplicitamente:
    per fare questo, esiste una funzione dedicata, chiamata **distruttore**,
    dove tutti i **```delete```** necessari possono essere chiamati
    ```cpp
    complesso::~complesso () 
      {
        // qui va ripulita la memoria allocata dinamicamente
      }

    ```    
  * eventuali **membri che siano oggetti di altre classi** saranno distrutti dal distruttore corrispondente
  * nel distruttore si possono anche implementare comportamenti aggiuntivi,
    come ad esempio il salvataggio automatico dell'informazione
  * anche il distruttore **non ha tipo di ritorno**
  * se non viene implementato,
    **il compilatore crea automaticamnete** un distruttore vuoto

![linea](../immagini/linea.png)

## 3.4 La ridefinizione di operatori, overloading

  * per i tipi predefiniti di ```C++``` le operazioni matematiche fondamentali
    sono effettuate con i simboli algebrici noti: ```+```, ```-```, ```*```, ```/```, ```=``` ....
  * si può definire il comportamento di queste funzioni anche per gli oggetti
    delle classi
    (come sempre, si distinguono dagli altri per i diversi tipi in ingresso)
  * ecco due esempi notevoli  

![linea](../immagini/linea.png)

### 3.4.1 L'operatore di assegnazione per tipi predefiniti

  * una operazione solitamente fattibile con tipi predefiniti è 
    l'assegnazione a partire da una altra variabile esistente:
    ```cpp
    int numero = 5 ;
    ```
    * in questo caso, il ```C++``` prima costruisce la variabile ```numero``` e le assegna un valore in memoria,
      successivamente le fa assumere il valore di ```5```

![linea](../immagini/linea.png)

### 3.4.2 L'operatore di assegnazione per una classe

  * il comportamento dell'operatore di assegnazione **va definito** per una classe
    ```cpp
    complesso & 
    complesso::operator= (const complesso & orig)
    {
      m_real = orig.m_real ;
      m_imag = orig.m_imag ;
      return *this ;
    }  
    ```
    * la **variabile in ingresso** è una referenza costante per garantire velocità e non modificabilità
    * la **variabile in uscita** è una referenza all'oggetto,
      per permettere la seguente sintassi:
      ```cpp
      complesso numero_complesso_6 = numero_complesso_5 = numero_complesso_2 ;
      ```
    * non viene restituita una copia dell'oggetto corrente per **risparmiare tempo**

![linea](../immagini/linea.png)

### 3.4.3 L'operatore di somma

  * vogliamo che l'operazione di somma fra numeri complessi si possa scrivere come:
    ```cpp
    complesso numero_complesso_4 = numero_complesso_3 + numero_complesso_2 ;
    ```
  * in ```C++``` si può ottenere defintendo un metodo della classe complesso 
    chiamato ```operator+```:
    ```cpp
    complesso
    complesso::operator+ (const complesso & addendo)
    {
      complesso somma (m_real, m_imag) ;
      somma.m_real = somma.m_real + addendo.m_real ;
      somma.m_imag = somma.m_imag + addendo.m_imag ;
      return somma ;
    }
    ```
    * la **variabile in ingresso** è una referenza costante per garantire velocità e non modificabilità
    * la **variabile in uscita** è un oggetto nuovo
  * l'```operator+``` ha in questo caso un solo argomento,
    perché uno dei due addendi è l'oggetto sul quale è chiamato.
    Infatti, le due scritture seguenti sono equivalenti:
    ```cpp
    complesso numero_complesso_4 = numero_complesso_3 + numero_complesso_2 ;
    complesso numero_complesso_4 = numero_complesso_3.operator+ (numero_complesso_2) ;
    ```

![linea](../immagini/linea.png)

### 3.4.4 Definizione al di fuori della classe

  * la funzione ```operator+``` può essere definita anche **al di fuori della classe**
    * in questo caso ha due argomenti, che sono entrambi gli addendi
  * in questo caso, tuttavia, nella funzione i membri privati degli oggetti **non sono accessibili**
    * bisogna definire **metodi pubblici di interfaccia** per accedere al valore dei membri
      ```cpp
      double 
      complesso::parte_reale () const
      {
        return m_real ;
      }
      ```
  * può essere comodo per definire operazioni **fra oggetti eterogenei**
    ```cpp
    complesso operator+ (const complesso & uno, const double & due)
      {
        double real = uno.parte_reale () + due ;
        double imag = uno.parte_immaginaria () ;
        complesso somma (real, imag) ;
        return somma ;
      }
    ```  
    * essendo una funzione **esterna alla classe**,
      in questo caso non è presente la denominazione di scope ```complesso::```

![linea](../immagini/linea.png)

## 3.5 L'attributo ```const```

  * la parola chiave ```const``` indica il fatto che **non sia permesso
    cambiare il valore** contenuto in una variabile o in un oggetto
  * const si **applica** al primo attributo alla sua sinistra, 
    se non c'è nulla si applica al primo attributo alla sua destra
    * a seconda della sua posizione, ha effetti differenti

![linea](../immagini/linea.png)

### 3.5.1 Esempi di utilizzo di ```const``` con i tipi predefiniti

  | sintassi  | effetto |
  | --- | --- |
  | ```const int C1 = 10 ;```    | ```C1``` è un intero il cui valore è costante |
  | ```int const C1 = 10 ;```    | ```C1``` è un intero il cui valore è costante |
  | ```const int * C2 ;```       | ```C2``` è un puntatore ad un ```const int```, cioè un puntatore ad un intero costante |
  | ```int const * C2 ;```       | ```C2``` è un puntatore ad un ```const int```, cioè un puntatore ad un intero costante |
  | ```int * const C3 ;```       | ```C3``` è un puntatore costante ad un intero variabile |
  | ```int const * const C4 ;``` | ```C4``` è un puntatore costante ad un intero costante |

  * NOTA BENE: siccome ```C3``` e ```C4``` sono puntatori costanti,
    vanno **immediatamente inizializzati**,
    perché i puntatori non sono inizializzati ad alcun valore di default:
    ```cpp
    int * const C3 (& numero) ;
    int const * const C4 (& C1) ;
    ```

![linea](../immagini/linea.png)

### 3.5.2 Oggetti definiti ```const```

  * le **stesse regole** si applicano ad oggetti definiti
  * tuttavia, si pone il problema aggiuntivo che, in generale,
    **i metodi di una classe possono modificare i membri** di un oggetto
  * per continuare ad utilizzare metodi preservando la caratteristica ```const```
    il ```C++``` richiede di **indicare quali metodi non modifichino i membri** 
    di una classe, aggiungendo l'attributo ```const``` al termine del loro prototpo:
    ```cpp
    double 
    complesso::parte_reale () const
    {
      return m_real ;
    }
    ```
  * su un oggetto di tipo ```const``` possono essere invocati 
    soltanto i metodi dichiarati ```const```
    
![linea](../immagini/linea.png)

## 3.6 Classi e puntatori

  * come abbiamo già visto, 
    esistono **puntatori e referenze ad oggetti**,
    con i medesimi comportamenti delle variaibli di tipo predefinito
  * per accedere a metodi e membri di un oggetto 
    attraveso un suo puntatore,
    si utilizza **l'operatore ```->``` invece di ```.```**
  * le classe possono anche **contenere puntatori** a variabili di tipo predefinito
    o ad altri oggetti
  * nel caso in cui si utilizzi **allocazione dinamica** della memoria,
    è prudente invocarla nel costruttore
    ed è **necessario ripulire la memoria nel distruttore**  

![linea](../immagini/linea.png)

## 3.7 ESERCIZI

  * Gli esercizi relativi alla lezione si trovano [qui](ESERCIZI.md)




