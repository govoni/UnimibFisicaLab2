#include <cmath>
#include <iostream>
#include "complesso.h"


complesso::complesso (double r, double i):
  m_real (r),
  m_imag (i)
  {}

complesso::complesso (const complesso & orig):
  m_real (orig.m_real),
  m_imag (orig.m_imag)
  {}

complesso::~complesso () {}

double 
complesso::modulo ()
  {
    return sqrt (m_real * m_real + m_imag * m_imag) ;
  }

double 
complesso::parte_reale () const
{
  return m_real ;
}

double 
complesso::parte_immaginaria () const
{
  return m_imag ;
}

void
complesso::stampami ()
{
  std::cout << this->m_real << " + " << this->m_imag << "i" << std::endl ;
  return ;
}

complesso
complesso::operator+ (const complesso & addendo)
{
 complesso somma (m_real, m_imag) ;
 somma.m_real = somma.m_real + addendo.m_real ;
 somma.m_imag = somma.m_imag + addendo.m_imag ;
 return somma ;
}

complesso & 
complesso::operator= (const complesso & orig)
{
  m_real = orig.m_real ;
  m_imag = orig.m_imag ;
  return *this ;
}  

complesso operator+ (const complesso & uno, const double & due)
  {
    double real = uno.parte_reale () + due ;
    double imag = uno.parte_immaginaria () ;
    complesso somma (real, imag) ;
    return somma ;
  }
