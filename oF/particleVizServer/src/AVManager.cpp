#ifdef DEBUG
#define DEBUG_MSG(str) do { std::cout << str << std::endl; } while( false )
#else
#define DEBUG_MSG(str) do { } while ( false )
#endif

#include "AVManager.h"

AVManager::AVManager(){
  ofLog() << "AVManager init";
  shared_ptr<map <int, shared_ptr<Particle>>>  particleMap = make_shared<map <int, shared_ptr<Particle>>>();
  ofLog(OF_LOG_NOTICE,ofToString(particleMap->size()));
  unique_ptr<VManager> vizManager = make_unique<VManager>(particleMap);
}


void AVManager::updateMap(PhenomenaCMD phenoCMD) {
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
        particleIt = particleMap->find(phenoCMD.getParams().parent);
        if (particleIt != particleMap->end()) {
          position.set(particleIt->second->getPosition());
        }
        else {
          position.set(ofGetWidth()/2, ofGetHeight()/2,0);
        }

        ofVec2f velocity;
        velocity.set(phenoCMD.getParams().vy,phenoCMD.getParams().vz);
        velocity.scale(1*phenoCMD.getParams().beta);
        DEBUG_MSG("Particle Name " + phenoCMD.getParams().name + to_string(phenoCMD.getParams().beta));

        particleMap->insert(make_pair(phenoCMD.getParams().id, make_shared<Particle>(newParticleData,position, velocity)));
    }

    if (phenoCMD.getCMD() == "REMOVE"){
        map <int, shared_ptr<Particle>>::const_iterator i = particleMap->find(phenoCMD.getParams().id);
        if (i != particleMap->end()) {
            cout << "Removing particle from VisualManager Hashmap with id: "<< phenoCMD.getParams().id << endl;
            particleMap->erase(i);
        }
        else{
            cout << "The particle is not in the Hashmap! " << endl;
        }
    }

    if (phenoCMD.getCMD() == "PURGE"){
        cout << "Erasing all particles in the Hashmap! PURGE!" << endl;
        particleMap->clear();
    }
    cout << "VisualManager Hashmap size is: " << particleMap->size() << endl;
}

void AVManager::update(){
  ofLog() << "update avmanager 1";
  particleIterator it;
  particleIterator it1 = particleMap->begin();
  particleIterator it2 = particleMap->end();
  for (it = it1 ; it!=it2; it++){
    it->second->update();
  }
  ofLog() << "update avmanager 2";
  vizManager->update();
  ofLog() << "update avmanager 3";
}

void AVManager::draw(){
    vizManager->draw();
}
