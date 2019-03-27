#include "ofApp.h"
#include "Parameters.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetWindowTitle("Univers Quàntic @ cccB");
  ofBackground(0);
  ofSetFrameRate(60);
  ofSetVerticalSync(false);
  ofSetCircleResolution(100);
  ofHideCursor();
  showStats = false;

  listManager = make_shared<ListManager>();
  OSCInPort = Parameters::OSCInPort;
  oscManager.setup(OSCInPort, listManager);
  oscManager.startThread();
  ofLog() << "listening for osc messages on port " << OSCInPort;
  vizManager.setup(listManager);
}

//--------------------------------------------------------------
void ofApp::update(){
  listManager->update();
  vizManager.update();
  sDisplay.update(listManager->numberOnScreen(), listManager->particleMap.size());
}

//--------------------------------------------------------------
void ofApp::draw(){
  vizManager.draw();
  if (showStats){sDisplay.display();}
}

//--------------------------------------------------------------
void ofApp::exit() {
  oscManager.stopThread();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  if(key == 'z'){
    showStats = !showStats;
  }

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
