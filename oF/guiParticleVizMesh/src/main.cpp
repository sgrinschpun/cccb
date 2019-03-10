#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
  //ofSetupOpenGL(1280,720,OF_WINDOW); // HD
	ofSetupOpenGL(1920,1080,OF_WINDOW); //FHD
	//ofSetupOpenGL(2560,1440,OF_WINDOW); // IMAC
	//ofSetupOpenGL(3840,2160,OF_WINDOW);	 // 4K
	//ofSetupOpenGL(7680,4320,OF_WINDOW); // 8K

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
