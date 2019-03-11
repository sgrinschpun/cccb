#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("guiParticleVizMesh");
    ofBackground(0);
    ofSetFrameRate(60);
    //ofSetBackgroundAuto(false);
    ofSetCircleResolution(100);
    ofSetVerticalSync(true);

    gui.setup();
    gui.add(shapesNum.set("number of shapes", 1, 1, 100));
    gui.add(radius.set("radius", ofGetHeight()/4, 1, ofGetHeight()/2));
    gui.add(posAmp.set("posAmp",
                    ofVec3f(0),
                    ofVec3f(0),
                    ofVec3f(720, 720, 720)));
    gui.add(rotAmp.set("rotAmp",
                    ofVec3f(0),
                    ofVec3f(0),
                    ofVec3f(720, 720, 720)));
    gui.add(speedAmp.set("speedAmp", 0, 0, 0.1));
    gui.add(colMode.set("color mode", 0));
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

    setupFbo();

    gifEncoder = make_shared<ofxGifEncoder>();
    gifEncoder -> setup(ofGetWidth(), ofGetHeight(), 0.25f, 256);
    //gifEncoder -> setDitherMode(OFX_GIF_DITHER_BAYER4x4);

    middle.set(fboWidth/2,fboHeight/2);

}

void ofApp::setupFbo(){
  fboWidth=ofGetWidth();
  fboHeight=ofGetHeight();

  //fboWidth=3840;
  //fboHeight=2160;

  ofFboSettings s;
  s.width = fboWidth;
  s.height = fboHeight;
  s.internalformat = GL_RGBA32F_ARB; //GL_RGBA;
  s.wrapModeHorizontal = GL_REPEAT; //
  s.wrapModeVertical = GL_REPEAT;
  s.useStencil = true;
  s.numSamples = 2;
  rgbaFbo.allocate(s);

  rgbaFbo.begin();
  ofClear(0,0,0,0);
  ofClearAlpha();
  rgbaFbo.end();

}

void ofApp::drawFboMove(){
  rgbaFbo.begin();
    ofEnableAlphaBlending();
    for (int i = 0; i < shapes.size(); i++) {
      ofPoint position = shapes[i].getPosition();
      ofPushMatrix();
      ofTranslate(position.x, position.y);
      shapes[i].draw();
      ofPopMatrix();
    }
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    ofFill();
    ofSetColor(0,0,0, fadeAmnt);
    ofDrawRectangle(0,0,fboWidth,fboHeight);
    ofDisableAlphaBlending();

    ofClearAlpha();
  rgbaFbo.end();
}

void ofApp::drawFboStatic(){
  rgbaFbo.begin();
    ofEnableAlphaBlending();
    ofPushMatrix();
    ofTranslate(middle.x, middle.y);
    for (int i = 0; i < shapes.size(); i++) {
      shapes[i].draw();
    }
    ofPopMatrix();
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    ofFill();
    ofSetColor(0,0,0, 10);
    ofDrawRectangle(0,0,fboWidth,fboHeight);
    ofDisableAlphaBlending();
    ofClearAlpha();
  rgbaFbo.end();
}

void ofApp::drawFbo(){
  if (move){
    drawFboMove();
  }
  else {
    drawFboStatic();
  }

}



//--------------------------------------------------------------
void ofApp::update(){

    for (int i = 0; i < shapes.size(); i++) {
        shapes[i].update();

        shapes[i].setShapeNum(shapesNum);
        shapes[i].setRadius(radius);
        shapes[i].setPosAmp(posAmp);
        shapes[i].setRotAmp(rotAmp);
        shapes[i].setSpeedAmp(speedAmp);
        shapes[i].setColorMode(colMode);
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

    drawFbo();
}

//--------------------------------------------------------------
void ofApp::draw(){
  glEnable(GL_BLEND);
  glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
  rgbaFbo.draw(0,0);
  glDisable(GL_BLEND);

  if (start==true){
    getGIF();
  }

  if(guidraw) {
      gui.draw();
  }

}


void ofApp::screenCapture() {
  ofPixels pixels;
  rgbaFbo.readToPixels(pixels);
  img.setFromPixels(pixels);
  img.save("pic" + ofToString(imgcount) + ".png", OF_IMAGE_QUALITY_BEST);
  imgcount++;
}

void ofApp::getGIF() {

  if(framesCurr < framesTotal) {
      rgbaFbo.readToPixels(pixels);
      imgforgif.setFromPixels(pixels);
      gifEncoder -> addFrame(imgforgif, 0.033f);
  }

  if(framesCurr == framesTotal) {
      gifEncoder -> save("test.gif");
      imgforgif.clear();
      start = false;
  }
  framesCurr++;
}

void ofApp::GIFstart() {
    start = true;
    cout << start;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'c'){
      screenCapture();
    }

    if (key == 'g') {
        guidraw = false;
    }

    if (key == 'h') {
        guidraw = true;
    }

    if (key == 'f') {
      GIFstart();
    }

    if (key == 'x') {
      buildXML();
    }

    if (key == 'l') {
      loadXML();
    }

    if (key == 'm') {
      move = true;
    }

    if (key == 's') {
      move = false;
    }
}

void ofApp::buildXML(){
  ofxXmlSettings settings;
  settings.addTag("shape");
  settings.pushTag("shape");
    settings.addValue("shapesNum", shapesNum);
    settings.addValue("radius", radius);
    settings.addValue("width", width);
    settings.addValue("segments", segments);
    settings.addValue("speedAmp", speedAmp);
  settings.popTag();
  settings.addTag("variations");
  settings.pushTag("variations");
    settings.addTag("posAmp");
    settings.pushTag("posAmp");
      settings.addValue("x", posAmp->x);
      settings.addValue("y", posAmp->y);
      settings.addValue("z", posAmp->z);
    settings.popTag();
    settings.addTag("rotAmp");
    settings.pushTag("rotAmp");
      settings.addValue("x", rotAmp->x);
      settings.addValue("y", rotAmp->y);
      settings.addValue("z", rotAmp->z);
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
    settings.addValue("colMode", colMode);
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
      shapesNum.set(settings.getValue("shapesNum", 0));
      radius.set(settings.getValue("radius", 0));
      width.set(settings.getValue("width", 0));
      segments.set(settings.getValue("segments", 0));
      speedAmp.set(settings.getValue("speedAmp", 0.00));
    settings.popTag();
    settings.pushTag("variations");
      settings.pushTag("posAmp");
        ofVec3f position;
        position.x = settings.getValue("x", 0);
        position.y = settings.getValue("y", 0);
        position.z = settings.getValue("z", 0);
        posAmp.set(position);
      settings.popTag();
      settings.pushTag("rotAmp");
        ofVec3f rotation;
        rotation.x = settings.getValue("x", 0);
        rotation.y = settings.getValue("y", 0);
        rotation.z = settings.getValue("z", 0);
        rotAmp.set(rotation);
      settings.popTag();
    settings.popTag();
    settings.pushTag("wiggle");
      framesPerCycle.set(settings.getValue("framesPerCycle", 0.00));
      noiseStep.set(settings.getValue("noiseStep", 0.00));
      noiseAmount.set(settings.getValue("noiseAmount", 0.00));
      settings.popTag();
    settings.pushTag("color");
    fadeAmnt.set(settings.getValue("fadeAmnt", 0));
    colMode.set(settings.getValue("colMode", 0));
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
