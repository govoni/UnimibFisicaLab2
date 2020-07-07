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

![linea](immagini/linea.png)

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

![linea](immagini/linea.png)

### 1.1.3 ```C``` e ```C++```

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

![linea](immagini/linea.png)

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

![linea](immagini/linea.png)

### 1.2.2 Uno scheletro vuoto

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

![linea](immagini/linea.png)

### 1.2.3 La prima compilazione

  * il codice sorgente appena creato va **compilato** perche' possa essere eseguito dal calcolatore
  * si consiglia di svolgere tutti gli esercizi presentati in ogni lezione in una cartella dedicata, 
    quindi, dopo aver aperto una SHELL:
    ```
    > mkdir Lab2_Modulo1
    > cd Lab2_Modulo1
    > mkdir Lezione_01
    > cd Lezione_01
    > touch main_00.cpp
    ```
    * il comando ```touch``` crea un file vuoto, in questo caso con nome ```main.cpp```
  * aprite ```main.cpp``` con il vostro editor preferito e scriveteci il programma da eseguire, 
    quindi salvate il programma
  * per compilare il programma si utilizza il comando ```c++```, chiamato **compilatore**:
    ```
    > c++ -o main_00 main_00.cpp
    ```
    * l'argomento ```-o main_00``` dice al copilatore di chiamare l'eseguibile con il nome ```main_00```
    * per eseguire il programma:
    ```
    > ./main_00
    ```
    * non succede nulla: non ci sono istruzioni all'interno della funzione ```main```!
    * l'istruzione ```return 0``` non dice di scrivere a schermo ```0```, 
      ma di restituire alla SHELL il valore ```0```    

  | suggerimenti |
  | -------------|
  
  * includete sempre all'inizio del codice sorgente un commento 
    che contenga il **comando di compilazione** del programma

![linea](immagini/linea.png)
    
### 1.2.4 Scrivere a schermo

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

![linea](immagini/linea.png)

### 1.2.5 Il lavoro del compilatore

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

  * in questo ultimo passaggio, vengono **connessi i vari oggetti del compilatore**
  * nel nostro esempio, la parte pre-compilata delle librerie viene debitamente connessa 
    alle chiamate presenti nella funzione ```main```
  * NOTA BENE: gli oggetti del compilatore **non** hanno a che fare con la programmazione ad oggetti,
    si tratta di uno sfortunato caso di omonimia  

![linea](immagini/linea.png)

### 1.2.6 Parametri passati a linea di comando

  * si possono passare informazioni al programma aggiungendo **parametri a linea di comando**
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

![linea](immagini/linea.png)

### 1.2.7 Parametri chiesti all'utente del programma

  * la liberia ```<iostream>``` puo' essere anche utilizzata per **leggere informazioni dalla tastiera**
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

![linea](immagini/linea.png)

## 1.3 le variabili 

  * le informazioni sono manipolate dal programma sotto forma di **variabili**
  * **diversi tipi di oggetti** hanno tipicamente bisogno di dimenioni differenti di memoria
    e di un formato diverso di scrittura
  * per ogni differente possibilita' esiste un **tipo associato in ```C++```**,
    che contiene le informazioni di lunghezza e formattazione
  * i principali tipi sono i seguenti:
  
  | tipo                            | Keyword | contenuto  |
  | ------------------------------- | ------- | ---------- |
  | Boolean                         | bool    | vero/falso |     
  | Character                       | char    | singoli caratteri |
  | Integer                         | int     | numeri interi fra -32768 fino a 32767 |
  | Floating point (virgola mobile) | float   | numeri razionali | 
  | Double floating point           | double  | numeri razionali |
  | Valueless                       | void    | nessun tipo |

![linea](immagini/linea.png)

## 1.3.1 la loro inizializzazione 

  * le variabili si inizializzano utilizzando le keyword indicate in tabella:
    ```cpp
    // definizione di due numeri interi
    int num1 = 0 ;
    int num2 = 3 ;
    // somma di due numeri interi
    int somma = num1 + num2 ; 
    std::cout << "Somma: " << somma << std::endl ; 
    // definizione di due numeri razionali
    float razionale1 = 3.1416 ;
    double razionale2 = 1.4142 ; 
    // definizione di un carattere
    char lettera = 'a' ;
    // definizione di un valore booleano
    bool condizione = true ;
    ```
    * NOTA BENE: le variabili di tipo ```char``` sono definite con valori indicati fra apici, non fra virgolette   

  | suggerimenti |
  | -------------|
  
  * non appena una variabile viene definita, **assegnare sempre un valore** ad essa
    * che possa essere un buon **valore di default** nei calcoli a seguire, oppure
    * che **non** possa avere senso nel programma, in modo da rendersi conto subito 
      nel caso in cui la variabile non assuma i valori che dovrebbe
  * definire **una variabile per riga**, per chiarezza di lettura
  * dare **nomi lunghi ed esplicativi** alle variabili    

![linea](immagini/linea.png)

### 1.3.2 l'attributo ```const```

  * l'attributo ```const``` premesso ad una variabile indica che essa **non puo' cambiare di valore**
    durante l'esecuzione del programma.
  * se si prova a modificare una variabile dichiarata ```const```,
    il compilatore si accorge di questo errore di grammatica di programmazione
    e **non compila**, restituendo un errore:  
    ```    
    > c++ -o main_05 main_05.cpp
    main_05.cpp:10:12: error: cannot assign to variable 'numero' with const-qualified type 'const int'
        numero = numero + 1 ;
        ~~~~~~ ^
    main_05.cpp:9:15: note: variable 'numero' declared const here
        const int numero = 0 ;
        ~~~~~~~~~~^~~~~~~~~~
    1 error generated.
    ```

![linea](immagini/linea.png)

### 1.3.3 gli array di variabili

  * ad una variabile e' associata una **zona di memoria** nella RAM,
    dove il calcolatore la scrive durante le operazioni
  * in ```C++``` e' possibile definire una zona di memoria estesa,
    chiamata **array**,
    predisposta a contenere un **elenco di variabili dello stesso tipo**
    giustapposte in celle di memoria contigue
    ```cpp
    // array di 5 numeri interi
    int num_array[5] ;
    ```
      * la dimensione dell'array, 
        indicata fra parentesi nella definizione della variabile,
        non puo' essere una variabile (nemmeno ```const```),
        **deve essere un numero scritto nel codice sorgente**
  * **le singole celle di memoria** sono accessibili 
    tramite l'operatore ```operator[]``` applicato al nome della variabile,
    che si scrive utilizzando le parentesi quadre
    come nell'esempio che segue:
    ```cpp
    num_array[0] = 3 ;
    num_array[1] = 6 ;
    num_array[2] = 9 ;
    num_array[3] = 11 ;
    num_array[4] = 131 ;
    ```

![linea](immagini/linea.png)

### 1.3.4 gli indici degli array

  * gli indici delle celle di memoria di un array lungo N **partono a 0 e finiscono ad N-1**
  * il compilatore **non sempre si accorge** che gli indici siano in questo intervallo
  * qualunque tentativo di leggere una zona di memoria all'esterno di questo intervallo
    puo' produrre un errore in fase di compilazione,
    oppure un comportamento inatteso del programma
    ```cpp
    int index = 4 ;
    std::cout << num_array[index + 1] << std::endl ;
    ```
  * NOTA BENE: si tratta di errori difficili da trovare, 
    bisogna prestare molta attenzione agli indici di lettura degli array

![linea](immagini/linea.png)

### 1.3.5 il casting fra diversi tipi

  * il casting in ```C``` e' la **conversione fra diversi tipi di variabili numeriche**
  * siccome le medesime operazioni fra tipi diversi possono dare risultati differenti
    (provate a calcolare il valore della frazione 3/5
     come rapporto fra due variabili ```int``` o come rapporto fra due variabili ```float```),
    e' importante sapere **come convertire variabili in maniera esplicita**,
    utilizzando la sintassi ```(type) numero``` per convertire la variabile ```numero```
    nel tipo ```type```:
    ```cpp
    int numero_intero = 4 ;
    float numero_razionale = (float) numero_intero ;
    ```

![linea](immagini/linea.png)

### 1.3.6 il casting in ```C++```

  * in ```C++``` l'operazione di casting ha portata piu' ampia
    e puo' essere realizzato con operatori dedicati:
    ```cpp
    float secondo_razionale = static_cast<float> (numero_intero) ;
    ```

![linea](immagini/linea.png)

## 1.4 gli operatori

  * Gli operatori predefiniti in ```C++``` permettono di compiere **operazioni fra variabili**
  * **Per ogni tipo di variabile**, esistono operatori corrispondenti alle operazioni 
    che si possono fare fra queste variabili
  * gli operatori si comportano **alla stregua di funzioni**, con variabili in ingresso
    e variabili di ritorno
  * tipicamente un operatore agisce su un singolo di tipo, 
    quindi l'applicazione di operatori a piu' di un tipo 
    implica un **casting implicito** fatto dal compilatore  

![linea](immagini/linea.png)

### 1.4.1 l'operatore di assegnazione

  * attribuiscono il valore iniziale ad una variabile:
    ```cpp
    int numero = 5 ;
    ```
    * in questo caso, il tipo in ingresso e' un ```int``` 
      (la variabile stessa e' una sorta di argomento implicito dell'operatore)
    * l'effetto dell'operatore e' quello di assegnare alla variabile ```numero``` il valore 
      che sta a destra del simbolo ```=```
    * il tipo in uscita e' ancora ```int``` ed e' il valore assegnato alla variabile  
    ```cpp
    std::cout << (numero = 7) << std::endl ;
    ```
    * di conseguenza, le assegnazioni si possono fare in cascata:
    ```cpp
    int numero_2 = numero = 7 ;
    ```
  * anche per l'operatore di assegnazione accade casting implicito:
    ```cpp
    float razionale = 5 ;
    ```
    * ```5``` e' di tipo ```int```, quindi viene prima convertito in ```float``` (```5.```)
      e poi passato come argomento all'operatore di assegnazione

![linea](immagini/linea.png)

### 1.4.2 operatori aritmetici

  * corrispondono alle **tipiche operazioni matematiche** fra numeri interi o razionali
    ```cpp
    float R1 = 5. ;
    float R2 = 5. ;
    float R3 = R1 + R2 ;
    std::cout << R3 << std::endl ;
    R3 = R3 + 4.5 ;
    std::cout << R3 << std::endl ;
    ```

![linea](immagini/linea.png)

### 1.4.3 operatori aritmetici composti con assegnazione

  * gli operatori aritmetici esistono anche **composti con l'operatore di assegnazione**
    ```cpp
    R3 += 2.1 ;
    std::cout << R3 << std::endl ;
    ```

    | operatore | op. composto | operazione |
    | --- | --- | --- |
    | ```+``` | ``` += ``` | addizione |
    | ```-``` | ``` -= ``` | sottrazione |
    | ```*``` | ``` *= ``` | moltiplicazione |
    | ```/``` | ``` /= ``` | divisione |
    | ```%``` | ``` %= ``` | resto della divisione tra interi |

![linea](immagini/linea.png)

### 1.4.4 operatori di incremento

  * **L'incremento o decremento unitario** di una variabile si puo' ottenere 
    anche con operaori dedicati:

    | operatore | operazione |
    | --- |  --- |
    | ```++``` | incremento unitario |
    | ```--``` | decremento unitario |

  * l'operatore agisce direttamente sulla variabile al quale viene applicato,
    similmente agli operatori composti:
    ```cpp
    int num = 5 ;
    ++num ;
    std::cout << num << std::endl ;
    --num ;
    std::cout << num << std::endl ;
    ```

![linea](immagini/linea.png)

### 1.4.5 pre-incremento e post-incremento

  * ciascun operatore esiste in due versioni:
    * **pre-incremento** o **pre-decremento**: la variabile a cui viene applicato 
      viene modificata dall'operatore **prima** dell'esecuzione di eventuali altre operazioni
      che accadono in quella linea (```++num```, ```--num```), 
      quindi l'operatore restituisce la variabile stessa
    * **post-incremento** o **post-decremento**: la variabile a cui viene applicato 
      viene modificata dall'operatore **dopo** dell'esecuzione di eventuali altre operazioni
      che accadono in quella linea (```num++```, ```num--```)
    ```cpp
    int num1 = 5 ;
    std::cout << ++num1 << std::endl ;
    int num2 = 5 ;
    std::cout << num2++ << std::endl ;
    std::cout << num2 << std::endl ;
    ```
    * gli operatori di post-incremento e post-decremento **creano una copia** della variabile
      alla quale sono applicati, incrementano la variabile e restituiscono la copia
      (che non e' stata incrementata)
    * di conseguenza, gli operatori di post-incremento e post-decremento **sono piu' lenti** 
      di quelli di pre-incremento e pre-decremento
      e richiedono che **sia possibile creare una copia** della variabile alla quale sono applicati
  * gli operatori di incremento vengono tipicamente utilizzati per aumentare o diminuire
    il valore delle variabili indice dei cicli

![linea](immagini/linea.png)

### 1.4.6 operatori relationali

  * gli operatori relazionali confrontano i valodi di variabili
  * prendono in ingresso due variabili e restituiscono un valore booleano

    | operatore | operazione |
    | --- |  --- |
    | ```==``` | uguaglianza |
    | ```!=``` | non uguaglianza |
    | ```<```  | minore di |
    | ```<=``` | minore o uguale |
    | ```>```  | maggiore di |
    | ```>=``` | maggiore o uguale |

  * NOTA BENE: l'operatore di uguaglianza ha **due segni ```=```** nel nome,
    perche' l'operatore con un solo ```=``` assegna il valore di destra alla varibile di sinistra.
    questa e' una frequente sorgente di errori 

![linea](immagini/linea.png)

### 1.4.7 operatori logici

  * gli operatori logici codifcano le relazioni fra variabili booleane:
    | operatore | operazione |
    | --- |  --- |
    | ```&&``` | and |
    | ```\|\|``` | or  |
    | ```!```  | not |
  * NOTA BENE: spesso accade casting implicito fra variabili intere e booleane:
    in questo caso, lo ```0``` risulta falso,
    mentre ogni altro valore intero risulta vero

![linea](immagini/linea.png)

### 1.4.8 le precedenze fra operatori

  * se in una singola linea di un codice sorgente vengono effettuate diverse istruzioni,
    il calcolatore le esegue da destra verso sinistra, 
    rispettando l'ordine imposto da eventuali parentesi
    e una serie di regole di precedenza
  * la lista completa delle precedenze si trova [qui](https://en.cppreference.com/w/cpp/language/operator_precedence)  
  * ad esempio, nella tabella che segue,
    gli operatori nelle celle in alto hanno precedenza rispetto a quelli sotto

  | categorie di priorita' |
  | -------------| 
  |  ```a++```, ```a[]```  |
  |  ```++a```, ```!```  |
  |  ```a*b```, ```a/b```, ```a%b```  |
  |  ```a+b```, ```a-b``` |
  |  ```<```, ```<=```, ```>```, ```>=``` |
  |  ```==```, ```!=``` |
  |  ```&&``` |
  |  ```||``` |
  |  ```=```, ```+=```, ```-=```, ```*=```, ```/=```, ```%=``` |
    
![linea](immagini/linea.png)

## 1.5 le strutture di controllo

  * Le strutture di controllo sono il metodo che si utilizza nei linguaggi di programmazione procedurali
    per **gestire il flusso di istruzioni** che il calcolatore deve eseguire.
    Esistono tre tipi di strutture di controllo:
    * **sequenza**: si tratta della configurazione di default: 
      le istruzioni si susseguono una dopo l'altra
    * **selezione**: a seconda che una condizione sia o meno soddisfatta,
      il calcolatore sceglie di eseguire diverse istruzioni
    * **ciclo**: un insieme di istruzioni viene ripetuto un certo numero di volte,
      in funzione di un algoritmo che decide quando l'iterazione e' terminata  

  ![strutture](immagini/strutture.png)

![linea](immagini/linea.png)

### 1.5.1 gli scope

  * nel codice sorgente diverse istruzioni vengono raggruppate in insiemi chiamati **scope**,
    delimitati da parentesi graffe
  * le **variabili** definite all'interno di uno scope 
    rimangono definite solamente fino alla chiusura dello scope
    e vengono automaticamente rimosse alla chiusura della parentesi graffa
  * singole istruzioni all'interno di una struttura di controllo
    possono essere sostituite da un intero scope  

![linea](immagini/linea.png)

### 1.5.2 ```if ... else```

  * la sequenza ```if (condizione) {scope} else {scope alternativo}``` realizza una selezione binaria,
    nella quale una istruzione o uno scope di istruzioni vengono eseguiti 
    nel caso in cui venga **soddisfatta una condizione booleana**
  * opzionalmente, uno **scope alternativo** puo' essere eseguito 
    nel caso in cui la condizione risulti falsa
    ```cpp
    int num1 = 5 ;
    if (num1 % 2 == 0) 
      {
        std::cout << num1 << " e' pari\n" ;
      }
    else  
      {
        std::cout << num1 << " e' dispari\n" ;
      }
    ```

![linea](immagini/linea.png)

### 1.5.3 switch 

  * la sequenza ```switch ... case ... default``` realizza una selezione fra molte opzioni,
    basata sul valore di una variabile:
    ```cpp
    int num2 = 2 ;
    switch (num2) {
      case 1:
        // blocco di istruzioni
        std::cout << "uno\n" ;
        break;
      case 2:
        // blocco di istruzioni
        std::cout << "due\n" ;
        break;
      default:
        std::cout << "altri numeri\n" ;
        // blocco di istruzioni
    }
    ```
  * nella struttura di controllo ```switch (espressione)```
    vengono eseguite le istruzioni che stanno sotto la linea ```case``` 
    tale per cui **```espressione``` e' uguale al valore riportato 
    dopo la parola chiave ```case```**
  * per evitare che vengano eseguite anche le istruzioni riportate dopo i ```case``` sequenti,
    solitamente si inserisce in ogni blocco di istruzioni il comando **```break```**,
    che interrompe l'esecuzione dello scope
    * la situazione in cui le istruzioni eseguite non siano soltanto quelle 
      del ```case``` corrispondente al valore di ```espressione```
      prende il nome di **fallthrough**
    * il comando ```break``` puo' essere utilizzato anche per **interrompere l'esecusione di un ciclo**
    * la presenza di un ```break``` **non e' obbligatoria** 
  * oltre ai vari ```case```, 
    si puo' aggiungere un ulteriore caso, 
    che contiene istruzioni da svolgere nell'evenienza in cui nessuno dei ```case```
    venga soddisfatto, 
    che viene etichettato con la parola chiave **```default```**
    * il caso di ```default``` **non e' obbligatorio**

![linea](immagini/linea.png)

### 1.5.4 il ciclo ```for```

  * la struttura di controllo ```for ()``` 
    e' un modo di implmentare la struttura di controllo a ciclo,
    tipicamente nel caso in cui al ciclo sia **associato un conteggio**
  * nella parentesi che segue il comando ```for``` sono solitamente riportate tre istruzioni,
    separati da un punto e virgola:
    * **inizializzazione**: dove viene inizializzata (e talvolta definita) 
      una variabile che conta il numero di cicli, detta contatore
    * **controllo**: dove si verifica se il numero di cicli abbia oltrepassato una determinata soglia
    * **incremento**: dove si incrementa il contatore
    ```cpp
    int N = 10 ;
    for (int i = 0 ; i < N ; ++i)
      {
        std::cout << "il doppio di " << i << " vale: " << 2 * i << std::endl ;
      }
    ```
    * **le variabili** definite fra parentesi rimangono definite soltanto all'interno
      dello scope del ciclo
    * l'operazione di controllo viene compiuta **prima** di effettuare nell'iterazione corrispondente  
    * l'operazione di incremento viene compiuta **dopo** che e' stata effettuata l'iterazione corrispondente
  * c'e' **molta liberta'** nella scrittura di un ciclo ```for```:
    i tre campi fra parentesi possono anche essere vuoti ed il programma compila 
    * utilizzare una scrittura non ortodossa del ciclo ```for```
      puo' portare al errori logici nel programma,
      che possono portare a risultati inaffidabili in fase di esecuzione

![linea](immagini/linea.png)

### 1.5.5 il ciclo ```while```

  * la struttura di controllo ```while ()``` 
    e' un modo di implmentare la struttura di controllo a ciclo,
    tipicamente nel caso in cui si voglia continuare il ciclo 
    fintanto che una **condizione risulta vera**
  * nella parentesi che segue l'istruzione ```while```
    deve trovare luogo un'affermazione da verificare; 
    se l'affermazione e' vera, lo scope del ciclo viene effettuato
    ```cpp
    int N = 10 ;
    int i = 0 ;
    while (i < N)
      {
        std::cout << "il doppio di " << i << " vale: " << 2 * i << std::endl ;
        ++i ;
      }
    ```
    * il controllo viene effettuato **prima** dell'esecuzione dell'iterazione corrispondente
    * se il **campo fra parentesi e' vuoto**, il ciclo avviene e continua indefinitamente; 
      va quindi interrotto con il comando ```break```
    * questo permette di distribuire all'interno dello scope del ciclo diversi controlli,
      aumentando considerevolmente il rischio che il ciclo non termini mai  
  * talvolta conviene che la condizione di proseguimento del ciclo 
    venga controllata **dopo l'esecuzione di ogni iterazione**
    (ad esempio quando, prima della prima iterazione, non ha senso effettuare il controllo)
  * per ottenere questo comportamento, 
    si utilizza la sintassi ``` do { ... } while ()```   
    ```cpp
    do
      {
        std::cout << "il doppio di " << i << " vale: " << 2 * i << std::endl ;
        ++i ;
      }
    while (i < 2 * N) ;
    ```
 
 ![linea](immagini/linea.png)
 
## 1.5.6 l'interruzione di un ciclo

  * oltre a sfruttare la condizione controllata da un ciclo,
    **la sua esecuzione puo' essere interrotta** con due comandi:
  * l'istruzione ```break``` interrompe l'esecuzione dell'iterazione ed esce dal ciclo
  * l'istruzione ```continue``` interrompe l'esecuzione dell'iterazione 
    e passa a quella successiva

![linea](immagini/linea.png)
 
## 1.6 le funzioni

  * insiemi di istruzioni che svolgono un **compito preciso e spesso ripetuto** 
    all'interno di uno o piu' programmi 
    vengono solitamente raggruppate in funzioni,
    che si utilizzano come un singolo comando
  * le funzioni hanno un nome, una o piu' variabili in ingresso 
    e restituiscono una sola variabile,
    con il comando ```return```

![linea](immagini/linea.png)
 
## 1.6.1 un primo esempio

  * le funzioni vanno **definite prima di essere chiamate**
    ```cpp
    int raddoppia (int input_value) 
      {
        return 2 * input_value ;
      }
    
    int main (int arcg, char ** argv)
      {
      
        for (int i = 0 ; i < 5 ; ++i)
          {
            std::cout << "il doppio di " << i << " vale: " << raddoppia (i) << std::endl ;
          }
        return 0 ;
      }
    ```

![linea](immagini/linea.png)
 
## 1.6.2 funzioni senza tipo di ritorno

  * una funzione che non restituisce alcun valore si definisce 
    con la parola chiave ```void``` come tipo di ritorno
    ed al suo interno l'istruzione ```return``` e' immediatamente seguita da una virgola
    ```cpp
    int raddoppia (int input_value) 
      {
        return 2 * input_value ;
      }

    void scriviAschermo (int input_value) 
      {
        std::cout << "ecco il numero da scrivere: " << input_value << std::endl ;
        return ;
      }

    int main (int arcg, char ** argv)
      {
          for (int i = 0 ; i < 5 ; ++i)
          {
            scriviAschermo (raddoppia (i)) ;
          }

        return 0 ;
      }
    ```

![linea](immagini/linea.png)
 
## 1.6.3 funzoni ed omonimia

  * il nome di una funzione, insieme ai suoi tipi in ingresso,
    la **identifica univocamente**, dunque non possono esistere due funzioni
    diverse con lo stesso nome e gli stessi tipi in ingresso
    nello stesso programma
    * funzioni con lo stesso nome, ma con tipi in ingresso diversi, possono coesistere
      ```cpp
      int raddoppia (int input_value) 
        {
          return 2 * input_value ;
        }
      
      float raddoppia (float input_value) 
        {
          return 2 * input_value ;
        }
      ```

![linea](immagini/linea.png)

### 1.6.4 il prototipo di una funzione e la sua implementazione

  * definire una funzione prima di essere chiamata
    e' necessario per **permettere il controllo grammaticale** del codice sorgente 
    da parte del compilatore
  * per effettuare il controllo grammaticale, 
    al compilatore e' **sufficiente** conoscere il nome della funzione,
    la variabili in ingresso e quelle in uscita
  * e' quindi lecito anticipare questa informazione sotto forma di **prototipo**,
    posticipando la scrittura dell'implementazione della funzione:
    ```cpp
    int raddoppia (int) ;
    
    int main (int arcg, char ** argv)
      {
      
        for (int i = 0 ; i < 5 ; ++i)
          {
            std::cout << "il doppio di " << i << " vale: " << raddoppia (i) << std::endl ;
          }
        return 0 ;
      }
    
    int raddoppia (int input_value) 
      {
        return 2 * input_value ;
      }
    ```
    * cio' permette di lasciare piu' in evidenza la funzione ```main``` rispetto alle altre
    * nella scrittura del prototipo, **non e' necessario** indicare il nome delle variabili
      (ma e' permesso)

![linea](immagini/linea.png)

### 1.6.5 valori di default degli argomenti di una funzione

  * nel prototipo, oppure nell'implementazione, si possono assegnare **valori di default** alle variabili,
    che corrispondono al valore utilizzato dalla funzione per quella variabile
    nel caso in cui il valore non venga passato
    ```cpp
    int raddoppia (int input_value = 0) 
      {
        return 2 * input_value ;
      }
    ```
    * il valore di default deve essere attribuito solamente **in uno dei due luoghi**
    * in caso di **funzioni con piu' variabili in ingresso**, 
      se ad una variabile viene assegnato un valore di default
      anche le variabili seguenti devono possederlo, 
      per evitare situazioni di ambiguita'

![linea](immagini/linea.png)

### 1.6.6 l'esportazione delle funzioni in librerie

  * funzioni che vengono utilizzate in piu' di un programma ```main``` 
    possono essere **scritte in un file diverso**,
    in modo che non sia necessario riscriverle ogni volta
  * ogni funzione, dopo essere stata compilata, diventa un **oggetto del compilatore**
  * dopo la compilazione, il **linker** (che e' il terzo passaggio della compilazione)
    connette le varie funzioni per costruire l'eseguibile finale
  * per permettere al compilatore di **controllare la grammatica** in fase di compilazione,
    e' sempre necessario mettere nel codice sorgente del ```main``` il prototipo delle funzioni
  * questa struttura viene realizzata tipicamente con tre file: 
    ```libreria.h```, ```libreria.cc```, ```main.cpp```

![linea](immagini/linea.png)

### 1.6.7 il file ```libreria.h```

  * ```libreria.h```: e' il file che contiene il codice sorgente dei prototipi delle altre funzioni
    ```cpp
    #ifndef libreria_h
    #define libreria_h
    
    int raddoppia (int) ;
    
    #endif
    ```
     * le linee che iniziano con ```#``` sono istruzioni al preprocessore,
       si tratta del controllo di una condizione:
       se non e' definita una variabile (```#ifndef```) con il nome ```libreria_h```,
       si considera tutto quello che segue fino ad ```#endif```
     * questo permette di non definire due volte il prototipo di una funzione,
       che genererebbe un errore di compilazione  

![linea](immagini/linea.png)

### 1.6.8 il file ```libreria.cc```

  * ```libreria.cc```: e' il file che contiene il codice sorgente delle altre funzioni
    ```cpp
    #include "libreria.h"      
    
    int raddoppia (int input_value) 
      {
        return 2 * input_value ;
      }
    ```
     * il codice sorgente include ```libreria.h```
       per ereditare tutte le definizioni e gli altri include
       che stanno al suo interno

![linea](immagini/linea.png)

### 1.6.9 il file ```main.cpp```

  * ```main.cpp```: e' il file che contiene il codice sorgente della funzione ```main```
    ```cpp
    #include <iostream>
    #include "libreria.h"
       
    int main (int arcg, char ** argv)
      {
      
        for (int i = 0 ; i < 5 ; ++i)
          {
            std::cout << "il doppio di " << i << " vale: " << raddoppia (i) << std::endl ;
          }
        return 0 ;
      }
    ```
     * il codice sorgente include ```libreria.h```
       per ereditare tutte le definizioni e gli altri include
       che stanno al suo interno
     * il file ```libreria.cc``` non viene mai incluso, 
       ma va indicato nel comando di compilazione:
       ```
       > c++ -o main_16 libreria.cc main_16.cpp
       ```  

![linea](immagini/linea.png)

### 1.6.10 librerie in ```C++```

  * si possono creare ed includere piu' di una libreria in un programma
  * le librerie di ```C++``` funzionano in questo modo,
    con i codici sorgente delle librerie spesso gia' compilati
    ed il file da includere indicato fra parentesi angolate, 
    come ad esempio ```#include <iostream>```

  | suggerimenti |
  | -------------|

  * e' utile **organizzare** le proprie librerie per funzionalita', 
    sia per strutturazione logica del proprio programma
    che per decidere che cosa includere e compilare in ogni programma
  * l'utilizzo di una funzione comporta **rallentamento** nel programma,
    perche' richiede al calcolatore di cercare in memoria la funzione
    di passarle gli argomenti e di recuperarne l'output,
    che sono operazioni aggiuntive

![linea](immagini/linea.png)

### 1.6.11 le funzioni ```inline```


  * si puo' utilizzare la parola chiave ```inline```,
    per funzioni piccole (in cui queste istruzioni aggiuntive richiedono tempo confrontabile
    rispetto all'esecuzione dello scope della funzione),
    che chiede al compilatore di **sostituire la funzione con la sua implementazione**  
    ```cpp
    #ifndef libreria_h
    #define libreria_h
    
    inline int raddoppia (int input_value) 
      {
        return 2 * input_value ;
      }
    
    #endif
    ```
    * in questo caso, la funzione va definita prima del ```main```, quindi **nel file ```.h```**
    * il compilatore puo' decidere di ignorare la parola chiave ```inline```

![linea](immagini/linea.png)

### 1.6.12 funzioni matematiche

  * la libreria ```cmath``` offre un'utile **estensione delle operazioni matematiche**
  * per poterla utilizzare, bisogna includerne il file ```.h``` (detto header) corrispondente: 
    ```#include <cmath>```
  * la libreria contiene funzioni e variabili notevoli
    * la lista delle funzioni notevoli si trova [qui](http://www.cplusplus.com/reference/cmath/), 
      contiene funzioni trigonometriche, funzioni di potenza, iperboliche...

![linea](immagini/linea.png)

### 1.6.13 un esempio: radice quadrata ed elevamento a potenza

  * un esempio di utilizzo delle funzioni presenti in ```cmath```
    riguarda **l'elevamento a potenza e la radice quadrata**:
    ```cpp
    float num = 4.5 ;
    std::cout << "quadrato di " << num << ": " << pow (num, 2) << "\n" ;
    num = pow (num, 2) ;
    std::cout << "radice di " << num << ": " << sqrt (num) << "\n" ;
    std::cout << "radice di " << num << ": " << pow (num, 0.5) << "\n" ;
    ```
  * la **funzione ```pow```** ha come primo argomento la base della potenza,
    come secondo argomento il suo esponente
  * utiilzzare l'espressione ```num * num``` invece di ```pow (num, 2)```  
    e' **meno dispendioso** in termini di tempo di esecuzione

![linea](immagini/linea.png)

### 1.6.14 accesso all'orologio del computer

  * un'altra libreria di uso frequente
    ```ctime```
  * l'istruzione ```clock ()``` restituisce il **tempo di calcolo** del processore
    consumato dal programma,
    espresso in cicli di calcolo
    * la **frequenza dei cicli di calcolo** e' disponibile nella variabile ```CLOCKS_PER_SEC```
  * l'istruzione ```ctime ()``` resituisce il **tempo trascorso** a partire dal primo gennaio 1970:

![linea](immagini/linea.png)

### 1.6.15 un test di performance

  * se volessimo **confrontare la velocita' di esecuzione** della funzione ```pow (x, 2)```
    rispetto all'operazione ```x * x``` potremmo ripetere entrambe le operazioni molte (```N```) volte
    e misurare il tempo di calcolo nei due casi:
    ```cpp
    double start = (double) clock () / CLOCKS_PER_SEC ; 
    for (double i = 0; i < N; ++i) 
      {
        test += pow (i, 2) ; 
      }
    double stop = (double) clock () / CLOCKS_PER_SEC ;
    std::cout << "tempo di esecuzione per pow: " << stop - start << " secondi\n" ;

    start = (double) clock () / CLOCKS_PER_SEC ; 
    for (double i = 0; i < N; ++i) 
      {
        test += i * i ; 
      }
    stop = (double) clock () / CLOCKS_PER_SEC ;
    std::cout << "tempo di esecuzione per i*i: " << stop - start << " secondi\n" ;
    ```
  * si otterrebbe un **risultato** di questo tipo:
  ```
tempo di esecuzione per pow: 30.2506 secondi
tempo di esecuzione per i*i: 3.91943 secondi
  ```  

![linea](immagini/linea.png)

## 1.8 direttive al preprocessore

  * L'insieme di istruzioni che iniziano con il simbolo ```#``` si chiamano
    **direttive al preprocessore** perche' vengono lette ed interpretate
    prima della fase di compilazione
  * si tratta di istruzioni che **non riguardano la fase di compilazione** del programma,
    quindi **macro e variabili del preprocessore sono concetti diversi**
    rispetto alle funzioni e variabili di ```C++```  

![linea](immagini/linea.png)

## 1.8.1 la direttiva ```#include```

  * come abbiamo gia' visto,
    questa istruzione viene utilizzata quando si scrivono **librerie di funzioni**
    in un file separato da quello che contiene il codice sorgente del ```main``` program
  * seguendo questa direttiva, 
    il preprocessore **sostituisce alla linea l'intero file** riportato dopo ```#include```

![linea](immagini/linea.png)

## 1.8.2 variabili del preprocessore

  * la direttiva ```#define``` **definisce variabili** del preprocessore
  * viene estensivamente utilizzata per impedire la doppia definizione del prototipo di una funzione
    e per impedire che si crei un circolo infinito di istruzioni ```#include```,
    unitamente al controllo booleano ```#ifndef``` (se non e' definita):
    ```cpp
    #ifndef libreria_h
    #define libreria_h
    
    int raddoppia (int) ;
    
    #endif
    ```
  * e' invalso nell'uso utilizzare ```#define``` anche in sostituzione di variabili del ```C++```
    ```cpp
    #define NUMERO 150
    ```
    * si tratta di una **cattiva pratica di programmazione**, 
      perche' puo' portare a comportamenti inattesi del codice (inclusi problemi di compilazione)
      e rende difficile la fattorizzazione del codice
    * in questo caso, ```NUMERO``` **non e' una variabile del ```C++```**,
      bensi' il preprocessore sostituisce il testo ```NUMERO``` con il testo ```100``` nel programma
      prima della compilazione
    * quando si utilizzano questi metodi poco ortodossi,
      e' buona regola utilizzare **prassi sintattiche che differenzino chiaramente**
      le effettive variabili del ```C++``` dalle sostituzioni di testo del preprocessore, 
      ad esempio scrivendone il nome interamente in caratteri maiuscoli    

![linea](immagini/linea.png)

### 1.8.3 le macro del preprocessore 

  * si possono anche definire **macro del preprocessore**,
    che sono espressioni che richiamano in forma il comportamento delle funzioni del ```C++```
    ```cpp
    #define quadrato(a) a*a
    ```
  * utilizzare le macro del processore come funzioni 
    **puo' produrre disastri**, questo programma:
    ```cpp
    int main (int argc, char ** argv)
      { 
        double numero = 3. ;
        double risposta = quadrato (numero + 1.) ;
      
        std::cout << "Il quadrato di " << numero + 1. 
                  << " vale " << risposta << "\n" ;
        return 0 ;
      }
    ```
    produce come output:
    ```
    Il quadrato di 4 vale 7
    ```

![linea](immagini/linea.png)

## 1.9 la scrittura del proprio programma

  * perche' un codice sorgente **compili**, 
    bisogna rispettare sintassi e grammatica del ```C++```
  * perche' un programma **funzioni**,
    bisogna evitare errori logici nell'uso del ```C++```
    e nella funzionalita' degli algoritmi
  * perche' un codice sorgente **sia leggibile**,
    e' buona cosa seguire regole aggiuntive di buon senso nella scrittura    

![linea](immagini/linea.png)

### 1.9.1 la nomenclatura di variabili e funzioni

  * scegliete nomi di funzioni e variabili **lunghi ed autoesplicativi**
  * scegliete nomi che riguardino il ruolo effettivo di variabili e funzioni:
    ad esempio, se una variabile o una funzione servono 
    nel programma per ottenere un determinato calcolo,
    ma abbiano funzionalita' piu' ampia,
    il loro nome deve **riflettere l'effettiva funzionalita'**
  * scegliete un **sistema consistente** di nomenclatura, ad esempio:
    * le funzioni iniziano con lettere minuscole, le variabili con lettere maiuscole
    * nei nomi compposti da piu' parole, si divide il nome con un ```_``` (e.g. ```calcola_media```),
      oppure rendendo maiuscola ogni parola all'interno (e.g. ```calcolaMedia```)

![linea](immagini/linea.png)

### 1.9.2 la dimensione degli scope

  * scegliete di scrivere **scope piccoli**: 
    se il numero di istruzioni in uno scope e' molto alto,
    spezzatelo in sotto-gruppi tramite funzioni
  * una **numero indicativo** di istruzioni oltre il quale pensare se spezzare lo scope
    in funzioni e' 7

![linea](immagini/linea.png)

### 1.9.3 utilizzare i commenti nel codice sorgente

  * molti commenti nel codice sorgente aiutano a **capire cosa facciano** funzioni e variabili,
    descrivendo il loro contenuto o la loro funzionalita'
  * i commenti possono essere utilizzati per chiarire **che cosa sta succedendo nel codice sorgente**
  * la **spiegazione di eventuali formule** utilizzate,
    oppure il **link a pagine web** di riferimento,
    possono essere inseriti nei commenti
  * nel caso di scope molto lunghi,
    per cui la chiusura di parentesi graffe non si vede insieme all'apertura,
    si possono usare commenti per ricordare al lettore
    **quale scope sia chiuso** da una graffa:
    ```cpp
    int main (int argc, char ** argv)
      { 
        for (int i1 = 0 ; i1 < 100 ; ++i1)
          {
            /* tante istruzioni che si susseguono */
          } // ciclo su i1
        return 0 ;
      }
    ```

![linea](immagini/linea.png)

### 1.9.4 l'indentazione del codice sorgente

  * indentare il codice coerentemente aiuta enormemente la lettura del codice sorgente
  * **tutte le istruzioni di uno stesso scope** devono inizare alla medesima colonna
  * quando si apre uno scope, 
    le istruzioni devono **inziare in posizione rientrata**
    rispetto allo scope precedente:
    **scegliete una regola** (ad es. 2 colonne) ed attenetevi rigorosamente a quella
    * imparate ad usare con cognizione di causa il tasto ```TAB```,
      oppure non utilizzatelo
  * decidete se **aprire le parentesi graffe** alla fine di una linea, 
    oppure dopo essere andati accapo
  * non chiudete parentesi graffe su una **linea in cui ci sono istruzioni**

![linea](immagini/linea.png)

### 1.9.5 la fattorizzazione di un programma

  * molto spesso **pezzi di codice sorgente vengono riciclati** copiandoli da programmi vecchi
    ed incollandoli in programmi nuovi
  * per facilitare questa operazione e per rendere il codice sorgente piu' comprensibile,
    e' buona norma mantenere il piu' vicino possible tutte le istruzioni relative
    ad un **medesimo blocco logico** del programma
    * definire le variabili **appena prima che vengano utilizzate**
      (cioe' NON tutte all'inizio del programma)
    * NON sparpagliare per il programma istruzioni che **logicamente si susseguono**


![linea](immagini/linea.png)

### 1.9.5 dettagli

  * il ```C++``` **distingue maiuscole da minuscole**, 
    quindi ```num``` e ```Num``` sono due variabili diverse
  * il ```C++``` **non riconosce caratteri speciali** come lettere accentate,
    quindi non usatele nei codici sorgente
  * esistono **caratteri riservati** al ```C++```, come le virgolette, gli apici, o il backslash:
    nell'output a schermo evitate di utilizzarli, oppure fateli precedere con il carattere ```\\```, 
    che dice al compilatore di non utilizzare il carattere successivo come carattere riservato

![linea](immagini/linea.png)

## 1.10 le opzioni di compilazione

  * durante la compilazione di un codice sorgente,
    il compilatore (```c++```) prende in ingresso **diversi parametri**. 
    Alcuni sono elencati qui:
    | parametro | ruolo |
    | --------- | --------- |  
    |  ```*.cc```, ```*.cpp```  | codice dell'implementazione: deve esserci una sola funzione ```main``` |
    | ```-o eseguibile``` | nome da assegnare all'eseguibile: valore di default e' ```a.out``` |
    | ```-O0``` | compilazione veloce e non ottimizzata, esecuzione lenta |
    | ```-O2``` | compilazione ottimizzata e lenta, esecuzione piu' veloce |
    | ```-O3``` | compilazione ottimizzata e lenta, esecuzione piu' veloce |
    | ```-Wall``` | accende tutti i Warning: il compilatore avvisa in caso di problemi sospetti |
    | ```-Werror``` | trasforma Warning in errori: il compilatore non compila se ci sono Warning |
    * provate a confrontare l'uso di ```pow (x, 2)``` con ```x * x``` a diversi livelli di ottimizzazione:
      che cosa cambia?
    * una **lista completa** di opzioni di compilazione si trova [qui](https://gcc.gnu.org/onlinedocs/gcc/Option-Summary.html)

![linea](immagini/linea.png)

### 1.10.1 il caso di librerie non di default

  * nel caso si utilizzino **librerie non di default**, 
    si puo' istruire il compilatore riguardo alla loro posizione nel computer:
    | parametro | ruolo |
    | --------- | --------- |  
    | ```-l[linalg]``` | nome (\*) della libreria precompilata (oggetto del compilatore) da linkare al programma |
    | ```-L[/path/to/shared-libraries]``` | la cartella dove stanno le librerie da linkare |
    | ```-I[/path/to/header-files]``` | dove stanno gli header file da includere |
    * (\*) il nome della libreria deve essere linalg.dll in Windows, liblinalg.so su Unix-like (e.g. Linux), linalg.dylib su MacOSX
  * spesso (come vedremo per ROOT) pacchetti esterni **forniscono anche un comando**
    che prepara queste opzioni per il compilatore

![linea](immagini/linea.png)

## 1.11 gli errori di compilazione

  * in caso di errore di compilazione, 
    il compilatore mostra a schemo la **descrizione degli errori** che ha riscontrato
  * il messaggio di errore e' solitamente utile a capire il problema:
    ```
    > c++ -o main_05 main_05.cpp
    main_05.cpp:10:12: error: cannot assign to variable 'numero' with const-qualified type 'const int'
        numero = numero + 1 ;
        ~~~~~~ ^
    main_05.cpp:9:15: note: variable 'numero' declared const here
        const int numero = 0 ;
        ~~~~~~~~~~^~~~~~~~~~
    1 error generated.
    ```
     * in questo caso, il compilatore indica **il file** con il codice sorgente problematico,
       **la linea** alla quale ha trovato un errore
       e **la ragione** per la quale ha ritenuto che ci fosse un problema
  * spesso un singolo errore genera altri errori in cascata,  
    quindi e' consigliato risolvere gli errori uno per uno, 
    iniziando dal primo che si trova

![linea](immagini/linea.png)

## 1.12 ESERCIZI

  * Gli esercizi relativi alla prima lezione si trovano [qui](ESERCIZI.md)


