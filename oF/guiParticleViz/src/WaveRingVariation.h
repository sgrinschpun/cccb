#pragma once
#include "ofMain.h"
#include "WaveRing.h"
#include "Cycle.h"
#include "ofxGifEncoder.h"
#include "Kinematics.h"

class WaveRingVariation {

public:
    WaveRingVariation();
    void update();
    void draw();

    void setShapeNum(int shapesNum);
    void setFadeAmnt(int fadeAmnt);
    //Variations
    void setRadius(float radius);
    void setPosAmp(ofVec3f _posAmp);
    void setRotAmp(ofVec3f _rotAmp);
    void setSpeedAmp(float _speedAmp);
    void setColorMode(bool colMode);
    void setStauration(int saturation);
    void setBrightness(int brightness);
    void setAlpha(int alpha);
    //shape
    void setNoiseStep(float noiseStep);
    void setNoiseAmount(float noiseAmount);
    void setWidth(float width);
    void setCycle(int framesPerCycle);
    void setSegments(int segments);

    shared_ptr<Cycle> cycle;
    shared_ptr<Kinematics> kinematics;
    ofPoint getPosition();

private:
    vector<WaveRing> waverings;
    int shapesNum {10};
    int fadeAmnt {50};
    int framesPerCycle {50};
};
