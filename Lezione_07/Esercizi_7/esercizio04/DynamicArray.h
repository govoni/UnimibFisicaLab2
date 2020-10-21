#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

template <typename T>
class DynamicArray{

    public:
        DynamicArray();
        DynamicArray(int & dim);
        DynamicArray(const DynamicArray& copy);
        ~DynamicArray() { delete[] elements_p; };
        void push_back(const T & val);
        T & operator[] (const int& i);
        void resize();
        void clear();

        //------ Optional: define iterator for this class -----
        class iterator {
        public:
            //These are standard in order to define an iterator.
            //Constructor takes a pointer to template var (see line 31,32).
            //Overload the ++, != and * operators. C++ takes care of the rest.

            iterator(T * ptr): ptr(ptr){};
            iterator operator++() { ++ptr; return *this; }; 
            bool operator!=(const iterator & other) const { return ptr != other.ptr; };
            const T& operator*() const { return *ptr; };
        private:
            T* ptr;
        };

        iterator begin() const { return iterator(elements_p); }
        iterator end() const { return iterator(elements_p + current_size); }

        //------------------------------------------------------

    private:
        int capacity;
        int current_size;
        T * elements_p;

};

template <typename T>
DynamicArray<T>::DynamicArray(): 
    capacity(4), 
    current_size(0), 
    elements_p(capacity ? new T[capacity] : nullptr){

}

template <typename T>
DynamicArray<T>::DynamicArray(int & dim): 
    capacity(dim), 
    current_size(0), 
    elements_p(capacity ? new T[capacity] : nullptr){

}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray& copy): 
    capacity(copy.capacity), 
    current_size(copy.capacity), 
    elements_p(copy.capacity ? new T[copy.capacity] : nullptr){

        if (elements_p){
            for(int i = 0; i < capacity; ++i){
                elements_p[i] = copy.elements_p[i];
            }
        }

}

template <typename T>
void DynamicArray<T>::push_back(const T & val){

    if(current_size < capacity){
        elements_p[current_size] = val;
        current_size++;
    }
    else{
        std::cout << "augmenting size from " << capacity;
        capacity*=2;
        std::cout << "to " << capacity << std::endl;

        T * buffer = new T[capacity];

        for(int i = 0; i < current_size; ++i){
            buffer[i] = elements_p[i];
        }

        delete[] elements_p;
        elements_p = buffer;

        elements_p[current_size] = val;
        current_size++;

    }

    return;
}

template <typename T>
void DynamicArray<T>::clear(){
    capacity = 4;
    current_size = 0;
    delete[] elements_p;
    elements_p = new T[capacity];

    return;
}

template <typename T> 
T & DynamicArray<T>::operator[](const int& i){
    if(i > current_size-1 || i < 0 ) throw std::out_of_range("requested index out of array dimension");
    return elements_p[i];
}



#endif // DYNAMIC_ARRAY_H