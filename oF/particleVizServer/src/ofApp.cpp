#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetWindowTitle("Univers Quàntic @ cccB");
  ofBackground(0);
  ofSetFrameRate(60);
  ofSetVerticalSync(false);
  ofSetCircleResolution(100);
  ofHideCursor();

  avManager = make_shared<AVManager>();
  oscManager.setup(PORT, avManager);
  oscManager.startThread();
  ofLog() << "listening for osc messages on port " << PORT;

}

//--------------------------------------------------------------
void ofApp::update(){
  ofLog() << "update ofapp 1";
  avManager->update();
  ofLog() << "update ofapp 2";

}

//--------------------------------------------------------------
void ofApp::draw(){
  ofLog() << "draw ofapp 1";
  avManager->draw();
  ofLog() << "draw ofapp 2";
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
