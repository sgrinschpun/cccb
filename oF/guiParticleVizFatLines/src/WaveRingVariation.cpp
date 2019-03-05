#ifdef DEBUG
#define DEBUG_MSG(str) do { std::cout << str << std::endl; } while( false )
#else
#define DEBUG_MSG(str) do { } while ( false )
#endif
#include "WaveRingVariation.h"

WaveRingVariation::WaveRingVariation() {
    cycle = make_shared<Cycle>(framesPerCycle);

    ofPoint position;
    position.set(ofGetWidth()/2, ofGetHeight()/2,0);
    ofVec3f velocity;
    velocity.set(0,1,0);
    kinematics = make_shared<Kinematics>(position, velocity);

}

ofPoint WaveRingVariation::getPosition(){
  return kinematics->getPosition();
}

void WaveRingVariation::update() {

  while (waverings.size() != shapesNum){
      if (waverings.size() < shapesNum) {
          WaveRing wr = WaveRing(cycle);
          waverings.push_back(wr);
      } else if (waverings.size() > shapesNum) {
          waverings.pop_back();
      }
  }

  for(int i=0; i<waverings.size(); i++){
    waverings[i].update();
  }

  kinematics->update();
}


void WaveRingVariation::draw() {
  ofEnableBlendMode(OF_BLENDMODE_ADD);
  for(int i=0; i<waverings.size(); i++){
    waverings[i].draw();
  }

}

void WaveRingVariation::setShapeNum(int _shapesNum) {
    shapesNum = _shapesNum;
}

void WaveRingVariation::setFadeAmnt(int _fadeAmnt){
    fadeAmnt = _fadeAmnt;
}

void WaveRingVariation::setCycle(int _framesPerCycle){
  framesPerCycle = _framesPerCycle;
  cycle -> setFramesPerCycle(_framesPerCycle);
}

void WaveRingVariation::setRadius(float _radius) {
  for(int i=0; i<waverings.size(); i++){
    waverings[i].setRadius(_radius);
  }
}

void WaveRingVariation::setPosAmp(ofVec3f _posAmp) {
  for(int i=0; i<waverings.size(); i++){
    waverings[i].setPosAmp(_posAmp);
  }
}

void WaveRingVariation::setRotAmp(ofVec3f _rotAmp) {
  for(int i=0; i<waverings.size(); i++){
    waverings[i].setRotAmp(_rotAmp);
  }
}

void WaveRingVariation::setSpeedAmp(float _speedAmp) {
  for(int i=0; i<waverings.size(); i++){
    waverings[i].setSpeedAmp(_speedAmp);
  }
}

void WaveRingVariation::setColorMode(bool _colMode) {
  for(int i=0; i<waverings.size(); i++){
    waverings[i].setColorMode(_colMode);
  }
}

void WaveRingVariation::setNoiseStep(float _noiseStep){
  for(int i=0; i<waverings.size(); i++){
    waverings[i].setNoiseStep(_noiseStep);
  }
}

void WaveRingVariation::setNoiseAmount(float _noiseAmount){
  for(int i=0; i<waverings.size(); i++){
    waverings[i].setNoiseAmount(_noiseAmount);
  }
}

void WaveRingVariation::setWidth(float _width){
  for(int i=0; i<waverings.size(); i++){
    waverings[i].setWidth(_width);
  }
}

void WaveRingVariation::setSegments(int _segments){
  for(int i=0; i<waverings.size(); i++){
    waverings[i].setSegments(_segments);
  }
}

void WaveRingVariation::setStauration(int _saturation){
  for(int i=0; i<waverings.size(); i++){
    waverings[i].setStauration(_saturation);
  }
}
void WaveRingVariation::setBrightness(int _brightness){
  for(int i=0; i<waverings.size(); i++){
    waverings[i].setBrightness(_brightness);
  }
}
void WaveRingVariation::setAlpha(int _alpha){
  for(int i=0; i<waverings.size(); i++){
    waverings[i].setAlpha(_alpha);
  }
}
