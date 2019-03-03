#ifdef DEBUG
#define DEBUG_MSG(str) do { std::cout << str << std::endl; } while( false )
#else
#define DEBUG_MSG(str) do { } while ( false )
#endif

#include "VisualManager.hpp"
#include "ParticleData.h"

VisualManager::VisualManager(){
  setupFbo();
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
        velocity.scale(3*phenoCMD.getParams().beta);
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
    cout << "VisualManager Hashmap size is: " << particleMap.size() << endl;
}

void VisualManager::setupFbo(){
  fboWidth=ofGetWidth();
  fboHeight=ofGetHeight();

  ofFboSettings s;
  s.width = fboWidth;
  s.height = fboHeight;
  s.internalformat = GL_RGBA;
  //s.useStencil = true;
  //s.numSamples = 2;
  rgbaFbo.allocate(s);

  rgbaFbo.begin();
  ofClear(0,0,0,0);
  rgbaFbo.end();

  pixels.allocate(fboWidth,fboHeight,OF_IMAGE_COLOR_ALPHA);
  img.allocate(fboWidth,fboHeight,OF_IMAGE_COLOR_ALPHA);

}

void VisualManager::update(){
    for(auto pair:particleMap) {
      pair.second->update();
    }
}

void VisualManager::draw(){
  for(auto pair:particleMap) {
    rgbaFbo.begin();
    ofEnableAlphaBlending();
    pair.second->draw();
    ofDisableAlphaBlending();
    rgbaFbo.end();

    rgbaFbo.readToPixels(pixels);
    img.setFromPixels(pixels.getData(),fboWidth,fboHeight,OF_IMAGE_COLOR_ALPHA);
    pixels.clear();

  }
  img.update();
  glEnable(GL_BLEND);
  glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
  img.draw(0,0);
  //img.clear();
  glDisable(GL_BLEND);

}
