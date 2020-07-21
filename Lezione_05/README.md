# Lezione 5: the data visualisation with ROOT

![linea](../immagini/linea.png)

## 5.1 Introduzione

  * [```ROOT```](https://root.cern.ch) offre un insieme di strumenti 
    di **visualizzazione, analisi e salvataggio dati**
    sviluppati nell'ambito della fisica delle particelle elementari
  * gli strumenti sono **scritti in ```C++```** ed esiste l'interfaccia ```Python``` per utilizzarli,
    con adattamenti al formato dei dati alla sintassi tipica di quell'ambiente
  * ```ROOT``` offre anche un **ambiente interattivo** 
    che si presenta nella forma di una linea di comando,
    dove istruzioni scritte in ```C++``` vengono interpretate
    da un parser dedicato

![linea](../immagini/linea.png)

### 5.1.1 l'organizzazione delle librerie di ```ROOT```

  * in un programma scritto in ```C++```, 
    ogni oggetto di ```ROOT``` viene reso disponibile nel codice sorgente
    con il corrispondente comando ```#include```
  * la maggior parte degli strumenti disponibili sono implementati
    **sotto forma di classi**  
    ```cpp
    #include "TH1F.h"

    int main (int argc, char ** argv)
      {
        TH1F istogramma ("istogramma", "istogramma", 10, -5., 5.) ;
        return 0 ;
      }
    ```
  * la **visualizzazione** degli strumenti statistici e' un aspetto fondamentale del programma,
    quindi molte opzioni grafiche sono integrate negli oggetti statistici

![linea](../immagini/linea.png)

### 5.1.2 prerquisiti per utilizzare ```ROOT```

  * dopo l'installazione, le librerie di ```ROOT``` sono salvate nel disco fisso
    solitamente in una cartella dedicata
  * per avviare l'interfaccia interattiva e per conoscere dove stiano le librerie,
    **e' necessario che:** 
      * la cartella che contiene l'eseguibile ```root```
        faccia parte della lista di indirizzi salvati nella variabile d'ambiente della SHELL
        ```$PATH```
      * la cartella che contiene le librerie precompilate f
        faccia parte della lista di indirizzi salvati nella variabile d'ambiente della SHELL
        ```$LD_LIBRARY_PATH```
  * esiste lo script ```thisroot.sh``` nelle cartelle di installazione che va richiamato
    per effettuare tali impostazioni:
    ```
    > source thisroot.sh
    ```      
      
![linea](../immagini/linea.png)

### 5.1.3 come compilare un programma che include classi di ```ROOT```

  * e' necessario **fornire al compilatore opzioni aggiuntive** perche' sia in grado di trovare
    tutti i file da includere e tutte le librerie da compilare
  * la lista di opzioni aggiuntive si **visualizza** con il seguente comando di SHELL:
    ```
    > root-config --cflags --glibs  
    ```
  * per evitare di copiare ed incollare il suo output nel comando di compilazione,
    si puo' **includere la sua chiamata direttamente nel programma di compilazione**,
    utilizzando gli apici inversi:
    ```
    > c++ -o main_00 `root-config --glibs --cflags` main_00.cpp
    ```
    
![linea](../immagini/linea.png)

## 5.2 TH1F: istogrammi monodimensionali

  * gli **istogrammi** sono una rappresentazione di distribuzioni differenziali,
    costruita a partire da un campione di numeri,
    che chiamiamo **eventi**
  * si parte quindi da **un campione di eventi *{x<sub>i</sub>}<sub>i=1,..,N</sub>***
    * un esempio di un campione di eventi
      e' **l'insieme delle misure raccolte durante un esperimento**,
      oppure una **sequenza di numeri pseudo-casuali**

![linea](../immagini/linea.png)

## 5.2.1 istogrammi monodimensionali

  * per una variabile casuale di interesse *x*, si suddivide il suo intervallo di definizione
    in **sotto-intervalli adiacenti e disgiunti** delimitati da *{x<sub>k</sub>}*
    * l'intervallo *k*-esimo e' limitato fra x<sub>k</sub> ed x<sub>k+1</sub>
    * solitamente gli intervalli sono chiamati **bin**
  * un istogramma e' l'**insieme dei conteggi degli eventi che cascano in ogni intervallo** 
![istogramma](immagini/istogramma_solo.png)
  * la visualizzazione di un istogramma mono-dimensionale mostra tipicamente:
    * sull'**asse orizzontale** l'intervallo di definizione della variabile *x*
    * sull'**asse verticale** i conteggi corrispondenti a ciascun bin
    * sopra ad ogni bin, **una barra verticale** alta quanto i conteggi

![linea](../immagini/linea.png)

## 5.2.2 istogrammi monodimensionali e distribuzioni di densita' di probabilita'

  * al **limite per la dimensione dei bin che diventa infinitesima**,
    un istogramma diventa una funzione continua
![istogramma_pdf](immagini/istogramma_e_pdf.png)
  * se si dividesse il contenuto di ogni bin per il numero totale di eventi *N*,
    questa funzione e' normalizzata, 
    quindi un istogramma diventa l'approssimazione di una 
    distribuzione di densita' di probabilita'



![linea](../immagini/linea.png)


- concetto di istogramma
- nome della variabile, nome dell'istogramma, titolo dell'istogramma
- visualizzazione dell'istogramma
- accedere alle statistiche dell'istogramma
- riempimenti pesati
- visualizzazione logaritmica
- opzioni grafiche
- scalare un istogramma
- DrawNormalized ()

## TH2F: istogrammi bidimnesionali

## TGraph

## TNtuple

## THStack

## TStringhe


### 5.1.1 

  | vantaggi |
  | -------- |


![linea](../immagini/linea.png)

## %.X ESERCIZI

  * Gli esercizi relativi alla lezione si trovano [qui](ESERCIZI.md)




