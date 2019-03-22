#ifdef DEBUG
#define DEBUG_MSG(str) do { std::cout << str << std::endl; } while( false )
#else
#define DEBUG_MSG(str) do { } while ( false )
#endif

#include "OSCManager.h"

OSCManager::OSCManager(){
}

void OSCManager::setup(int _port, shared_ptr<AVManager> &_avManager){
  avManager = _avManager;
  oscReceiver.setup(_port);
  ofLog() << "OSCManager setup";
}

void OSCManager::threadedFunction(){
  while(isThreadRunning()) {
    //ofLog() << "thread running";
    while(oscReceiver.hasWaitingMessages()){
      ofLog() << "message";
        ofxOscMessage message;
        oscReceiver.getNextMessage(message);
        if(message.getAddress() == "/particle/operation"){
            avManager->updateMap(oscHandler.releaseParticle(message));
        }
        else if (message.getAddress().find("/particle/attributes") != string::npos) {
            oscHandler.acumulativeParticleParse(message);
        }
        else{
        }
    }
  }
  ofLog() << "threaded 00";
}
