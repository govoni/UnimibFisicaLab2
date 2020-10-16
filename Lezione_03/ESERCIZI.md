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
