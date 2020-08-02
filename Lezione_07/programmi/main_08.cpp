/*
c++ -o main_08 main_08.cpp
*/

#include <iostream>
#include <vector>

using namespace std ;

int main (int argc, char ** argv)
  {
    vector<double> v_1 ;
    vector<double> v_2 (5, 1.1) ;
    vector<double> v_3 (v_2) ;

    cout << "elemento 1 di v_2 " << v_2[1] << endl ;
    cout << "elemento 1 di v_2 " << v_2.at (1) << endl ;

    cout << v_1.size () << endl ;
    v_1.push_back (3.) ; 
    v_1.push_back (4.) ; 
    cout << v_1.size () << endl ;
    v_1.pop_back () ; 
    cout << v_1.size () << endl ;

    double * array_3 = & v_3.at (0) ;
    cout << "elemento 2 di v_3 " << array_3[2] << endl ;

    for (int i = 0 ; i < v_3.size () ; ++i)
      cout << "elemento " << i << ": " << v_3.at (i) << "\n" ;

    for (vector<double>::const_iterator it = v_3.begin () ;
         it != v_3.end () ;
         ++it)
      cout << "elemento " << it - v_3.begin () << ": " << *it << "\n" ;

    return 0 ;
  }
