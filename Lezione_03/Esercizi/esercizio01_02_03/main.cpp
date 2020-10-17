//c++ -o main main.cpp complesso.cc

#include "complesso.h"

int main(){

    //-----------  Testing constructors  -----------

    complesso c_num1; //default
    c_num1.stampami();

    complesso c_num2(1); //real
    c_num2.stampami();

    complesso c_num3(3,5); //real + i*imag
    c_num3.stampami();

    complesso c_num_copy(c_num2); //copying, only real
    c_num_copy.stampami();

    //-----------  Testing destructor in a new scope ({})  -----------

    {
        complesso in_new_scope;
        
    } // here "in_new_scope" goes out of scope and destructor is called.

    //-----------  Testing class methods  -----------

    std::cout << "Il modulo di 3 +i5 è: " << c_num3.modulo() << " la fase è: " << c_num3.fase() << std::endl;


    // Trying to compute the phase of 0 + i0 (0/0). Catching the exception to continue
    try {
      double fase_impossibile = c_num1.fase(); 
    } catch (const char* msg) {
     std::cerr << msg << std::endl;
    }

    //-----------  Testing overloading =, +, *  -----------

    std::cout << "Test overloading operatori" << std::endl;
    c_num1 = c_num3;    // = overloading
    c_num1.stampami();

    c_num1 += 1;        // += numero reale
    c_num1.stampami();
    c_num1 += c_num3;   // += numero complesso
    c_num1.stampami();
    c_num1 -= 1;        // -= numero reale
    c_num1.stampami();
    c_num1 -= c_num3;   // -= numero complesso
    c_num1.stampami();

    c_num1 *= 2;        // *= numero reale
    c_num1.stampami();
    c_num1 *= c_num3;   // *= numero complesso
    c_num1.stampami();
    c_num1 /= 2;        // /= numero reale
    c_num1.stampami();
    c_num1 /= c_num3;   // /= numero complesso
    c_num1.stampami();

    //----------- End -----------

    std::cout << "Al termine dell'esecuzione della funzione main" \
                    " verrà distrutto tutto ciò creato al suo interno: " << std::endl;

    return 0;
}