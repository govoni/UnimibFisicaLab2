# Esercizi per la lezione 1

## Esercizio 1.1 

Scrivere un programma che, letti due numeri interi da terminale, restituisca il loro rapporto.

![linea](../immagini/linea.png)

## Esercizio 1.2

Scrivere un programma che scrive a terminale la radice quadrata di 2, il cubo di 2 il seno di pigreco quarti.

![linea](../immagini/linea.png)

## Esercizio 1.3

Scrivere un programma che legga da linea di comando un numero intero a scelta tra 1 e 2
e restituisca a terminale il valore inserito, 
o un messaggio di errore in caso di inserimento di altri interi.

![linea](../immagini/linea.png)

## Esercizio 1.4 

Scrivere un programma che richieda all’utente di inserire un numero intero 
e che sappia riconoscere se il numero e' pari o dispari 
(utilizzare l’operatore ```%```, 
implementando due funzioni che stampino a schermo messaggi diversi nei due casi)
  * Implementare nel main un ciclo infinito con l’istruzione ```do ... while (condizione)```,
    che ripeta l'operazione fintanto che il numero inserito e' positivo.

![linea](../immagini/linea.png)

## Esercizio 1.5 

Scrivere una funzione che calcoli il fattoriale di un numero intero non negativo

![linea](../immagini/linea.png)

## Esercizio 1.6

Scrivere la funzione fattoriale in modo ricorsivo, 
cioe' facendo in modo che la funzione che calcola il fattoriale chiami se stessa
dove necessario, sfruttando il fatto che ```N! = N * (N-1)!```.

![linea](../immagini/linea.png)

## Esercizio 1.7

Scrivere un programma che chieda all’utente di inserire 10 numeri da tastiera 
e li memorizzi in un array.
Implementare le funzioni:
```cpp
  double Media (float array[], int N);
  double Varianza (float array[], int N);
```  
e utilizzarle nel main per calcolare la media e la varianza dei numeri inseriti.
