/*
c++ -o main_05 main_05.cpp
*/

#include<iostream> 

int main  (int argc, char ** argv)
  {
    int vec[] = {2, 20} ;
    std::cout << vec << std::endl ;

    std::cout << vec[0] << " == " << *vec << std::endl ;
    std::cout << vec[1] << " == " << *(vec+1) << std::endl ;


    return 0 ; 
}
