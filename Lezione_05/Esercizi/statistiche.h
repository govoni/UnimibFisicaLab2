#ifndef statistiche_h
#define statistiche_h

#include <cmath>

class statistiche
{
  public:

  statistiche () ;
  statistiche (int d): dim(d), last_idx(0), arr(dim ? new float[dim] : nullptr) {} ;
  ~statistiche () { delete[] arr; } ;

  // aggiunge un numero alle informazioni salvate
  void aggiungiNumero (float val);

 
  // resituisce la media dei numeri aggiunti
  double media () const ;
  // restituisce la varianza dei numeri aggiunti
  // in caso di opzione true, applica la correzione di Bessel
  double varianza_1 (bool corretta = false) const ;
  // restituisce la varianza dei numeri aggiunti
  // in caso di opzione true, applica la correzione di Bessel
  double varianza_2 (bool corretta = false) const ;
  // resituisce la deviazione standard
  // in caso di opzione true, applica la correzione di Bessel
  double dev_standard (bool corretta = false) const ;
  // resituisce la deviazione standard dalla media
  double dev_standard_media (bool corretta = false) const ;
  //restituisce varianza degli scarti quadratici
  double varianza_SQ(bool corretta = false) const;
  //restituisce std dev degli scarti quadratici
  double dev_standard_SQ(bool corretta = false) const;
  //restituisce std dev della media degli scarti quadratici
  double dev_standard_media_SQ(bool corretta = false) const;
  // resituisce il numero dei numeri aggiunti
  double N () const { return last_idx; } ;
  //reset
  void reset() { for(int i = 0; i < last_idx; ++i) arr[i] = 0; last_idx = 0; };

  private:
    int dim;
    int last_idx;
    float* arr;
   
} ;


 void statistiche::aggiungiNumero (float val){
     
    if (last_idx >= dim) throw std::out_of_range("Inner index >= array size. Check for dimensions");

    arr[last_idx] = val; 
    ++last_idx;
    return;
 }

double statistiche::media() const{
    /*
        \hat{\mu} = sum(x_i)/N
    */

    double sum = 0;
    for(int i = 0; i < last_idx; i++){
        sum += arr[i];
    }

    return sum/last_idx;
}

double statistiche::varianza_1(bool corretta) const{
    /*
        First variant. Performs one scan of the array. Based on the 
        following. Take the numerator of the variance formula:
        sum[(x_i - \mu)^2] = sum((x_i)^2 + (\mu)^2 - 2x_i\mu) = \sum(x_i^2) + N\mu^2 - 2\mu sum(x_i)
        two sums -> x_i and x_i^2. The first one is also useful to compute the mean while the second
        is only instrumental for the variance computation.
    */ 

    double sum = 0;
    double sum_q = 0;
    for(int i = 0; i < last_idx; ++i){
        sum += arr[i];
        sum_q += pow(arr[i],2);
    }

    double mean = sum/last_idx;

    if (corretta) return (sum_q + last_idx*pow(mean, 2)- 2*mean*sum)/(last_idx-1);
    else  return (sum_q)/(last_idx) - pow(mean,2);
    
}

double statistiche::varianza_2(bool corretta) const{
    /*
        Second variant. Performs two scan of the array -> worse performances.
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
    double sum_q = 0;
    for(int i = 0; i < last_idx; ++i){
        sum_q += pow(pow(arr[i] - mean, 2 ) - var, 2);
    }
    
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

#endif

