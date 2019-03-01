//
//  AVServer.hpp
//  oscReceiveExample
//
//  Created by Oscar Martinez Carmona on 05/02/2019.
//

#pragma once

#include "ofxOsc.h"
#include "OSCHandler.hpp"
#include "AudioVisualManager.hpp"
#include <iostream>

class AVServer{
    ofxOscReceiver oscReceiver;
    OSCHandler oscHandler;
    AudioVisualManager manageAV;

public:
    AVServer();
    void begin(int port);
    void update();
    void draw();
};
