#ifndef VETTORE_H
#define VETTORE_H

#include <cmath>

template <int N> 
class vettore{
  public:
    vettore();
    vettore (const vettore<N> & orig);
    ~vettore () {}; 
    void setCoord (int i, double val);
    double norm ();
    double at (int i) const;
    vettore<N> & operator= (const vettore<N> & orig);
    vettore<N> operator+ (const vettore<N> & orig);
    vettore<N> operator* (const double & fac);
    void operator += (const vettore<N> & orig);
    void operator *= (const double & orig);
    double & operator[] (int i);

  private:
    double elementi[N] ;
} ;

template <int N> 
vettore<N>::vettore(){
    for (int i = 0 ; i < N ; ++i) elementi[i] = 0. ;
}

template <int N> 
vettore<N>::vettore (const vettore<N> & orig){ 
    for (int i = 0 ; i < N ; ++i) elementi[i] = orig.elementi[i] ;
}

template <int N> 
void vettore<N>::setCoord (int i, double val){
    if (i < 0 || i > N-1) return ;
    elementi[i] = val ;
    return ;
}

template <int N> 
double vettore<N>::norm(){
    double sum = elementi[0] * elementi[0] ; 
    for (int i = 1 ; i < N ; ++i) sum += elementi[i] * elementi[i] ;
    return sqrt (sum) ;
}

template <int N> 
double vettore<N>::at (int i) const{
    if(i > N-1 || i < 0) {
        std::cout << "requested index out of array dimension. Return 0" << std::endl;
        return 0.;
    }
    return elementi[i] ;
}

template <int N> 
vettore<N> & vettore<N>::operator= (const vettore<N> & orig){
    for (int i = 0 ; i < N ; ++i) elementi[i] = orig.elementi[i] ;
    return *this ;
}

template <int N> 
vettore<N> vettore<N>::operator+ (const vettore<N> & orig){
    vettore<N> v;
    for (int i = 0 ; i < N ; ++i) v[i] = elementi[i] + orig.elementi[i] ;
    return v;
}


template <int N> 
vettore<N> vettore<N>::operator* (const double & fac){
    vettore<N> v;
    for (int i = 0 ; i < N ; ++i) v[i] = elementi[i] * fac ;
    return v ;
}

template <int N> 
void vettore<N>::operator+= (const vettore<N> & orig){
    for (int i = 0 ; i < N ; ++i) elementi[i] += orig.elementi[i] ;
    return;
}

template <int N> 
void vettore<N>::operator*= (const double & fac){
    for (int i = 0 ; i < N ; ++i) elementi[i] *= fac;
    return ;
}

template <int N> 
double & vettore<N>::operator[] (int i){
    return elementi[i] ;
}

#endif