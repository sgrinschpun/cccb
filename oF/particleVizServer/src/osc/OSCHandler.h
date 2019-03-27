#ifndef _OSCHandler
#define _OSCHandler
#include "ofxOsc.h"
#include "PhenomenaCMD.h"
#include "ParticleData.h"

class OSCHandler{
    PhenomenaParams middleParams;

public:
    OSCHandler();
    void acumulativeParticleParse(ofxOscMessage message);
    PhenomenaCMD releaseParticle(ofxOscMessage message);


};
#endif
