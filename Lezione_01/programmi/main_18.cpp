/*
c++ -o main_18 main_18.cpp
c++ -o main_18 -O3 main_18.cpp

*/

#include <iostream>
#include <cmath>
#include <ctime>

int main (int argc, char ** argv)
  {

    long int N = 1e9 ; 
    double test = 0 ;

    double start = (double) clock () / CLOCKS_PER_SEC ; 
    for (double i = 0; i < N; ++i) 
      {
        test += pow (i, 2) ; 
      }
    double stop = (double) clock () / CLOCKS_PER_SEC ;
    std::cout << "tempo di esecuzione per pow: " << stop - start << " secondi\n" ;

    start = (double) clock () / CLOCKS_PER_SEC ; 
    for (double i = 0; i < N; ++i) 
      {
        test += i * i ; 
      }
    stop = (double) clock () / CLOCKS_PER_SEC ;
    std::cout << "tempo di esecuzione per i*i: " << stop - start << " secondi\n" ;


    return 0 ;
  }

