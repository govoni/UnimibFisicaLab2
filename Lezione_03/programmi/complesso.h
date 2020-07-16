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
  double parte_reale () const ;
  double parte_immaginaria () const ;

  void stampami () ; 

  complesso operator+ (const complesso & addendo) ;  
  complesso & operator= (const complesso & orig) ;  

private:
  double m_real ;
  double m_imag ;
} ;

complesso operator+ (const complesso & uno, const double & due) ;


#endif