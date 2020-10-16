#include "myarray.h"

mioArray::mioArray(const mioArray& copy)
    : mioarr(copy.dim ? new double[copy.dim] : nullptr)
    , dim(copy.dim){
        /*
            Copy constructor.
            Viene copiato il contenuto solo se mioarr non punta a null.
        */
        if (mioarr){
            for(int i = 0; i < dim; i++){
                mioarr[i] = copy.mioarr[i];
            }
        }
}

bool mioArray::check_idx(int idx) const{
    /*
        Semplice check tra l'indice (idx) inserito e la dimensione
        dell'array (attributo della classe).
    */
    return idx < dim;
}

double mioArray::get1(int idx) const{
    /*
        Prima funzione per richiedere un valore dall'array. 
        Viene svolto un check sull'indice e, se più grande della dimensione
        dell'array, viene stampato un messaggio a schermo.
        In ogni caso viene restituito il valore nella cella di memoria
        a cui punta mioarr[idx] = *(mioarr + idx)...Qualunque essa sia!

        -->Questo vuol dire che se, per sbaglio, sbagliamo l'indexing dell'array
        C++ non ci avvertirà ma restituirà un valore "a caso". C++
        non implementa check sui limiti degli oggetti (per mantenere alte performances).
    */
    if (!check_idx(idx)){
        std::cout << "L'indice inserito è più grande della dimensione dell'array" << std::endl;
    }      
    return mioarr[idx]; //questo non da mai errore
}

double mioArray::get2(int idx) const{
    /*
        Seconda funzione per richiedere un valore dall'array. 
        Viene svolto un check sull'indice e, se più grande della dimensione
        dell'array, viene lanciato un errore del tipo out_of_range con un messaggio a 
        piacere all'interno delle parentesi (). Se la richiesta è valida viene restituito il valore.
    */
    if (!check_idx(idx)){
        throw std::out_of_range ("L'indice inserito è più grande della dimensione dell'array\n");
    }      

    return mioarr[idx];
}



void mioArray::fill(int idx, double num){
    /*
        Metodo per riempire l'array. Richiesto in input l'indice (idx) e il valore
        da assegnare alla cella di memoria puntata da (mioarr+idx) -> mioarr[idx] = num.
        Se l'indice supera la dimensione dell'array viene visualizzato a terminale un messaggio 
        e non viene riempita la cella di memoria. 
        L'operazione mioarr[idx] = num funzionerebbe anche se idx > dim.
    */

    if (check_idx(idx)){
        mioarr[idx] = num;
        return;
    }
    else{
        std::cout << "L'indice inserito è più grande della dimensione dell'array" << std::endl;
        return;
    }

}

void mioArray::print() const{

    std::cout << "Mio array:" << std::endl;
    for(int i = 0; i < dim; i++){
        std::cout << mioarr[i] << " ";
    }
    std::cout << std::endl;

    return;
}
