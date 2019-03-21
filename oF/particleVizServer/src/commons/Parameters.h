#ifndef _Parameters //
#define _Parameters //
#include "ofMain.h"
#include "ofxXmlSettings.h"

class Parameters {
  private:
    static shared_ptr<ofxXmlSettings> xmlParameters;
    static shared_ptr<ofxXmlSettings> setXMLParameters();
  public:
    static float BMag;
    static float setBMag();
    static float velocityAmp;
    static float setVelocityAmp();
    static float fadeAmnt;
    static float setFadeAmnt();
    static float baseRadius;
    static float setBaseRadius();

};
#endif
