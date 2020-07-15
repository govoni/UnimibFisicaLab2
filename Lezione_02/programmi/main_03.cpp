/*
c++ -o main_03 main_03.cpp
*/

#include<iostream> 

int main  (int argc, char ** argv)
  {
    int var = 137 ; 
    std::cout << "var vale: " << var    
              << " ed ha indirizzo " << &var << std::endl ;
    int * ptr ;
    std::cout << "ptr punta a: " << ptr << std::endl ;

    ptr = & var ;
    std::cout << "Ora ptr punta a var: " << ptr
              << " ed il valore a cui punta vale: " << *ptr << std::endl ; 

    * ptr = 100 ;
    std::cout << "var ora vale: " << var << std::endl ;

    int pippo = * ptr ;
    std::cout << "La variabile pippo vale: " << pippo << std::endl; 

    (*ptr)++;
    std::cout << "var ora vale: " << var << " e pippo vale: " << pippo << std::endl; 

    return 0 ; 
}
