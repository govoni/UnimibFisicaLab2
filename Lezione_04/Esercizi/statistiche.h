
#ifndef statistiche_h
#define statistiche_h

#include <iostream>
#include <cmath>

//----------------- Statistic class -----------------

class statistiche
{
  public:

  statistiche (): dim(10), last_idx(0), arr (new float[dim]), sum (0.), sum_q (0.) {};
  statistiche (int d): dim(d), last_idx(0), arr(dim ? new float[dim] : nullptr), sum (0.), sum_q (0.) {} ;
  ~statistiche () { delete[] arr; } ;

  // aggiunge un numero alle informazioni salvate
  void aggiungiNumero (float val);

 
  // resituisce la media dei numeri aggiunti
  double media () const ;
  // restituisce la varianza dei numeri aggiunti
  // in caso di opzione true, applica la correzione di Bessel
  double varianza_1 (bool corretta = false) const ;
  // restituisce la varianza dei numeri aggiunti
  // in caso di opzione true, applica la correzione di Bessel
  double varianza_2 (bool corretta = false) const ;
  // resituisce la deviazione standard
  // in caso di opzione true, applica la correzione di Bessel
  double dev_standard (bool corretta = false) const ;
  // resituisce la deviazione standard dalla media
  double dev_standard_media (bool corretta = false) const ;
  //restituisce varianza degli scarti quadratici
  double varianza_SQ(bool corretta = false) const;
  //restituisce std dev degli scarti quadratici
  double dev_standard_SQ(bool corretta = false) const;
  //restituisce std dev della media degli scarti quadratici
  double dev_standard_media_SQ(bool corretta = false) const;
  // resituisce il numero dei numeri aggiunti
  double N () const { return last_idx; } ;
  //reset
  void reset() { for(int i = 0; i < last_idx; ++i) arr[i] = 0; last_idx = 0; sum = 0. ; sum_q = 0. ;};

  private:
    int dim;
    int last_idx;
    float* arr;
    double sum ;
    double sum_q ;

   
} ;

#endif