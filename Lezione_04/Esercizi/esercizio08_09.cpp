//c++ -o es_8_9 esercizio08_09.cpp
#include <iostream>
#include <cmath>

static const int A =  214013;
static const int C =  2531011;
static const int M =  2147483647;
long int seed_;

//----------------- Redefining random number generator (LCG) -----------------

void rnd(){
    /*
        Updating the seed with LCG algorithm
    */
    seed_ = (A* seed_ + C)%M;
    return;
}

float rand_range(float min, float max){
    /*
        Updating the seed with LCG algorithm and scaling it in the required range [min, max]
    */
    rnd();
    return min + (max - min)*seed_ / static_cast<float> (M);
}

//----------------- Statistic class -----------------

class statistiche
{
  public:

  statistiche () ;
  statistiche (int d): dim(d), last_idx(0), arr(dim ? new float[dim] : nullptr), sum (0.), sum_q (0.) {} ;
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
  void reset() { for(int i = 0; i < last_idx; ++i) arr[i] = 0; last_idx = 0; sum = 0. ; sum_q = 0. ;};

  private:
    int dim;
    int last_idx;
    float* arr;
    double sum ;
    double sum_q ;

   
} ;


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


//----------------- MAIN -----------------


int main(){

    seed_ = 0; //setting global seed of the sequence
    float x_min = -5;
    float x_max = +5;

    int dim = 100000;
    statistiche* stats = new statistiche(dim/4);

    for(int i = 0; i < dim; ++i) stats->aggiungiNumero(rand_range(x_min, x_max));

    std::cout << "Uniform distribution in [" << x_min << "," << x_max << "] : " << std::endl;
    std::cout << "Theoretical mean (0.5(a+b)): " << 0.5*(x_min + x_max) 
              << " Computed mean: "              << stats->media() 
              << "+-"                            << stats->dev_standard_media(true) 
              << std::endl;

    std::cout << "Theoretical variance (1/12 (b-a)^2): " << (float(1)/12)*pow(x_max - x_min, 2) 
              << " Computed variance: "                  << stats->varianza_1(true) 
              << "+-"                                    << stats->dev_standard_media_SQ(true) 
              << std::endl;


    //Checking for CLT
    stats->reset();
    int d = 20; //number of extractions before computing mean
    for(int i = 0; i < dim; ++i){
        double sum = 0;
        for(int j = 0; j < d; ++j){
            sum += rand_range(x_min, x_max);
        }
        stats->aggiungiNumero(sum/d);
    }

    std::cout << "\n\nCheck for CLT with N: "    << d << std::endl;
    std::cout << "Theoretical mean (0.5(a+b)): " << 0.5*(x_min + x_max) 
              << " Computed mean: "              << stats->media() 
              << "+-"                            << stats->dev_standard_media(true) 
              << std::endl;

    std::cout << "Theoretical variance (1/12 (b-a)^2)/N: " << (float(1)/12)*pow(x_max - x_min, 2)/d 
              << " Computed variance: "                    << stats->varianza_1(true) 
              << "+-"                                      << stats->dev_standard_media_SQ(true) 
              << std::endl;

    



    return 0;
}

