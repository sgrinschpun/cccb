#ifndef _CallToActionDisplay
#define _CallToActionDisplay
#include "ofMain.h"
#include "ParticleData.h"
#include "Particle.h"
#include "ofxCenteredTrueTypeFont.h"

class CallToActionDisplay {
  private:
    static ofxCenteredTrueTypeFont myFont;
    void setupFont();

    vector<shared_ptr<Particle>> particleList;
    void setParticleList();
    int selectedParticle;

    float padding {20};
    void setText(const string &text);

  public:
    void setNew();
    void update();
    void draw();
    CallToActionDisplay();
};
#endif
