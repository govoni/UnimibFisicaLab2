/*
c++ -o main_14 main_14.cpp
*/

#include <iostream>


int raddoppia (int input_value) 
  {
    return 2 * input_value ;
  }


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----


float raddoppia (float input_value) 
  {
    return 2 * input_value ;
  }


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----


void scriviAschermo (int input_value) 
  {
    std::cout << "ecco il numero da scrivere: " << input_value << std::endl ;
    return ;
  }


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----


int main (int argc, char ** argv)
  {
  
    for (int i = 0 ; i < 5 ; ++i)
      {
        std::cout << "il doppio di " << i << " vale: " << raddoppia (i) << std::endl ;
      }

    std::cout << std::endl ;

    for (int i = 0 ; i < 5 ; ++i)
      {
        scriviAschermo (raddoppia (i)) ;
      }

    return 0 ;
  }

