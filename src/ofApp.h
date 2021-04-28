#pragma once
#include<cmath>
#include<vector>

#include "ofMain.h"
#include "FractalMode.h"
#include "drawMode1.h"
#include "drawMode2.h"
#include "drawMode3.h"
#include "drawMode4.h"
//testing menger:
#include "Menger.h"
#include "ofLight.h"
#include "ofEasyCam.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		//void drawString();

		void drawMode1(int x, int y, int n);
		void drawMode2(int length, int n, int x, int y, int d);
		void drawMode3(float x, float y, float size, int n);
		//new:
		void drawMode4(float, float, float, float, int);
		void drawMode5(float, float, float, int);
		//
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
	private:
		char mode;
		int depth = 10;
		int depthM1 = 4;


		DM1 *dm1;
		DM2 *dm2;
		DM3 *dm3;
		DM4 *dm4;

    	vector<Menger> cubes;
		vector<Menger> restart;
		//storage for all the cubes
        float rot = 0;
		//variable used to rotate the cube hehehehe

		vector<Fractal*> dms;	
		ofLight spotlight;

		ofEasyCam cam;
		int zoom = 100;


		//variables for animation feature
		int timer = 0;
		bool animation = false;
		
};
