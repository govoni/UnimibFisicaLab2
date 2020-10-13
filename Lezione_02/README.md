# Lezione 2: ripasso di ```C``` ed introduzione al ```C++```, parte 2

## Indice

  * [2.1 Variabili e puntatori](#21-variabili-e-puntatori)
    * [2.1.1 La gestione delle variabili nel calcolatore](#211-la-gestione-delle-variabili-nel-calcolatore)
    * [2.1.2 Lo spazio occupato dalle variabili](#212-lo-spazio-occupato-dalle-variabili)
    * [2.1.3 Le dimensioni tipiche di alcuni tipi](#213-le-dimensioni-tipiche-di-alcuni-tipi)
    * [2.1.4 L'indirizzo di memoria di una variabile](#214-lindirizzo-di-memoria-di-una-variabile)
    * [2.1.5 Salvare l'indirizzo di memoria: i puntatori](#215-salvare-lindirizzo-di-memoria-i-puntatori)
    * [2.1.6 Dalla variabile al puntatore e viceversa](#216-dalla-variabile-al-puntatore-e-viceversa)
    * [2.1.7 Puntatori non inizializzati](#217-puntatori-non-inizializzati)
    * [2.1.8 I puntatori sono variabili](#218-i-puntatori-sono-variabili)
    * [2.1.9 Inizializzare una variabile a partire da un puntatore](#219-inizializzare-una-variabile-a-partire-da-un-puntatore)
    * [2.1.10 Puntatori di puntatori](#2110-puntatori-di-puntatori)
    * [2.1.11 risalire la caterna di indirizzi](#2111-risalire-la-caterna-di-indirizzi)
    * [2.1.12 Puntatori ed array](#2112-puntatori-ed-array)
    * [2.1.13 Gli elementi di un array](#2113-gli-elementi-di-un-array)
    * [2.1.14 L'algebra dei puntatori](#2114-lalgebra-dei-puntatori)
    * [2.1.15 Le referenze](#2115-le-referenze)
    * [2.1.16 Riepilogo sui puntatori](#2116-riepilogo-sui-puntatori)
  * [2.2 Il passaggio di parametri alle funzioni](#22-il-passaggio-di-parametri-alle-funzioni)
    * [2.2.1 Passaggio per valore](#221-passaggio-per-valore)
    * [2.2.2 Passaggio per puntatore](#222-passaggio-per-puntatore)
    * [2.2.3 Passaggio per referenza](#223-passaggio-per-referenza)
    * [2.2.4 L'output di una funzione](#224-loutput-di-una-funzione)
    * [2.2.5 Come reagisce il compilatore nel caso di una referenza](#225-come-reagisce-il-compilatore-nel-caso-di-una-referenza)
    * [2.2.6 Come reagisce il compilatore nel caso di un puntatore](#226-come-reagisce-il-compilatore-nel-caso-di-un-puntatore)
  * [2.3 La gestione dinamica della memoria](#23-la-gestione-dinamica-della-memoria)
    * [2.3.1 Heap and Stack](#231-heap-and-stack)
    * [2.3.2 Allocazione di una variabile nella Stack](#232-allocazione-di-una-variabile-nella-stack)
    * [2.3.3 Allocazione di una variabile nella Heap](#233-allocazione-di-una-variabile-nella-heap)
    * [2.3.4 Esempio di allocazione dinamica: utilizzo in una funzione](#234-esempio-di-allocazione-dinamica-utilizzo-in-una-funzione)
    * [2.3.5 Un errore pernicioso](#235-un-errore-pernicioso)
    * [2.3.5 Allocazione dinamica ed array](#235-allocazione-dinamica-ed-array)
    * [2.3.6 Non bisogna perdere il puntatore!](#236-non-bisogna-perdere-il-puntatore)
    * [2.3.7 Trova l'errore, 1](#237-trova-lerrore-1)
    * [2.3.8 Trova l'errore, 2](#238-trova-lerrore-2)
    * [2.3.9 Trova l'errore, 3](#239-trova-lerrore-3)
    * [2.3.10 Trova l'errore, 4](#2310-trova-lerrore-4)
    * [2.3.11 Trova l'errore, 5](#2311-trova-lerrore-5)
  * [2.4 ESERCIZI](#24-esercizi)

![linea](../immagini/linea.png)

## 2.1 Variabili e puntatori

![linea](../immagini/linea.png)

### 2.1.1 La gestione delle variabili nel calcolatore

  * In un computer tutto è rappresentato mediante **numeri**
  * I numeri sono salvati in **zone di memoria** (Random Access Memory = RAM)
  * Le celle della memoria sono individuate mediante **indirizzi**
  * Le **variabili di diversi tipi occupano una o più celle** di memoria (una zona),
    a seconda del tipo
    * Il calcolatore è in grado di **interpretare correttamente il contenuto** di una zona di memoria, 
      se conosce l'indirizzo della prima cella ed il tipo salvato

![cella](immagini/celle.png)

![linea](../immagini/linea.png)

### 2.1.2 Lo spazio occupato dalle variabili 

  * ogni tipo ha una **dimensione assegnata** nella RAM
  * per i tipi numerici interi, una dimensione assegnata significa che **i valori che la variabile può assumere
    sono limitati**
  * i tipi in virgola mobile (```float```, ```double```) non hanno limitazioni in valore, ma in precisione,
    quindi il tipo ```double```, occupando più celle di memoria, è più preciso del tipo ```float``` 
  * per conoscere la dimensione occupata da un tipo, si può utilizzare la funzone ```sizeof ()```:
    ```cpp
    std::cout << "Dimensione di un char : " << sizeof (char)  
             << " byte" << std::endl ; 

    ```

![linea](../immagini/linea.png)

### 2.1.3 Le dimensioni tipiche di alcuni tipi 

  * a seconda dell'architettura del calcolatore che si sta utilizzando, 
    le **dimensioni di un tipo possono cambiare**
  * nella tabella che segue,
    sono indicati **valori tipici** per le dimensioni dei tipi comunemente utilizzati
  * esistono **type modifier** che cambiano le caratteristiche di un tipo 
    (```signed```, ```unsigned```, ```short```, ```long```)
    che ne modificano la dimensione o l'intervallo di copertura

 | tipo | dimensione (in Byte) | intervallo |
 | --- | :---: | :---: |
 | short int              | 2      | -32,768 to 32,767               |   
 | unsigned short int     | 2      | 0 to 65,535                     |               
 | unsigned int           | 4      | 0 to 4,294,967,295              |                      
 | int                    | 4      | -2,147,483,648 to 2,147,483,647 |                 
 | long int               | 4      | -2,147,483,648 to 2,147,483,647 |                 
 | unsigned long int      | 4      | 0 to 4,294,967,295              |    
 | long long int          | 8      | -(2^63) to (2^63)-1             |     
 | unsigned long long int | 8      | 0 to 18,446,744,073,709,551,615 |                 
 | signed char            | 1      | -128 to 127                     |               
 | unsigned char          | 1      | 0 to 255                        |            
 | float                  | 4      |                                 |                      
 | double                 | 8      |                                 |                      
 | long double            | 12     |                                 |                        
 | wchar_t                | 2 or 4 | 1 wide character                |                    


![linea](../immagini/linea.png)

### 2.1.4 L'indirizzo di memoria di una variabile

  * per ogni variabile, in ```C++``` si conosce il suo **valore** tramite il suo nome
  * si può anche conoscere il suo indirizzo di memoria,
    tramite l'operatore ```&```:
    ```cpp
    int numero_intero = 5 ;
    std::cout << "valore:    " << numero_intero << std::endl ;
    std::cout << "indirizzo: " << & numero_intero << std::endl ;
    ```

![linea](../immagini/linea.png)

### 2.1.5 Salvare l'indirizzo di memoria: i puntatori

  * l'indirizzo di una cella di memoria è un numero, 
    quindi può essere a sua volta **salvato in una variabile**
  * variabili che contengono indirizzi alla prima cella di memoria di altre variabili 
    sono chiamate **puntatori**
  * siccome rivestono un ruolo fondamentale nella programmazione,
    si **dichiarano in modo specifico**, con la sintassi ```type * var```:
    ```cpp
    int * puntatore_ad_intero ;
    ```
  * questa dichiarazione fa sì che **il programma sappia come accedere al contenuto**
    della cella di memoria che sta all'indirizzo salvato in ```puntatore_ad_intero```,
    perché sa di che tipo si tratta

![cella](immagini/puntatore.png)

![linea](../immagini/linea.png)

### 2.1.6 Dalla variabile al puntatore e viceversa

  * il simbolo ```*```, oltre a comparire nella dichiarazione di un puntatore,
    rappresenta anche l'opertore che estrae il valore della variabile contenuta
    nell'indirizzo di memoria puntato:
    ```cpp
    int * puntatore_ad_intero = & numero_intero ;
    std::cout << "valore   : " << numero_intero << std::endl ;
    std::cout << "indirizzo: " << & numero_intero << std::endl ;
    std::cout << "puntatore: " << puntatore_ad_intero << std::endl ;
    std::cout << "valore   : " << * puntatore_ad_intero << std::endl ;
    ```
    produce come output:
    ```
    valore   : 5
    indirizzo: 0x7ffeeedfa44c
    puntatore: 0x7ffeeedfa44c
    valore   : 5
    ```
![linea](../immagini/linea.png)

### 2.1.7 Puntatori non inizializzati

  * un puntatore definito e non inizializzato non punta ad alcun indirizzo di memoria:
    ```cpp
    int * puntatore_ad_intero ;
    std::cout << "puntatore: " << puntatore_ad_intero << std::endl ;
    ```
    produce come ouptut:
    ```
    0x0
    ```

![linea](../immagini/linea.png)

### 2.1.8 I puntatori sono variabili

  * un puntatore è una variabile,
    dunque può **cambiare valore** anche dopo essere stato inizializzato:  
    ```cpp
    ptr = & var ;
    std::cout << "Ora ptr punta a var: " << ptr
              << " ed il valore a cui punta vale: " << *ptr << std::endl ; 
    ```
    produce come output:
    ```
    Ora ptr punta a var: 0x7ffeee47f43c ed il valore a cui punta vale: 137
    ```
  * se un puntatore viene inizializzato all'indirizzo di una variabile,
    si può **accedere alla variabile tramite il puntatore**;
    in questo caso viene modificato ```*ptr``` e visualizzato il valore di ```var```:
    ```cpp
    *ptr = 100 ;
    std::cout << "var ora vale: " << var << std::endl ;
    ```

![linea](../immagini/linea.png)

### 2.1.9 Inizializzare una variabile a partire da un puntatore

  * una variabile può essere inizializzata con il valore presente
    all'indirizzo contenuto in un puntatore: 
    ```cpp
    int pippo = * ptr ;
    std::cout << "La variabile pippo vale: " << pippo << std::endl; 
    ```
    produce come output:
    ```
    La variabile pippo vale: 100
    ```
    * a questo punto, le modifiche a ```*ptr``` effettuate dopo l'inzializzazione
      **non hanno effetto su ```pippo```**, perché quest'ultimo è un'altra variabile
      (quindi con il contenuto salvato in un'altra zona di memoria):
      ```cpp
      (*ptr)++;
      std::cout << "var ora vale: " << var << " e pippo vale: " << pippo << std::endl; 
      ```
      produce come output:
      ```
      var ora vale: 101 e pippo vale: 100
      ```

![linea](../immagini/linea.png)

### 2.1.10 Puntatori di puntatori

  * se un puntatore è una variabile, 
    ha un **contenuto ed un indirizzo di memoria**
  * quindi, si può costruire un puntatore al suo indirizzo, 
    cioè un puntatore a puntatore

![ptrptr](immagini/puntatore_a_puntatore.png)

![linea](../immagini/linea.png)

### 2.1.11 risalire la caterna di indirizzi

  * tramite l'operatore ```*``` si può arrivare fino al valore della variabile iniziale:
    ```cpp
    int var = 137 ; 
    int * ptr = & var ;
    int ** ptrAptr = & ptr ;

    std::cout << "var    : " << var << std::endl ;
    std::cout << "ptr    : " << ptr << std::endl ;
    std::cout << " `--> *ptr: " << *ptr << std::endl ;
    std::cout << "ptrAptr: " << ptrAptr << std::endl ;
    std::cout << " `--> *ptrAptr: " << *ptrAptr << std::endl ;
    std::cout << "        `-->**ptrAptr: " << **ptrAptr << std::endl ;
    ```
    produce come output:
    ```
    var    : 137
    ptr    : 0x7ffee7f0e43c
     `--> *ptr: 137
    ptrAptr: 0x7ffee7f0e430
     `--> *ptrAptr: 0x7ffee7f0e43c
            `-->**ptrAptr: 137
    ```

![linea](../immagini/linea.png)

### 2.1.12 Puntatori ed array

  * Quando si definisce un array, suo nome (senza parentesi graffe) 
    contiene **l’indirizzo di memoria del primo elemento** dell’array:  
    ```cpp
    int vec[] = {2, 20} ;
    std::cout << vec << std::endl ;
    ```
    produce come output:
    ```
    0x7ffeef024440
    ```

![linea](../immagini/linea.png)

### 2.1.13 Gli elementi di un array

  * se ```vec``` è il puntatore al primo elemento dell'array,
    **```*vec``` è il suo contenuto**:
    ```cpp
    std::cout << vec[0] << " == " << *vec << std::endl ;
    ```
  * si può accedere agli **elementi successivi dell'array** tramite l'operatore ```*```  
    ```cpp
    std::cout << vec[1] << " == " << *(vec+1) << std::endl ;
    ```

![cella](immagini/array.png)

![linea](../immagini/linea.png)

### 2.1.14 L'algebra dei puntatori

  * l'**algebra dei puntatori** con gli operatori ```+``` e ```-``` funziona
    perché il puntatore è di un tipo definito,
    quindi il programma sa di quante celle di memoria muoversi per raggiungere
    la zona di memoria successiva
    * ```*(vec+1)``` non è la cella di memoria successiva a quella
      indicizzata da ```vec```,
      ma quella che dista da ```vec``` la dimensione di un intero
  * le due sintassi ```vec[i]``` e ```*(vec+i)``` significano la stessa cosa,
    cioè sono due rappresentazioni della medesima operazione fatta dal calcolatore

![linea](../immagini/linea.png)

### 2.1.15 Le referenze

  * Le referenze sono **alias per i nomi delle variabili**. 
    In termini di contenuti, la variabile o la sua referenza sono la stessa cosa:
    ```cpp
    double pi_greco = 3.1415 ;
    double & ref = pi_greco ;
    std::cout << "ref fornisce un alias di pi_greco: "
              << ref << std::endl ;

    pi_greco = 3.141592 ;
    std::cout << "ref fornisce un alias di pi_greco: "
              << ref << std::endl ;
    ```
  * di conseguenza, una referenza si crea **soltanto a partire da una variabile esistente**
  * allo stesso tempo, si **comporta come un puntatore**, 
    cioè dà accesso alle variabili direttamente tramite l'indirizzo di memoria,
    piuttosto che il suo contenuto

![linea](../immagini/linea.png)

### 2.1.16 Riepilogo sui puntatori

  * ```C++``` permette di accedere alla memoria in due modi:
    * tramite le **variabili**, che rappresentano il valore contenuto nella memoria
    * tramite i **puntatori**, che rappresentano l'indirizzo fisico dove i valori sono salvati
  * fornisce inoltre il modo di passare da una rappresentazione all'altra:
    * l'**operatore \*** permette di passare da puntatore a variabile
    * l'**operatore &** permette di passare da variabile a puntatore
  * le **referenze** sono un alias delle variabili, 
    che in realtà maneggiano l'indirizzo di memoria invece del valore della variabile

|  azione | effetto |
| --- | --- |                                    
| ```int var = 137 ;```       | Creazione variabile int              |                              
| ```int* ptr ;```            | Creazione variabile puntatore a int  |                         
| ```ptr = &var ;```          | Indirizzo di memoria di var          |                           
| ```int new_var = * ptr ;``` | Contenuto della cella puntata da ptr |                                     
| ```int& ref = var ;```      | Creazione di un alias di var         |                                   


![linea](../immagini/linea.png)

## 2.2 Il passaggio di parametri alle funzioni

  * tutti i tre tipi di accesso alla memoria (valore di una variabile, puntatore o referenza)
    possono essere usati per **passare argomenti ad una funzione**

![linea](../immagini/linea.png)

### 2.2.1 Passaggio per valore

  * nel passaggio per valore, 
    nel prototipo della funzione fra parentesi è indidcato il **nome della variabile**
    ```cpp
    int raddoppia (int valore)
    {
      valore *= 2 ; 
      return valore ;
    }
    ```
  * il calcolatore **crea una copia** della variabile di input
    e passa la copia alla funzione
  * questo significa che **il passaggio di informazione è lento** 
    e la variabile passata alla funzione
    **non risente delle azioni che subisce all'interno della funzione**:
    ```cpp
    int numero = 5 ;
    std::cout << "raddoppio (valore)    " << raddoppia (numero) << "\n" ;
    std::cout << "numero: " << numero << "\n" ;
    ```
    restituisce come risultato (numero rimane uguale a 5):
    ```
    raddoppio (valore)    10
    numero: 5
    ```

![linea](../immagini/linea.png)

### 2.2.2 Passaggio per puntatore

  * nel passaggio per valore, 
    nel prototipo della funzione fra parentesi è indidcato il **puntatore alla variabile**
    da passare
    ```cpp
    int raddoppia (int * valore)
    {
      *valore *= 2 ; 
      return *valore ;
    }
    ```
  * il calcolatore pasa alla funzione la variabile puntatore, 
    quindi **il passaggio di informazione è veloce**
    ed ogni modifica fatta alla zona di memoria indicizzata dal puntatore all'interno della funzione
    **ha effetto anche al di fuori dello scope della funzione**:
    ```cpp
    std::cout << "raddoppio (puntatore) " << raddoppia (& numero) << "\n" ;
    std::cout << "numero: " << numero << "\n" ;
    ```
    restituisce come risultato (numero diventa uguale a 10):
    ```
    raddoppio (puntatore) 10
    numero: 10
    ```

![linea](../immagini/linea.png)

### 2.2.3 Passaggio per referenza

  * nel passaggio per valore, 
    nel prototipo della funzione fra parentesi è indidcata la **referenza alla variabile**
    da passare
    ```cpp
    int raddoppiaRef (int & valore)
    {
      valore *= 2 ; 
      return valore ;
    }
    ```
  * il calcolatore pasa alla funzione l'alias alla variabile, che si comporta come un puntatore 
  * quindi **il passaggio di informazione è veloce**
    ed ogni modifica fatta alla referenza all'interno della funzione 
    **ha effetto anche al di fuori dello scope della funzione**:
    ```cpp
    std::cout << "raddoppio (referenza) " << raddoppiaRef (numero) << "\n" ;
    std::cout << "numero: " << numero << "\n" ;
    ```
    restituisce come risultato (numero diventa uguale a 10):
    ```
    raddoppio (referenza) 10
    numero: 10
    ```

![linea](../immagini/linea.png)

### 2.2.4 L'output di una funzione

  * nelle funzoni viste finora, l'oggetto restituito dalla funzione è il valore di variabile
  * questo valore viene scritto nella zona di memoria della variabile alla quale
    viene assegnato il valore (```risultato``` nell'esempio che segue):
    ```cpp
    int risultato = raddoppia (numero) ;
    ```
  * ritornare il puntatore o la referenza ad una variabile è **un'operazione rischiosa 
    e non sempre permessa**
  * infatti, ogni volta che una variabile viene definita all'interno della funzione,
    al termine della funzione viene **elimiata dal calcolatore** (va out of scope)  

![linea](../immagini/linea.png)

### 2.2.5 Come reagisce il compilatore nel caso di una referenza

  * fuori dalla funzione 
    la variabile ```risultato``` non esiste più,
    quindi la referenza, che è il suo alias,
    **non ha significato**:
    ```cpp
    int & raddoppiaReturnReferenza (int valore)
    {
      int risultato = valore * 2 ; 
      return risultato ;
    }
    ```
    in fase di compilazione produce un **Warning**:
    ```
    main_08.cpp:23:10: warning: reference to stack memory associated with local variable 'risultatò returned [-Wreturn-stack-address]
      return risultato ;
             ^~~~~~~~~
    ```
 
![linea](../immagini/linea.png)

### 2.2.6 Come reagisce il compilatore nel caso di un puntatore

  * fuori dalla funzione 
    il puntatore a questa variabile indicizza una **zona di memoria non più occupata**
    ```cpp
    int * raddoppiaReturnPuntatore (int valore)
    {
      int risultato = valore * 2 ; 
      return & risultato ;
    }
    ```
    anche in questo caso, in fase di compilazione produce un **Warning**:
    ```
    main_08.cpp:17:12: warning: address of stack memory associated with local variable 'risultatò returned [-Wreturn-stack-address]
      return & risultato ;
               ^~~~~~~~~
    ```
  * il passaggio di valori per puntatore è **veloce**:
    per approfittare appieno di questa proprietà,
    dobbiamo **acquisire un controllo più stretto della memoria**

![linea](../immagini/linea.png)

## 2.3 La gestione dinamica della memoria

  * in generale,
    quando una nuova variabile viene creata
    il calcolatore compie **due operazioni**:
    * riservare la memoria per la variabile, chiamata **allocazione di memoria**
    * **inizializzazione della variabile** in quello spazio di memoria

![linea](../immagini/linea.png)

### 2.3.1 Heap and Stack

  * il programma (quindi il programmatore) ha a disposizione due tipi di gestione della RAM:

  | **stack** |
  | --------- |

  * le variabili vengono salvate in **zone contigue** di memoria (da cui il nome)
  * il calcolatore si occupa della manutenzione della stack:
    la memoria viene **automaticamente allocata e cancellata** a fine scope

  | **heap** |
  | -------- |

  * le variabili vengono salvate in **una zona meno ordinata** di memoria
  * il calcolatore **non** si occupa della manutenzione della stack:
    il programma (quindi il programmatore) deve **ricordarsi di svuotare la memoria**

![linea](../immagini/linea.png)

### 2.3.2 Allocazione di una variabile nella Stack

  * una qualunque definizione di variabili vista finora 
    è un esempio di uso della stack:
    ```cpp
    int numero = 5 ;
    float array[3] ;
    array[0] = 4.3 ;
    // etc
    ```
  * utilizzare la stack è detto anche **allocazione automatica della memoria**

  | **vantaggi** |
  | --------- |

  * il programmatore non si preoccupa della gestione della memoria

  | **svantaggi** |
  | --------- |

  * la zona di RAM riservata alla stack è **piccola**
  * la dimensione delle variabili deve essere **nota al momento della compilazione**

![linea](../immagini/linea.png)

### 2.3.3 Allocazione di una variabile nella Heap

  * per allocare una variabile nella heap si usa l'istruzione **```new```**:
    ```cpp
    int * numero = new int (5) ;
    std::cout << * numero << std::endl ;
    ```
    * new **ritorna un puntatore** alla zona di memoria allocata,
      da assegnare ad una variabile
    * se si perde il valore del puntatore, 
      diventa **impossibile rintracciare la zona di memoria** allocata da ```new``` 
  * la zona di memoria non viene deallocata automaticamente,
    nel codice sorgente **è necessario utilizzare l'istruzione ```delete```** per farlo:
    ```cpp
    delete numero ;
    ```
  * utilizzare la stack è detto anche **allocazione dinamica della memoria**

  | **vantaggi** |
  | --------- |

  * la memoria heap è **molto più grande** della stack
  * il programmatore può decidere la dimensione della variabile durante l'esecuzione del programma
  * la memoria non viene cancellata automaticamente a fine scope

  | **svantaggi** |
  | --------- |

  * se non si libera la memoria con ```delete```,
    in particolare nei cicli,
    questa si intasa e l'esecuzione rischia di **interrompersi ad un punto casuale**
    (cioè quando la memoria è piena)
    ed è molto difficile identificare il problema nel programma

![linea](../immagini/linea.png)

### 2.3.4 Esempio di allocazione dinamica: utilizzo in una funzione

  * la funzione seguente sfrutta il fatto che la memoria allocata dinamicamente
    **non viene cancellata quando finisce lo scope**:
    ```cpp
    int * creaInteroDoppio (int valore)
    {
      int * risultato = new int (valore * 2) ; 
      return risultato ;
    }
    ```
  * infatti, il valore del risultato **rimane accessibile** anche 
    dopo che la funzione è stata eseguita:
    ```cpp
    int numero = 5 ;
    int * doppio = creaInteroDoppio (numero) ;
    std::cout << "Valore iniziale: " << numero  << std::endl ;
    std::cout << "Valore doppio  : " << *doppio << std::endl ;
    ```
  * **non bisogna dimenticare** di svuotare la memoria quando la variabile non serve più:
    ```cpp
    delete doppio ;
    ```    

![linea](../immagini/linea.png)

### 2.3.5 Un errore pernicioso

  * nell'utilizzo della funzione ```creaInteroDoppio```
    non bisogna dimenticare di assegnare ad una variabile il valore del puntatore
  * la linea seguente non dà errore, 
    tuttavia **perde il valore del puntatore** 
    alla memoria allocata dinamicamente      
    ```cpp
    std::cout << "Valore doppio  : " << *creaInteroDoppio (numero) << std::endl ;
    ```
  * di conseguenza, **non è possibile utilizzare il comando ```delete```**
    e la zona di memoria rimane inutilizzabile fino al termine 
    dell'esecuzione del programma

![linea](../immagini/linea.png)

### 2.3.5 Allocazione dinamica ed array

  * siccome l'allocazione statica richiede che la dimensione delle variabili sia nota in fase di compilazione,
    la lunghezza di un array deve essere scritta nel codice sorgente:
    ```cpp    
    float array[3] ;  // QUESTO VA BENE
    int N = 5 ;
    float array[N] ;  // QUESTO __NON__ VA BENE
    ```
    * la linea ```float array[N]``` non è corretta in ```C++```, 
      la dimensione dell'array non sarà ```5```, ma un numero che a priori non conosciamo,
      creando problemi in esecuzione difficili da identificare
  * si può utilizzare allocazione dinamica della memoria
    per creare array che abbiano dimensione scelta durante l'esecuzione     
    ```cpp    
    int N = 5 ;
    float * dynamic_array = new float [N] ;
    ```
    * invece delle parentesi tonde, dopo il tipo della variabile bisogna utilizzare **parentesi quadre**
  * avendo usato l'operatore ```new```, la memoria va liberata quando l'array non serve più:
  ```cpp
  delete [] dynamic_array ;
  ```
  * non bisogna dimenticare le **parentesi quadre** dopo ```delete```
  * fintanto che siste, questo array si utilizza come uno allocato staticamente

![linea](../immagini/linea.png)

### 2.3.6 Non bisogna perdere il puntatore!

  * anche in questo caso, il puntatore restituito da ```new```
    è l'unico accesso alla memoria allocata dinamicamente,
    quindi **non va persa quell'informazione**,
    altrimenti non si riesce più a liberare la memoria

![arrrayeptr](immagini/arrayeptr.png)

![linea](../immagini/linea.png)

### 2.3.7 Trova l'errore, 1

  * cosa c'è di sbagliato nella sequenza di istruzioni seguente?
    ```cpp
    int anArray[10];
    int* num;
    int* vec = new int[10]; num = anArray;
    vec = num;
    delete[] vec;
    ```

![linea](../immagini/linea.png)

### 2.3.8 Trova l'errore, 2

  * cosa c'è di sbagliato nella sequenza di istruzioni seguente?
    ```cpp
    int nElem ;
    // ...
    double * myArray ; 
    if (nElem > 0)
      myArray = new double[nElem] ; 
    // ...
    delete[] myArray ;
    ```

![linea](../immagini/linea.png)

### 2.3.9 Trova l'errore, 3

  * cosa c'è di sbagliato nella sequenza di istruzioni seguente?
    ```cpp
    int nElem ;
    double * myArray = new double[10] ; 
    // ...
    if (nElem > 0)
      myArray = new double[nElem] ; 
    // ...
    delete[] myArray ;
    ```

![linea](../immagini/linea.png)

### 2.3.10 Trova l'errore, 4

  * cosa c'è di sbagliato nella sequenza di istruzioni seguente?
    ```cpp
    int myFunction (int * inArray, int dim)
      {
        int sumEven = 0 ;
        int myArray[dim] ;
        unsigned int indx = 0;
        for (unsigned int i = 0 ; i < 10 ; ++i) 
          {
            if (inArray[i]%2 == 0) 
              {
                myArray[indx] = inArray[i] ;
                ++indx ; 
              }
          }
        for (unsigned int i = 0 ; i < indx ; ++i)
          sumEven += myArray[i]; 
        return sumEven;
      }

    ```

![linea](../immagini/linea.png)

### 2.3.11 Trova l'errore, 5

  * cosa c'è di sbagliato nella sequenza di istruzioni seguente?
    ```cpp
    int myFunction (int * inArray, int dim)
      {
        int sumEven = 0 ;
        int * myArray = new int[dim] ;
        unsigned int indx = 0 ;
        for (unsigned int i = 0 ; i < 10 ; ++i) 
          {
            if (inArray[i]%2 == 0) 
              {
                myArray[indx] = inArray[i] ;
                ++indx ; 
              }
          }
        for (unsigned int i = 0 ; i < indx ; ++i)
          sumEven += myArray[i] ; 
        return sumEven ;
      }
    ```

![linea](../immagini/linea.png)

## 2.4 ESERCIZI

  * Gli esercizi relativi alla lezione si trovano [qui](ESERCIZI.md)


