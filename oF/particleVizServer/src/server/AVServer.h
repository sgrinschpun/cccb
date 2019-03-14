#ifndef _AVServer
#define _AVServer

#include "ofxOsc.h"
#include "OSCHandler.h"
#include "AudioVisualManager.h"

class AVServer{
    ofxOscReceiver oscReceiver;
    OSCHandler oscHandler;
    AudioVisualManager manageAV;

public:
    AVServer();
    void setup(int port);
    void draw();
    void update();

};
#endif
