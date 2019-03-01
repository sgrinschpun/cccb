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
    float speedNoise {ofRandom(10)};
    float speed {ofRandom(10)/10000};
    ofVec3f posNoise;
    ofVec3f pos;
    ofVec3f rotNoise;
    ofVec3f rot;
    int col {0};
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

    //shape
    void setNoiseStep(float _noiseStep);
    void setNoiseAmount(float _noiseAmount);
    void setWidth(float _width);
    void setCycle(int _framesPerCycle);
    void setSegments(int _segments);
    //variation
    void setRadius(float radius);
    void setPosAmp(ofVec3f pos);
    void setRotAmp(ofVec3f rot);
    void setSpeedAmp(float speed);
    void setColorMode(bool colMode);
    void setStauration(int saturation);
    void setBrightness(int brightness);
    void setAlpha(int alpha);

    WaveRing(shared_ptr<Cycle>& cycle);

};
#endif
