# Esercizi per la lezione 7

## Esercizio 7.1

Si scriva una funzione ```somma``` che,
utilizzando la tecnologia ```template```,
sia applicabile a qualunque tipo numerico del ```C++```.

![linea](../immagini/linea.png)

## Esercizio 7.2 

Si testi la funzione ```somma``` sviluppata nell'esercizio precedente
sulla classe dei numeri complessi sviluppata durante la Lezione 3,
aggiungendo anche una specializzazione per un tipo a piacere.

![linea](../immagini/linea.png)

## Esercizio 7.3

Si costruisca la classe ```SimpleArray```, templata sul tipo degli oggetti che contiene, 
implementando le funzioni definite nel prototipo presentato a lezione.
  * Si ricordi di utilizzare correttamente l'allocazione dinamica della memoria.
  * Si aggiungano alla classe anche metodi che permettano di accedere agli elementi della classe
    in caso vengano chiamati su un oggetto ```const```.
  * Si faccia in modo che i metodi di accesso al contenuto del ```SimpleArray``` 
    controllino il valore dell'indice
    prima di accedere all'array salvato in memoria.
  * Si verifichi che la classe ```SimpleArray``` può essere templata sulla classe dei numeri complessi
    sviluppata durante la Lezione 3.
    
![linea](../immagini/linea.png)

## Esercizio 7.4

Si implementi una classe templata dal nome ```DynamicArray``` che inizialmente
non contenga alcun elemento ed abbia un metodo ```push_back ()``` che permetta di aggiungere 
un elemento in fondo all'array degli elementi già esistenti.
  * Si progetti un meccanismo che rimpiazzi l'array che contiene gli elementi quando è pieno,
    sostituendolo con uno più capiente.
  * Si aggiunga un metodo che permetta anche di svuotare l'oggetto di tipo ```DynamicArray```.

![linea](../immagini/linea.png)

## Esercizio 7.5

Si implementi la classe templata ```vettore``` definita nella lezione.
  * Si ricordi di controllare che gli indici passati ai metodi della classe siano entro i limiti 
    della memoria occupata dagli oggetti di tipo ```vettore```
  * Si aggiungano gli **operatori algebrici** necessari per la definizione di uno spazio vettoriale

![linea](../immagini/linea.png)

## Esercizio 7.6

Si implementi la classe templata ```matrice``` delle matrici quadrate di dimensione *N*, 
templata sulla dimensione delle matrici, 
definendo anche le operazioni fra matrici.
  * Si definiscano gli operatori di moltiplicazione fra matrici e vettori,
    utilizzando anche la classe ```vettore```.
  * Si verifichi il funzionamento dell'algoritmo creato costruendo un esempio
    basato sulle rotazioni nel piano. 
  * Si scriva un metodo per il calcolo del determinante di una matrice nel caso sia quadrata,
    sfruttando la formula di Laplace ed una funzione ricorsiva.
  * Si ricordi che, 
    in ogni caso di ricorsività,
    oltre alla formula iterativa va aggiunto anche il metodo che restituisce il determinate
    nel caso della matrice più piccola possibile, cioè quella composta da un unico numero.
    Quindi, oltre al metodo:
    ```cpp
    double determinante () 
      {
        // implementazione
      }
    ```  
    è necessario anche aggiungere, al di fuori della definizione della classe ```matrice```,
    la specializzazione al caso di dimensione ```1```:
    ```cpp
    template<>
    double matrice<1,1>::determinante () { return elementi[0][0] ; }
    ```
  * Si scriva un metodo che calcola la matrice inversa, nel caso di una matrice quadrata
    e che ritorna una matrice nulla se la matrice orginale non è quadrata
    o ha determinante nullo.

![linea](../immagini/linea.png)

## Esercizio 7.7

Si crei un ```std::vector``` vuoto e, tramite un ciclo ```for```, 
lo si riempia con i primi 10 numeri della successione di Fibonacci.
  * E' conveniente, dal punto di vista dell'esecuzione di questo esercizio,
    utilizzare una funzione esterna al ciclo per il calcolo dei numeri di Fibonacci?
  * Si stampi a schermo il suo contenuto utilizzando un ciclo su un numero intero,
    oppure utilizzando un iteratore.

![linea](../immagini/linea.png)

## Esercizio 7.8

Si crei un ```std::vector``` vuoto e lo si riempia con cinque oggetti
del tipo della classe ```complesso``` sviluppato durante la Lezione 3.
  * Tramiti opportuni messaggi a schermo, 
    si verifichi quando vengono chiamati costruttore,
    *copy constructor*, operatore di assegnazione e distruttore
    della classe ```complesso```

![linea](../immagini/linea.png)

## Esercizio 7.9

Si crei una ```std::map``` vuota e la si riempia con una sequenza di numeri complessi,
utilizzando la norma dei numeri stessi come chiave di ordinamento della mappa.
  * Si stampino quindi a schermo i numeri, ordinati per norma.

![linea](../immagini/linea.png)

## Esercizio 7.10

Si crei una ```std::string``` riempita con un periodo scelto a piacere.
  * Si contino il numero di parole ed il numero di lettere (spazi esclusi)
    che compongono il periodo.
  * Si divida la stringa in singole parole,
    ciascuna salvata con una stringa all'interno di un ```std::vector```.  


