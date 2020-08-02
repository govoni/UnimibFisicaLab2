# Lezione 8: programmazione ad oggetti: l'ereditarieta' ```public```

![linea](../immagini/linea.png)

## 8.1 Introduzione

  * nella programmazione ad oggetti,
    la **traslazione dalle funzioni ai metodi delle funzionalita'** dei programmi
    produce necessariamente una proliferazione di classi
    per svolgere i compiti dei programmi
  * spesso succede che classi simili **implentino comportamenti comuni**
    insieme a comportamenti specifici per ciascuna di esse  
  * il meccanismo dell'ereditarieta' permette di **evitare di reimplementare comportamenti comuni**,
    definendoli soltanto una volta per una **classe base**,
    facendo in modo che vengano ereditati da diverse **classi derivate**
  * le classi derivate, dunque, **adattano ed estendono comportamenti generali** 
    definiti nella classe base

![linea](../immagini/linea.png)

### 8.1.1 Rappresentazione grafica

  * il meccanismo di ereditarieta' ```public``` introduce una **gerarchia fra classi**:
    ogni classe derivata e' un caso particolare della classe base.
    Questo concetto e' noto come la **regola is-a**
    ![gerarchia](../immagini/gerarchia.png)

![linea](../immagini/linea.png)

### 8.1.2 Problemi di privacy

  * nelle classi, 
    i membri ed i metodi sono divisi in parte ```public``` e parte ```private```:
    **come funziona l'accesso** nel caso dell'ereditarieta'?  
  * i membri e metodi ```public``` delle classi base **sono accessibili** alle classi derivate
  * i membri e metodi ```private``` delle classi base **non sono accessibili** alle classi derivate
  * esiste una terza catergoria: 
    i membri e metodi ```protected``` delle classi base **non sono accessibili al di fuori** della classe base,
    **restando accessibili alle classi derivate**.

![linea](../immagini/linea.png)

## 8.2 Implementazione dell'esempio delle forme geometriche 

![linea](../immagini/linea.png)

### 8.2.1 La classe base: ```forma```

  * la **classe base** per le forme geometriche ha un contenuto molto semplice:
    ```cpp
    class forma
    { 
      public:
        
        forma (double area = -1.) : m_area (area) {} ;
        ~forma () {} ;
        double area () const { return m_area ; } ;
    
      protected:  
    
        double m_area ;
    
    } ;

    ```
    * il membro ```m_area``` e' ```protected``` perche' sia accessibile
      anche alle classi derivate
    * in questo caso non ci sono ```private```, ma si potrebbero mettere  
  * un oggetto di tipo ```forma``` puo' essere istanziato in un programma ```C++``` 
    ```cpp
    forma forma_base ;
    cout << forma_base.area () << endl ;
    ```

![linea](../immagini/linea.png)

### 8.2.2 Una classe derivata: ```quadrato```

  * La sintassi per definire una **classe derivata pubblicamente** e' la seguente:
    ```cpp
    class quadrato : public forma 
    {
      public:
    
        quadrato (double lato = 1.) :
          m_lato (lato),
          forma (lato * lato) {}
    
        double lato () const { return m_lato ; }
        void cambia_lato (double lato) 
          {
            m_lato = lato ;
            m_area = m_lato * m_lato ;
            return ;
          } ;
    
        ~quadrato () {} ;
    
      private:  
    
        double m_lato ;
    
    } ;

    ```
    * il membro ```m_lato``` e' **dichiarato ```private```** 
      perche' nella progettazione della struttura di ereditarieta' 
      non ci sono classi derivate che debbano accedervi
    * i metodi specifici della classe quadrato   
      **si aggiungono** a quelli della classe base
    * il membro **```m_area``` e' accessibile** anche dalla classe ```quadrato```  

![linea](../immagini/linea.png)

### 8.2.3 La classe derivata nel programma principale

  * nella funzione ```main```, 
    o in qualunque altra funzione dove venga utilizzato,
    per un oggetto di tipo ```quadrato``` si possono chiamare i metodi pubblici
    **sia della classe base che di quella derivata**:
    ```cpp
    quadrato forma_quadrata (3.) ;
    cout << "area: " << forma_quadrata.area () << endl ;
    cout << "lato: " << forma_quadrata.lato () << endl ;
    forma_quadrata.cambia_lato (4.) ;
    cout << "area: " << forma_quadrata.area () << endl ;
    ```
  * la consistenza delle informazioni (ad esempio, che l'area sia calcolata correttamente)
    dipende dalla **bonta' dell'implementazione**

![linea](../immagini/linea.png)

### 8.2.4 Un'altra classe derivata: il ```rettangolo```

  * da una medesima classe base possono ereditare **diverse classi derivate**:
    ```cpp
    class rettangolo : public forma 
    {
      public:
    
        rettangolo (double lato_o = 1., double lato_v = 1.) :
          m_lato_o (lato_o),
          m_lato_v (lato_v),
          forma (lato_o * lato_v) {}
    
        double lato_o () const { return m_lato_o ; }
        double lato_v () const { return m_lato_v ; }
    
        void cambia_lato_o (double lato) 
          {
            m_lato_o = lato ;
            m_area = m_lato_o * m_lato_v ;
            return ;
          } 
    
        void cambia_lato_v (double lato) 
          {
            m_lato_v = lato ;
            m_area = m_lato_o * m_lato_v ;
            return ;
          }
    
        ~rettangolo () {} ;
    
      private:  
    
        double m_lato_o ;
        double m_lato_v ;
    
    } ;
  
    ```
  * in questo caso, **sono necessari piu' metodi e piu' membri**
    per descrivere le proprieta' del rettangolo

![linea](../immagini/linea.png)

### 8.2.5 La regola is-a: una specializzazione

  * L'ereditarieta' delle funzionalita' delle classi base nelle classi derivate
    e' un aspetto importante della progettazione del codice sorgente
    e **riguarda il comportamento** di una classe
  * ad esempio, per il ```C++``` un quadrato **non** e' una specilizzazione di un rettangolo,
    nonostante dal punto di vista geometrico il quadrato sia un rettangolo con lati uguali
    * ad un rettangolo si puo' modificare la lunghezza di un lato e rimane un rettangolo,
      mentre se si modifica la lunghezza di un lato di un quadrato,
      la forma geometrica **diventa un rettangolo generico**
  * quindi la classe ```quadrato``` **non e' una specializzazione** della classe ```rettangolo```,
    perche' non tutte le funzioni di ```rettangolo``` possono essere applicate a ```quadrato```

![linea](../immagini/linea.png)

## 8.3 ereditarieta' e polimorfismo



![linea](../immagini/linea.png)

## 8.X ESERCIZI

  * Gli esercizi relativi alla lezione si trovano [qui](ESERCIZI.md)


