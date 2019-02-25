#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("guiParticleViz");
    ofBackground(0);
    ofSetFrameRate(60);
    //ofSetBackgroundAuto(false);
    ofSetCircleResolution(256);
    ofSetVerticalSync(true);

    gui.setup();
    gui.add(shapes_num.set("number of shapes", 1, 1, 100));
    gui.add(radius.set("radius", ofGetHeight()/4, 1, ofGetHeight()/2));
    gui.add(pos.set("pos",
                    ofVec3f(0),
                    ofVec3f(0),
                    ofVec3f(720, 720, 720)));
    gui.add(rot.set("rot",
                    ofVec3f(0),
                    ofVec3f(0),
                    ofVec3f(720, 720, 720)));
    gui.add(speed.set("speed", 0, 0, 0.1));
    gui.add(color_mode.set("color mode", 0));
    gui.add(fadeAmnt.set("Fade Amount", 50, 0, 255));

    //WaveRing
    gui.add(framesPerCycle.set("framesPerCycle", 50, 1, 500));
    gui.add(segments.set("segments", 100, 100, 100));
    gui.add(width.set("width", 2, 0, 40));
    gui.add(noiseStep.set("noiseStep", 0.0,0, 1));
    gui.add(noiseAmount.set("noiseAmount", 0.40, 0.0, 100));
    gui.add(saturation.set("saturation",200,0,255));
    gui.add(brightness.set("brightness",255,0,255));
    gui.add(alpha.set("alpha",100,0,255));

    guidraw = true;

    WaveRingVariation wrv;
    shapes.push_back(wrv);

}

//--------------------------------------------------------------
void ofApp::update(){

    for (int i = 0; i < shapes.size(); i++) {
        shapes[i].update();

        shapes[i].setShapeNum(shapes_num);
        shapes[i].setRadius(radius);
        shapes[i].setPosAmp(pos);
        shapes[i].setRotAmp(rot);
        shapes[i].setSpeedAmp(speed);
        shapes[i].setColorMode(color_mode);
        shapes[i].setFadeAmnt(fadeAmnt);
        shapes[i].setNoiseStep(noiseStep);
        shapes[i].setNoiseAmount(noiseAmount);
        shapes[i].setWidth(width);
        shapes[i].setCycle(framesPerCycle);
        shapes[i].setRadius(radius);
        shapes[i].setSegments(segments);
        shapes[i].setStauration(saturation);
        shapes[i].setBrightness(brightness);
        shapes[i].setAlpha(alpha);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i < shapes.size(); i++) {
        shapes[i].draw();
    }

    if(guidraw) {
        gui.draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 's'){
      for (int i = 0; i < shapes.size(); i++) {
          shapes[i].screenCapture();
      }
    }

    if (key == 'g') {
        guidraw = false;
    }

    if (key == 'f') {
      for (int i = 0; i < shapes.size(); i++) {
          shapes[i].GIFstart();
      }
    }

    if (key == 'x') {
        buildXML();
    }

    if (key == 'l') {
        loadXML();
    }
}

void ofApp::buildXML(){
  ofxXmlSettings settings;
  settings.addTag("shape");
  settings.pushTag("shape");
    settings.addValue("shapes_num", shapes_num);
    settings.addValue("radius", radius);
    settings.addValue("width", width);
    settings.addValue("segments", segments);
    settings.addValue("speed", speed);
  settings.popTag();
  settings.addTag("variations");
  settings.pushTag("variations");
    settings.addTag("pos");
    settings.pushTag("pos");
      settings.addValue("x", pos->x);
      settings.addValue("y", pos->y);
      settings.addValue("z", pos->z);
    settings.popTag();
    settings.addTag("rot");
    settings.pushTag("rot");
      settings.addValue("x", rot->x);
      settings.addValue("y", rot->y);
      settings.addValue("z", rot->z);
    settings.popTag();
  settings.popTag();
  settings.addTag("wiggle");
  settings.pushTag("wiggle");
    settings.setValue("framesPerCycle", framesPerCycle);
    settings.setValue("noiseStep", noiseStep);
    settings.setValue("noiseAmount", noiseAmount);
  settings.popTag();
  settings.addTag("color");
  settings.pushTag("color");
    settings.addValue("fadeAmnt", fadeAmnt);
    settings.addValue("color_mode", color_mode);
    settings.addValue("saturation", saturation);
    settings.addValue("brightness", brightness);
    settings.addValue("alpha", alpha);
  settings.popTag();
  settings.saveFile("settings.xml");
}

void ofApp::loadXML(){
  ofxXmlSettings settings;
  if(settings.loadFile("settings.xml")){
    settings.pushTag("shape");
      shapes_num.set(settings.getValue("shapes_num", 0));
      radius.set(settings.getValue("radius", 0));
      width.set(settings.getValue("width", 0));
      segments.set(settings.getValue("segments", 0));
      speed.set(settings.getValue("speed", 0.00));
    settings.popTag();
    settings.pushTag("variations");
      settings.pushTag("pos");
        ofVec3f position;
        position.x = settings.getValue("x", 0);
        position.y = settings.getValue("y", 0);
        position.z = settings.getValue("z", 0);
        pos.set(position);
      settings.popTag();
      settings.pushTag("rot");
        ofVec3f rotation;
        rotation.x = settings.getValue("x", 0);
        rotation.y = settings.getValue("y", 0);
        rotation.z = settings.getValue("z", 0);
        rot.set(rotation);
      settings.popTag();
    settings.popTag();
    settings.pushTag("wiggle");
      framesPerCycle.set(settings.getValue("framesPerCycle", 0));
      noiseStep.set(settings.getValue("noiseStep", 0));
      noiseAmount.set(settings.getValue("setNoiseAmount", 0));
      settings.popTag();
    settings.pushTag("color");
    fadeAmnt.set(settings.getValue("fadeAmnt", 0));
    color_mode.set(settings.getValue("color_mode", 0));
    saturation.set(settings.getValue("saturation", 0));
    brightness.set(settings.getValue("brightness", 0));
    alpha.set(settings.getValue("alpha", 0));
    settings.popTag();
  }
  else{
    ofLogError("Settings file did not load!");
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
