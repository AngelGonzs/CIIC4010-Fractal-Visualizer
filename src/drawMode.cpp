#include "drawMode1.h"

DM1::DM1(bool activate):Fractal(activate){}

void DM1::draw(int x,int y, int n, int radius){
    if(n!=0){
        ofSetColor(x/4, y/4, n*64 );

        ofDrawCircle(x, y, radius);
        draw(x+radius , y, n-1, radius/2 );
        draw(x-radius , y, n-1, radius/2 );
        draw(x, y+radius , n-1, radius/2 );
        draw(x, y-radius , n-1, radius/2);
    }
}

        // drawMode1(x+100, y, n-1);
        // drawMode1(x-100, y, n-1);
        // drawMode1(x, y+100, n-1);
        // drawMode1(x, y-100, n-1);