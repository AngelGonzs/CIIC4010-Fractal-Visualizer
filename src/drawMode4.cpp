#include "drawMode4.h"

DM4::DM4(bool activate): Fractal(activate){}

void DM4::draw(float x, float y, float size, int n){
    if(n!=0){
        // ofSetColor(x+(n+5)*10,y+(n+5)*10,size*5);
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