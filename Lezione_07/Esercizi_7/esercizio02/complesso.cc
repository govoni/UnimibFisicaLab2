#include "complesso.h"
#include <cmath>


//--------------Constructors------------------

complesso::complesso ():
  m_real (0.),
  m_imag (0.){}

complesso::complesso (double r):
  m_real (r),
  m_imag (0.){}

complesso::complesso (double r, double i):
  m_real (r),
  m_imag (i){}

complesso::complesso (const complesso & orig):
  m_real (orig.m_real),
  m_imag (orig.m_imag){
      //empty
}

//--------------Destructor------------------

complesso::~complesso (){
    // ~ deletes the "complesso" object and stack allocated memory.
    // This is the place to clean the dinamically allocated memory.
    // In this example we do not have dinamically allocated memory so the destructor is empty.

}

//--------------Public methods---------------

double complesso::modulo (){

    return sqrt(m_real * m_real + m_imag * m_imag) ;

}

double complesso::fase(){

    double mod = modulo();

    if (mod == 0){
        std::cout << "Parte reale e immaginaria = 0. La fase non è definita" << std::endl;
        return -1;
    }

    return acos(m_real/mod);
}


void complesso::stampami (){


    std::cout << this->m_real << " + " << this->m_imag << "i" << std::endl ;
    return ;

}


complesso complesso::somma(const complesso & orig){
  complesso ret(m_real + orig.m_real, m_imag + orig.m_imag);
  return ret;
}


complesso complesso::differenza(const complesso & orig){
  complesso ret(m_real - orig.m_real, m_imag - orig.m_imag);
  return ret;
}

complesso complesso::moltiplicazione(const complesso & fattore){
  const double m_real_copy(m_real), m_imag_copy(m_imag); //definisco copie da usare nelle operazioni
  double new_m_real = (m_real_copy*fattore.m_real) - (m_imag_copy*fattore.m_imag) ;
  double new_m_imag = (m_real_copy*fattore.m_imag) + (m_imag_copy*fattore.m_real) ;

  complesso ret(new_m_real, new_m_imag);
  return ret;
}

complesso complesso::moltiplicazione(const double & fattore){
  complesso ret(fattore*m_real, fattore*m_imag);
  return ret;
}


//--------------Overloading---------------

complesso &  complesso::operator= (const complesso & orig){
  m_real = orig.m_real ;
  m_imag = orig.m_imag ;
  return *this ;
}  

complesso complesso::operator+ (const complesso & addendo){
  complesso ret(m_real, m_imag);
  ret.m_real += addendo.m_real ;
  ret.m_imag += addendo.m_imag ;
  return ret;
}

void complesso::operator+= (const complesso & addendo){
  m_real = m_real + addendo.m_real ;
  m_imag = m_imag + addendo.m_imag ;
  return ;
}

void complesso::operator+= (const double & addendo){
  m_real = m_real + addendo;
  return ;
}

void complesso::operator-= (const complesso & addendo){
  m_real = m_real - addendo.m_real ;
  m_imag = m_imag - addendo.m_imag ;
  return ;
}

void complesso::operator-= (const double & addendo){
  m_real = m_real - addendo;
  return ;
}

void complesso::operator*= (const complesso & fattore){
  const double m_real_copy(m_real), m_imag_copy(m_imag); //definisco copie da usare nelle operazioni
  m_real = (m_real_copy*fattore.m_real) - (m_imag_copy*fattore.m_imag) ;
  m_imag = (m_real_copy*fattore.m_imag) + (m_imag_copy*fattore.m_real) ;
  return ;
}

void complesso::operator*= (const double & fattore){
  m_real = m_real*fattore ;
  m_imag = m_imag*fattore ;
  return ;
}

void complesso::operator/= (const complesso & fattore){

  double denom = (fattore.m_real*fattore.m_real) + (fattore.m_imag*fattore.m_imag); // c^2 + d^2

  //Controlli
  if (denom==0){ 
    if (fattore.m_real){
      m_real = m_real/fattore.m_real;
      return;
    }
    else{
      std::cout << "Divisione per 0, ricontrolla inputs" << std::endl;
      return;
    }
  }

  const double m_real_copy(m_real), m_imag_copy(m_imag); //definisco copie da usare nelle operazioni
  m_real = (m_real_copy*fattore.m_real + m_imag_copy*fattore.m_imag)/denom ;
  m_imag = (m_imag_copy*fattore.m_real - m_real_copy*fattore.m_imag)/denom ;
  return ;
}

void complesso::operator/= (const double & fattore){

  if(fattore == 0){
    std::cout << "Errore: Divisione per 0" << std::endl;
    return;
  }

  m_real = m_real/fattore ;
  m_imag = m_imag/fattore ;
  return ;
}
