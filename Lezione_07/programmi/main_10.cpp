/*
c++ -o main_10 main_10.cpp
*/


#include <iostream>
#include <string>

using namespace std ;

int main (int argc, char ** argv) 
  {
    string s_1 ;
    cout << s_1.length () << endl ;
    s_1 = "nel mezzo del cammin" ;
    cout << s_1 << endl ;
    cout << s_1.length () << endl ;
    string s_2 = " di nostra vita" ;
    string s_3 = s_1 + s_2 ;
    cout << s_3 << endl ;

    string s_4 = "nostra" ;

    int posizione = s_3.find (s_4) ;
    cout << "La parola \"" << s_4 
         << "\" inizia al carattere " << posizione 
         << " della frase: \"" << s_3 
         << "\"\n" ;

    string s_5 = "caronte" ;
    posizione = s_3.find (s_5) ;
    cout << "La parola \"" << s_5 
         << "\" inizia al carattere " << posizione 
         << " della frase: \"" << s_3 
         << "\"\n" ;

    string s_6 = "caronte" ;

    cout << (s_5 == s_3) << endl ;

    char A = 'A' ; 
    cout << sizeof (A) << endl ;

    string S = "A" ;
    cout << sizeof (S) << endl ;   
    cout << sizeof (S.c_str ()) << endl ;   

    char * S_c = "A" ;
    cout << sizeof (S_c) << endl ;

    return 0 ;
  }
