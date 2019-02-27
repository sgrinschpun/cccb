#ifndef _WaveRingVariation
#define _WaveRingVariation
#include "ofMain.h"
#include "WaveRing.h"
#include "Cycle.h"

class WaveRingVariation {

public:
    WaveRingVariation();
    void update();
    void draw();

    void setPosition(ofPoint _position);

    void setShapeNum(int _shapesNum);
    void setFadeAmnt(int _fadeAmnt);
    //Variations
    void setRadius(float _radius);
    void setPos(ofVec3f _pos);
    void setRot(ofVec3f _rot);
    void setSpeed(float _speed);
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

    float fboWidth;
    float fboHeight;

private:
  vector<WaveRing> waverings;
  int shapesNum {1};
  int framesPerCycle{50};

  ofFbo rgbaFbo;
  int fadeAmnt{50};
  void drawFbo();
};
#endif
