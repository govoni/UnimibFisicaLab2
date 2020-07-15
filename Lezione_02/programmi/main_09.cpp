/*
c++ -o main_09 main_09.cpp
*/


#include<iostream> 


int main  (int argc, char ** argv)
  {
    int * numero = new int (5) ;
    std::cout << * numero << std::endl ;
    delete numero ;
    return 0 ; 
  }
