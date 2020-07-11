# Esercizi per la lezione 2

## Esercizio 2.1 

Scrivere un programma che assegni il valore di una variabile ad un'altra utilizzando un puntatore. 
Stampare inoltre a terminale i valori e gli indirizzi di ogni variabile prima e dopo l'assegnazione.

![linea](../immagini/linea.png)

## Esercizio 2.2 

Dichiarare un puntatore e poi cercare di assegnargli direttamente un valore numerico. Cosa succede? Perché?

![linea](../immagini/linea.png)

## Esercizio 2.3

Utilizzare new e delete per creare e distruggere una variabile double ed un array di double.
    
![linea](../immagini/linea.png)

## Esercizio 2.4

Realizzare una funzione che risolva un’equazione di secondo grado: ax2 + bx + c = 0. 
La funzione deve rendere disponibile il risultato al programma che la chiama. 
  * Il prototipo della funzione deve essere:
    ```cpp
    bool solve2ndDegree (double * par, double * x) ;
    ```
  * La funzione deve restituire una variabile ```bool (true/false)``` a
    seconda che esistano o meno soluzioni reali dell’equazione
  * La funzione riceve in input due puntatori a double:
    * ```double * par``` serve per passare l’array dei coefficienti
    * ```double * x```  è l’indirizzo di un array in cui salvare le soluzioni dell’equazione
    
![linea](../immagini/linea.png)

## Esercizio 2.5

Rifare l’esercizio su media/varianza realizzando un’unica funzione che le calcoli entrambe,
facendo opportuno uso puntatori o referenze.
    
![linea](../immagini/linea.png)

## Esercizio 2.6

Scrivere una funzione che, dato un array di N interi, 
lo ordini dal più piccolo al più grande 
(suggerimento: creare un array inserendo alcuni numeri a caso per testare che l'ordinamento funzioni). 
  * Il prototipo della funzione deve essere:
    ```cpp
    void SortArray (double * myArray, int dim) ;
    ```
![linea](../immagini/linea.png)

## Esercizio 2.7

Scrivere una funzione ```creaArray (...) ``` che prenda in input un numero intero,
crei un array di tipo ```float``` lungo quando il numero intero di input
e restituisca il puntatore al primo elemento dell'array.
