#include "algebra_2.h"

#include <iostream>

using namespace std ;

vettore::vettore (int N) : 
  m_N (N),
  m_elementi (new double[N])
  {
    for (int i = 0 ; i < m_N ; ++i) m_elementi[i] = 0. ;
  }

// .... .... .... .... .... .... .... .... .... .... .... .... .... ....

vettore::vettore (const std::vector<double> & v) :
  m_N (v.size ()),
  m_elementi (new double[v.size ()])
  {
    for (int i = 0 ; i < m_N ; ++i) m_elementi[i] = v.at (i) ;
  }

// .... .... .... .... .... .... .... .... .... .... .... .... .... ....

vettore::vettore (const vettore & orig) : 
  m_N (orig.m_N),
  m_elementi (new double[orig.m_N])
  {
    for (int i = 0 ; i < m_N ; ++i) m_elementi[i] = orig.m_elementi[i] ;
  }

// .... .... .... .... .... .... .... .... .... .... .... .... .... ....

vettore & vettore::operator = (const vettore & orig)
  {
    m_N = orig.m_N ;
    m_elementi = new double[m_N] ;
    for (int i = 0 ; i < m_N ; ++i) m_elementi[i] = orig.m_elementi[i] ;
    return *this ;
  }

// .... .... .... .... .... .... .... .... .... .... .... .... .... ....

vettore::~vettore () { delete [] m_elementi ; } 

// .... .... .... .... .... .... .... .... .... .... .... .... .... ....

void vettore::setCoord (int i, double val)
  {
    if (i < 0 || i > m_N-1) return ;
    m_elementi[i] = val ;
    return ;
  }

// .... .... .... .... .... .... .... .... .... .... .... .... .... ....

double vettore::norm () const
  {
    double sum = m_elementi[0] * m_elementi[0] ; 
    for (int i = 1 ; i < m_N ; ++i) sum += m_elementi[i] * m_elementi[i] ;
    return sqrt (sum) ;
  }

// .... .... .... .... .... .... .... .... .... .... .... .... .... ....

int vettore::N () const {return m_N ;}

// .... .... .... .... .... .... .... .... .... .... .... .... .... ....

double vettore::at (int i) const
  {
    if (i < 0 || i > m_N-1) return 0. ;
    return m_elementi[i] ;
  }

// .... .... .... .... .... .... .... .... .... .... .... .... .... ....

void vettore::stampa () const
  {
    for (int i = 0 ; i < m_N ; ++i)
      cout << this->at (i) << "\t" ;
    cout << "\n" ;
  }

// .... .... .... .... .... .... .... .... .... .... .... .... .... ....

double vettore::operator[] (int i) const
  {
    return m_elementi[i] ;
  }

// .... .... .... .... .... .... .... .... .... .... .... .... .... ....

vettore vettore::operator+ (const vettore & v) const 
  {
    vettore result (*this) ;
    for (int i = 0 ; i < m_N ; ++i) 
      result.setCoord (i, result.at (i) + v.at (i)) ;
    return result ;
  }

// .... .... .... .... .... .... .... .... .... .... .... .... .... ....

vettore vettore::operator- (const vettore & v) const 
  {
    vettore result (*this) ;
    for (int i = 0 ; i < m_N ; ++i) 
      result.setCoord (i, result.at (i) - v.at (i)) ;
    return result ;
  }

// .... .... .... .... .... .... .... .... .... .... .... .... .... ....

vettore vettore::operator* (double val) const 
  {
    vettore result (*this) ;
    for (int i = 0 ; i < m_N ; ++i) 
      result.setCoord (i, result.at (i) * val) ;
    return result ;
  }

// .... .... .... .... .... .... .... .... .... .... .... .... .... ....

double vettore::dot (const vettore & v) const
  {
    if (m_N != v.N ())
      {
        cerr << "prodotto scalare fra vettori di dimensione diversa" << endl ;
        exit (1) ;
      }
    double result = 0 ;
    for (int i = 0 ; i < m_N ; ++i) result += this->at (i) * v.at (i) ; 
    return result ;
  }

// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----

matrice::matrice (int R) :
  m_R (R),
  m_C (R),
  m_elementi (new double [R * R]) 
  {
    for (int i = 0 ; i < m_R ; ++i) 
      for (int j = 0 ; j < m_C ; ++j) 
        this->setCoord (i, j, 0.) ;
  }

// .... .... .... .... .... .... .... .... .... .... .... .... .... ....

matrice::matrice (int R, int C) :
  m_R (R),
  m_C (C),
  m_elementi (new double [R * C]) 
  {
    for (int i = 0 ; i < m_R ; ++i) 
      for (int j = 0 ; j < m_C ; ++j) 
        this->setCoord (i, j, 0.) ;
  }

// .... .... .... .... .... .... .... .... .... .... .... .... .... ....

matrice::matrice (const matrice & orig) :
  m_R (orig.m_R),
  m_C (orig.m_C),
  m_elementi (new double [orig.m_R * orig.m_C]) 
  {
    for (int i = 0 ; i < m_R ; ++i) 
      for (int j = 0 ; j < m_C ; ++j) 
        this->setCoord (i, j, orig.at (i,j)) ;
  }

// .... .... .... .... .... .... .... .... .... .... .... .... .... ....

matrice & matrice::operator= (const matrice & orig)
  {
    m_R = orig.m_R ;
    m_C = orig.m_C ;
    m_elementi = new double [orig.m_R * orig.m_C] ;
    for (int i = 0 ; i < m_R ; ++i) 
      for (int j = 0 ; j < m_C ; ++j) 
        this->setCoord (i, j, orig.at (i,j)) ;
    return *this ;
  }

// .... .... .... .... .... .... .... .... .... .... .... .... .... ....

matrice::~matrice () { delete [] m_elementi ; } 

// .... .... .... .... .... .... .... .... .... .... .... .... .... ....

int matrice::index (int i, int j) const 
  {
    int index = j + i * m_C ;
    if (index < 0 || index >= m_R * m_C) 
      {
        cerr << "indici matrice fuori intervallo" << endl ;
        exit (1) ;
      }  
    return index ; 
  } 

// .... .... .... .... .... .... .... .... .... .... .... .... .... ....

void matrice::setCoord (int i, int j, double val)
  {
    m_elementi[index (i, j)] = val ;
    return ;
  }

// .... .... .... .... .... .... .... .... .... .... .... .... .... ....

double matrice::at (int i, int j) const
  {
    return m_elementi[index (i, j)] ;
  }

// .... .... .... .... .... .... .... .... .... .... .... .... .... ....

void matrice::stampa () const
  {
    for (int i = 0 ; i < m_R ; ++i)
      {
        for (int j = 0 ; j < m_C ; ++j)
          cout << this->at (i, j) << "\t" ;
        cout << "\n" ;
      }
  }

// .... .... .... .... .... .... .... .... .... .... .... .... .... ....

bool matrice::quadrata () const {return (m_R == m_C) ;} 

// .... .... .... .... .... .... .... .... .... .... .... .... .... ....

// per matrici quadrate
int matrice::rango () const {return m_R ;}

// .... .... .... .... .... .... .... .... .... .... .... .... .... ....

// per matrici quadrate
int matrice::N_righe () const {return m_R ;}

// .... .... .... .... .... .... .... .... .... .... .... .... .... ....

// per matrici quadrate
int matrice::N_colonne () const {return m_C ;}

// .... .... .... .... .... .... .... .... .... .... .... .... .... ....

bool matrice::simmetrica () const
  {
    if (!this->quadrata ()) return false ;
    for (int i = 0 ; i < m_R ; ++i)
      for (int j = i+1 ; j < m_R ; ++j)
        if (fabs (this->at (i,j) - this->at (j,i)) > 0.00001) return false ;
    return true ;
  }

// .... .... .... .... .... .... .... .... .... .... .... .... .... ....

void matrice::dimensioni () const { cout << m_R << " x " << m_C << endl ; } 

// .... .... .... .... .... .... .... .... .... .... .... .... .... ....

// produce la sottomatrice in cui mancano riga r e colonna c
matrice matrice::minore (int r, int c) const
  {
    matrice M_out (m_R-1, m_C-1) ;
    int i_new = 0 ; 
    for (int i = 0 ; i < m_R ; ++i)
      {
        if (i == r) continue ;
        int j_new = 0 ;
        for (int j = 0 ; j < m_C ; ++j)
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

matrice matrice::inversa () const
  {
    double invdet = this->determinante () ;
    matrice M_out (m_C, m_R) ;
    if (invdet < 0.000001) return M_out ;
    invdet = 1. / invdet ;
    for (int i = 0 ; i < m_R ; ++i)
      {
        for (int j = 0 ; j < m_C ; ++j)
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

matrice matrice::trasposta () const
  {
    matrice M_out (m_C, m_R) ;
    for (int i = 0 ; i < m_R ; ++i)
      for (int j = 0 ; j < m_C ; ++j)
        M_out.setCoord (j, i, this->at (i,j)) ;
    return M_out ;  
  }

// .... .... .... .... .... .... .... .... .... .... .... .... .... ....

double matrice::determinante () const
  {
    if (!this->quadrata ()) return 0. ;
    if (this->rango () == 1) return this->at (0,0) ;
    double det = 0. ;
    for (int i = 0 ; i < m_R ; ++i)
      {
        det += this->at (0,i) * pow (-1, i + 2) * this->minore (0,i).determinante () ;
      }
    return det ; 
  }

// .... .... .... .... .... .... .... .... .... .... .... .... .... ....

void matrice::operator*= (double val)
  {
    for (int i = 0 ; i < m_R * m_C ; ++i)
      {
        m_elementi[i] *= val ;
      }
    return ; 
  }

// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----

vettore operator* (const matrice & M, const vettore & v)
  {
    if (M.N_colonne () != v.N ())
      {
        cerr << "prodotto fra matrice e vettore con dimensioni non compatibili" << endl ;
        exit (1) ;
      }
  
    vettore w (M.N_righe ()) ;
  
    for (int i = 0 ; i < M.N_righe () ; ++i)
      {
        double res = 0 ;
        for (int j = 0 ; j < M.N_colonne () ; ++j) res += M.at (i,j) * v.at (j) ;
        w.setCoord (i, res) ;
      }
    return w ;
  }

// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----

matrice operator* (const matrice & M1, const matrice & M2)
  {
    if (M1.N_colonne () != M2.N_righe ())
      {
        cerr << "prodotto fra matrici con dimensioni non compatibili" << endl ;
        exit (1) ;
      }
  
    matrice M_out (M1.N_righe (), M2.N_colonne ()) ;
  
    for (int i = 0 ; i < M1.N_righe () ; ++i)
      for (int k = 0 ; k < M2.N_colonne () ; ++k)
        {
          double res = 0 ;
          for (int j = 0 ; j < M1.N_colonne () ; ++j) res += M1.at (i,j) * M2.at (j,k) ;
          M_out.setCoord (i, k, res) ;
        }
    return M_out ;
  }

// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----

matrice operator+ (const matrice & M1, const matrice & M2)
  {
    if (M1.N_colonne () != M2.N_colonne () ||
        M1.N_righe () != M2.N_righe ())
      {
        cerr << "somma fra matrici con dimensioni non compatibili" << endl ;
        exit (1) ;
      }
  
    matrice M_out (M1.N_righe (), M1.N_colonne ()) ;
  
    for (int i = 0 ; i < M1.N_righe () ; ++i)
      for (int k = 0 ; k < M1.N_colonne () ; ++k)
        {
          M_out.setCoord (i, k, M1.at (i,k) + M2.at (i,k)) ;
        }
    return M_out ;
  }

