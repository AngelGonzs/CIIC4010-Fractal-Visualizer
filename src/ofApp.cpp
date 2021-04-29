#include "ofApp.h"
int cubeCounter = 0;
//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(15);
    dm1 = new DM1(false);

    dm2 = new DM2(false, depth);
    dm2->randomize(depth);

    dm3 = new DM3(false);
    dm4 = new DM4(false);

    dms.push_back(dm1);
    dms.push_back(dm2);
    dms.push_back(dm3);
    dms.push_back(dm4);

    Menger bocks(0,0,0,200);
    cubes.push_back(bocks);
    restart = cubes;

}

//--------------------------------------------------------------
void ofApp::update(){
    /* The update method is called muliple times per second
    It's in charge of updating variables and the logic of our app */
    ofSetBackgroundColor(0,0,0);
    //ofDrawBitmapString("Fractal Figures Visualizer. With depth control, even!", ofGetWidth()/2 - 50, ofGetHeight()/2);
    //ofDrawBitmapString("Test.", 0, 0);
    if(animation){
        timer += 1;
        if(timer>=30){
            depth++;
            if(depthM1 < 6) depthM1++;
            if(mengerDepth < 5) mengerDepth++;
            //those are the limits yea...

            timer = 0;
            //note that if many modes are activated at once there WILL be delay
            //this is due to how bad my VM is :)
            // (if u r not on a VM congrats)
        }
        if(depth >= 10){
            depth = 10;
            depthM1 = 4;
            mengerDepth = 1;
            //returns depths to default values
            animation = false;
        }
    }

    for(int i=0; i<dms.size();i++){
        if(dms[i]->getActivate()){
            switchCounter++;
        }
    }
    if(switchCounter > 0) oneOn = true;
    if(switchCounter == 0) oneOn = false;
    switchCounter = 0;


}



//--------------------------------------------------------------
void ofApp::draw(){
    /* The update method is called muliple times per second
    It's in charge of drawing all figures and text on screen */
    ofNoFill();
    if(oneOn == false && mode != '5' && mode != '6'){
    ofDrawBitmapString("Fractal Figures Visualizer. With depth control, even!", 0, 20);
    ofDrawBitmapString("This program has 6 modes you can interact with, and some features you can use. :)", 0, 50);
    ofDrawBitmapString("Press '1' to activate Circle Fractal.", 0, 70);
    ofDrawBitmapString("Press '2' to activate Fractal Tree.", 0, 90);
    ofDrawBitmapString("Press '3' to activate the Sierpiński Triangle :D.", 0, 110);
    ofDrawBitmapString("Press '4' to activate a Square based Fractal.", 0, 130);
    ofDrawBitmapString("Press '5' to activate a 2D Menger Cube, courtesy of Angel's hard work. Click to change the depths of the cube. :DD", 0, 150);
    ofDrawBitmapString("Press '6' to activate the 3D Menger Cube. Clicking and holding the mouse will allow you to rotate it, thanks to the EasyCam. :D", 0, 170);
    ofDrawBitmapString("Press '+' to increase the depth of the fractal levels.", 0, 190);
    ofDrawBitmapString("Press '-' to reduce the depth of the fractal levels.", 0, 210);
    ofDrawBitmapString("Press the Spacebar to activate the animation.", 0, 230);
    ofDrawBitmapString("Made by Angel Gonzalez and Yamil Mendez.", ofGetWidth()/256, ofGetHeight()/1.01);
    }
======

    if(dms[0]->getActivate()){
        dms[0]->draw(ofGetWidth()/2, ofGetHeight()/2, depthM1, 100);
    }
    if(dms[1]->getActivate()){
        dms[1]->draw(ofGetWidth()/2, ofGetHeight()-50, depth, 200);
    }
    if(dms[2]->getActivate()) {
        dms[2]->draw(ofGetWidth() / 4, 10, 500, depth);
    }
    if(dms[3]->getActivate()){
        ofTranslate(ofGetWidth()/2 - 100, ofGetHeight()/2 - 100);
        dms[3]->draw(0,0,200,mengerDepth);
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
    if(mode=='4'){
        dms[3]->setActivate();
        mode = '0';
    }

    if(mode=='5'){
        ofDrawBitmapString("Click to generate", 10,10);
        ofDrawBitmapString("Four clicks will cause a reset", 10,20);

        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        ofRotateXDeg(rot);
        ofSetColor(255);
        // spotlight.enable();
        for(Menger temp: cubes){
            temp.draw();
        }
        rot += 0.1;
    }

    if(mode=='6'){
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        cam.begin();
        ofRotateXDeg(rot);
        drawMode4(0,0,0,300,mengerDepth);
        rot += 0.01;
    }

    //method to desactivate all 2d stuff
    //when 3d stuff is on
    //damn i just realized that it's deactivator and not
    // desactivator yikes big typo lol
    //I gotchu fam
    if(deactivator){
        for(int i=0; i<dms.size();i++){
            if(dms[i]->getActivate()){
                dms[i]->setActivate();
            }
        }
        deactivator = false;
    }


    cam.end();
    // spotlight.disable();
    //for some reason the spotlight would never turn off so I have deleted it
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
            deactivator = true;
            break;
        case '6':
            mode = '6';
            deactivator = true;
            break;


        case '-':
            if(depth>0) depth--;
            if(depthM1>0) depthM1--;
            if(mengerDepth>0) mengerDepth--;
            break;

        case '=':
            depth++;
            depthM1++;
            mengerDepth++;
            break;

        case ' ':
            depth = 0;
            depthM1 = 0;
            mengerDepth = 0;
            animation = true;
            break;
    }
}

//--------------------------------------------------------------
//this mode was purely for practice and to help the development
//of a recursive menger sponge
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

    if(cubeCounter >=3){
        cubes = restart; 
        cubeCounter = 0;
        //reset
    }
    else{
        cubes = next;
        cubeCounter++;
        //generating a new layer
    }
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