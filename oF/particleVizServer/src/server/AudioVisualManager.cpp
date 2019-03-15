#include "AudioVisualManager.h"

AudioVisualManager::AudioVisualManager(){}

void AudioVisualManager::update(PhenomenaCMD phenoCMD){
    vManager.updateMap(phenoCMD);

}

void AudioVisualManager::draw(){
    vManager.update();
    vManager.draw();
}
