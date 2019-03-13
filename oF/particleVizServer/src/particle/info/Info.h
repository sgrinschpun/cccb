#ifndef _Info
#define _Info
#include "ofMain.h"
#include "ParticleData.h"

class Info {
  private:
    static ofTrueTypeFont myFont;
    void setupFont();
    float radius;



  public:
    shared_ptr<ParticleData> data;

    void drawInfo(ofVec2f& _velocity);

    Info(shared_ptr<ParticleData>& _data, float radius);
    ~Info(){
      data.reset();
    }

  };
  #endif
