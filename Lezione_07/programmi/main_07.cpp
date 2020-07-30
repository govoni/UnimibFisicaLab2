/*
c++ -o main_07 main_07.cpp
*/

#include <iostream>

// insieme di operazioni
namespace ops
{
  template <typename T>
  T somma (T a, T b)
    {
      return a + b ;
    }
    
  template<>
  float somma (float a, float b)
    {
      std::cout << "SOMMA DI FLOAT" << std::endl ;
      return a + b ;
    }
  
  template <typename T1, typename T2>
  T2 somma (T1 a, T2 b)
    {
      return a + b ;
    }
}

int main (int argc, char ** argv)
  {
    int i_a = 1 ;
    int i_b = 2 ;
    double d_a = 5. ;
    double d_b = 7. ;

    std::cout << "somma di interi    " << ops::somma (i_a, i_b) << std::endl ;
    std::cout << "somma di razionali " << ops::somma (d_a, d_b) << std::endl ;

    return 0 ;
  }
