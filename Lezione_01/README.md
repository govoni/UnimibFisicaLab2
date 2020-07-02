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

  * ogni programma da compilare deve contenere una ed una sola funzione chiamata ```main```, 
    che viene eseguita dal calcolatore quando il programma viene lanciato

