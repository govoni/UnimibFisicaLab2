/*
c++ -o main_02 main_02.cpp
*/

#include<iostream> 

int main  (int argc, char ** argv)
  {

    int numero_intero = 5 ;
    int * puntatore_ad_intero = & numero_intero ;

    std::cout << "valore   : " << numero_intero << std::endl ;
    std::cout << "indirizzo: " << & numero_intero << std::endl ;
    std::cout << "puntatore: " << puntatore_ad_intero << std::endl ;
    std::cout << "valore   : " << * puntatore_ad_intero << std::endl ;

    return 0 ; 
}
