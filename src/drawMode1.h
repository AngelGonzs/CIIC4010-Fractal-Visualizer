#include "FractalMode.h" //Brings neccesary functions to implement DrawMode1. All DrawMode.h files will include this file.

class DM1: public Fractal{
    public:
        DM1(bool);
        void draw(float,float,float,int);
};