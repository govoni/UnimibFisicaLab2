/*
Esercizio 14: Si determini con il metodo della sezione aurea il minimo della funzione g(x) = x2 + 7.3x + 4 nell'intervallo (-10, 10).

c++ -o esercizio14 esercizio14.cpp
*/

#include <iostream>
#include <cmath>


double funz (double x)
{
  return (x*x + 7.3*x + 4);

} 

double sezioneAurea (double g (double),double x0, double x1, double precision)
{
  double r = 0.618;
  double x2 = 0;
  double x3 = 0; 
  double larghezza = fabs(x1-x0);
   
  while (larghezza > precision)
    {        
        x2 = x0 + r * (x1 - x0) ;
        x3 = x0 + (1. - r) * (x1 - x0);  
    
      if (g(x3) > g(x2) ) 
       {  //restringo l'intervallo tennedo fisso uno dei due estremi e spostando l'altro        
          x0 = x3;
          x1 = x1;         
        }            
      else 
          { //restringo l'intervallo tennedo fisso uno dei due estremi e spopstando l'altro
             x1 = x2;
             x0 = x0;          
          }
          
        larghezza = fabs(x1-x0) ;            
    } 
                                 
  return (x0+x1)/2. ;
}

//----------------- MAIN -----------------
int main (int argc, char ** argv)
{
  double x_min = - 10.;
  double x_max = 10.;
  double risoluzione = 0.0001;
  
  std::cout << "Minimo della funzione " << sezioneAurea (funz, x_min, x_max, risoluzione) << std::endl;
  
 return 0;
 } 





