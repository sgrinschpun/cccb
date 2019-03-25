#include "BigBang.h"

BigBang::BigBang(){
}

void BigBang::setup(){
}


void BigBang::draw(){
  if (ofGetFrameNum()%5==0){
    col = ofRandom(255);
  }
  ofFloatColor thisColor = ofColor::fromHsb(col, 200, 200,255);
  ofSetColor(thisColor);
  ofPushMatrix();
  ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
  bigBangFont->drawStringCentered("BIG BANG", 0, 0);
  ofPopMatrix();
}
