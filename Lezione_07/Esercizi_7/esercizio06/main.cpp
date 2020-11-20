/*
c++ -o es6 main.cpp

Testo:
    Si implementi la classe templata matrice delle matrici quadrate di dimensione N, 
    templata sulla dimensione delle matrici, definendo anche le operazioni fra matrici.
*/
#include "matrice.h"

template <int R, int C>
void fill(Matrice<R,C>& mat, double alpha, int axis){
    /*
        axis = 0 if x, 1 if y, 2 if z
    */  
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            if (i == j){
                i != axis ? mat.setCoord(i,j, cos(alpha)) : mat.setCoord(i,j, 1);
            }
            else{
                i+j+axis == 3 ? mat.setCoord(i,j, (j-1)*sin(alpha)) : mat.setCoord(i,j, 0);

            }
        }
    }

    return;

}

int main(){

    vettore<3> v;
    for(int i = 0; i < 3; ++i) i==0 ? v.setCoord(i,1) : v.setCoord(i,0); // (1,0,0)

    Matrice <3,3> rot_z;
    
    //-------------------------------------------------------------------------------
    //----------------------- Manual filling -> exact result ------------------------
    /*
    //filling rotation matrix around z-axis [(cos, -sin, 0), (sin, cos, 0), (0, 0, 1)]
    //pi/2 cos = 0, sin = 1
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            if (i == j){
                i != 2 ? rot_z.setCoord(i,j, 0) : rot_z.setCoord(i,j, 1);
            }
            else{
                i+j == 1 ? rot_z.setCoord(i,j, (i-j)) : rot_z.setCoord(i,j, 0);

            }
        }
    }
    */
    //-------------------------------------------------------------------------------

    fill(rot_z, M_PI/2, 2); // automatic filling -> approx. errors

    std::cout << "Rotation matrix alpha = pi/2" << std::endl;
    rot_z.stampa();

    vettore<3> v_rot = rot_z * v;
    std::cout << "Rotazione pi/2 around z axis of (1,0,0)" << std::endl;
    for(int i = 0; i < 3; ++i) std::cout << v_rot.at(i) << " ";
    std::cout << "\n";

    //-------------------------------------------------------------------------------
    //----------------------- Manual filling -> exact result ------------------------
    /*
    //filling rotation matrix around z-axis [(cos, -sin, 0), (sin, cos, 0), (0, 0, 1)]
    //pi cos = -1, sin = 0
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            if (i == j){
                i != 2 ? rot_z.setCoord(i,j, -1) : rot_z.setCoord(i,j, 1);
            }
            else{
                rot_z.setCoord(i,j, 0);

            }
        }
    }
    */
    //-------------------------------------------------------------------------------

    fill(rot_z, M_PI, 2); // automatic filling -> approx. errors

    std::cout << "Rotation matrix alpha = pi" << std::endl;
    rot_z.stampa();

    v_rot = rot_z * v;
    std::cout << "Rotazione pi around z axis of (1,0,0)" << std::endl;
    for(int i = 0; i < 3; ++i) std::cout << v_rot.at(i) << " ";
    std::cout << "\n";

    //-------------------------------------------------------------------------------
    //----------------------- Manual filling -> exact result ------------------------
    /*
    //Rotation around each axis returns original vector
    Matrice<3,3> rot_x;
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            if (i == j){
                i != 0 ? rot_x.setCoord(i,j, -1) : rot_x.setCoord(i,j, 1);
            }
            else{
                rot_x.setCoord(i,j, 0);

            }
        }
    }

    Matrice<3,3> rot_y;
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            if (i == j){
                i != 1 ? rot_y.setCoord(i,j, -1) : rot_y.setCoord(i,j, 1);
            }
            else{
                rot_y.setCoord(i,j, 0);

            }
        }
    }
    */
    //-------------------------------------------------------------------------------

    Matrice<3,3> rot_x; fill(rot_x, M_PI, 0);
    Matrice<3,3> rot_y; fill(rot_y, M_PI, 1);
    
    Matrice<3,3> par = rot_x*rot_y*rot_z;
    for(int i = 0; i < 3; ++i) v.setCoord(i,1); // (1,1,1)

    std::cout << "Rotation of pi around every axis of (1,1,1) yields" << std::endl;
    vettore<3> v_par = par * v;
    for(int i = 0; i < 3; ++i) std::cout << v_par.at(i) << " ";
    std::cout << "\n";


    return 0;
}