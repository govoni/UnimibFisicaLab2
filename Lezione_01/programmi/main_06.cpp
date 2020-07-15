/*
c++ -o main_06 main_06.cpp
*/

#include <iostream>

int main (int argc, char ** argv)
  {
    // array di 5 numeri interi
    int num_array[5] ;
    num_array[0] = 3 ;
    num_array[1] = 6 ;
    num_array[2] = 9 ;
    num_array[3] = 11 ;
    num_array[4] = 131 ;

    int index = 4 ;
    std::cout << num_array[index + 1] << std::endl ;

    float float_array[] = {2., 3.14} ;
    std::cout << float_array[0] << std::endl ;
    std::cout << float_array[1] << std::endl ;

    return 0 ;
  }

