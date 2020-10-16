#ifndef MY_ARRAY_H
#define MY_ARRAY_H

#include <iostream> 

class mioArray{

    public:

        //Il costruttore prende in input la dimensione e inizializza il membro ( dim(d) ).
        //Successivamente crea dinamicamente l'array mioarr(). Nell'espressione logica tra parentesi
        //si chiede (simbolo ?) se dim > 0 (interi diversi da 0 sono true). Se è vero allora viene
        //inizializzato l'array (new double[dim]) altrimenti (:) viene inizializzato l'oggetto a nullptr.
        mioArray(int d): dim(d), mioarr(dim ? new double[dim] : nullptr) {}; 
        mioArray(const mioArray& copy);
        ~mioArray(){ delete[] mioarr; };

        bool check_idx(int idx) const;
        double get1(int idx) const;
        double get2(int idx) const;
        void fill(int idx, double num);
        void print() const; //opzionale, solo per comodità

    private:
        int dim;
        double* mioarr;


};

#endif //MY_ARRAY_H