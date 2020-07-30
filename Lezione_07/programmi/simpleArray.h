#ifndef simpleArray_h
#define simpleArray_h

template <class T> 
class SimpleArray {
public:
  // Costruttore
  SimpleArray (const int & elementsNum):
    elementsNum_p (elementsNum),
    elements_p (new T [elementsNum])
    {}
  // Distruttore
  ~SimpleArray () 
    {
      delete [] elements_p ;
    }
  // Metodo che restituisce un elemento dell'array
  T & element (const int& i) 
    {
      if( i < elementsNum_p) return elements_p[i] ;
      else return elements_p[elementsNum_p - 1] ; 
    }
  // Overloading di operator[]
  T & operator[] (const int& i) 
    {
      if (i < elementsNum_p) return elements_p[i] ;
      else return elements_p[elementsNum_p - 1] ; 
    }

private:

  int elementsNum_p ;
  T * elements_p ;
} ;

#endif