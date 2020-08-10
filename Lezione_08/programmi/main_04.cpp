/*
c++ -o main_04 main_04.cpp
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std ;

int main (int argc, char ** argv)
{
  vector<float> v ;
  for (int i = 0 ; i < 10 ; ++i) v.push_back (0.5 * i) ;

  vector<float>::iterator risultato = 
    find (v.begin (), v.end (), 3.5) ;

  if (risultato != v.end ()) cout << "trovato " << *risultato << endl ;

  return 0 ;
}
