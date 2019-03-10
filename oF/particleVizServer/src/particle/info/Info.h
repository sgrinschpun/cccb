#ifndef _Info
#define _Info
#include "ofMain.h"
#include "ParticleData.h"

class Info {
  private:
    static ofTrueTypeFont myFont;
    void setupFont();



  public:
    shared_ptr<ParticleData> data;

    void drawInfo();

    Info(shared_ptr<ParticleData>& _particleData);
    ~Info(){
      data.reset();
    }

  };
  #endif
