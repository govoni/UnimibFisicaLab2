# Lezione 1: ripasso di ```C``` ed introduzione al ```C++```

## 1.1 Introduzione

### 1.1.1 Linguaggio di programmazione e linguaggio macchina

  * le istruzioni che un calcolatore segue per eserguire i compiti assegnati 
    sono scritte in **linguaggio macchina**, 
    che non e' umanamente intelleggibile 
  * i **linguaggi di programmazione** sono gli strumenti di scrittura umana 
    delle istruzioni per il calcolatore
  * la **traduzione** delle istruzioni scritte in linguaggi di programmazione
    in istruzioni per il calcolatore e' effettuata da appositi programmi
  * l'**esecuzione** di un programma corrisponde al momento in cui il calcolatore 
    segue le istruzioni impartite

### 1.1.2 linguaggi intepretati o compilati

  * esistono **due grandi categorie** di linguaggi di programmazione:  

  | linguaggi interpretati |
  | -----------------------|

  * la traduzione del programma avviene automaticamente 
    **durante la sua esecuzione**
  * le istruzioni sono lette e tradotte riga per riga, 
    quindi spesso il programmatore puo' scrivere la riga successiva
    dopo aver osservato il risultato dell'istruzione precedente  
  * il programma e' in generale **lento**, 
    perche' la traduzione contestuale non e' ottimizzata
  * ```python``` e' un linguaggio di programmazione interpretato  

  | linguaggi compilati |
  | --------------------|

  * la traduzione del programma avviene prima della sua esecuzione,
    tramite l'invocazione di **istruzioni specifiche di compilazione**
  * il programma va concepito nella sua interezza prima dell'esecuzione
  * le istruzioni vengono eseguite **velocemente**  
  * ```C``` e ```C++``` sono esempi di linguaggi di programmazione compilati

### ```C``` e ```C++```

  * ```C``` e' un linguaggio di programmazione:
    * **imperativo**, cioe' che impartisce sequenze di istruzioni al calolatore
    * **procedurale**, cioe' che permette di raggruppare istruzioni in procedure
  * ```C++``` e' un linguaggio di programmazione:
    * che **estende il ```C```**: 
      * un programma ```C``` compila anche in ```C++```
      * la sintassi del ```C``` e' valida anche in ```C++```
      * esistono concetti nuovi nel ```C++```
      * esiste piu' liberta' nel ```C++```
    * **object oriented**, cioe' che permette di definire nuovi tipi di variabili
      all'interno dei programmi
      * vedremo che si tratta di un cambio di paradigma fondamentale
    * permette la **programmazione template**, 
      che e' una forma di generalizzazione delle istruzioni impartite al calcolatore
      * vedremo che porta alla creazione di molte librerie di utilita' generale
  * esistono diverse versioni del linguaggio ```C++```:
    **C++98** (che useremo noi), C++03, C++11 (che accenneremo), C++14, C++17


## 1.2 Un primo programma

### 1.2.1 Il codice sorgente

  * la sequenza di istruzioni scritte nel linguaggio di programmazione
    sono salvate in un file di testo, 
    che e' solitamente chiamato **codice sorgente**
  * gli **editor di testo** dedicati alla programmazione contengono strumenti
    specifici che permettono di evidenziare la sintassi del codice
    e talvolta controllarne la grammatica ed ortografia
  * oltre alle istruzioni, in un codice sorgente si possono inserire **commenti**,
    che sono frasi ignorate durante la compilazione
    * i commenti in ```C``` iniziano con ```/*``` e terminano con ```*/```:
    ```c
    \* questo e' un commento
    *\
    ```
  * ATTENZIONE: i simboli di apertura e chiusura di commenti **non funzionano come parentesi**
  * in ```C++``` i commenti possono anche iniziare con ```//```  
    e terminano automaticamente a fine riga:
    ```cpp
    // questo e' un commento
    ```

### 1.2.1 Uno scheletro vuoto

  * ogni programma da compilare deve contenere una ed una sola **funzione chiamata ```main```**, 
    che viene eseguita dal calcolatore quando il programma viene lanciato
  * esistono due versioni della funzione ```main```
    * una **senza argomenti** e corrisponde al caso in cui il programma sia eseguito da SHELL senza argomenti 
    ```cpp
    int main ()
      {
        return 0 ;
      }
    ```
    * una **con argomenti in ingresso**, che corrispondono alla frase scritta a linea di comando
      per lanciare il programma
    ```cpp
    int main (int arcg, char ** argv)
      {
        return 0 ;
      }
    ```
  * entrambe le versioni del programma funzionano ed entrambe le funzioni ```main``` restituiscono alla SHELL
    un numro intero, chiamato **exit status**
    * solitamente e' ```0``` se tutto e' andato bene, 
      mentre e' un numero non nullo se ci sono stati problemi durante l'esecuzione
      (esistono codici di errori codificati, 
       tuttavia il programmatore ha la liberta' di aggiungerne o cambiarli)
  
  | suggerimenti |
  | -------------|
  
  * nello scrivere un programma, ogni volta che si apre una parentesi graffa **chiuderla immediatamente**,
    per non dimenticarlo
  * non dimenticate le variabili di ritorno delle funzioni, ```main``` incluso  

### 1.2.2 La prima compilazione

  * il codice sorgente appena creato va **compilato** perche' possa essere eseguito dal calcolatore
  * si consiglia di svolgere tutti gli esercizi presentati in ogni lezione in una cartella dedicata, 
    quindi, dopo aver aperto una SHELL:
    ```
    mkdir Lab2_Modulo1
    cd Lab2_Modulo1
    mkdir Lezione_01
    cd Lezione_01
    touch main_00.cpp
    ```
    * il comando ```touch``` crea un file vuoto, in questo caso con nome ```main.cpp```
  * aprite ```main.cpp``` con il vostro editor preferito e scriveteci il programma da eseguire, 
    quindi salvate il programma
  * per compilare il programma si utilizza il comando ```c++```, chiamato **compilatore**:
    ```
    c++ -o main_00 main_00.cpp
    ```
    * l'argomento ```-o main_00``` dice al copilatore di chiamare l'eseguibile con il nome ```main_00```
    * per eseguire il programma:
    ```
    ./main_00
    ```
    * non succede nulla: non ci sono istruzioni all'interno della funzione ```main```!
    * l'istruzione ```return 0``` non dice di scrivere a schermo ```0```, 
      ma di restituire alla SHELL il valore ```0```    

  | suggerimenti |
  | -------------|
  
  * includete sempre all'inizio del codice sorgente un commento 
    che contenga il comando di compilazione del programma
    
### 1.2.2 Scrivere a schermo

  * oltre ai comandi fondamentali disponibili di default,
    insiemi di istruzioni dedicati allo svolgimento di determinati compiti
    sono **incapsulate in librerie**
  * bisogna dichiarare al programma che si vuole utilizzarle
  * per scrivere a schermo, 
    si utilizza la che gestisce il flusso (stream) di informazione in input (i) ed output (o) 
    durante l'esecuzione del programma: ```iostream```
    ```cpp
    #include <iostream>

    int main (int arcg, char ** argv)
      {
        std::cout << "42" << std::endl ;
        return 0 ;
      }
    ```
    * la linea ```#include <iostream>``` dice al compilatore di utilizzare la libreria ```iostream```
        * il compilatore sa dove trovare le librerie standard tramite variabili di ambiente della SHELL
    * la variabile ```cout``` (see-out) rappresenta lo strumento di output; 
      in questo caso, essendo quello standard (```std::```) si tratta dello schermo
    * la variabile ```endl``` e' la fine della linea, essendo quella standard e' un accapo
    * il simbolo ```<<``` rappresenta l'operatore di redirezione,
      che sposta quello che sta alla propria destra verso sinistra. 
      Quindi in questo caso prima ```endl``` viene incollato a ```42```,
      quindi l'insieme dei due viene inviato allo schermo.
  * l'esecuzione del programma visualizzera' a schermo ```42```:
    ```
    > c++ -o main_01 main_01.cpp
    > ./main_01 
    42
    ```

### 1.2.2 Il lavoro del compilatore

  * La compilazione di un programma di divide in tre fasi

  | preprocessing |
  | --------------|

  * **creazione del programma** da compilare:
    * vengono eseguite le direttive al preprocessore, che iniziano con il simbolo ```#```
    * ad esempio, l'istruzione ```#include <iostream>``` chiede al preprocessore
      di copiare al posto della linea stessa tutto il codice sorgente 
      contenuto nella libreria ```iostream```

  | compilazione |
  | -------------|

  * il compilatore vero e prorio entra in azione in questo stadio
  * controllo sintattico del programma
    * ad esempio, ```itn``` invece di ```int``` da' errore
  * controllo grammaticale del programma
  * traduzione del codice sorgente in linguaggio macchina
  * ogni funzione, creata in lunguaggio macchina, diventa un **oggetto del compilatore**

  | linking |
  | --------|

  * in questo ultimo passaggio, vengono connessi i vari oggetti del compilatore
  * nel nostro esempio, la parte pre-compilata delle librerie viene debitamente connessa 
    alle chiamate presenti nella funzione ```main```
  * NOTA BENE: gli oggetti del compilatore **non** hanno a che fare con la programmazione ad oggetti,
    si tratta di uno sfortunato caso di omonimia  

### 1.2.3 Parametri passati a linea di comando

  * si possono passare informazioni al programma aggiungendo parametri a linea di comando
  * la SHELL passa alla funzione ```main``` la frase scritta dall'utente, 
    sotto forma di ```array``` di stringhe di tipo ```C```
    * ```argc``` e' il numero di elementi dell'```array```
    * ```argv``` e' l'array stesso
    ```cpp
    #include <iostream>

    int main (int arcg, char ** argv)
      {
        std::cout << "42" << std::endl ;
        std::cout << "ecco il nome dell'eseguibile: " << argv[0] << "\n" ;
        return 0 ;
      }
    ```

### 1.2.3 Parametri chiesti all'utente del programma

  * la liberia ```<iostream>``` puo' essere anche utilizzata per leggere informazioni dalla tastiera
    ```cpp
    #include <iostream>

    int main (int arcg, char ** argv)
      {
        int numero = 0 ;
        std::cout << "inserisci un numero\n" ;
        std::cin >> numero ;
        std::cout << "hai inserito: " << numero << "\n" ;
        return 0 ;
      }
    ```
    * la tastiera e' identificata da ```std::cin```
    * l'operatore ```>>``` trasferisce l'informazione dall'esterno verso il programma:
    ```
    > ./main_03 
    inserisci un numero
    4 
    hai inserito: 4
    ```

## 1.2 le variabili 

### 1.2.1 i tipi di default

### 1.2.2 il casting fra diversi tipi

## 1.3 gli operatori

### 1.3.1 operatori relazionali

### 1.3.2 operatori logici

### 1.3.3 le precedenze fra operatori

## 1.4 le strutture di controllo

### 1.4.1 if ... then ... else

### 1.4.2 switch 

### 1.4.3 for 

### 1.4.4 while

## 1.5 funzioni matematiche

## 1.6 accesso all'orologio del computer

## 1.7 direttive al preprocessore

### 1.7 le trappole nell'uso delle macro 
http://www.programmiamo.altervista.org/C/funzioni/funz14.html

## 1.8 le funzioni

### 1.8.1 il prototipo di una funzione e la sua implementazione

### 1.8.2 la divisione in file separati

## 1.9 flag di compilazione




