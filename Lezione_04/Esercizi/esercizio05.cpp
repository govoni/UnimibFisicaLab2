// c++ -o es5 esercizio05.cpp
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

float fgaus (float x){
    /*
        Gaussian distribution sigma = 1
    */
    return exp (-0.5 * x * x) ; 
}

float fpois (float x){
    /*
        Possion distribution mu=2. 
        The definition of a factorial cannot be defined for non-integers, 
        but a common generalization is the gamma function, defined for all 
        positive reals and all negative non-integers -> true gamma in stl (std::tgamma).
    */
    float fact = std::tgamma(x+1);
    return exp(-3)*pow(3, x)/fact; 
}

float funif (float x){
    /*
        Uniform distribution in -2, 2 -> constant at 1/4 
    */      
    return float(1)/4;
}

float rand_TAC (float f (float), float xMin, float xMax, float yMax){
    /*
        Try and catch. input requires a function  (f) taking as
        inputs float values and output float values. The algorithm also 
        requires x_min and x_max to extract a uniform number in this range.
        It then requires the y_max of the pdf (as pdf are non-negative y_min=0).
    */
    float x = 0. ;
    float y = 0. ; 
    do {
      x = rand_range (xMin, xMax) ;
      y = rand_range (0, yMax) ;
    } while (y > f (x)) ;
    return x ; 
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

    float x_min = -3;
    float x_max = 3;

    for(int i=0; i < dim; ++i){
        vals[i] = rand_TAC(fgaus, x_min, x_max, 10);
    }

    //Rough visualization of gaussian
    std::cout << "\n\nGAUSSIAN\n\n" << std::endl;
    visualize(vals, dim, 10, x_min, x_max);

    x_min = 0;
    x_max = 10;
    for(int i=0; i < dim; ++i){
        vals[i] = rand_TAC(fpois, x_min, x_max, 10);
    }
    //Rough visualization of poisson
    std::cout << "\n\nPOISSONIAN\n\n" << std::endl;
    visualize(vals, dim, 10, x_min, x_max);

    x_min = -2;
    x_max = 2;
    for(int i=0; i < dim; ++i){
        vals[i] = rand_TAC(funif, x_min, x_max, float(1)/4);
    }
    //Rough visualization of poisson
    std::cout << "\n\nUNIFORM\n\n" << std::endl;
    visualize(vals, dim, 10, x_min, x_max);


    return 0;
}