/*
c++ -o main_00 main_00.cpp
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

    ifstream input_file ; 
    input_file.open (argv[1], ios::in) ;

    int numeroMax = -1 ;
    if (argc > 2) numeroMax = atoi (argv[2]) ;

    vector<float> data ;

    float input ;
    while (true) 
      {
        input_file >> input ;
        if (input_file.eof () == true) break ;
        data.push_back (input) ;
        if (numeroMax > 0 && data.size () == numeroMax) break ;
      } 
    input_file.close () ;

    cout << "letti " << data.size () << " eventi" << endl ;

    return 0 ;
}
