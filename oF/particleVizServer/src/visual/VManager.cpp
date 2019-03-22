#ifdef DEBUG
#define DEBUG_MSG(str) do { std::cout << str << std::endl; } while( false )
#else
#define DEBUG_MSG(str) do { } while ( false )
#endif

#include "VManager.h"
#include "Parameters.h"

float VManager::fadeAmnt{Parameters::fadeAmnt};

VManager::VManager(shared_ptr<map <int, shared_ptr<Particle>>> _particleMap){
  ofLog() << "vmanager init 1";
  particleMap = _particleMap;
  setupFbo();
  callToAction = make_unique<CallToActionController>(particleMap);
  ofLog() << "vmanager init 2";
}

void VManager::setupFbo(){
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
  ofLog() << "setup rgbagbo";
  ofClear(0,0,0,0);
  rgbaFbo.end();

}

void VManager::drawFbo(){
  ofLog() << "drawfbo 1";
  rgbaFbo.begin();
    ofLog() << "drawfbo 2";
    ofEnableAlphaBlending();
    ofEnableBlendMode(OF_BLENDMODE_DISABLED);
    for (particleIterator  it = particleMap->begin(); it != particleMap->end(); it++){
      ofVec2f position = it->second->getPosition();
      ofPushMatrix();
      ofTranslate(position.x, position.y);
      it->second->draw();
      ofPopMatrix();
    }
    ofDisableBlendMode();
    callToAction->drawImage();
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    ofFill();
    ofSetColor(0,0,0, fadeAmnt);
    ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());
    ofDisableBlendMode();
    ofDisableAlphaBlending();
    ofLog() << "drawfbo 2";
  rgbaFbo.end();
}



void VManager::update(){
  ofLog() << "update vmanager 1";
    ofEnableBlendMode(OF_BLENDMODE_DISABLED);
    drawFbo();
    ofDisableBlendMode();

    //sDisplay.update(particleMap.size());
    callToAction->update();
    ofLog() << "update vmanager 2";
}

void VManager::draw(){
  ofLog() << "draw vmanager 1";
  ofEnableBlendMode(OF_BLENDMODE_DISABLED);
  rgbaFbo.draw(0,0);

  for (particleIterator it = particleMap->begin(); it != particleMap->end(); it++){
    ofVec2f position = it->second->getPosition();
    ofPushMatrix();
    ofTranslate(position.x, position.y);
      it->second->drawInfo();
    ofPopMatrix();
  }
  ofDisableBlendMode();

  callToAction->drawText();
  //sDisplay.display();
  ofLog() << "draw vmanager 2";
}
