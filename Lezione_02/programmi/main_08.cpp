/*
c++ -o main_08 main_08.cpp
*/


#include<iostream> 

int raddoppiaReturnValore (int valore)
{
  int risultato = valore * 2 ; 
  return risultato ;
}

int * raddoppiaReturnPuntatore (int valore)
{
  int risultato = valore * 2 ; 
  return & risultato ;
}

int & raddoppiaReturnReferenza (int valore)
{
  int risultato = valore * 2 ; 
  return risultato ;
}

int main  (int argc, char ** argv)
  {

    int numero = 5 ;

    std::cout << "Valore   : " << raddoppiaReturnValore    (numero) << std::endl ;
    std::cout << "Puntatore: " << raddoppiaReturnPuntatore (numero) << std::endl ;
    std::cout << "Referenza: " << raddoppiaReturnReferenza (numero) << std::endl ;

    return 0 ; 
}
