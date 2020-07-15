/*
c++ -o main_13 main_13.cpp
*/

#include <iostream>

int main (int argc, char ** argv)
  {
    int num1 = 5 ;
    if (num1 % 2 == 0) 
      {
        std::cout << num1 << " e' pari\n" ;
      }
    else  
      {
        std::cout << num1 << " e' dispari\n" ;
      }

    // ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----

    int num2 = 2 ;
    switch(num2) {
      case 1:
        // blocco di istruzioni
        std::cout << "uno\n" ;
        break;
      case 2:
        // blocco di istruzioni
        std::cout << "due\n" ;
        break;
      default:
        std::cout << "altri numeri\n" ;
        // blocco di istruzioni
    }

    // ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----

    int N = 10 ;
    for (int i = 0 ; i < N ; ++i)
      {
        std::cout << "il doppio di " << i << " vale: " << 2 * i << std::endl ;
      }

    std::cout << std::endl ;

    // ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----

    int i = 0 ;
    while (i < N)
      {
        std::cout << "il doppio di " << i << " vale: " << 2 * i << std::endl ;
        ++i ;
      }

    // ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----

    do
      {
        std::cout << "il doppio di " << i << " vale: " << 2 * i << std::endl ;
        ++i ;
      }
    while (i < 2 * N) ;
  
    return 0 ;

  }

