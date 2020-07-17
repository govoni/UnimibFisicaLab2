# Esercizi per la lezione 3

## Esercizio 3.1 

Implementate la classe ```complesso``` come descritta nella lezione al paragrafo ```3.2.1```,
includendo anche un programma di test delle sue funzionalita'.

![linea](../immagini/linea.png)

## Esercizio 3.2

Aggiungete alla classe ```complesso``` i vari tipi di costruttore 
discussi nella sezione ```3.3``` della lezione.

![linea](../immagini/linea.png)

## Esercizio 3.3

Aggiungete alla classe ```complesso``` le seguenti operazioni:
  * somma di due numeri complessi
  * differenza fra due numeri complessi
  * moltiplicazione per un numero reale
  * prodotto fra due numeri complessi
  * operatore ```+=``` con come argomento un numero complesso
  * operatore ```+=``` con come argomento un numero reale
  * operatore ```-=``` con come argomento un numero complesso
  * operatore ```-=``` con come argomento un numero reale
  * operatore ```*=``` con come argomento un numero complesso
  * operatore ```*=``` con come argomento un numero reale
  * operatore ```/=``` con come argomento un numero complesso
  * operatore ```/=``` con come argomento un numero reale
  * in quali casi vanno effettuati controlli sul valore dei numeri complessi in input alle funzioni?

![linea](../immagini/linea.png)

## Esercizio 3.4 

Scrivete una classe chiamata ```mioArray```
che implementi un array di numeri ```double``` con dimensione impostata dall'utente
al momento della creazione degli oggetti,
utilizzando l'allocazione dinamica della memoria
e ripulisca la memoria nel distruttore.
  * Scrivete inoltre un programma di test che verifichi le funzionalita' della classe.
  * La classe ```mioArray``` deve contenere un metodo per accedere ai suoi elementi
    che operi un controllo sul valore dell'indice, 
    che avverta con un messaggio a schermo nel caso in cui si cerchi di accedere
    ad un indice che non sta nell'array
  * Si faccia in modo che sia possibile utilizzare questa funzione
    sia nel caso in cui si voglia modificare il contenuto delle celle dell'array,
    sia nel caso in cui l'oggetto di tipo ```mioArray``` sia ```const```

![linea](../immagini/linea.png)

## Esercizio 3.5 

Trovare e correggete gli errori riguardanti l’uso dell’attributo ```const```
```cpp
#include <iostream>

int fun01 (const int a) 
  {
    a = 2 ;
    return a ; 
  }

void fun02 (const int * a) 
  {
    *a = 2 ;
  }

void fun03 (int * const a) 
  {
    *a = 2 ;
  }

void fun04 (int* const * a, int * const *b) 
  {
    * a = *b ; 
  }

void fun05 (int const & a) 
  {
    a = 2 ; 
  }

int main(int argc, char** argv) 
{
  const int a = 1 ;
  a = 6 ;
  std::cout << "a = " << a << std::endl ;
  const int * b = new int (1) ; 
  *b = 2 ;
  int * c = new int (3) ;
  b = c ;
  std::cout << "b = " << *b << std::endl ;
  int * const d = new int(1) ; 
  *d = 2 ;
  int* e = new int (3) ;
  d = e ;
  
  const int f = 1 ;
  std::cout << "d = " << *d << std::endl ; 
  std::cout << "fun01 = " << fun01 (f) << std::endl ; 
  int g = 1 ;
  std::cout << "fun01 = " << fun01(g) << std::endl ;

  const int * h = new int (1) ;
  fun02 (h) ;
  std::cout << "h = " << *h << std::endl ; 
  int* i = new int (1) ;
  fun02 (i) ;
  std::cout << "i = " << *i << std::endl ;
  const int* j = new int (1) ;
  fun03 (j) ;
  std::cout << "j = " << *j << std::endl ; 
  int * k = new int (1) ;
  fun03 (k) ;
  std::cout << "k = " << *k << std::endl ;
  int * l = new int (1) ; 
  int * m = new int (2) ; 
  fun04 (&l, &m) ;
  std::cout << "l = " << *l << std::endl ; 
  const int n = 1;
  fun05 (n) ; 
  std::cout << "n = " << n << std::endl;

  return 0; 
}

```
