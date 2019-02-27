#include "WaveRing.h"

WaveRing::WaveRing(shared_ptr<Cycle>& cycle):cycle(cycle){

  //pos.set(0, 0, 0); //
  //rotate.set(0, 0, 0); //
  //speedNoise = ofRandom(10);
  //speed = ofRandom(10)/10000;
  //posNoise.set(ofRandom(10), ofRandom(10), ofRandom(10));
  //pos.set(0, 0, 0);
  //rotNoise.set(ofRandom(10), ofRandom(10), ofRandom(10));
  //rot.set(0, 0, 0);

  setupCircleMeshRing();

}

void WaveRing::setupCircleRing(){
  ofPoint p;
  ofFloatColor thisColor = ofColor::fromHsb(col, saturation, brightness, alpha);
  for(int i=0; i<=segments; i++){
    p.x =  (radius * cos(TWO_PI * i / segments));
    p.y =  (radius * sin(TWO_PI * i / segments));
    fatLinePoints.push_back(p);
    fatLineColors.push_back(thisColor);
    fatLineWidths.push_back(width);
  }
  fatLine.add(fatLinePoints, fatLineColors, fatLineWidths);
  fatLine.setFeather(2);
  fatLine.setClosed(true);

}

void WaveRing::updateWigglyCircleRing(){
  float max = noiseAmount*(cycle -> getEaseQuart2());
  ofPoint p;
  ofFloatColor thisColor;

  if (col_mode) {
    thisColor = ofColor::fromHsb(col, 0, 15, 255);
  }else{
    thisColor = ofColor::fromHsb(col, saturation, brightness, alpha);
  }

  for(int i=0; i<=segments; i++){
    p.x =  radius*cos(TWO_PI * i / segments);
    p.y =  radius*sin(TWO_PI * i / segments);
    p.x += ofSignedNoise(noiseCursor+noiseStep*p.x/radius, noiseCursor+noiseStep*p.y/radius)*max;
    p.y += ofSignedNoise(noiseCursor+noiseStep*p.x/radius, noiseCursor+noiseStep*p.y/radius)*max;
    fatLine.updatePoint(i, p);
    fatLine.updateWeight(i, width);
    fatLine.updateColor(i, thisColor);
  }
  fatLine.update();
}


void WaveRing::draw(){
  ofEnableBlendMode(OF_BLENDMODE_ADD);
  ofPushMatrix();
    ofTranslate(pos);
    ofRotateX(rotate.x);
    ofRotateY(rotate.y);
    ofRotateZ(rotate.z);
    fatLine.draw();
  ofPopMatrix();
}

void WaveRing::update(){
  if (cycle -> newLoop()==true){
     noiseCursor+= 0.1;
  }
  updateWigglyCircleRing();

  speed = ofNoise(speedNoise)*speed;

  pos.set((ofNoise(posNoise.x)*2-1)*pos.x,
          (ofNoise(posNoise.y)*2-1)*pos.y,
          (ofNoise(posNoise.z)*2-1)*pos.z);

  rotate.set((ofNoise(rotNoise.x)*2-1)*rot.x,
             (ofNoise(rotNoise.y)*2-1)*rot.y,
             (ofNoise(rotNoise.z)*2-1)*rot.z);

  speedNoise += 0.01;

  posNoise.x += speed;
  posNoise.y += speed;
  posNoise.z += speed;

  rotNoise.x += speed;
  rotNoise.y += speed;
  rotNoise.z += speed;

  col += colSpeed;
  if(col >= 255 || col <= 0) colSpeed *= -1;
}

void WaveRing::setNoiseStep(float _noiseStep){
  noiseStep=_noiseStep;
}

void WaveRing::setNoiseAmount(float _noiseAmount){
  noiseAmount=_noiseAmount;
}

void WaveRing::setWidth(float _width){
  width = _width;
}

void WaveRing::setRadius(float _radius){
  radius = _radius;
}

void WaveRing::setSegments(int _segments){
  segments = _segments;
}

void WaveRing::setPos(ofVec3f _pos) {
    pos = _pos;
}

void WaveRing::setRot(ofVec3f _rot) {
    rot = _rot;
}

void WaveRing::setSpeed(float _speed) {
    speed = _speed;
}

void WaveRing::setColorMode(bool _colMode) {
    colMode = _colMode;
}

void WaveRing::setSaturation(int _saturation) {
    saturation = _saturation;
}

void WaveRing::setBrightness(int _brightness) {
    brightness = _brightness;
}

void WaveRing::setAlpha(int _alpha) {
    alpha = _alpha;
}
