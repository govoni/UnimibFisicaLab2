/*
c++ -o main_06 main_06.cpp
*/

#include<iostream> 

int main  (int argc, char ** argv)
  {

    double pi_greco = 3.1415 ;
    double & ref = pi_greco ;
    std::cout << "ref fornisce un alias di pi_greco: "
              << ref << std::endl ;

    pi_greco = 3.141592 ;
    std::cout << "ref fornisce un alias di pi_greco: "
              << ref << std::endl ;

    std::cout << & ref << std::endl ;
    std::cout << & pi_greco << std::endl ;


    return 0 ; 
}
