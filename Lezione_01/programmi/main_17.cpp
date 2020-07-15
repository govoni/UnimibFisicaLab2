/*
c++ -o main_17 main_17.cpp
*/

#include <iostream>
#include <cmath>

int main (int argc, char ** argv)
  {
    float num = 4.5 ;
    std::cout << "quadrato di " << num << ": " << pow (num, 2) << "\n" ;
    num = pow (num, 2) ;
    std::cout << "radice di " << num << ": " << sqrt (num) << "\n" ;
    std::cout << "radice di " << num << ": " << pow (num, 0.5) << "\n" ;

    return 0 ;
  }

