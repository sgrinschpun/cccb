//
//  AVServer.cpp
//  oscReceiveExample
//
//  Created by Oscar Martinez Carmona on 05/02/2019.
//

#include "AVServer.hpp"

AVServer::AVServer(){}

void AVServer::begin(int port){
    oscReceiver.setup(port);
}

void AVServer::refresh(){
     while(oscReceiver.hasWaitingMessages()){
         ofxOscMessage message;
         oscReceiver.getNextMessage(message);
         cout << message.getAddress() << endl;
         if(message.getAddress() == "/particle/operation"){
             manageAV.update(oscHandler.releaseParticle(message));
         }
         else if (message.getAddress() != "/particle/operation") {
             oscHandler.acumulativeParticleParse(message);
         }
         else{

         }
     }
}
void AVServer::display(){
    manageAV.visualize();
}
