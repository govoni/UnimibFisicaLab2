//c++ -o es6 esercizio06.cpp
#include <iostream> 
#include <cmath>
#include <iomanip>

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

float inv_exp(float y){
    /*
        For completeness we define the \lambda parameter of the 
        exponential distribution (actually a waste of memory but cool to play).
        pdf(x) = \lambda * exp(-\lambda x) x >= 0, 0 otherwise.
        F(x) = int_{0}^{x} pdf(x)dx = 1 - exp(-\lambda * x) for x >= 0, 0 otherwise.
        F^{-1}(y) = - (ln(1-y)) / \lambda
    */

    float lambda = 1;
    return - (log(1-y)/lambda);

}

void visualize(float* vals, int dim, int bins, float x_min, float x_max){
    /*
        Simple visualization of the distribution in the shell output.
        This function requires a pointer to the first element of an array of floats, its
        dimension, the bin you want to represent and the edges x_min and x_max.

    */

    float step = (x_max - x_min)/bins;
    std::cout << std::left << std::setw(4) << "Bin Range" << std::right << std::setw(10) << " " << "Entries" << std::endl ;
    for(int j  = 0; j < bins; ++j){
        float lower_edge = x_min + j*step;
        float upper_edge = x_min + (j+1)*step;
        
        std::cout << std::left << std::setw(4) << lower_edge << "," << std::right << std::setw(4) << upper_edge << ": " ;
        for(int i = 0; i < dim;  ++i){
            if (lower_edge <= vals[i] &&  vals[i] < upper_edge) std::cout << "=";
        }
        std::cout << "\n";
    }

    return;
}

int main(){

    seed_ = 0; //setting global seed of the sequence
    int dim = 200; //extracting 200 values
    float vals[dim]; //defining the array to same this pseudo-random values

    float y_min = 0;
    float y_max = 1;

    for(int i=0; i < dim; ++i){
        vals[i] = inv_exp(rand_range(y_min, y_max));
    }

    //Rough visualization of gaussian
    std::cout << "\n\nEXPONENTIAL\n\n" << std::endl;
    visualize(vals, dim, 10, 0, 5);


}