#ifdef DEBUG
#define DEBUG_MSG(str) do { std::cout << str << std::endl; } while( false )
#else
#define DEBUG_MSG(str) do { } while ( false )
#endif

#include "ListManager.h"
#include <mutex>



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
        auto particleIt = particleMap.find(phenoCMD.getParams().parent);
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
        std::unique_lock<std::mutex> lck (this->_mtx);
        particleMap.insert(make_pair(phenoCMD.getParams().id, make_shared<Particle>(newParticleData,position, velocity)));
    }

    else if (phenoCMD.getCMD() == "REMOVE"){
        map <int, shared_ptr<Particle>>::const_iterator i = particleMap.find(phenoCMD.getParams().id);
        if (i != particleMap.end()) {
            ofLog(OF_LOG_NOTICE, "Removing particle from particleMap with id: " + ofToString(phenoCMD.getParams().id));
            std::unique_lock<std::mutex> lck (this->_mtx);
            particleMap.erase(i);
        }
        else{
            ofLog(OF_LOG_NOTICE,  "The particle is not in particleMap! ");
        }
    }

    else if (phenoCMD.getCMD() == "PURGE"){
        ofLog(OF_LOG_NOTICE, "Erasing all particles in particleMap! PURGE!");
        std::unique_lock<std::mutex> lck (this->_mtx);
        particleMap.clear();
    }
    ofLog(OF_LOG_NOTICE,"particleMap size is: " + ofToString(particleMap.size()));
    ofLog(OF_LOG_NOTICE,"particleMap is empty? " +  ofToString(listIsEmpty()));
}

void ListManager::cleanupList(){

  for(auto iter=particleMap.begin(); iter!=particleMap.end(); ){
    if (particleIsOutOfBounds(iter->second)){
      particleMap.erase(iter++);
    }
    else{++iter;}
  }
}

bool ListManager::particleIsOutOfBounds(const shared_ptr<Particle>& _particle){
  bool outOfBounds = false;
  ofVec2f position = _particle->getPosition();
  if (position.x > ofGetWidth()+padding || position.x < 0-padding || position.y > ofGetHeight()+padding || position.y < 0-padding){
    outOfBounds = true;
  }
  ofLog()<<outOfBounds;
  return outOfBounds;
}


void ListManager::update(){
  std::unique_lock<std::mutex> lck (this->_mtx);
  for(auto pair:particleMap) {
    pair.second->update();
  }
  cleanupList();
}

void ListManager::draw(){

}
