#ifndef generazione_h
#define generazione_h


// media sempre zero
// non normalizzata, cosi' il massimo in zero vale sempre 1
double fgaus (double x, double sigma) 
  {
    return exp (-0.5 * x * x / (sigma * sigma)) ; 
  }


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----


double rand_range (double min, double max)
  {
    return min + (max - min) * rand () / static_cast<double> (RAND_MAX) ;
  } 


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----


double rand_TAC_gaus (double sigma)
  {
    double x = 0. ;
    double y = 0. ; 
    do {
      x = rand_range (-5 * sigma, 5 * sigma) ;
      y = rand_range (0, 1.) ;
    } while (y > fgaus (x, sigma)) ;
    return x ; 
  }


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----


double rand_TAC_uniform (double sigma)
  {
//    sqrt (3) = 1.7320508076
    return rand_range (-1.7320508076 * sigma, 1.7320508076 * sigma) ; 
  }

#endif