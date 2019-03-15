#ifndef _WaveRingVariation
#define _WaveRingVariation
#include "ofMain.h"
#include "WaveRing.h"
#include "Cycle.h"

class WaveRingVariation {

public:
    WaveRingVariation();

    ~WaveRingVariation(){
      cycle.reset();
    }

    void update();
    void draw();

    void setShapeNum(int _shapesNum);
    //Variations
    void setRadius(float _radius);
    void setPosAmp(ofVec3f _posAmp);
    void setRotAmp(ofVec3f _rotAmp);
    void setSpeedAmp(float _speedAmp);
    void setColorMode(bool _colMode);
    void setSaturation(int _saturation);
    void setBrightness(int _brightness);
    void setAlpha(int _alpha);
    //shape
    void setNoiseStep(float _noiseStep);
    void setNoiseAmount(float _noiseAmount);
    void setWidth(float _width);
    void setCycle(int _framesPerCycle);
    void setSegments(int _segments);

    shared_ptr<Cycle> cycle;

private:
  vector<unique_ptr<WaveRing>> waverings;
  float radius;
  int shapesNum {1};
  int framesPerCycle{50};

};
#endif
