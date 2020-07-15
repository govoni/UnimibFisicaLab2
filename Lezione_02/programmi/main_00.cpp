/*
c++ -o main_00 main_00.cpp
*/

#include<iostream> 

int main  (int argc, char ** argv)
  {

    std::cout << "Dimensione di un char : " << sizeof (char)  
             << " byte" << std::endl ; 
    std::cout << "Dimensione di un int : " << sizeof (int) 
             << " bytes" << std::endl ; 
    std::cout << "Dimensione di un short int : " << sizeof (short int)  
             << " bytes" << std::endl ; 
    std::cout << "Dimensione di un long int : " << sizeof (long int)  
              << " bytes" << std::endl ; 
    std::cout << "Dimensione di un signed long int : " << sizeof (signed long int) 
              << " bytes" << std::endl ; 
    std::cout << "Dimensione di un unsigned long int : " << sizeof (unsigned long int)  
              << " bytes" << std::endl ; 
    std::cout << "Dimensione di un float : " << sizeof (float)  
              << " bytes" <<std::endl ; 
    std::cout << "Dimensione di un double : " << sizeof (double)  
              << " bytes" << std::endl ; 
    std::cout << "Dimensione di un wchar_t : " << sizeof (wchar_t)  
              << " bytes" <<std::endl ; 
      
    return 0 ; 
}
