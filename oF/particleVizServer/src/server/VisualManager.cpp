//
//  VisualManager.cpp
//  oscReceiveExample
//
//  Created by Oscar Martinez Carmona on 05/02/2019.
//

#include "VisualManager.hpp"
#include "ParticleData.h"
VisualManager::VisualManager(){}

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
        ofVec3f velocity;
        ofPoint position;
        velocity.set(ofRandom(-10.0, 10.0),ofRandom(-10.0, 10.0),0);
        position.set(ofGetWidth()/2, ofGetHeight()/2,0);
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

void VisualManager::refreshMap(){
    for(auto pair:particleMap) {
        pair.second->update();
    }
}

void VisualManager::visualizeMap(){
    for(auto pair:particleMap) {
        pair.second->draw();
    }
}
