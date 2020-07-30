# Lezione 7: programmazione ```template```

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

![linea](../immagini/linea.png)

### 7.3.1 definizione di una classe ```template```

  * esempio dell'array a dimensione impostata a runtime
  * come si potrebbe fargli aumentare dimensione, se serve?

![linea](../immagini/linea.png)

### 7.3.2 implementazione di una classe ```template```

![linea](../immagini/linea.png)

### 7.3.3 utilizzo di una classe ```template```

![linea](../immagini/linea.png)

## 7.4 ```template``` multipli

![linea](../immagini/linea.png)

## 7.5 ordine nelle librerie: i ```namespace```

![linea](../immagini/linea.png)

### 7.5.1 costruzione di un ```namespace```

![linea](../immagini/linea.png)

### 7.5.2 utilizzo di un ```namespace``` come default

![linea](../immagini/linea.png)

## 7.6 ESERCIZI

  * Gli esercizi relativi alla lezione si trovano [qui](ESERCIZI.md)


