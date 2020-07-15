/*
c++ -o main_07 main_07.cpp
*/


#include<iostream> 

int raddoppia (int valore)
{
  valore *= 2 ; 
  return valore ;
}

int raddoppia (int * valore)
{
  *valore *= 2 ; 
  return *valore ;
}

int raddoppiaRef (int & valore)
{
  valore *= 2 ; 
  return valore ;
}

int main  (int argc, char ** argv)
  {

    int numero = 5 ;
    std::cout << "raddoppio (valore)    " << raddoppia (numero) << "\n" ;
    std::cout << "numero: " << numero << "\n" ;
    std::cout << "raddoppio (puntatore) " << raddoppia (& numero) << "\n" ;
    std::cout << "numero: " << numero << "\n" ;
    numero = 5 ;
    std::cout << "raddoppio (referenza) " << raddoppiaRef (numero) << "\n" ;
    std::cout << "numero: " << numero << "\n" ;

    int risultato = raddoppia (numero) ;

    return 0 ; 
}
