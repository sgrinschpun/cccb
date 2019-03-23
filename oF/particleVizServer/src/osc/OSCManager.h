#ifndef _OSCManager
#define _OSCManager
#include "ofMain.h"
#include "ofxOsc.h"
#include "OSCHandler.h"
#include "ListManager.h"

class OSCManager: public ofThread{
private:
  ofxOscReceiver oscReceiver;
  OSCHandler oscHandler;
  ListManager listManager;

public:
  OSCManager();
  void setup(int _port, ListManager &_listManager);
  void threadedFunction();

};
#endif
