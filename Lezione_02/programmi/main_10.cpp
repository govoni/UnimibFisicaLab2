/*
c++ -o main_10 main_10.cpp
*/


#include<iostream> 

int * creaInteroDoppio (int valore)
{
  int * risultato = new int (valore * 2) ; 
  return risultato ;
}


int main  (int argc, char ** argv)
  {

    int numero = 5 ;

    int * doppio = creaInteroDoppio (numero) ;

    std::cout << "Valore iniziale: " << numero  << std::endl ;
    std::cout << "Valore doppio  : " << *doppio << std::endl ;

    delete doppio ;

//utilizzo errato della funzione!
//    std::cout << "Valore doppio  : " << *creaInteroDoppio (numero) << std::endl ;

    return 0 ; 
}
