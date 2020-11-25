/*
c++ -o main_07 main_07.cpp

*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std ;

int main (int argc, char ** argv)
  {

    if (argc < 2)
      {
        cerr << "uso: " << argv[0] << " nomeFile [numero_di_eventi]" << endl ;
        exit (1) ;
      }

    int numeroMax = 10 ;
    if (argc > 2) numeroMax = atoi (argv[2]) ;

    ofstream output_file ;
    output_file.open (argv[1], ios::out) ;

    if (!output_file.is_open ()) return 1 ;
    
    for (int i = 0 ; i < numeroMax ; ++i)
      {
        output_file << i << "\n" ;
      }  

    output_file.close () ;

    cout << "scritti " << numeroMax << " eventi" << endl ;

    return 0 ;
}
