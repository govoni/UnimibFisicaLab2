/*
c++ -o main_15 main_15.cpp
*/

#include <iostream>

int raddoppia (int) ;

int main (int argc, char ** argv)
  {
  
    for (int i = 0 ; i < 5 ; ++i)
      {
        std::cout << "il doppio di " << i << " vale: " << raddoppia (i) << std::endl ;
      }
    return 0 ;
  }

// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----

int raddoppia (int input_value) 
  {
    return 2 * input_value ;
  }




