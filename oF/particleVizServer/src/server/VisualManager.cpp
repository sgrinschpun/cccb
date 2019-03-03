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
}

void VisualManager::setupPixs(){

  while (pixs.size() != particleMap.size()){
      if (pixs.size() < particleMap.size()) {
          pixs.push_back(ofPixels());
      } else if (pixs.size() > particleMap.size()) {
          pixs.pop_back();
      }
  }

  for(int i=0; i<pixs.size(); i++){
    if(!pixs[i].isAllocated()){
      pixs[i].allocate(fboWidth,fboHeight,OF_IMAGE_COLOR_ALPHA);
    }
  }
}

void VisualManager::update(){
    setupPixs();

    DEBUG_MSG("Map Size: "+ to_string(particleMap.size()));
    DEBUG_MSG("Pixs Size: "+ to_string(pixs.size()));

    int loopCount = 0;
    for(auto pair:particleMap) {
      //update the particle
      pair.second->update();

      //draw particle in fbo
      rgbaFbo.begin();
      ofEnableAlphaBlending();
      pair.second->draw();
      ofDisableAlphaBlending();
      rgbaFbo.end();

      rgbaFbo.readToPixels(pixs[loopCount]);

      loopCount ++;
    }
}

void VisualManager::draw(){

    for(int i=0; i<pixs.size(); i++){
      img.setFromPixels(pixs[i].getData(),fboWidth,fboHeight,OF_IMAGE_COLOR_ALPHA);
      pixs[i].clear();
      img.update();
    }

    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
    img.draw(0,0);
    glDisable(GL_BLEND);
    img.clear();

    //rgbaFbo.clear();

}
