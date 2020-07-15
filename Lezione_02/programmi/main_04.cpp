/*
c++ -o main_04 main_04.cpp
*/

#include<iostream> 

int main  (int argc, char ** argv)
  {
    int var = 137 ; 
    int * ptr = & var ;
    int ** ptrAptr = & ptr ;

    std::cout << "var    : " << var << std::endl ;
    std::cout << "ptr    : " << ptr << std::endl ;
    std::cout << " `--> *ptr: " << *ptr << std::endl ;
    std::cout << "ptrAptr: " << ptrAptr << std::endl ;
    std::cout << " `--> *ptrAptr: " << *ptrAptr << std::endl ;
    std::cout << "        `-->**ptrAptr: " << **ptrAptr << std::endl ;

    return 0 ; 
}
