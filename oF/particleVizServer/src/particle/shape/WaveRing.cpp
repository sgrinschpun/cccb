#ifdef DEBUG
#define DEBUG_MSG(str) do { std::cout << str << std::endl; } while( false )
#else
#define DEBUG_MSG(str) do { } while ( false )
#endif
#include "WaveRing.h"

WaveRing::WaveRing(shared_ptr<Cycle>& cycle):cycle(cycle){
  speedNoise = ofRandom(10);
  speedAmp = ofRandom(10)/10000;
  pos.set(0, 0, 0);
  posNoise.set(ofRandom(10), ofRandom(10), ofRandom(10));
  posAmp.set(0, 0, 0);
  rot.set(0, 0, 0);
  rotNoise.set(ofRandom(10), ofRandom(10), ofRandom(10));
  rotAmp.set(0, 0, 0);
  col = ofRandom(255);
  setupCircleRing();
}

void WaveRing::setupCircleRing(){
  wigglyMeshRing.setMode(OF_PRIMITIVE_LINE_STRIP);
}

void WaveRing::updateWigglyCircleRing(){
  float max = noiseAmount*(cycle -> getEaseQuart2());
  ofPoint p;
  wigglyMeshRing.clear();

  for(int i=0; i<=segments; i++){
    p.x =  radius*cos(TWO_PI * i / segments);
    p.y =  radius*sin(TWO_PI * i / segments);
    p.x += ofSignedNoise(noiseCursor+noiseStep*p.x/radius, noiseCursor+noiseStep*p.y/radius)*max;
    p.y += ofSignedNoise(noiseCursor+noiseStep*p.x/radius, noiseCursor+noiseStep*p.y/radius)*max;
    wigglyMeshRing.addVertex(p);
  }
}


void WaveRing::draw(){
  ofFloatColor thisColor;
  if (colMode) {
    thisColor = ofColor::fromHsb(col, 0, 15, 255);
  }else{
    thisColor = ofColor::fromHsb(col, saturation, brightness, alpha);
  }
  //ofEnableBlendMode(OF_BLENDMODE_ADD);
  ofSetLineWidth(width);
  ofSetColor(thisColor);
  ofNoFill();
  ofPushMatrix();
    ofTranslate(pos);
    ofRotateX(rot.x);
    ofRotateY(rot.y);
    ofRotateZ(rot.z);
    wigglyMeshRing.drawFaces();
  ofPopMatrix();
}

void WaveRing::update(){
  if (cycle -> newLoop()==true){
     noiseCursor+= 0.1;
  }
  updateWigglyCircleRing();

  float thisNoise =ofNoise(speedNoise);
  speed = thisNoise*speedAmp;

  pos.set((ofNoise(posNoise.x)*2-1)*posAmp.x,
          (ofNoise(posNoise.y)*2-1)*posAmp.y,
          (ofNoise(posNoise.z)*2-1)*posAmp.z);

  rot.set((ofNoise(rotNoise.x)*2-1)*rotAmp.x,
          (ofNoise(rotNoise.y)*2-1)*rotAmp.y,
          (ofNoise(rotNoise.z)*2-1)*rotAmp.z);

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

void WaveRing::setPosAmp(ofVec3f _posAmp) {
    posAmp = _posAmp;
}

void WaveRing::setRotAmp(ofVec3f _rotAmp) {
    rotAmp = _rotAmp;
}

void WaveRing::setSpeedAmp(float _speedAmp) {
    speedAmp = _speedAmp;
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
