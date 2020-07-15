#ifndef complesso_h
#define complesso_h

class complesso
{
public: 
  complesso (double r, double i) ;
  complesso (const complesso & orig) ;
  ~complesso () ;

  double modulo () ;      
  double fase () ;      

  void sommami (const complesso & aggiunta) ;


private:
  double m_real ;
  double m_imag ;
} ;



#endif