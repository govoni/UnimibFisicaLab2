# Esercizi per la lezione 8

## Esercizio 8.1

Si definisca una semplice struttura di ereditarieta' delle forme geometriche,
seguendo l'esempio presentato ad inizio lezione.
  * Si aggiunga alla classe ```forma``` un membro ```private``` (ad esempio un'etichetta)
    e si verifichi che e' accessibile dalle classi derivate 
    solamente tramite un metodo aggiuntivo ```public``` o ```protected``` della classe base.
  * Si verifichi la sequenza delle chiamate dei costruttori e dei distruttori
    della parte base e derivata delle classi al momento della creazione e della distruzione
    dei diversi oggetti, inserendo in ogni costruttore e distruttore un messaggio a schemo.  

![linea](../immagini/linea.png)

## Esercizio 8.2 

Si modifichi la struttura precedente aggiungendo la funzione ```calcola_area``` 
in tutta la catena di ereditarieta'.
  * Si verifichi il comportamento polimorfico introdotto dal *dynamic binding*.
  * Si verifichi che, eliminando la parola chiave ```virtual```, 
    il *dynamic binding* non funziona.
  * Si verifichi che il *dynamic binding* avviene in esecuzione e non in fase di compilazione,
    implementando una funzione ```void stampa_area (forma * input)```
    che stampa a schermo l'area di un oggetto di tipo ```rettangolo``` 
    o ```quadrato``` a seconda della scelta dell'utente.

![linea](../immagini/linea.png)

## Esercizio 8.3

Si implementino i generatori di numeri casuali scritti durante la Lezione 4
come oggetti derivati della seguente classe puramente virtuale
e si verifichi il *dynamic binding*.
```cpp
class generatore
{
  public :

    generatore (int seed = 1.) : m_seed (seed) {} 
    virtual ~generatore () {} 
    virtual void set_seed (int num) ; 
    virtual double set_seed (int num) ; 
    virtual double generate () ; 
    int get_seed () const { return m_seed ; }

  protected :  

    int m_seed ;
} ;
```
 
![linea](../immagini/linea.png)

## Esercizio 8.4

Si inseriscano i generatori precedenti in una ```std::map``` 
e si utilizzi un loop sugli elementi della mappa
per verificare quanto tempo impieghi ciascun generatore, 
in media,
a generare un evento pseudo-casuale.

![linea](../immagini/linea.png)

## Esercizio 8.5

Si costriusca un ```vector``` di numeri interi contenente il doppo dei primi dieci numeri interi.
  * Si mostri che l'algoritmo ```std::find``` non trova alcuno dei primi dieci numeri dispari al suo interno.
  * Si trovi l'iteratore all'elemento che contiene il numero *6*.
  * Si mostri che ognuno dei primi dieci numeri pari compare una volta sola all'interno del ```vector```.

![linea](../immagini/linea.png)

## Esercizio 8.6


![linea](../immagini/linea.png)

## Esercizio 8.7


![linea](../immagini/linea.png)

## Esercizio 8.8


![linea](../immagini/linea.png)

## Esercizio 8.9
