// c++ -o main main.cpp myarray.cc

#include "myarray.h"

int main(){

    int dim = 10;

    mioArray arr(dim);

    //Riempio l'array con dummy values
    for(int i = 0; i < dim; i++){
        arr.fill(i, i);
    } 

    //Mostra contenuto
    arr.print();

    //modifico valore di una cella
    arr.fill(1, 10.5);

    //Mostra contenuto ma usando la funzione get
    std::cout << "Mio array: " << std::endl;
    for(int i = 0; i < dim; i++){
        std::cout << arr.get1(i) << " ";
    } 
    std::cout << std::endl;

    //Proviamo a chiedere il valore dell'array per un indice > dimensione
    double num = arr.get1(11);
    std::cout << "La prima funzione get1 restituisce un valore " << num << " anche se l'indice richiesto 11 "\
                    "supera la dimensione dell\'array " << dim << std::endl;

    //Proviamo a fare lo stesso con la seconda funzione. 
    //La sintassi try-catch viene usata per continuare nell'esecuzione del programma.
    //Senza di essa il programma si bloccherebbe con messaggio di errore come output da terminale (e.what()).
    try {
        double error = arr.get2(11);
    }
    catch (const std::out_of_range& e) {
        std::cout << "La seconda funzione restituisce un errore se l'indice richiesto supera "\
                        "la dimensione dell\'array.\nErrore: " << e.what();
    }
    

    //Test con un oggetto di tipo const
    //Copiamo il contenuto di arr in un nuovo oggetto const new_arr
    const mioArray new_arr(arr);

    //stampiamo
    new_arr.print();

    std::cout << "Possiamo ricevere informazioni dall'oggetto di tipo const ad esempio " << new_arr.get2(1) << std::endl;

    return 0;

}