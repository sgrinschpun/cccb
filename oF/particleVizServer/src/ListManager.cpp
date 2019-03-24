#ifdef DEBUG
#define DEBUG_MSG(str) do { std::cout << str << std::endl; } while( false )
#else
#define DEBUG_MSG(str) do { } while ( false )
#endif

#include "ListManager.h"

ListManager::ListManager(){
}

bool ListManager::listIsEmpty(){
  bool status = false;
  if (particleMap.size()==0) {
    status = true;
  }
  return status;
}


void ListManager::updateMap(PhenomenaCMD phenoCMD) {
    if (phenoCMD.getCMD() == "ADD"){
        ofLog(OF_LOG_NOTICE, "Inserting particle to particleMap with id: " + ofToString(phenoCMD.getParams().id));
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

        ofVec2f velocity;
        velocity.set(phenoCMD.getParams().vy,phenoCMD.getParams().vz);
        velocity.scale(phenoCMD.getParams().beta);
        DEBUG_MSG("Particle Name " + phenoCMD.getParams().name + to_string(phenoCMD.getParams().beta));

        particleMap.insert(make_pair(phenoCMD.getParams().id, make_shared<Particle>(newParticleData,position, velocity)));
    }

    if (phenoCMD.getCMD() == "REMOVE"){
        map <int, shared_ptr<Particle>>::const_iterator i = particleMap.find(phenoCMD.getParams().id);
        if (i != particleMap.end()) {
            ofLog(OF_LOG_NOTICE, "Removing particle from particleMap with id: " + ofToString(phenoCMD.getParams().id));
            particleMap.erase(i);
        }
        else{
            ofLog(OF_LOG_NOTICE,  "The particle is not in particleMap! ");
        }
    }

    if (phenoCMD.getCMD() == "PURGE"){
        ofLog(OF_LOG_NOTICE, "Erasing all particles in particleMap! PURGE!");
        particleMap.clear();
    }
    ofLog(OF_LOG_NOTICE,"particleMap size is: " + ofToString(particleMap.size() ));
    ofLog(OF_LOG_NOTICE,"particleMap is empty?" +  ofToString(listIsEmpty() ));
}

void ListManager::update(){
  for(auto pair:particleMap) {
    pair.second->update();
  }
}

void ListManager::draw(){

}
