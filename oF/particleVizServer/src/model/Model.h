#ifndef _Model //
#define _Model //
#include "ofMain.h"
#include "WaveRingVariation.h"
#include "ParticleData.h"
#include "ofxXmlSettings.h"


class Model {
  private:

  void buildParameters();
  void setShape();
  void specificParameters();

  public:
    shared_ptr<WaveRingVariation> shape;
    shared_ptr<ParticleData> data;

    int shapesNum;
    float radius;
    float width;
    int segments;
    float speed;
    ofVec3f pos;
    ofVec3f rot;
    int framesPerCycle;
    float noiseStep;
    float noiseAmount;
    int fadeAmnt;
    bool colorMode;
    int saturation;
    int brightness;
    int alpha;

    void draw();
    void update();

    void setPosition(ofPoint _position);

    Model(shared_ptr<ParticleData>& _particleData);

};
#endif
