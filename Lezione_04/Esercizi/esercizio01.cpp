//c++ -o es1 esercizio01.cpp
#include <iostream> 

static const int A =  214013;
static const int C =  2531011;
static const int M =  2147483647;

void rand(long int &num){
    num = (A* num + C)%M;
    return;
}

int main(){

    long int seed_ =  0;
    for(int i = 0; i < 10; ++i){
        rand(seed_);
        std::cout << i << ": " << seed_ << std::endl;
    }

    return 0;
}