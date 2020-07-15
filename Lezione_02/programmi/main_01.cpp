/*
c++ -o main_01 main_01.cpp
*/

#include<iostream> 

int main  (int argc, char ** argv)
  {

    int numero_intero = 5 ;

    std::cout << "valore:    " << numero_intero << std::endl ;
    std::cout << "indirizzo: " << & numero_intero << std::endl ;
      
    return 0 ; 
}
