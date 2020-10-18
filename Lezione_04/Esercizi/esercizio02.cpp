//c++ -o es2 esercizio02.cpp
#include <iostream> 

class LCG{

    public:

        LCG(): seed_(0) {};
        LCG(int s): seed_(s) {};
        ~LCG() {};
        void set_seed(long int s) { seed_ = s; };
        long int* rnd();

    private:
        long int seed_; // unsigned long int if M  > 2147483647
        const int A = 214013;
        const int C = 2531011;
        const int M = 2147483647;

};

long int* LCG::rnd(){
    seed_ = (A*seed_ + C)%M; //updating the seed x_{n+1} = (A*x_{n}  + C)%M
    return &seed_; //return reference to class member
}

int main(){

    LCG rand; // initialize with seed = 0

    for(int i = 0; i < 10; ++i){
        std::cout << i << ": " << *rand.rnd() << std::endl;
    }

    return 0;
}