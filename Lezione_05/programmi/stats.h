#ifndef stats_h
#define stats_h

#include <cmath>

class stats 
{
  public:

    stats () :
      m_sum (0.),
      m_sumSq (0.),
      m_N (0)
      {}

    long long int addEvent (double value) 
      {
        m_sum += value ;
        m_sumSq += value * value ;
        ++m_N ;
        return m_N ;
      }

    double getMean () const
      {
        if (m_N == 0) return 0. ; 
        return m_sum / static_cast<double> (m_N) ;
      }

    double getVariance (bool correct = false) const
      {
        if (m_N == 0) return 0. ; 
        double sigma = m_sumSq / static_cast<double>  (m_N) 
                       - (m_sum * m_sum) / static_cast<double> (m_N * m_N) ;
        if (correct && m_N > 1) sigma = sigma * m_N / static_cast<double> (m_N - 1) ;         
        return sigma ;
      }

    double getSigma (bool correct = false) const
      {
        return sqrt (getVariance (correct)) ;
      }

    double getVarianceMean (bool correct = false) const
      {
        return getVariance (correct) / m_N ;
      }

    double getSigmaMean (bool correct = false) const
      {
        return sqrt (getVarianceMean (correct)) ;
      }

  private:  

    double m_sum ;
    double m_sumSq ;
    long long int m_N ;

} ;


#endif