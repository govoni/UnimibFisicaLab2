#ifndef generatori_h
#define generatori_h

#include <cmath>
#include <cstdlib>

class generatori
{
  public:

    generatori () :
      xMin (0.),
      xMax (0.),
      yMax (0.),
      N(0)
      {}

    ~generatori () {}
       

float rand_range (float min, float max)
  {
    return min + (max - min) * rand () / static_cast<float> (RAND_MAX) ;
  } 


float rand_TAC (float f (float), float xMin, float xMax, float yMax)
 {
    float x = 0. ;
    float y = 0. ; 
    do {
      x = rand_range (xMin, xMax) ;
      y = rand_range (0, yMax) ;
    } while (y > f (x)) ;
    return x ; 
}


float rand_TCL (float xMin, float xMax, int N )
  {
    float y = 0. ; 
    for (int i = 0 ; i < N ; ++i)
      y += rand_range (xMin, xMax) ;
    y /= N ;
    return y ;
  }    

  private:  
  
    float xMin ;
    float xMax ;
    float yMax;
    int N;

} ;


#endif
