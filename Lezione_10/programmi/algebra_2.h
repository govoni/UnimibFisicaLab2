#ifndef algebra_2_h
#define algebra_2_h

#include <cmath>
#include <vector>

class matrice ;

class vettore 
{
  public:
    vettore (int N) ;
    vettore (const std::vector<double> & v) ;
    vettore (const vettore & orig) ;
    vettore & operator = (const vettore & orig) ;
    ~vettore () ;

    void    setCoord (int i, double val) ;
    double  norm () const ;
    int     N () const ;
    double  at (int i) const ;
    void    stampa () const ;
    double  operator[] (int i) const ;
    vettore operator+ (const vettore & v) const ;
    vettore operator- (const vettore & v) const ;
    vettore operator* (double val) const ;
    double  dot (const vettore & v) const ;

  private:
    double * m_elementi ;
    int m_N ;
} ;


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----


class matrice
{
  public:
    matrice (int R) ;
    matrice (int R, int C) ;
    matrice (const matrice & orig) ;
    matrice & operator= (const matrice & orig) ;
    ~matrice () ;

    void    setCoord (int i, int j, double val) ;
    double  at (int i, int j) const ;
    void    stampa () const ;
    bool    quadrata () const ;
    int     rango () const ;
    int     N_righe () const ;
    int     N_colonne () const ;
    bool    simmetrica () const ;
    void    dimensioni () const ;
    matrice minore (int r, int c) const ;
    matrice inversa () const ;
    matrice trasposta () const ;
    double  determinante () const ;
    void    operator*= (double val) ;

  private:
    int index (int i, int j) const ;
    int m_R ;
    int m_C ;
    double * m_elementi ;
} ;


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----


vettore operator* (const matrice & M, const vettore & v) ;
matrice operator* (const matrice & M1, const matrice & M2) ;
matrice operator+ (const matrice & M1, const matrice & M2) ;

#endif