#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetWindowTitle("Univers Quàntic @ cccB");
  ofBackground(0);
  ofSetFrameRate(60);
  ofSetVerticalSync(false);
  ofSetCircleResolution(100);
  ofHideCursor();

  oscManager.setup(PORT, listManager);
  oscManager.startThread();
  ofLog() << "listening for osc messages on port " << PORT;

  vizManager.setup(listManager);

}

//--------------------------------------------------------------
void ofApp::update(){
  listManager.update();
  vizManager.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
  vizManager.draw();
}

//--------------------------------------------------------------
void ofApp::exit() {
  oscManager.stopThread();
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
