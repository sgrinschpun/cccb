#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	//ofSetupOpenGL(1024,768,OF_WINDOW);
	ofSetupOpenGL(1920,1080,OF_FULLSCREEN);
	//ofSetupOpenGL(1920,1200,OF_FULLSCREEN);
	//ofSetupOpenGL(2560,1440,OF_WINDOW); // IMAC
	//ofSetupOpenGL(3840,2160,OF_WINDOW);	 // 4K
	//ofSetupOpenGL(7680,4320,OF_WINDOW); // 8K

	shared_ptr<ProjectFonts> fonts= make_shared<ProjectFonts>();

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

};
