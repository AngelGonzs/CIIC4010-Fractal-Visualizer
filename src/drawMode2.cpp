#include "drawMode2.h"
#include <cmath>
DM2::DM2(bool activate, int n):Fractal(activate){
    this->n = n;
}

void DM2::draw(int x, int y, int n, int length){
    if(n != 0){
        ofSetColor(x/4, y/4, n*25.6);

        int leftAngle = randDegrees[n-1];
        int rightAngle = randDegrees[randDegrees.size() - n + 1 ];



        int middleY = y-length;
        int leftBranchX = x -length*cos(PI/180*leftAngle);
        int leftBranchY = middleY -length*sin(PI/180*leftAngle);
        int rightBranchX = x +length*cos(PI/180*rightAngle);
        int rightBranchY = middleY -length*sin(PI/180*rightAngle);

        ofDrawLine(x, y, x,y-length);
        ofDrawLine(x, y-length, rightBranchX, rightBranchY);
        ofDrawLine(x,y-length, leftBranchX, leftBranchY);

        draw(rightBranchX, rightBranchY, n-1, length/2);
        draw(leftBranchX, leftBranchY, n-1, length/2);
    }
}

void DM2::randomize(int n){
    for(int i=0;i<n*2;i++){
        randDegrees.push_back(ofRandom(30,70));
    }
} /*fills a vector of random degrees from 30 to 70 from which
on the draw function they will be picked for the left and right branch*/