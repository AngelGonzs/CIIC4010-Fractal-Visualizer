#include "drawMode3.h"

DM3::DM3(bool activate): Fractal(activate){}


void DM3::draw(int x, int y, int size, int n){
    if(n == 0) {
        return;
    }

    ofSetColor(x/4, y/4, n*25.6);

    ofPoint a(x, y);
    ofPoint b(x + size, y);
    ofPoint c(x + size / 2, y + ((sqrt(3) * size) / 2));

    ofDrawTriangle(a, b, c);

    draw(x, y, size / 2, n - 1);
    draw(b.x, y, size / 2, n - 1);
    draw(c.x, c.y, size/2, n-1);
}