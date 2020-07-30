/*
c++ -o main_06 main_06.cpp
*/

#include <iostream>
#include <cmath>
#include "somma.h"

template <int N> 
class vettore 
{
  public:
    vettore ()
      {
        for (int i = 0 ; i < N ; ++i) elementi[i] = 0. ;
      }
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

  private:
    float elementi[N] ;
} ;


int main (int argc, char ** argv)
  {
    vettore<2> v1 ;
    v1.setCoord (0, 3.) ;
    v1.setCoord (1, 4.) ;
    std::cout << v1.norm () << std::endl ;
    return 0 ;
  }
