#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "WaveRingVariation.h"
#include "ofxXmlSettings.h"


class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    void buildXML();
    void loadXML();

    ofxPanel gui;
    bool guidraw;

    //WaveRing panel parameters
    ofParameter<float> noiseStep;
    ofParameter<float> noiseAmount;
    ofParameter<int> framesPerCycle;
    ofParameter<int> segments;
    ofParameter<float> width;
    //Variations panel parameters
    ofParameter<int> shapesNum;
    ofParameter<int> fadeAmnt;
    ofParameter<float> radius;
    ofParameter<ofVec3f> posAmp;
    ofParameter<ofVec3f> rotAmp;
    ofParameter<float> speedAmp;
    //Color parameters
    ofParameter<bool> colMode;
    ofParameter<int> saturation;
    ofParameter<int> brightness;
    ofParameter<int> alpha;

    vector<WaveRingVariation> shapes;


};
