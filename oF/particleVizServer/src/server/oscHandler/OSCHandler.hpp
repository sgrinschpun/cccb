//
//  OSCHandler.hpp
//  oscReceiveExample
//
//  Created by Oscar Martinez Carmona on 05/02/2019.
//

#pragma once

#include <stdio.h>
#include "ofxOsc.h"
#include "PhenomenaCMD.hpp"
#include "ParticleData.h"

class OSCHandler{
    PhenomenaParams middleParams;
    //PhenomenaParams oscMessageToParams(ofxOscMessage message);
    //ParticleData paramsToParticleData(ofxOscMessage message);
    //PhenomenaParams jsonStringToParams(string jsonString);
public:
    OSCHandler();
    void acumulativeParticleParse(ofxOscMessage message);
    PhenomenaCMD releaseParticle(ofxOscMessage message);
    //PhenomenaCMD parseJson(ofxOscMessage message);
    //PhenomenaCMD parse(ofxOscMessage message);
private:

};
