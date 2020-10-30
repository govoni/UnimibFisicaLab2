//c++ -o es_8_9 statistiche.cc esercizio08_09.cpp
#include <iostream>
#include <cmath>
#include "statistiche.h"

static const int A =  214013;
static const int C =  2531011;
static const int M =  2147483647;
long int seed_;

//----------------- Redefining random number generator (LCG) -----------------

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

//----------------- MAIN -----------------


int main(){

    seed_ = 0; //setting global seed of the sequence
    float x_min = -5;
    float x_max = +5;

    int dim = 100000;
    statistiche* stats = new statistiche(dim/4);

    for(int i = 0; i < dim; ++i) stats->aggiungiNumero(rand_range(x_min, x_max));

    std::cout << "Uniform distribution in [" << x_min << "," << x_max << "] : " << std::endl;
    std::cout << "Theoretical mean (0.5(a+b)): " << 0.5*(x_min + x_max) 
              << " Computed mean: "              << stats->media() 
              << "+-"                            << stats->dev_standard_media(true) 
              << std::endl;

    std::cout << "Theoretical variance (1/12 (b-a)^2): " << (float(1)/12)*pow(x_max - x_min, 2) 
              << " Computed variance: "                  << stats->varianza_1(true) 
              << "+-"                                    << stats->dev_standard_media_SQ(true) 
              << std::endl;


    //Checking for CLT
    stats->reset();
    int d = 20; //number of extractions before computing mean
    for(int i = 0; i < dim; ++i){
        double sum = 0;
        for(int j = 0; j < d; ++j){
            sum += rand_range(x_min, x_max);
        }
        stats->aggiungiNumero(sum/d);
    }

    std::cout << "\n\nCheck for CLT with N: "    << d << std::endl;
    std::cout << "Theoretical mean (0.5(a+b)): " << 0.5*(x_min + x_max) 
              << " Computed mean: "              << stats->media() 
              << "+-"                            << stats->dev_standard_media(true) 
              << std::endl;

    std::cout << "Theoretical variance (1/12 (b-a)^2)/N: " << (float(1)/12)*pow(x_max - x_min, 2)/d 
              << " Computed variance: "                    << stats->varianza_1(true) 
              << "+-"                                      << stats->dev_standard_media_SQ(true) 
              << std::endl;

    



    return 0;
}

