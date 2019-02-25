//
//  OSCHandler.cpp
//  oscReceiveExample
//
//  Created by Oscar Martinez Carmona on 05/02/2019.
//

#include "OSCHandler.hpp"
#define DEBUG true

OSCHandler::OSCHandler(){}

void OSCHandler::acumulativeParticleParse(ofxOscMessage message){
    if(message.getAddress() == "/particle/id")
        middleParams.id = message.getArgAsInt(0);
    if(message.getAddress() == "/particle/parent")
        middleParams.parent = message.getArgAsInt(0);
    if(message.getAddress() == "/particle/name")
        middleParams.name = message.getArgAsString(0);
    if(message.getAddress() == "/particle/mass")
        middleParams.mass = message.getArgAsFloat(0);
    if(message.getAddress() == "/particle/charge")
        middleParams.charge = message.getArgAsFloat(0);
    if(message.getAddress() == "/particle/type")
        middleParams.type = message.getArgAsString(0);
    if(message.getAddress() == "/particle/E")
        middleParams.E = message.getArgAsFloat(0);
    if(message.getAddress() == "/particle/vx")
        middleParams.vx = message.getArgAsFloat(0);
    if(message.getAddress() == "/particle/vy")
        middleParams.vy = message.getArgAsFloat(0);
    if(message.getAddress() == "/particle/vz")
        middleParams.vz = message.getArgAsFloat(0);
    if(message.getAddress() == "/particle/beta")
        middleParams.beta = message.getArgAsFloat(0);

    // if(message.getAddress() == "/particle/p")
    //     middleParams.p = message.getArgAsFloat(0);
    // if(message.getAddress() == "/particle/composition")
    //     middleParams.composition[0] = message.getArgAsString(0);
}

PhenomenaCMD OSCHandler::releaseParticle(ofxOscMessage message){
    string cmd = message.getArgAsString(0);
    PhenomenaCMD phenoCMD(cmd, middleParams);
    return phenoCMD;
}
