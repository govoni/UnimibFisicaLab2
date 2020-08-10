/*
c++ -o main_06 main_06.cpp
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std ;


bool confronto (int i, int j) 
  { 
    if (i % 2 == 0) 
      {
        if (j % 2 != 0) return true ;
        else return (i < j) ;
      }
    else
      {
        if (j % 2 == 0) return false ;
        else return (i < j) ;
      }
  }

int main (int argc, char ** argv)
{
  vector<int> v ;
  v.push_back (3) ;
  v.push_back (2) ;
  v.push_back (10) ;
  v.push_back (-1) ;

  for (int i = 0 ; i < v.size () - 1 ; ++i) cout << v.at (i) << ", " ;
  cout << v.at (v.size () - 1) << endl ;

  sort (v.begin (), v.end (), confronto) ;

  for (int i = 0 ; i < v.size () - 1 ; ++i) cout << v.at (i) << ", " ;
  cout << v.at (v.size () - 1) << endl ;

  return 0 ;
}
