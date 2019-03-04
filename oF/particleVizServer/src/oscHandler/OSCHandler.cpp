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
    if(message.getAddress() == "/particle/attribute/id")
        middleParams.id = message.getArgAsInt(0);
    if(message.getAddress() == "/particle/attribute/parent")
        middleParams.parent = message.getArgAsInt(0);
    if(message.getAddress() == "/particle/attribute/name")
        middleParams.name = message.getArgAsString(0);
    if(message.getAddress() == "/particle/attribute/mass")
        middleParams.mass = message.getArgAsFloat(0);
    if(message.getAddress() == "/particle/attribute/charge")
        middleParams.charge = message.getArgAsFloat(0);
    if(message.getAddress() == "/particle/attribute/type")
        middleParams.type = message.getArgAsString(0);
    if(message.getAddress() == "/particle/attribute/E")
        middleParams.energy = message.getArgAsFloat(0);
    if(message.getAddress() == "/particle/attribute/vx")
        middleParams.vx = message.getArgAsFloat(0);
    if(message.getAddress() == "/particle/attribute/vy")
        middleParams.vy = message.getArgAsFloat(0);
    if(message.getAddress() == "/particle/attribute/vz")
        middleParams.vz = message.getArgAsFloat(0);
    if(message.getAddress() == "/particle/attribute/beta")
        middleParams.beta = message.getArgAsFloat(0);

    // if(message.getAddress() == "/particle/attribute/p")
    //     middleParams.p = message.getArgAsFloat(0);
    // if(message.getAddress() == "/particle/attribute/composition")
    //     middleParams.composition[0] = message.getArgAsString(0);
}

PhenomenaCMD OSCHandler::releaseParticle(ofxOscMessage message){
    string cmd = message.getArgAsString(0);
    PhenomenaCMD phenoCMD(cmd, middleParams);
    return phenoCMD;
}
