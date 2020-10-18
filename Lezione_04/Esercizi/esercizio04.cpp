//c++ -o es4 esercizio04.cpp
#include <iostream> 

static const int A =  214013;
static const int C =  2531011;
static const int M =  2147483647;
long int seed_;

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

int main(){

    seed_ = 0; //setting global seed of the sequence
    float min = -3;
    float max = 3;

    for(int i =0; i < 10; ++i) std::cout << rand_range(min, max) << std::endl;

    return 0;
}