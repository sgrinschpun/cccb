#ifndef _WaveRing //
#define _WaveRing //
#include "ofMain.h"
#include "ofxFatLine.h"
#include "Cycle.h"

class WaveRing {

  private:
    ofxFatLine fatLine;
    vector<ofDefaultVec3> fatLinePoints;
    vector<ofFloatColor> fatLineColors;
    vector<double> fatLineWidths;
    int segments {100};
    float width {0};
    float noiseStep {0.0};
    float noiseAmount{0.0};
    float noiseCursor {0.1};
    float radius {0};
    ofVec3f rotate;
    float speed {0.001};
    float speedAmp;
    float speedNoise;
    ofVec3f pos;
    ofVec3f posAmp;
    ofVec3f posNoise;
    ofVec3f rot;
    ofVec3f rotAmp;
    ofVec3f rotNoise;
    int col;
    float colSpeed {1};
    bool colMode {0};
    int saturation {255};
    int brightness {255};
    int alpha {255};

    void setupCircleRing();
    void updateWigglyCircleRing();

  public:
    shared_ptr<Cycle> cycle;

    void draw();
    void update();

    void setNoiseStep(float _noiseStep);
    void setNoiseAmount(float _noiseAmount);
    void setWidth(float _width);
    void setCycle(int _framesPerCycle);
    void setSegments(int _segments);
    void setRadius(float _radius);
    void setPosAmp(ofVec3f _posAmp);
    void setRotAmp(ofVec3f _rotAmp);
    void setSpeedAmp(float _speedAmp);
    void setColorMode(bool _colMode);
    void setSaturation(int _saturation);
    void setBrightness(int _brightness);
    void setAlpha(int _alpha);

    WaveRing(shared_ptr<Cycle>& cycle);

};
#endif
