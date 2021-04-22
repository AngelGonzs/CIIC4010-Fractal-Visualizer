#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(15);
    dm1 = new DM1(false);

    dm2 = new DM2(false, depth);
    dm2->randomize(depth);

    dm3 = new DM3(false);

    dms.push_back(dm1);
    dms.push_back(dm2);
    dms.push_back(dm3);

    Menger bocks(0,0,0,200);
    cubes.push_back(bocks);

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
        spotlight.disable();
        dms[2]->setActivate();
        mode = '0';
    }

    if(mode=='4'){
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        ofRotateXDeg(rot);
        ofSetColor(255);
        spotlight.enable();
        for(Menger temp: cubes){
            temp.draw();
        }
        rot += 0.1;
        spotlight.disable();

    }

    if(mode=='5'){
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        cam.begin();
        ofRotateXDeg(rot);
        drawMode4(0,0,0,300,depthM1);
        rot += 0.01;
    }

    if(mode=='6'){
        ofTranslate(ofGetWidth()/2 - 100, ofGetHeight()/2 - 100);
        drawMode5(0,0,200,depthM1);
    }
    cam.end();
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
        case '5':
            mode = '5';
            break;
        case '6':
            mode = '6';
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

        case '.':
            zoom+=5;
    }
}

//--------------------------------------------------------------
void ofApp::drawMode4(float x, float y, float z, float size, int n){
    if(n!=0){
        ofPushMatrix();

        ofTranslate(x,y,z);

        // ofFill();
        //fill is NOT working well
        ofSetColor(255);
        // ofSetColor(x + x*size, y + y*size,  z+z*size);
        ofDrawBox(x,y,z, size);


        ofPopMatrix();
            for(int i = -1; i<2; i++){
                for(int j = -1; j<2; j++){
                    for(int k = -1; k<2; k++){
                        
                        int sum = abs(i) + abs(j) + abs(k);
                        if(sum>1){
                            drawMode4(x + i*(size/6), y + j*(size/6), z + k*(size/6), size/3, n-1);
                        }
                }
            }
        }
    }
}
//--------------------------------------------------------------
//need to move this to a fractal mode later but as of now i wont cause no.
void ofApp::drawMode5(float x, float y, float size, int n){
    if(n!=0){
        // ofSetColor(x+(n+5)*10,y+(n+5)*10,size*5);
        ofDrawRectangle(x,y,size,size);
        for(int i=-1;i<2;i++){
            for(int j=-1;j<2;j++){
                int sum = abs(i) + abs(j);
                if(sum!=0){
                    drawMode5(x - i*(size/3) + size/3, y + j*(size/3) + size/3, size/3, n-1);
                }
            }
        }
        
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
    // vector<Menger> nextCreation = cubes[0].creator();
    // cubes = nextCreation;
    vector<Menger> next;
    for(Menger h: cubes){
        vector<Menger> temp = h.creator();
        next.insert(next.end(), temp.begin(), temp.end());
    }
    cubes = next;
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