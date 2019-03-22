#ifndef _OSCManager
#define _OSCManager
#include "ofMain.h"
#include "ofxOsc.h"
#include "OSCHandler.h"
#include "AVManager.h"

class OSCManager: public ofThread{
private:
  ofxOscReceiver oscReceiver;
  OSCHandler oscHandler;
  shared_ptr<AVManager> avManager;

public:
  OSCManager();
  void setup(int _port, shared_ptr<AVManager> &_avManager);
  void threadedFunction();

};
#endif
