#ifdef DEBUG
#define DEBUG_MSG(str) do { std::cout << str << std::endl; } while( false )
#else
#define DEBUG_MSG(str) do { } while ( false )
#endif
#include "WaveRingVariation.h"

WaveRingVariation::WaveRingVariation() {

  fboWidth = ofGetWidth();
  fboHeight= ofGetHeight();
  ofFboSettings s;
  s.width = fboWidth;
  s.height = fboHeight;
  s.internalformat = GL_RGBA;
  //s.internalformat = GL_RGBA32F_ARB;
  //s.useDepth = true;
  s.useStencil = true;
  s.numSamples = 2;
  //(s.textureTarget = GL_TEXTURE_2D;
  //s.wrapModeHorizontal = GL_REPEAT;
  //s.wrapModeVertical = GL_REPEAT;
  rgbaFbo.allocate(s);

  rgbaFbo.begin();
  ofClear(255,255,255, 0);
  rgbaFbo.end();
}

void WaveRingVariation::setPosition(ofPoint _position){
  position = _position;
}

void WaveRingVariation::update() {

  for(int i=0; i<waverings.size(); i++){
    waverings[i].update();
  }

  //ofEnableAlphaBlending();
  rgbaFbo.begin();
  drawFbo();
  ofClearAlpha();
  rgbaFbo.end();
}

void WaveRingVariation::drawFbo(){
  ofEnableBlendMode(OF_BLENDMODE_ADD);
  ofPushMatrix();
  //ofTranslate(fboWidth/2, fboHeight/2);
  ofTranslate(position.x, position.y);
  for(int i=0; i<waverings.size(); i++){
    waverings[i].draw();
  }
  ofPopMatrix();

  ofEnableBlendMode(OF_BLENDMODE_ALPHA);
  ofFill();
  ofSetColor(0,0,0, fadeAmnt);
  ofDrawRectangle(0,0,fboWidth,fboHeight);
}

void WaveRingVariation::draw() {
  rgbaFbo.draw(0,0);
}

void WaveRingVariation::setShapeNum(int _shapesNum) {
    shapesNum = _shapesNum;
    for(int i=0; i<shapesNum; i++){
      WaveRing wr = WaveRing(cycle);
      waverings.push_back(wr);
    }
}

void WaveRingVariation::setFadeAmnt(int _fadeAmnt){
  fadeAmnt = _fadeAmnt;
}

void WaveRingVariation::setCycle(int _framesPerCycle){
  framesPerCycle = _framesPerCycle;
  cycle = make_shared<Cycle>(framesPerCycle);
}

void WaveRingVariation::setRadius(float _radius) {
  radius=_radius;
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

void WaveRingVariation::setSaturation(int _saturation){
  for(int i=0; i<waverings.size(); i++){
    waverings[i].setSaturation(_saturation);
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
