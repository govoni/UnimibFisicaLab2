#include <cmath>
#include "complesso.h"


complesso::complesso (double r, double i):
  m_real (r),
  m_imag (i)
  {}

complesso::~complesso () {}

double complesso::modulo ()
  {
    return sqrt (m_real * m_real + m_imag * m_imag) ;
  }