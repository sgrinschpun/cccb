#ifndef _CallToActionDisplay
#define _CallToActionDisplay
#include "ofMain.h"
#include "ParticleData.h"
#include "Particle.h"

class CallToActionDisplay {
  private:
    static ofTrueTypeFont myFont;
    void setupFont();

    vector<shared_ptr<Particle>> particleList;
    void setParticleList();
    int selectedParticle;

  public:
    void setNew();
    void update();
    void draw();
    CallToActionDisplay();

};
#endif
