#ifndef _Info
#define _Info
#include "ofMain.h"
#include "FontsManager.h"
#include "ParticleData.h"

class Info {
  private:
    shared_ptr<ofxCenteredTrueTypeFont> infoFont;

    string getName();

  public:
    shared_ptr<ParticleData> data;
    float radius;

    void drawInfo(ofVec2f& _velocity);

    Info(shared_ptr<ParticleData>& _data, float radius);
    ~Info(){
      data.reset();
    }

};
#endif
