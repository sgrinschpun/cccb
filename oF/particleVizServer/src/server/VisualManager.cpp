#ifdef DEBUG
#define DEBUG_MSG(str) do { std::cout << str << std::endl; } while( false )
#else
#define DEBUG_MSG(str) do { } while ( false )
#endif

#include "VisualManager.hpp"
#include "ParticleData.h"

VisualManager::VisualManager(){
  setupFbo();
  setupFont();
}

ofTrueTypeFont VisualManager::myFont;

void VisualManager::setupFont(){
  if (!myFont.isLoaded()){
    myFont.load("Lato-Regular.ttf",15);
  }
}

void VisualManager::updateMap(PhenomenaCMD phenoCMD) {
    if (phenoCMD.getCMD() == "ADD"){
        cout << "Inserting particle to VisualManager Hashmap with id: "<< phenoCMD.getParams().id << endl;
        shared_ptr<ParticleData> newParticleData =
        make_shared<ParticleData>(phenoCMD.getParams().id,
                                  phenoCMD.getParams().parent,
                                  phenoCMD.getParams().name,
                                  phenoCMD.getParams().mass,
                                  phenoCMD.getParams().charge,
                                  phenoCMD.getParams().type,
                                  phenoCMD.getParams().energy
                                );

        ofPoint position;
        particleIt = particleMap.find(phenoCMD.getParams().parent);
        if (particleIt != particleMap.end()) {
          position.set(particleIt->second->getPosition());
        }
        else {
          position.set(ofGetWidth()/2, ofGetHeight()/2,0);
        }

        ofVec3f velocity;
        velocity.set(phenoCMD.getParams().vy,phenoCMD.getParams().vz,phenoCMD.getParams().vx);
        velocity.scale(2*phenoCMD.getParams().beta);
        DEBUG_MSG("Particle Name " + phenoCMD.getParams().name);

        particleMap.insert(make_pair(phenoCMD.getParams().id, make_shared<Particle>(newParticleData,position, velocity)));
    }

    if (phenoCMD.getCMD() == "REMOVE"){
        map <int, shared_ptr<Particle>>::const_iterator i = particleMap.find(phenoCMD.getParams().id);
        if (i != particleMap.end()) {
            cout << "Removing particle from VisualManager Hashmap with id: "<< phenoCMD.getParams().id << endl;
            particleMap.erase(i);
        }
        else{
            cout << "The particle is not in the Hashmap! " << endl;
        }
    }
    
    if (phenoCMD.getCMD() == "PURGE"){
        cout << "Erasing all particles in the Hashmap! PURGE!" << endl;
        particleMap.clear();
    }
    cout << "VisualManager Hashmap size is: " << particleMap.size() << endl;
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
    for(auto pair:particleMap) {
      ofPoint position = pair.second->getPosition();
      ofPushMatrix();
      ofTranslate(position.x, position.y);
      pair.second->draw();
      ofPopMatrix();
    }
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    ofFill();
    ofSetColor(0,0,0, 10);
    ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());
    ofDisableAlphaBlending();

  rgbaFbo.end();
}

void VisualManager::update(){
    for(auto pair:particleMap) {
      pair.second->update();
    }
    drawFbo();
    sDisplay.update(particleMap.size());
}

void VisualManager::draw(){
  glEnable(GL_BLEND);
  glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
  rgbaFbo.draw(0,0);
  glDisable(GL_BLEND);
  sDisplay.display();
}
