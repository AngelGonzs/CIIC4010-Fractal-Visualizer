#include "drawMode3.h"

DM3::DM3(bool activate): Fractal(activate){}


void DM3::draw(float x, float y, float size, int n){
    if(n == 0) {
        return;
    }

    ofSetColor(x/4, y/4, n*25.6);

    ofPoint a(x, y);
    ofPoint b(x + size, y);
    ofPoint c(x + size / 2, y + ((sqrt(3) * size) / 2));

    ofDrawTriangle(a, b, c);

    draw(x, y, size / 2, n - 1);
    draw((a.x + b.x) / 2, (a.y + b.y) / 2, size / 2, n - 1);
    draw(x + size/4, y + ((sqrt(3) * size/2) / 2) , size/2, n-1);
}