/*
c++ -o main_11 main_11.cpp
*/


#include<iostream> 


int main  (int argc, char ** argv)
  {
    int N = 5 ;
    float * dynamic_array = new float [N] ;
    delete [] dynamic_array ;
    return 0 ;
  }
