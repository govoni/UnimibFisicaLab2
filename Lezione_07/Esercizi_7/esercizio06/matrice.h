#ifndef MATRICE_H
#define MATRICE_H

#include <iostream>
#include <cmath>
#include "../esercizio05/vettore.h"

template <int R, int C>
class Matrice{
    public:

        Matrice ();
        Matrice (const Matrice<R,C>& orig);
        ~Matrice () {};

        void setCoord(const int& i, const int& j, const double& val);
        double at (const int& i, const int& j) const;
        void stampa();
        bool quadrata() const;
        int rango() const;
        bool simmetrica() const;
        double determinante() const;
        Matrice<R-1, C-1> minore (const int& r, const int& c) const;
        Matrice<C, R> inversa () const;
        Matrice<C, R> trasposta () const;
        vettore<R> operator* (const vettore<C>& v);



    private:
        double elementi[R][C];

};

template <int R, int C>
Matrice<R,C>::Matrice(){
    for (int i = 0 ; i < R ; ++i) 
          for (int j = 0 ; j < C ; ++j) 
            elementi[i][j] = 0. ;
}

template <int R, int C>
Matrice<R,C>::Matrice(const Matrice<R,C>& orig){
    for (int i = 0 ; i < R ; ++i) 
          for (int j = 0 ; j < C ; ++j) 
            elementi[i][j] = orig.elementi[i][j] ;
}

template <int R, int C>
void Matrice<R,C>::setCoord(const int& i, const int& j, const double& val){

    if (i < 0 || i > R-1) return ;
    if (j < 0 || j > C-1) return ;
    elementi[i][j] = val ;
    return ;
}

template <int R, int C>
double Matrice<R,C>::at(const int& i, const int& j) const{

    if (i < 0 || i > R-1) return 0.;
    if (j < 0 || j > C-1) return 0.;
    return elementi[i][j];
}

template <int R, int C>
void Matrice<R,C>::stampa(){
    for (int i = 0 ; i < R ; ++i){
        for (int j = 0 ; j < C ; ++j)
            std::cout << this->at (i, j) << "\t" ;
        std::cout << "\n" ;
    }
}

template <int R, int C>
bool Matrice<R,C>::quadrata () const {return (R == C) ;} 

template <int R, int C>
int Matrice<R,C>::rango () const {
    if(quadrata()) return R ;
    else{
        std::cout << "Matrix not square. Returning -1" << std::endl;
        return -1;
    }
}

template <int R, int C>
bool Matrice<R,C>::simmetrica () const{
    if (!this->quadrata ()) return false ;
    for (int i = 0 ; i < R ; ++i){
        for (int j = i+1 ; j < R ; ++j)
        if (fabs (elementi[i][j] - elementi[j][i]) > 0.00001) return false ;
    }
    return true ;
}

template <int R, int C>
double Matrice<R,C>::determinante () const{
    if (!this->quadrata ()){
        std::cout << "Matrix not square. Returning -1" << std::endl;
        return -1;
    }

    double det = 0. ;
    for (int i = 0 ; i < R ; ++i){
        det += elementi[0][i] * pow (-1, i + 2) * this->minore (0,i).determinante () ;
    }

    return det ; 
}

template<>
double Matrice<1,1>::determinante () const { return elementi[0][0] ; }

template <int R, int C>
Matrice<R-1, C-1> Matrice<R,C>::minore (const int& r, const int& c) const{
    Matrice<R-1, C-1> M_out ;
    int i_new = 0 ; 
    for (int i = 0 ; i < R ; ++i){
        if (i == r) continue ;
        int j_new = 0 ;
        for (int j = 0 ; j < C ; ++j){
            if (j == c) continue ;
            M_out.setCoord (i_new, j_new, this->at (i,j)) ;
            ++j_new ;
        }
        ++i_new ;
    }
    return M_out ;  
}

template <int R, int C>
Matrice<C, R> Matrice<R,C>::inversa () const{
    Matrice<C, R> M_out ;

    double invdet = 0.;
    try{
        invdet = this->determinante () ;
    }
    catch (const std::domain_error& de){
        std::cerr << de.what() << std::endl;
        return M_out ;
    }

    if (invdet < 0.000001) return M_out ;

    for (int i = 0 ; i < R ; ++i){
        for (int j = 0 ; j < C ; ++j){
            M_out.setCoord (
                j, i,  // trasposta
                this->minore (i,j).determinante () * pow (-1, i+j+2) // complemento algebrico
                * invdet  // divisione per il determinante
            ) ;
        }
    }

    return M_out ;
}

template <int R, int C>
Matrice<C, R> Matrice<R,C>::trasposta () const{

    Matrice<C, R> M_out ;
    for (int i = 0 ; i < R ; ++i){
        for (int j = 0 ; j < C ; ++j)
        M_out.setCoord (j, i, this->at (i,j)) ;
    }

    return M_out ;  
}


template <int R, int C>
vettore<R> Matrice<R,C>::operator* (const vettore<C>& v){
    vettore<R> w ;

    for (int i = 0 ; i < R ; ++i){
        double res = 0 ;
        for (int j = 0 ; j < C ; ++j) res += (this->at (i,j) * v.at (j));
        w.setCoord (i, res) ;
    }

    return w ;
}

template <int M, int N, int O>
Matrice<M,O> operator* (const Matrice<M,N> & M1, const Matrice<N,O> & M2){
    Matrice<M,O> M_out ;

    for (int i = 0 ; i < M ; ++i){
        for (int k = 0 ; k < O ; ++k){
            double res = 0 ;
            for (int j = 0 ; j < N ; ++j) res += M1.at (i,j) * M2.at (j,k) ;
            M_out.setCoord (i, k, res) ;
        }
    }
    return M_out ;
}

#endif