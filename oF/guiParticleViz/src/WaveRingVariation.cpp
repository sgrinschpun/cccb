#ifdef DEBUG
#define DEBUG_MSG(str) do { std::cout << str << std::endl; } while( false )
#else
#define DEBUG_MSG(str) do { } while ( false )
#endif
#include "WaveRingVariation.h"

WaveRingVariation::WaveRingVariation() {
    cycle = make_shared<Cycle>(framesPerCycle);

    //FBO
    //fboWidth = 7680;
    //fboHeight = 4320;
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
    DEBUG_MSG(s.internalformat);

    rgbaFbo.begin();
    ofClear(255,255,255, 0);
    rgbaFbo.end();

    gifEncoder = make_shared<ofxGifEncoder>();
    gifEncoder -> setup(ofGetWidth(), ofGetHeight(), 0.25f, 256);
    //gifEncoder -> setDitherMode(OFX_GIF_DITHER_BAYER4x4);
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

  //ofEnableAlphaBlending();
  rgbaFbo.begin();
  drawFbo();
  ofClearAlpha();
  rgbaFbo.end();
}

void WaveRingVariation::drawFbo(){

  ofEnableBlendMode(OF_BLENDMODE_ADD);
  ofPushMatrix();
  ofTranslate(fboWidth/2, fboHeight/2);
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

  if (start==true){
    getGIF();
  }
}

void WaveRingVariation::screenCapture() {
  ofPixels pixels;
  rgbaFbo.readToPixels(pixels);
  img.setFromPixels(pixels);
  img.save("pic" + ofToString(imgcount) + ".png", OF_IMAGE_QUALITY_BEST);
  imgcount++;
}

void WaveRingVariation::getGIF() {

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

void WaveRingVariation::GIFstart() {
    start = true;
    cout << start;
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

void WaveRingVariation::setPosAmp(ofVec3f _pos) {
  for(int i=0; i<waverings.size(); i++){
    waverings[i].setPosAmp(_pos);
  }
}

void WaveRingVariation::setRotAmp(ofVec3f _rot) {
  for(int i=0; i<waverings.size(); i++){
    waverings[i].setRotAmp(_rot);
  }
}

void WaveRingVariation::setSpeedAmp(float _speed) {
  for(int i=0; i<waverings.size(); i++){
    waverings[i].setSpeedAmp(_speed);
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
