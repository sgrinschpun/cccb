#ifdef DEBUG
#define DEBUG_MSG(str) do { std::cout << str << std::endl; } while( false )
#else
#define DEBUG_MSG(str) do { } while ( false )
#endif

#include "VisualManager.h"
#include "Parameters.h"

VisualManager::VisualManager(){
}

void VisualManager::setup(shared_ptr<ListManager>& _listManager){
  this->setupFbo();
  listManager = _listManager;
  callToAction.setup(listManager);
  fadeAmnt = Parameters::fadeAmnt;
}

void VisualManager::setupFbo(){
  fboWidth=ofGetWidth();
  fboHeight=ofGetHeight();

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
  rgbaFbo.end();

}

void VisualManager::drawFbo(){
	rgbaFbo.begin();
    ofEnableAlphaBlending();
    ofEnableBlendMode(OF_BLENDMODE_DISABLED);
    listManager->lock();
    for(auto pair:listManager->particleMap) {
      ofVec2f position = pair.second->getPosition();
      ofPushMatrix();
      ofTranslate(position.x, position.y);
      pair.second->draw();
      ofPopMatrix();
    }
    listManager->unlock();
    ofDisableBlendMode();
    callToAction.drawImage();
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    ofFill();
    ofSetColor(0,0,0, fadeAmnt);
    ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());
    ofDisableBlendMode();
    ofDisableAlphaBlending();
  rgbaFbo.end();
}

void VisualManager::update(){
    ofEnableBlendMode(OF_BLENDMODE_DISABLED);
    drawFbo();
    ofDisableBlendMode();

    //sDisplay.update(particleMap.size());
    callToAction.update();

}

void VisualManager::draw(){
  ofEnableBlendMode(OF_BLENDMODE_DISABLED);
  rgbaFbo.draw(0,0);
  listManager->lock();
  for(auto pair:listManager->particleMap) {
    ofVec2f position = pair.second->getPosition();
    ofPushMatrix();
    ofTranslate(position.x, position.y);
    pair.second->drawInfo();
    ofPopMatrix();
  }
  listManager->unlock();
  ofDisableBlendMode();
  callToAction.drawText();
  //sDisplay.display();
}
