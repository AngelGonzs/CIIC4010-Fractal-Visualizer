#pragma once
#include "FractalMode.h"
#include "ofVec3f.h"
#include <cmath>
#include <vector>

class Menger{
    public:
        Menger(float, float, float, float);
        void draw();
        vector<Menger> creator();
    private:
        float x;
        float y;
        float z;
        float size;
        ofVec3f position;
};

