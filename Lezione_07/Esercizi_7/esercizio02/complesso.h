#include <iostream>

#ifndef COMPLESSO_H
#define COMPLESSO_H

class complesso{

public: 
    // Constructors
    complesso();
    complesso(double r); 
    complesso (double r, double i) ; 
    complesso (const complesso & orig);
    // Destructor
    ~complesso () ;

    // Public class methods
    double modulo () ;      
    double fase () ;  
    void stampami();  
    double get_real() { return m_real; };
    double get_imag() { return m_imag; };
    complesso somma(const complesso & orig);
    complesso differenza(const complesso & orig);
    complesso moltiplicazione(const double & fattore);
    complesso moltiplicazione(const complesso & fattore);

    // Operators overloading
    complesso &  operator= (const complesso & orig);
    complesso operator+ (const complesso & addendo);
    void operator+= (const complesso & addendo);
    void operator+= (const double & addendo);
    void operator-= (const complesso & addendo);
    void operator-= (const double & addendo);
    void operator*= (const complesso & fattore);
    void operator*= (const double & fattore);
    void operator/= (const complesso & fattore);
    void operator/= (const double & fattore);
    

private:
    // Private members
    double m_real ;
    double m_imag ;

} ;

#endif // COMPLESSO_H
