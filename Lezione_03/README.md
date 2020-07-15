# Lezione 3: programmazione ad oggetti, le classi

![linea](../immagini/linea.png)

## 3.1 La generalizzazione del concetto di tipo

![linea](../immagini/linea.png)

## 3.1.1 Uno sguardo ravvicinato ai tipi predefiniti in ```C++```

- gestione della memoria
- inizializzazione delle variabili
- operazione sulle variabili
- liberazione della memoria

![linea](../immagini/linea.png)

### 3.1.2 Un esempio: i numeri complessi

- scritto in C
- con una funzione di esempio

![linea](../immagini/linea.png)

### 3.1.3 Se i numeri complessi fossero un tipo di ```C++```

- gestibili come variabili predefinite
- semplicita' di gestione
- solidita' dell'implementazione
  - conversione da coordinate polari a cartesiane
  - calcolo di rho, theta
  - operazioni fra numeri complessi

![linea](../immagini/linea.png)

### 3.2 Si puo' fare! La classe dei numeri complessi

![linea](../immagini/linea.png)

### 3.2.1 La definizione della classe (il file ```.h```)

![linea](../immagini/linea.png)

### 3.2.2 I membri di una classe

![linea](../immagini/linea.png)

### 3.2.3 I metodi di una classe

![linea](../immagini/linea.png)

### 3.2.4 Il campo ```public```

- e' il default se si scrive ```struct```

![linea](../immagini/linea.png)

### 3.2.5 Il campo ```private```

- e' il default per una classe

![linea](../immagini/linea.png)

### 3.2.5 L'implementazione della classe (il file ```.cc```)

- i ```::``` per definire univocamente i metodi

![linea](../immagini/linea.png)

### 3.3 Funzioni speciali di una classe

![linea](../immagini/linea.png)

### 3.3.1 Il costruttore

- cosa fare nel costruttore
- la lista di inizializzazione
- overloading
- niente tipo di ritorno

![linea](../immagini/linea.png)

### 3.3.2 Il costruttore di default

- come si fa a non averlo?

![linea](../immagini/linea.png)

### 3.3.3 Il costruttore di copia

- come e' scritto l'argomento
- niente tipo di ritorno anche qui

![linea](../immagini/linea.png)

### 3.3.4 L'operatore di assegnazione

- come e' scritto l'argomento
- tipo di ritorno?

![linea](../immagini/linea.png)

### 3.3.5 Il distruttore

- ricordare i delete!
- non chiamato esplicitamente
- niente tipo di ritorno
- quando viene chiamato?
  - allocazione automatica
  - allocazione dinamica

![linea](../immagini/linea.png)

## 3.4 La ridefinizione di operatori, overloading

- i vari ```operator```

![linea](../immagini/linea.png)

## 3.5 L'attributo ```const```

![linea](../immagini/linea.png)

### 3.5.1 Dove si puo' utlizzare in ```C++``` con i tipi predefiniti

![linea](../immagini/linea.png)

### 3.5.2 Oggetti definiti ```const```

![linea](../immagini/linea.png)

### 3.5.2 Metodi definiti ```const```

- un metodo ```const``` non puo' modificare nessun data member della classe
- se una classe è stata istanziata come ```const``` si possono usare solo i suoli metodi ```const```

![linea](../immagini/linea.png)

## 3.4 Classi e puntatori

![linea](../immagini/linea.png)

## 3.X ESERCIZI

  * Gli esercizi relativi alla prima lezione si trovano [qui](ESERCIZI.md)




