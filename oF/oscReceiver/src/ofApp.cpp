#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  oscReceiver.setup(PORT);

}

//--------------------------------------------------------------
void ofApp::update(){
  while(oscReceiver.hasWaitingMessages()){
    ofxOscMessage message;
    oscReceiver.getNextMessage(message);
    string address = message.getAddress();
    ofLog() << "address:  "<< address;
    int numargs = message.getNumArgs();
    ofLog() << "args:  "<< to_string(numargs);
    string type = message.getArgTypeName(0);
    if (type == "s"){
      string arg =  message.getArgAsString(0);
      ofLog() << "address:  "<< address <<"  "<< arg;
    }
    else if (type == "i"){
      int arg =  message.getArgAsInt(0);
      ofLog() << "address:  "<< address << arg;
    }
    else if (type == "f"){
      int arg =  message.getArgAsFloat(0);
      ofLog() << "address:  "<< address <<" message: " <<arg;
    }


  }
}



// void ofApp::update(){
//   while(oscReceiver.hasWaitingMessages()){
//       ofxOscMessage message;
//       oscReceiver.getNextMessage(message);
//       string address = message.getAddress();
//       int numargs = message.getNumArgs();
//       ofLog() << "address:  "<< address;
//       ofLog()<< "number of arguments:  " << numargs;
//
//       for(int i=0; i<numargs; i++){
//         string type = message.getArgTypeName(i);
//         if (type == "s"){
//           string arg =  message.getArgAsString(i);
//           ofLog() << type<< "  "<<arg;
//         }
//         else if (type == "i"){
//           int arg =  message.getArgAsInt(i);
//           ofLog() << type<<"  "<<to_string(arg);
//         }
//       }
//   }
//
// }

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
