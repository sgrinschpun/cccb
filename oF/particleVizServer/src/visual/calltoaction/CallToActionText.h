#ifndef _CallToActionText
#define _CallToActionText
#include "ofMain.h"
#include "FontsManager.h"
#include "ofxCenteredTrueTypeFont.h"

class CallToActionText {
  private:
    shared_ptr<ofxCenteredTrueTypeFont> ctaFont;

    string ca;
    string en;
    string es;

    float padding;
    float separation;

  public:
    void draw();
    void update();

    CallToActionText(string _ca, string _en, string _es);
    ~CallToActionText(){}
};
#endif
