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
per generare eventi distribuiti secondo una distribuzione di probabilita' Gaussiana.
  * Come si fa ad ottenere una distribuzione si probabilita' Normale, 
    cioe' Gaussiana centrata in zero con varianza unitaria?
  * Si verifichi visivamente che al crescere del numero di eventi
    aumenta la somiglianza fra la distribuzione ottenuta e la forma funzionale Gaussiana  

![linea](../immagini/linea.png)

## Esercizio 4.8

Si implementi la classe seguente, 
che calcola le statistiche associate ad un campione di numeri.
```cpp
class statistiche
{
  public:

  statistiche () ;
  ~statistiche () ;

  // aggiunge un numero alle informazioni salvate
  int aggiungiNumero () ;

 
  // resituisce la media dei numeri aggiunti
  double media () const ;
  // restituisce la varianza dei numeri aggiunti
  // in caso di opzione true, applica la correzione di Bessel
  double varianza (bool corretta = false) const ;
  // restituisce la sigma dei numeri aggiunti
  // in caso di opzione true, applica la correzione di Bessel
  double sigma (bool corretta = false) const ;
  // resituisce la deviazione standard
  // in caso di opzione true, applica la correzione di Bessel
  double dev_standard (bool corretta = false) const ;
  // resituisce la deviazione standard dalla media
  double dev_standard_media (bool corretta = false) const ;
  // resituisce il numero dei numeri aggiunti
  double N () const ;

  private:
  
  // etc...  
} ;

```
  * che membri privati e' necessario aggiungere alla classe per garantirne la funzionalita'?
  * che valore devono avere i membri privati in fase di inizilizzazione?
  * potrebbero essere utili anche metodi privati, da aggiungere alla classe?


![linea](../immagini/linea.png)

## Esercizio 4.9

Si collaudi la classe ```statistiche``` con ciascuono degli agoritmi di generazione implementati.
In particolare, poi:
  * si verifichi che il valore della varianza della distribuzione uniforme corrisponde alle attese
    (quale e' l'incertezza associata al numero ottenuto?)
  * si verifichi che il valore della varianza ottenuta con la tecnica del teorema centrale del limite
    corrisponda a quello atteso  

