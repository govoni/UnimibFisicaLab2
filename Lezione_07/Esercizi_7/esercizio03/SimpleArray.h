#ifndef SIMPLE_ARRAY_H
#define SIMPLE_ARRAY_H
#include <iostream>
#include "../esercizio02/complesso.h"

template <typename T> 
class SimpleArray {
public:
  SimpleArray (const int & elementsNum);
  SimpleArray (const SimpleArray & copy);
  ~SimpleArray () { delete[] elements_p; }; 
  T & element (const int& i);
  T & operator[] (const int& i);
  T operator[] (const int& i) const;

private:

  int elementsNum_p;
  T * elements_p;
} ;


template <typename T> 
SimpleArray<T>::SimpleArray (const int & elementsNum): 
    elementsNum_p(elementsNum), 
    elements_p(elementsNum_p ? new T[elementsNum_p] : nullptr){

}

template <typename T> 
SimpleArray<T>::SimpleArray (const SimpleArray & copy): 
    elementsNum_p(copy.elementsNum_p), 
    elements_p(copy.elementsNum_p ? new T[copy.elementsNum_p] : nullptr){

    if (elements_p){
        for(int i = 0; i < elementsNum_p; i++){
            elements_p[i] = copy.elements_p[i];
        }
    }

}


template <typename T> 
T & SimpleArray<T>::element(const int& i){
    if(i > elementsNum_p || i < 0){
        std::cout << "requested index out of array dimension. return first element" << std::endl;
        return elements_p[0];
    } 
    return elements_p[i];
}

template <typename T> 
T & SimpleArray<T>::operator[](const int& i){
    if(i > elementsNum_p || i < 0){
        std::cout << "requested index out of array dimension. return first element" << std::endl;
        return elements_p[0];
    } 
    return elements_p[i];
}

template <typename T> 
T SimpleArray<T>::operator[](const int& i) const{
    if(i > elementsNum_p || i < 0){
        std::cout << "requested index out of array dimension. return first element" << std::endl;
        return elements_p[0];
    } 
    return elements_p[i];
}

#endif //SIMPLE_ARRAY_H