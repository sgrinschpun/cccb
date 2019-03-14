#include "AVServer.h"

AVServer::AVServer(){}

void AVServer::setup(int port){
    oscReceiver.setup(port);
}

void AVServer::update(){
     while(oscReceiver.hasWaitingMessages()){
         ofxOscMessage message;
         oscReceiver.getNextMessage(message);
         if(message.getAddress() == "/particle/operation"){
             manageAV.update(oscHandler.releaseParticle(message));
         }
         else if (message.getAddress().find("/particle/attributes") != string::npos) {
             oscHandler.acumulativeParticleParse(message);
         }
         else{

         }
     }
}
void AVServer::draw(){
    manageAV.draw();
}
