#pragma once
#include "ofMain.h"
#include "WaveRing.h"
#include "Cycle.h"
#include "ofxGifEncoder.h"

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

    //Gif
    shared_ptr<ofxGifEncoder> gifEncoder;
    ofPixels pixels;
    ofImage imgforgif;
    int framesTotal {60};
    int framesCurr {0};
    bool start {false};
    void getGIF();
    void GIFstart();

    //screenCapture
    void screenCapture();
    int imgcount {0};
    ofImage img;

    //bigfile
    float fboWidth;
    float fboHeight;

private:
    vector<WaveRing> waverings;
    int shapesNum {10};
    int fadeAmnt {50};
    int framesPerCycle {50};

    ofFbo rgbaFbo;
    void drawFbo();
};
