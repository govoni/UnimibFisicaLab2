#ifndef statistiche_h
#define statistiche_h

#include <cmath>

class statistiche
{
  public:

    statistiche () :
      m_sum (0.),
      m_sumSq (0.),
      m_N (0)
      {}

    ~statistiche () {}

    // aggiunge un elemento al campione
    long long int addEvent (double value) 
      {
        m_sum += value ;
        m_sumSq += value * value ;
        ++m_N ;
        return m_N ;
      }

    // restituisce la media
    double getMean () const
      {
        if (m_N == 0) return 0. ; 
        return m_sum / static_cast<double> (m_N) ;
      }

    // restituisce la varianza
    double getVariance (bool correct = false) const
      {
        if (m_N == 0) return 0. ; 
        double sigma = m_sumSq / static_cast<double>  (m_N) 
                       - (m_sum * m_sum) / static_cast<double> (m_N * m_N) ;
        if (correct && m_N > 1) sigma = sigma * m_N / static_cast<double> (m_N - 1) ;         
        return sigma ;
      }

    // restituisce la sigma
    double getSigma (bool correct = false) const
      {
        return sqrt (getVariance (correct)) ;
      }

    // restituisce la varianza della media
    double getVarianceMean (bool correct = false) const
      {
        return getVariance (correct) / m_N ;
      }

    // restituisce la sigma della media
    double getSigmaMean (bool correct = false) const
      {
        return sqrt (getVarianceMean (correct)) ;
      }
    
    // restituisce il numero di eventi
    double getN () const
      {
        return m_N ;
      }
    
    // annulla tutti i membri
    void reset () 
      {
        m_sum = 0. ;
        m_sumSq = 0. ;
        m_N = 0 ;
        return ;
      }

  private:  

    // somma dei numeri del campione
    double m_sum ;
    // somma quadrata dei numeri del campione
    double m_sumSq ;
    // numero di elementi del campione
    long long int m_N ;

} ;


#endif