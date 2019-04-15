#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  sender.setup("localhost", PORT);

}

void ofApp::purgeParticles(){
  message.setAddress("/PURGE");
  sender.sendMessage(message);
  message.clear();
}

void ofApp::buildPythonBundleSimple(string _particle){
  message.setAddress("/ADD");
  message.addStringArg(_particle);
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
  if(key == 'q'){
    purgeParticles();
  }

  if(key == 'p'){
    buildPythonBundleSimple("pi0");
    sender.sendMessage(message);
    message.clear();
  }
  if(key == 'h'){
    buildPythonBundleSimple("h0(H_1)");
    sender.sendMessage(message);
    message.clear();
  }
  if(key == 't'){
    buildPythonBundleSimple("tau");
    sender.sendMessage(message);
    message.clear();
  }
  if(key == '6'){
    buildPythonBundleSimple("top");
    sender.sendMessage(message);
    message.clear();
  }
  if(key == 'w'){
    buildPythonBundleSimple("W+");
    sender.sendMessage(message);
    message.clear();
  }
  if(key == 'j'){
    buildPythonBundleSimple("J/psi");
    sender.sendMessage(message);
    message.clear();
  }
  if(key == 'o'){
    buildPythonBundleSimple("Omega_b-");
    sender.sendMessage(message);
    message.clear();
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
