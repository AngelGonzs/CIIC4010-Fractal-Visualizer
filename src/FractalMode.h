#pragma once
#include "ofMain.h"

class Fractal{
    public:
        Fractal(bool);
        virtual void draw(int,int,int,int) = 0;
        void setActivate();
        bool getActivate();
    private:
        bool activate = false;
};




/*Create an abstract class “FractalMode” this class should have the following methods:
draw(), setActivate(), getActivate() */
