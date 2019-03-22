#ifndef _CallToActionText
#define _CallToActionText
#include "ofMain.h"
#include "ofxCenteredTrueTypeFont.h"

class CallToActionText {
  private:
    static ofxCenteredTrueTypeFont myFont;
    void setupFont();

    string ca;
    string en;
    string es;

    float padding {20};

  public:
    void draw();
    void update();

    CallToActionText(string _ca, string _en, string _es);
    ~CallToActionText(){}
};
#endif
