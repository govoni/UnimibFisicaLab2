# Lezione 3: programmazione ad oggetti, le classi

![linea](../immagini/linea.png)

## 3.1 La generalizzazione del concetto di tipo

  * secondo la programmazione **object oriented**,
    le funzionalita' di un programma vanno associate all'informazione che processano,
  * cosi' come per ogni tipo predefinito (```int```, ```float```, et cetera)
    esistono gli operatori che ne gestiscono i comportamenti
  * in ```C++``` questo paradigma e' realizzato attraveso 
    il concetto di **classe, che e' una generalizzazione del tipo**,
    mentre gli **oggetti sono la generalizzazione delle variabili**

![linea](../immagini/linea.png)

## 3.1.1 Uno sguardo ravvicinato ai tipi predefiniti in ```C++```

  * un qualunque tipo predefinito e' caratterizzato da una serie di **proprieta'**:
  * funzioni per la **gestione della memoria**:
    * allocazione dello spazio nella RAM quando una variabile viene definita
    * liberazione dello spazio RAM quando una variabile cessa di esistere
  * **operatori** per maneggiare le variabili

![linea](../immagini/linea.png)

### 3.1.2 Un esempio: i numeri complessi

  * **costrutti piu' sofisticati** dei tipi predefiniti non godono di queste proprieta'
  * un numero complesso e' rappresentato da due numeri reali,
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
  * risulterebbe molto piu' comodo se fosse possibile 
    **definire un numero complesso** e associare ad esso le operazioni che lo riguardano:
    * migliore **gestione del programma**
    * **proprieta'** simili a quelle dei tipi predefiniti
    * mogliore **solidita' del design del codice sorgente**, 
      perche' migliora la consistenza del codice
      e le possibilita' di controllo di errori logici

![linea](../immagini/linea.png)

### 3.2 Si puo' fare! La classe dei numeri complessi

  * una classe e' di fatto la **definizione di un nuovo tipo**:
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

  * dopo la chiusura della parentesi graffa **c'e' un punto e virgola! ```} ;```**

![linea](../immagini/linea.png)

### 3.2.1 un primo esempio di utilizzo

  * in un qualunque punto del codice sorgente,
    si puo' quindi creare un numero complesso:
    ```cpp
    complesso numero_complesso_1 (0., 0.) ;
    complesso numero_complesso_2 (3., 4.) ;
    ```
  * in questo esempio ```complesso``` e' la classe (il nuovo tipo),
    mentre ```numero_complesso_1``` e ```numero_complesso_2```
    sono due **oggetti**

![linea](../immagini/linea.png)

### 3.2.2 I membri di una classe

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
  * e' buona regola di programmazione **identificare i membri in modo simbolico**,
    ad esempio con il prefisso ```m_```  

![linea](../immagini/linea.png)

### 3.2.3 I metodi di una classe

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
    ed il codice sorgente dove l'oggetto e' definito
  * e' talvolta auspicabile che i membri possano essere modificati 
    **soltanto attraverso i metodi**, 
    per evitare che subiscano operazioni
    che compromettano la funzionalita' dell'oggetto nel suo insieme
  * tutti i metodi ed i membri definiti **dopo la parola chiave ```private```**
    sono accessibili solo per i metodi della loro classe
  * se non si indica nulla, tutto il contenuto di una classe e' ```private```

![linea](../immagini/linea.png)

### 3.2.4 Il campo ```public```

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
    se non si indica nulla tutto il contenuto della classe e' ```public```

![linea](../immagini/linea.png)

### 3.2.5 L'implementazione della classe (il file ```complesso.cc```)

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
  * il nome di ogni metodo e' preceduto dal nome della classe, 
    separato dall'operatore di scope resolution ```::``` 

![linea](../immagini/linea.png)

### 3.3 Funzioni speciali di una classe

![linea](../immagini/linea.png)

### 3.3.1 Il costruttore

- cosa fare nel costruttore
- la lista di inizializzazione
- overloading
- niente tipo di ritorno

![linea](../immagini/linea.png)

### 3.3.2 Il costruttore di default

- come si fa a non averlo?

![linea](../immagini/linea.png)

### 3.3.3 Il costruttore di copia

- come e' scritto l'argomento
- niente tipo di ritorno anche qui

![linea](../immagini/linea.png)

### 3.3.4 L'operatore di assegnazione

- come e' scritto l'argomento
- tipo di ritorno?

![linea](../immagini/linea.png)

### 3.3.5 Il distruttore

- ricordare i delete!
- non chiamato esplicitamente
- niente tipo di ritorno
- quando viene chiamato?
  - allocazione automatica
  - allocazione dinamica

![linea](../immagini/linea.png)

## 3.4 La ridefinizione di operatori, overloading

- i vari ```operator```

![linea](../immagini/linea.png)

## 3.5 L'attributo ```const```

![linea](../immagini/linea.png)

### 3.5.1 Dove si puo' utlizzare in ```C++``` con i tipi predefiniti

![linea](../immagini/linea.png)

### 3.5.2 Oggetti definiti ```const```

![linea](../immagini/linea.png)

### 3.5.2 Metodi definiti ```const```

- un metodo ```const``` non puo' modificare nessun data member della classe
- se una classe è stata istanziata come ```const``` si possono usare solo i suoli metodi ```const```

![linea](../immagini/linea.png)

## 3.4 Classi e puntatori

![linea](../immagini/linea.png)

### 3.4.X ```this```

## 3.X ESERCIZI

  * Gli esercizi relativi alla prima lezione si trovano [qui](ESERCIZI.md)




