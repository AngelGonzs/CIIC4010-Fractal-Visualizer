#include "drawMode1.h"

DM1::DM1(bool activate):Fractal(activate){}

void DM1::draw(int x,int y, int n, int radius){
    if(n!=0){
        ofSetColor(x/4, y/4, n*64 );

        int rD = radius/n; //this alters the position of x/y and decreases the radius
        //to an extent, it serves as a complementary value to radius
        ofDrawCircle(x, y, radius);
        draw(x+radius - rD , y, n-1, radius - rD );
        draw(x-radius + rD , y, n-1, radius - rD );
        draw(x, y+radius - rD , n-1, radius - rD );
        draw(x, y-radius + rD , n-1, radius - rD );
    }
}