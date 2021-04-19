#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    dm1 = new DM1(false);

    dm2 = new DM2(false, depth);
    dm2->randomize(depth);

    dm3 = new DM3(false);

    dms.push_back(dm1);
    dms.push_back(dm2);
    dms.push_back(dm3);
}

//--------------------------------------------------------------
void ofApp::update(){
    /* The update method is called muliple times per second
    It's in charge of updating variables and the logic of our app */
    ofSetBackgroundColor(0,0,0);
    if(animation){
        timer += 1;
        if(timer>=120){
            depth++;
            depthM1++;
            timer = 0;
            //note that if many modes are activated at once there WILL be delay
            //this is due to how trash this VM is ;)
            // (if u r not on a VM congrats)
        }
        if(depth >= 10){
            depth = 10;
            depthM1 = 4;
            //returns depths to default values
            animation = false;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    /* The update method is called muliple times per second
    It's in charge of drawing all figures and text on screen */
    ofNoFill();
    ofDrawBitmapString(mode, 100,100);
    if(dms[0]->getActivate()){
        dms[0]->draw(ofGetWidth()/2, ofGetHeight()/2, depthM1, 100);
    }
    if(dms[1]->getActivate()){
        dms[1]->draw(ofGetWidth()/2, ofGetHeight()-50, depth, 200);
    }
    if(dms[2]->getActivate()) {
        dms[2]->draw(ofGetWidth() / 8, 10, ofGetHeight() / 2, depth);
    }

    if(mode=='1'){
        dms[0]->setActivate();
        mode = '0';
    }
    if(mode=='2'){
        dms[1]->setActivate();
        dm2->randomize(depth);
        mode = '0';
    }
    if(mode=='3'){
        dms[2]->setActivate();
        mode = '0';
    }


}
void ofApp::drawMode1(int x, int y, int n){
    if(n!=0){
        ofSetColor(x/4, y/4, n*64 );
        ofDrawCircle(x, y, 100);
        drawMode1(x+100, y, n-1);
        drawMode1(x-100, y, n-1);
        drawMode1(x, y+100, n-1);
        drawMode1(x, y-100, n-1);
    }
}
void ofApp::drawMode2(int length, int n, int x, int y, int d){
    if(n != 0){
        ofSetColor(x/4, y/4, n*25.6);


        int middleY = y-length;
        int leftBranchX = x -length*cos(PI/180*d);
        int leftBranchY = middleY -length*sin(PI/180*d);
        int rightBranchX = x +length*cos(PI/180*d);
        int rightBranchY = middleY -length*sin(PI/180*d);

        ofDrawLine(x, y, x,y-length);
        ofDrawLine(x, y-length, rightBranchX, rightBranchY);
        ofDrawLine(x,y-length, leftBranchX, leftBranchY);

        drawMode2(length/2, n-1,rightBranchX,rightBranchY, 30);
        drawMode2(length/2,n-1,leftBranchX,leftBranchY, 30);
    }
    
}

void ofApp::drawMode3(float x, float y, float size, int n){
    if(n == 0) {
        return;
    }

    ofSetColor(x/4, y/4, n*25.6);

    ofPoint a(x, y);
    ofPoint b(x + size, y);
    ofPoint c(x + size / 2, y + ((sqrt(3) * size) / 2));

    ofDrawTriangle(a, b, c);

    drawMode3(x, y, size / 2, n - 1);
    drawMode3(b.x, y, size / 2, n - 1);
    drawMode3(c.x, c.y, size/2, n-1);
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    // This method is called automatically when any key is pressed
    switch(key){
        case '1':
            mode = '1';
            break;
        case '2':
            mode = '2';
            break;
        case '3':
            mode = '3';
            break;
        case '4':
            mode = '4';
            break;

        case '-':
            if(depth>0) depth--;
            if(depthM1>0) depthM1--;
            break;

        case '=':
            depth++;
            depthM1++;
            break;

        case ' ':
            depth = 0;
            depthM1 = 0;
            animation = true;
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}