/*
c++ -o es1 esercizio01.cpp

Testo:
    Si scriva una funzione somma che, utilizzando la tecnologia template, 
    sia applicabile a qualunque tipo numerico del C++

*/


#include <iostream>

//-------------- Template sum -----------------

template <typename T1, typename T2>
double somma_d (T1 a, T2 b){ //returning double -> somma_b(a,b) = somma_b(b,a) for each c++ type of b and a
    return a + b ;
}

template <typename T1, typename T2>
T2 somma_t (T1 a, T2 b){ //returning T2 -> somma_t(a,b) != somma_t(b,a)
    return a + b ;
}

//--------- Optional: Variadic sum ------------

//Iterative way to sum numbers sum(a,b,c,...)

//base-case (only one number in input or last number in the recursion)
template<typename T>
double sum(T v) {
    return v;
}

//... is called parameter pack of zero or more template of type "Types" parameters
// -> this function allows forwarding of arbitrary numer of parameters to a function
template<typename T, typename... Types>
double sum(T v, Types&&... others) {
    /*
        Recursive sum: suppose we are calling this function as:
        sum(1,2,3,4) -> return 1 + sum(2,3,4);
        sum(2,3,4) -> return 1 + 2 + sum(3,4);
        sum(3,4) -> return 3 + sum(4); Here sum(4) is the identity template function (base-case) of line 24
        All in all:
        return 1+2+3+4;
    */
    return v + sum(others...);
}


int main (int argc, char ** argv)
  {
    int a = 1 ;
    double b = 1.5 ;

    std::cout << "somma_d preserves commutation rule of inputs. somma_d("<<a<<","<<b<<") = " 
                    << somma_d(a, b) << " somma_d("<<b<<","<<a<<") = " << somma_d(b,a) << std::endl;

    std::cout << "\nsomma_t does not preserve commutation rule of inputs. somma_t("<<a<<","<<b<<") = " 
                    << somma_t(a, b) << " somma_t("<<b<<","<<a<<") = " << somma_t(b,a) << std::endl;

    std::cout << "\nsomma_d can waste memory -> always returns double even if we sum integers of size: " << sizeof(somma_d(a, static_cast<int>(b)))
                    << std::endl;

    int somma_int = static_cast<int>(somma_d(a,b));
    float somma_float = static_cast<float>(somma_d(a,b));
    std::cout << "\nWe can always cast the result of somma_d(a,b) = " << somma_d(a,b) << " size: " << sizeof(somma_d(a,b))
                    << " into integer of value: " << somma_int << " size: " << sizeof(somma_int) <<
                    " or float of value: " << somma_float << " size: " << sizeof(somma_float) << std::endl;

    // Example of recursive sum

    double rec_sum = sum(a,b,a,b,a,b); //3*a + 3*b = 3+4.5 = 7.5
    std::cout << "\nRecursive sum sum(a,b,a,b,a,b) -> sum(int,double,...) = " << rec_sum << std::endl;
    

    return 0 ;
  }