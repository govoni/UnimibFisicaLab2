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

int main  (int arcg, char ** argv)
  {

    int numero = 5 ;
    std::cout << "raddoppio (valore)    " << raddoppia (numero) << " da " << numero << "\n" ;
    std::cout << "raddoppio (puntatore) " << raddoppia (& numero) << " da " << numero << "\n" ;
    numero = 5 ;
    std::cout << "raddoppio (referenza) " << raddoppiaRef (numero) << " da " << numero << "\n" ;

    return 0 ; 
}
