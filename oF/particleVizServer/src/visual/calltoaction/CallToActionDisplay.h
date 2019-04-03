#ifndef _CallToActionDisplay
#define _CallToActionDisplay
#include "ofMain.h"
#include "ParticleData.h"
#include "Particle.h"
#include "CallToActionText.h"
#include "ofxCenteredTrueTypeFont.h"

class CallToActionDisplay {
  private:
    static ofxXmlSettings xmlTexts;
    vector<CallToActionText> textList;
    void setTextList();
    int selectedText;

    vector<shared_ptr<Particle>> particleList;
    void setParticleList();
    int selectedParticle;

  public:
    void setNewParticle();
    void setNewText();
    void update();
    void drawImage();
    void drawText();
    CallToActionDisplay();
};
#endif
