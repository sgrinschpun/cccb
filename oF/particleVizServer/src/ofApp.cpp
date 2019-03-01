#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetWindowTitle("Univers Quàntic @ cccB");
  ofBackground(0);
  ofSetFrameRate(60);
  ofSetVerticalSync(true);
  ofSetCircleResolution(256);

  ofLog() << "listening for osc messages on port " << PORT;
  avServer.setup(PORT);

  setupFbo();
}

void ofApp::setupFbo(){
  ofFboSettings s;
  s.width = ofGetWidth();
  s.height = ofGetHeight();
  s.internalformat = GL_RGBA;
  s.useStencil = true;
  s.numSamples = 2;
  rgbaFbo.allocate(s);

  rgbaFbo.begin();
  ofClear(255,255,255, 0);
  rgbaFbo.end();
}

//--------------------------------------------------------------
void ofApp::update(){
    avServer.update();

    rgbaFbo.begin();
    avServer.draw();
    ofClearAlpha();
    rgbaFbo.end();
}

//--------------------------------------------------------------
void ofApp::draw(){
  rgbaFbo.draw(0,0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
