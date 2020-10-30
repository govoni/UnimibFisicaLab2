#include "statistiche.h"

 void statistiche::aggiungiNumero (float val){
     
    if (last_idx >= dim) 
      {
        float * tempo = new float [2*dim] ;
        for (int i = 0 ; i < dim ; ++i) tempo[i] = arr[i] ;
        dim = dim * 2 ;
        delete [] arr ;
        arr = tempo ;
      }
    arr[last_idx] = val; 
    sum += val ;
    sum_q += val * val ;
    ++last_idx;
    return;
 }

double statistiche::media() const{
    /*
        \hat{\mu} = sum(x_i)/N
    */

    return sum/last_idx;
}

double statistiche::varianza_1(bool corretta) const{
    /*
        First variant. Based on the following. 
        Take the numerator of the variance formula:
        sum[(x_i - \mu)^2] = sum((x_i)^2 + (\mu)^2 - 2x_i\mu) = \sum(x_i^2) + N\mu^2 - 2\mu sum(x_i)
        two sums -> x_i and x_i^2. The first one is also useful to compute the mean while the second
        is only instrumental for the variance computation.
    */ 

    double mean = media () ;

    if (corretta) return (sum_q + last_idx * mean * mean- 2*mean*sum)/(last_idx-1);
    else  return (sum_q)/(last_idx) - mean * mean;
    
}

double statistiche::varianza_2(bool corretta) const{
    /*
        Second variant. Performs two scans of the array -> worse performances.
        First computes the mean then sums (x_i - \mu)^2. Lastly takes the mean
        of the square deviations (with or without Bessel correction).
    */ 

    double mean  = media();
    double sum_q = 0;
    for(int i = 0; i < last_idx; ++i){
        sum_q += pow(arr[i] - mean, 2);
    }

    if (corretta) return sum_q/(last_idx-1);
    else  return sum_q/last_idx;

}

double statistiche::dev_standard (bool corretta) const{
    /*
        dev_std = sqrt(var)
    */ 
    
    return sqrt(varianza_1(corretta)); 
}

double statistiche::dev_standard_media (bool corretta) const{
    /*
        dev_std_media = (dev_std)/sqrt(N)
    */  
    
    return sqrt(varianza_1(corretta)/last_idx); 
}

double statistiche::varianza_SQ(bool corretta) const{
    
    double var = varianza_1(); // mean of the squared deviations var = (x_i - \mu)^2 / N
    double mean = media(); // \mu
    
    if (corretta) return sum_q/(last_idx - 1);
    else return sum_q/last_idx;
    
}

double statistiche::dev_standard_SQ (bool corretta) const{
    /*
        dev_std = sqrt(var)
    */ 
    
    return sqrt(varianza_SQ(corretta)); 
}

double statistiche::dev_standard_media_SQ (bool corretta) const{
    /*
        dev_std_media = sqrt(var)
    */ 
    
    return sqrt(varianza_SQ(corretta)/last_idx);
}


