/*
c++ -o main_09 main_09.cpp
*/

#include <iostream>
#include <map>

using namespace std ;

int main (int argc, char ** argv)
  {
    map <int, double> mappa_di_esempio ;
    mappa_di_esempio[5] = 5.5 ;
    mappa_di_esempio[3] = 3.3 ;
    mappa_di_esempio[5] = 4.1 ;
    mappa_di_esempio[12] = 7.9 ;
 
    for (map<int, double>::const_iterator it = mappa_di_esempio.begin () ;
         it != mappa_di_esempio.end () ;
         ++it)
      {
        cout << "elemento " << it->first
             << "\t-> "     << it->second
             << endl ;
      }    

    return 0 ;
  }
