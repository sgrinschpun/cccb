#ifndef _OSCSender
#define _OSCSender
#include "ofMain.h"
#include "ofxOsc.h"

class OSCSender{
    ofxOscSender sender;
public:
    void setup(string hostIP, int port);
    void sendBigBangMessage(bool isBigbangOn);
};
#endif
