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

![linea](../immagini/linea.png)

### 3.2.1 un primo esempio di utilizzo

  * in un qualunque punto del codice sorgente,
    si puo' quindi creare un numero complesso:
    ```cpp
    complesso numero_complesso (0., 0.) ;
    ```

![linea](../immagini/linea.png)

### 3.2.2 I membri di una classe

![linea](../immagini/linea.png)

### 3.2.3 I metodi di una classe

![linea](../immagini/linea.png)

### 3.2.4 Il campo ```public```

- e' il default se si scrive ```struct```

![linea](../immagini/linea.png)

### 3.2.5 Il campo ```private```

- e' il default per una classe

![linea](../immagini/linea.png)

### 3.2.5 L'implementazione della classe (il file ```complesso.cc```)

- i ```::``` per definire univocamente i metodi

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




