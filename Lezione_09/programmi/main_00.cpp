/*
c++ -o main_00 main_00.cpp

Testo:
  Si scriva un programma che legge i numeri salvati nel file dati_esponenziali.txt e li scriva in un vector<double>.

  Si faccia in modo che il nome del file sia passato a linea di comando.
  Si faccia in modo che il secondo argomneto a linea di comando, opzionale, sia il numero massimo di numeri da leggere dal file.
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

    vector<double> data ;

    double input_val ;
    while (true) 
      {
        input_file >> input_val ;
        if (input_file.eof () == true) break ;
        data.push_back (input_val) ;
        if (numeroMax > 0 && data.size () == numeroMax) break ;
      } 
    input_file.close () ;

    cout << "letti " << data.size () << " eventi" << endl ;

    return 0 ;
}
