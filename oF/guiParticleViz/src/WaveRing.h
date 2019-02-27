#ifndef _WaveRing //
#define _WaveRing //
#include "ofMain.h"
#include "ofxFatLine.h"
#include "Cycle.h"

class WaveRing {

  private:

    //shape
    ofxFatLine fatLine;
    vector<ofDefaultVec3> fatLinePoints;
    vector<ofFloatColor> fatLineColors;
    vector<double> fatLineWidths;
    int segments;
    float width;
    float noiseStep;
    float noiseAmount;
    float noiseCursor;
    //variation
    float radius;
    ofVec3f rotate;
    float speed_noise;
    float speed;
    ofVec3f pos_noise;
    ofVec3f pos;
    ofVec3f rot_noise;
    ofVec3f rot;
    int col;
    float col_speed;
    bool colMode;
    int saturation;
    int brightness;
    int alpha;

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
