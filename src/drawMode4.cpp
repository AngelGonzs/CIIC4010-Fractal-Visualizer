#include "drawMode4.h"

DM4::DM4(bool activate): Fractal(activate){}

void DM4::draw(float x, float y, float size, int n){
    if(n!=0){
        int color = x+y;

        if(color%5==0) ofSetColor(255,0,0); 
        else if (color%3==0) ofSetColor(255, 255, 0);
        else if (color%2==0) ofSetColor(0,0,255);
        else ofSetColor(0,255,0);
        //setting colors of course yea yea
        ofDrawRectangle(x,y,size,size);
        for(int i=-1;i<2;i++){
            for(int j=-1;j<2;j++){
                int sum = abs(i) + abs(j);
                if(sum!=0){
                    draw(x - i*(size/3) + size/3, y + j*(size/3) + size/3, size/3, n-1);
                }
            }
        }
        
    }
}