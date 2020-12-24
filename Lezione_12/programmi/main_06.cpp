/*
c++ -o main_06 ../../Lezione_10/programmi/algebra_2.cc main_06.cpp

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>

#include "../../Lezione_09/programmi/statistiche_vector.h"
#include "../../Lezione_10/programmi/algebra_2.h"

using namespace std ;


matrice determinaCovarianza (string nome_file)
{
  ifstream input_file ;
  input_file.open (nome_file.c_str (), ios::in) ;

  if (!input_file.is_open ()) exit (1) ;

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

  matrice covarianza (2) ;
  covarianza.setCoord (0, 0, V_xx) ;
  covarianza.setCoord (1, 1, V_yy) ;
  covarianza.setCoord (0, 1, V_xy) ;
  covarianza.setCoord (1, 0, V_xy) ;

  return covarianza ;
}


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 


int main (int argc, char ** argv)
{
  if (argc < 3)
    {
      cerr << "uso: " << argv[0] << " nomeFile1 nomeFile2" << endl ;
      exit (1) ;
    }

  matrice cov_1 = determinaCovarianza (argv[1]) ;
  matrice cov_2 = determinaCovarianza (argv[2]) ;

  cov_1.stampa () ;
  cout << endl ;
  cov_2.stampa () ;

  return 0 ;
}