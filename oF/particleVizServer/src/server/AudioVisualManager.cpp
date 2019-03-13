//
//  ListManager.hpp
//  oscReceiveExample
//
//  Created by Oscar Martinez Carmona on 05/02/2019.
//

#include "AudioVisualManager.hpp"

AudioVisualManager::AudioVisualManager(){}

void AudioVisualManager::update(PhenomenaCMD phenoCMD){
    vManager.updateMap(phenoCMD);

}

void AudioVisualManager::draw(){
    vManager.update();
    vManager.draw();
}
