/*
c++ -o main_05 main_05.cpp
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std ;

int main (int argc, char ** argv)
{
  vector<int> v ;
  v.push_back (3) ;
  v.push_back (2) ;
  v.push_back (10) ;
  v.push_back (-1) ;

  for (int i = 0 ; i < v.size () - 1 ; ++i) cout << v.at (i) << ", " ;
  cout << v.at (v.size () - 1) << endl ;

  sort (v.begin (), v.end ()) ;

  for (int i = 0 ; i < v.size () - 1 ; ++i) cout << v.at (i) << ", " ;
  cout << v.at (v.size () - 1) << endl ;

  return 0 ;
}
