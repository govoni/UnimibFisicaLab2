/*
c++ -o main_03 main_03.cpp

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

#include "../../Lezione_09/programmi/statistiche_vector.h"

using namespace std ;

int main (int argc, char ** argv)
{
  if (argc < 2)
    {
      cerr << "uso: " << argv[0] << " nomeFile" << endl ;
      exit (1) ;
    }

  // lettura dei dati dal file di input
  // ---- ---- ---- ---- ---- ---- ----  

  ifstream input_file ;
  input_file.open (argv[1], ios::in) ;

  if (!input_file.is_open ()) return 1 ;

  double input_x ;
  double input_y ;
  vector<double> data_x ;
  vector<double> data_y ;
  while (true) 
    {
      input_file >> input_x ;
      input_file >> input_y ;
      if (input_file.eof () == true) break ;
      data_x.push_back (input_x) ;
      data_y.push_back (input_y) ;
    } 
  input_file.close () ;

  // calcolo della matrice delle covarianze
  // ---- ---- ---- ---- ---- ---- ----  

  double V_xx = varianza (data_x) ;
  double V_yy = varianza (data_y) ;
  double M_x = media (data_x) ;
  double M_y = media (data_y) ;

  double V_xy = 0. ;
  for (int i = 0 ; i < data_x.size () ; ++i)
    {
      V_xy += (data_x.at (i) - M_x) * (data_y.at (i) - M_y) ;
    }
  V_xy /= data_x.size () ;

  return 0 ;
}