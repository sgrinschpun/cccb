#include "AudioVisualManager.h"

AudioVisualManager::AudioVisualManager(){}

void AudioVisualManager::updateMap(PhenomenaCMD phenoCMD){
    vManager.updateMap(phenoCMD);

}

void AudioVisualManager::update(){
    vManager.update();
}


void AudioVisualManager::draw(){
    vManager.draw();
}
