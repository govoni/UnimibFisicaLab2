#ifndef complesso_h
#define complesso_h

class complesso
{
public: 
  complesso (double r, double i) ;
  ~complesso () ;

  double modulo () ;      
  double fase () ;      

private:
  double m_real ;
  double m_imag ;
} ;



#endif