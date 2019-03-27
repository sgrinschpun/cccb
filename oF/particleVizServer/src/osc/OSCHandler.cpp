#include "OSCHandler.h"

OSCHandler::OSCHandler(){}

void OSCHandler::acumulativeParticleParse(ofxOscMessage message){
    if(message.getAddress() == "/particle/attributes/id")
        middleParams.id = message.getArgAsInt(0);
    if(message.getAddress() == "/particle/attributes/parent")
        middleParams.parent = message.getArgAsInt(0);
    if(message.getAddress() == "/particle/attributes/name")
        middleParams.name = message.getArgAsString(0);
    if(message.getAddress() == "/particle/attributes/mass")
        middleParams.mass = message.getArgAsFloat(0);
    if(message.getAddress() == "/particle/attributes/charge")
        middleParams.charge = message.getArgAsFloat(0);
    if(message.getAddress() == "/particle/attributes/type")
        middleParams.type = message.getArgAsString(0);
    if(message.getAddress() == "/particle/attributes/E")
        middleParams.energy = message.getArgAsFloat(0);
    if(message.getAddress() == "/particle/attributes/vx")
        middleParams.vx = message.getArgAsFloat(0);
    if(message.getAddress() == "/particle/attributes/vy")
        middleParams.vy = message.getArgAsFloat(0);
    if(message.getAddress() == "/particle/attributes/vz")
        middleParams.vz = message.getArgAsFloat(0);
    if(message.getAddress() == "/particle/attributes/beta")
        middleParams.beta = message.getArgAsFloat(0);
}

PhenomenaCMD OSCHandler::releaseParticle(ofxOscMessage message){
    string cmd = message.getArgAsString(0);
    PhenomenaCMD phenoCMD(cmd, middleParams);
    return phenoCMD;
}
