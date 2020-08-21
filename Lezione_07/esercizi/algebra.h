#ifndef algebra_h
#define algebra_h

#include <cmath>

template <int N> 
class vettore 
{
  public:
    vettore ()
      {
        for (int i = 0 ; i < N ; ++i) elementi[i] = 0. ;
      }

    vettore (const vettore<N> & orig)
      {
        for (int i = 0 ; i < N ; ++i) elementi[i] = orig.elementi[i] ;
      }

    vettore<N> & operator = (const vettore<N> & orig)
      {
        for (int i = 0 ; i < N ; ++i) elementi[i] = orig.elementi[i] ;
        return *this ;
      }

    ~vettore () {} 

    void setCoord (int i, double val)
      {
        if (i < 0 || i > N-1) return ;
        elementi[i] = val ;
        return ;
      }
    double norm ()
      {
        double sum = elementi[0] * elementi[0] ; 
        for (int i = 1 ; i < N ; ++i) sum += elementi[i] * elementi[i] ;
        return sqrt (sum) ;
      }

    double at (int i) const
      {
        if (i < 0 || i > N-1) return 0. ;
        return elementi[i] ;
      }

    double operator[] (int i) const
      {
        return elementi[i] ;
      }

  private:
    double elementi[N] ;
} ;


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----


template <int R, int C>
class matrice
{
  public:
    matrice ()
      {
        for (int i = 0 ; i < R ; ++i) 
          for (int j = 0 ; j < C ; ++j) 
            elementi[i][j] = 0. ;
      }

    // .... .... .... .... .... .... .... .... .... .... .... .... .... ....

    matrice (const matrice<R,C> & orig)
      {
        for (int i = 0 ; i < R ; ++i) 
          for (int j = 0 ; j < C ; ++j) 
            elementi[i][j] = orig.elementi[i][j] ;
      }

    // .... .... .... .... .... .... .... .... .... .... .... .... .... ....

    matrice<R,C> & operator= (const matrice<R,C> & orig)
      {
        for (int i = 0 ; i < R ; ++i) 
          for (int j = 0 ; j < C ; ++j) 
            elementi[i][j] = orig.elementi[i][j] ;
        return *this ;
      }

    // .... .... .... .... .... .... .... .... .... .... .... .... .... ....

    ~matrice () {} 

    // .... .... .... .... .... .... .... .... .... .... .... .... .... ....

    void setCoord (int i, int j, double val)
      {
        if (i < 0 || i > R-1) return ;
        if (j < 0 || j > C-1) return ;
        elementi[i][j] = val ;
        return ;
      }

    // .... .... .... .... .... .... .... .... .... .... .... .... .... ....

    double at (int i, int j) const
      {
        if (i < 0 || i > R-1) return 0. ;
        if (j < 0 || j > C-1) return 0. ;
        return elementi[i][j] ;
      }

    // .... .... .... .... .... .... .... .... .... .... .... .... .... ....

    void stampa () 
      {
        for (int i = 0 ; i < R ; ++i)
          {
            for (int j = 0 ; j < C ; ++j)
              std::cout << this->at (i, j) << "\t" ;
            std::cout << "\n" ;
          }
      }

    // .... .... .... .... .... .... .... .... .... .... .... .... .... ....

    bool quadrata () const {return (R == C) ;} 

    // .... .... .... .... .... .... .... .... .... .... .... .... .... ....

    // per matrici quadrate
    int rango () const {return R ;}

    // .... .... .... .... .... .... .... .... .... .... .... .... .... ....

    bool simmetrica () const
      {
        if (!this->quadrata ()) return false ;
        for (int i = 0 ; i < R ; ++i)
          for (int j = i+1 ; j < R ; ++j)
            if (fabs (elementi[i][j] - elementi[j][i]) > 0.00001) return false ;
        return true ;
      }

    // .... .... .... .... .... .... .... .... .... .... .... .... .... ....

    void dimensioni () const { std::cout << R << " x " << C << std::endl ; } 

    // .... .... .... .... .... .... .... .... .... .... .... .... .... ....

    // produce la sottomatrice in cui mancano riga r e colonna c
    matrice<R-1, C-1> minore (int r, int c) const
      {
        matrice<R-1, C-1> M_out ;
        int i_new = 0 ; 
        for (int i = 0 ; i < R ; ++i)
          {
            if (i == r) continue ;
            int j_new = 0 ;
            for (int j = 0 ; j < C ; ++j)
              {
                if (j == c) continue ;
                M_out.setCoord (i_new, j_new, this->at (i,j)) ;
                ++j_new ;
              }
            ++i_new ;
          }
        return M_out ;  
      }

    // .... .... .... .... .... .... .... .... .... .... .... .... .... ....

    matrice<C, R> inversa () const
      {
        double invdet = this->determinante () ;
        matrice<C, R> M_out ;
        if (invdet < 0.000001) return M_out ;
        invdet = 1. / invdet ;
        for (int i = 0 ; i < R ; ++i)
          {
            for (int j = 0 ; j < C ; ++j)
              {
                M_out.setCoord (
                   j, i,  // trasposta
                   this->minore (i,j).determinante () * pow (-1, i+j+2) // complemento algebrico
                   * invdet  // divisione per il determinante
                ) ;
              }
          }
        return M_out ;
      }

    // .... .... .... .... .... .... .... .... .... .... .... .... .... ....

    // produce la sottomatrice in cui mancano riga r e colonna c
    matrice<C, R> trasposta () const
      {
        matrice<C, R> M_out ;
        for (int i = 0 ; i < R ; ++i)
          for (int j = 0 ; j < C ; ++j)
            M_out.setCoord (j, i, this->at (i,j)) ;
        return M_out ;  
      }

    // .... .... .... .... .... .... .... .... .... .... .... .... .... ....

    double determinante () const
      {
        if (!this->quadrata ()) return 0. ;  
        double det = 0. ;
        for (int i = 0 ; i < R ; ++i)
          {
            det += elementi[0][i] * pow (-1, i + 2) * this->minore (0,i).determinante () ;
          }
        return det ; 
      }

  private:

    double elementi[R][C] ;

} ;


template<>
double matrice<1,1>::determinante () const { return elementi[0][0] ; }


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----


template <int R, int C>
vettore<R> operator* (const matrice<R,C> & M, const vettore<C> v)
{
  vettore<R> w ;

  for (int i = 0 ; i < R ; ++i)
    {
      double res = 0 ;
      for (int j = 0 ; j < C ; ++j) res += M.at (i,j) * v.at (j) ;
      w.setCoord (i, res) ;
    }
  return w ;
}


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----


template <int M, int N, int O>
matrice<M,O> operator* (const matrice<M,N> & M1, const matrice<N,O> & M2)
{
  matrice<M,O> M_out ;

  for (int i = 0 ; i < M ; ++i)
    for (int k = 0 ; k < O ; ++k)
      {
        double res = 0 ;
        for (int j = 0 ; j < N ; ++j) res += M1.at (i,j) * M2.at (j,k) ;
        M_out.setCoord (i, k, res) ;
      }
  return M_out ;
}



#endif