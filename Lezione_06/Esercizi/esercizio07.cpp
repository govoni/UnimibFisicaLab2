/*
Esercizio 07:Si implementi il metodo di integrazione crude-MC con la funzione di esempio f(x) = sin (x).
Si scriva l'algoritmo che calcola l'integrale come una funzione esterna al programma main, facendo in modo che prenda come parametri di ingresso, oltre agli estremi lungo l'asse x, anche il numero di punti pseudo-casuali da generare.
Si faccia in modo che l'algoritmo ritorni un contenitore contenente due elementi: il primo elemento sia il valore dell'integrale, il secondo sia la sua incertezza.

c++ -o esercizio07 esercizio07.cpp 
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>


float rand_range (float min, float max)
  {
    return min + (max - min) * rand () / static_cast<float> (RAND_MAX) ;
  } 


double fsin (double x) 
  {
    return sin (x) ; 
  }
  
 
void CrudeMC (int Nrand, double g(double), double xMin, double xMax, double* risultato )
   {
     double lunghezza  = (xMax - xMin);
     double somma = 0;
     double sommaQ = 0;
     double media = 0;
     double varianza = 0;
     
     for (int i = 0; i<Nrand; i++)
     {
        double x = rand_range(xMin, xMax);
        somma += g(x);
        sommaQ += g(x)*g(x);     
     }
      
     media = somma/static_cast<double>(Nrand);
     varianza = sommaQ/static_cast<double>(Nrand) - media*media ;
                                   
     risultato[0] = media*lunghezza ;
     risultato[1] = sqrt (varianza/static_cast<double>(Nrand)) * lunghezza;
     
    return;       
   }           

//----------------- MAIN -----------------
int main (int argc, char ** argv)
{ 
  srand (time (NULL)) ;
  int N = 10000 ;
  double x_min = 0. ;
  double x_max = M_PI ; 
  double* risultato = new double[2];
  
  CrudeMC(N,fsin,x_min,x_max,risultato);  
  std::cout << "Integrale = " << risultato[0] << " +/- "       << risultato[1] << std::endl ;
               
  delete[] risultato;          
            
  return 0 ;
}




