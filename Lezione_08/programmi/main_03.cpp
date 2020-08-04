/*
c++ -o main_03 main_03.cpp
*/

#include <iostream>
#include <vector>
#include <map>
#include "forme_polim.h"

using namespace std ;

int main (int argc, char ** argv)
{
  vector<forma *> v_forme ; 
  map<string, forma *> m_forme ; 
  
  forma forma_base ;
  v_forme.push_back (& forma_base) ; 
  m_forme["base"] = & forma_base ; 

  quadrato forma_quadrata (3.) ;
  v_forme.push_back (& forma_quadrata) ; 
  m_forme["quadrato"] = & forma_quadrata ; 

  rettangolo forma_rettangolare (3., 2.) ;
  v_forme.push_back (& forma_rettangolare) ; 
  m_forme["rettangolo"] = & forma_rettangolare ; 

  for (int i = 0 ; i < v_forme.size () ; ++i)
    cout << v_forme.at (i)->calcola_area () << endl ;

  cout << endl ;

  for (map<string, forma *>::const_iterator it = m_forme.begin () ;
       it != m_forme.end () ;
       ++it)
    cout << it->first << " ha area " << it->second->calcola_area () << endl ;

  return 0 ;
}
