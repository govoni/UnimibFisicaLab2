#ifndef forme_h
#define forme_h


class forma
{ 
  public:
    
    forma (double area = -1.) : m_area (area) {} 
    ~forma () {} 
    double area () const { return m_area ; } 
    virtual double calcola_area () { return -1. ; } 

  protected:  

    double m_area ;

} ;


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----


class quadrato : public forma 
{
  public:

    quadrato (double lato = 1.) :
      m_lato (lato),
      forma (lato * lato) {}

    double lato () const { return m_lato ; }
    void cambia_lato (double lato) 
      {
        m_lato = lato ;
        calcola_area () ;
        return ;
      } ;

    virtual double calcola_area () 
      { 
        m_area = m_lato * m_lato ; 
        return m_area ; 
      }

    ~quadrato () {} ;

  private:  

    double m_lato ;

} ;


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----


class rettangolo : public forma 
{
  public:

    rettangolo (double lato_o = 1., double lato_v = 1.) :
      m_lato_o (lato_o),
      m_lato_v (lato_v),
      forma (lato_o * lato_v) {}

    double lato_o () const { return m_lato_o ; }
    double lato_v () const { return m_lato_v ; }


    void cambia_lato_o (double lato) 
      {
        m_lato_o = lato ;
        calcola_area () ;
        return ;
      } 

    void cambia_lato_v (double lato) 
      {
        m_lato_v = lato ;
        calcola_area () ;
        return ;
      }

    virtual double calcola_area () 
      { 
        m_area = m_lato_o * m_lato_v ; 
        return m_area ; 
      }


    ~rettangolo () {} ;

  private:  

    double m_lato_o ;
    double m_lato_v ;

} ;


#endif