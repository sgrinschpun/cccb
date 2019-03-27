#ifndef _OSCManager
#define _OSCManager
#include "ofMain.h"
#include "ofxOsc.h"
#include "OSCHandler.h"
#include "ListManager.h"

class OSCManager: public ofThread {
private:
  ofxOscReceiver oscReceiver;
  OSCHandler oscHandler;
  shared_ptr<ListManager> listManager;

public:
  OSCManager();
  void setup(int _port, shared_ptr<ListManager>& _listManager);
  void threadedFunction();

};
#endif
