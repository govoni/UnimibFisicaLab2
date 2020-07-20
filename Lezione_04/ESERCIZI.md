# Esercizi per la lezione 4

## Esercizio 4.1 

Si scriva una funzione che implementi il generatore lineare congruenziale di numeri pseudo-casuali,
utilizzando questi parametri:
``` 
M = 2147483647
A = 214013
C = 2531011
```

![linea](../immagini/linea.png)

## Esercizio 4.2 

Si implementi il generatore nella forma di una classe,
che contenga un metodo di generazione di un numero casuale
ed un metodo di impostazione del ```seed``` di generazione,
utilizzando appropriatamente un membro ```private``` della classe
per salvare questa informazione.
  * come deve cambiare il ```seed``` salvato nel ```private``` della classe
    ogni volta che viene generato un nuovo numero casuale?

![linea](../immagini/linea.png)

## Esercizio 4.3

Si mostri che inizializzare il seed di un generatore di numeri pseudo-casuali 
equivale ad inserirsi in una sequenza di numeri pseudo-casuali
ad un qualunque punto.

    
![linea](../immagini/linea.png)

## Esercizio 4.4

Si implementi un generatore di numeri pseudo-casuali secondo una distribuzione uniforme
fra due estremi arbitrari.

![linea](../immagini/linea.png)

## Esercizio 4.5

Si implementi un generatore di numeri pseudo-casuali che utilizzi il metodo
try-and-catch per generare numeri casuali secondo un distribuzione di probabilita' arbitraria
  * si prenda come parametro di ingresso la pdf da utilizzare per la generazione di numeri casuali

![linea](../immagini/linea.png)

## Esercizio 4.6

Si implementi un generatore di numeri pseduo-casuali che utilizzi il metodo della funzione inversa
per generare eventi distribuiti secondo distribuzione di probabilita' esponenziale.

![linea](../immagini/linea.png)

## Esercizio 4.7

Si implementi un generatore di numeri pseudo-casuali che utilizzi il metodo del teorema centrale del limite
per generare eventi distribuiti secondo una distribuzione di probabilita' gaussiana.
