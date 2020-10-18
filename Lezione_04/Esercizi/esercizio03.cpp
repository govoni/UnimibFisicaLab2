// c++ -o es3 esercizio03.cpp
#include <iostream> 

//Same generator  as esercizio02.cpp
class LCG{

    public:

        LCG(): seed_(0) {};
        LCG(long int s): seed_(s) {};
        ~LCG() {};
        void set_seed(int s) { seed_ = s; };
        long int* rnd();

    private:
        long int seed_;
        const int A = 214013;
        const int C = 2531011;
        const int M = 2147483647;

};

long int* LCG::rnd(){
    seed_ = (A*seed_ + C)%M;
    return &seed_;
}

int main(){

    LCG rand;
    int dim = 10;
    long int vals[dim];

    std::cout << "ORIGINAL SEQUENCE" << std::endl;
    for(int i = 0; i < dim; ++i){
        vals[i] = *rand.rnd();
        std::cout << i << ": " << vals[i] <<  ", ";
        
    }
    std::cout << std::endl;

    //Inserting the seed at any point of the sequence and let it 
    //generate numbers up to dim-1.
    //Behaviour: reproducing original sequence starting from the i-th position.

    for (int i = 0; i < dim-1; ++i){
        std::cout << "Start seed: " << vals[i] << std::endl;
        rand.set_seed(vals[i]);

        for(int j = 0; j < dim-i-1; j++){
            std::cout << j+i+1 << ": " << *rand.rnd() <<  ", ";
        }
        std::cout << std::endl;
    }


    return 0;
}