#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  sender.setup("localhost", PORT);

  //buildOfBundle();
  buildPythonBundleSimple("Z0");


  sender.sendMessage(message);
  //sender.sendBundle(bundle);
}

void ofApp::buildPythonBundleSimple(string _particle){
  message.setAddress("/ADD");
  message.addStringArg("Z0");
  //bundle.addMessage(message);
  //message.clear();
}


void ofApp::buildOfBundle(){
  message.setAddress("/particle/attributes/id");
  message.addIntArg(1);
  bundle.addMessage(message);
  message.clear();
  message.setAddress("/particle/attributes/parent");
  message.addIntArg(-1);
  bundle.addMessage(message);
  message.clear();
  message.setAddress("/particle/attributes/name");
  message.addStringArg("Z0");
  bundle.addMessage(message);
  message.clear();
  message.setAddress("/particle/attributes/mass");
  message.addFloatArg(0.8);
  bundle.addMessage(message);
  message.clear();
  message.setAddress("/particle/attributes/charge");
  message.addFloatArg(0.);
  bundle.addMessage(message);
  message.clear();
  message.setAddress("/particle/attributes/type");
  message.addStringArg("boson");
  bundle.addMessage(message);
  message.clear();
  message.setAddress("/particle/attributes/E");
  message.addFloatArg(0.8);
  bundle.addMessage(message);
  message.clear();
  message.setAddress("/particle/attributes/vx");
  message.addFloatArg(0.);
  bundle.addMessage(message);
  message.clear();
  message.setAddress("/particle/attributes/vy");
  message.addFloatArg(0.);
  bundle.addMessage(message);
  message.clear();
  message.setAddress("/particle/attributes/vz");
  message.addFloatArg(0.);
  bundle.addMessage(message);
  message.clear();
  message.setAddress("/particle/attributes/beta");
  message.addFloatArg(0.);
  bundle.addMessage(message);
  message.clear();
  message.setAddress("/particle/attributes/symbolName");
  message.addStringArg("Z0");
  bundle.addMessage(message);
  message.clear();
  message.setAddress("/particle/operation");
  message.addStringArg("ADD");
  bundle.addMessage(message);
  message.clear();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

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
