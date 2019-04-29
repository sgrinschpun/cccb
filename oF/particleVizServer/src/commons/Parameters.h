#ifndef _Parameters //
#define _Parameters //
#include "ofMain.h"
#include "ofxXmlSettings.h"

class Parameters {
  private:
    static shared_ptr<ofxXmlSettings> xmlParameters;
    //static shared_ptr<ofxXmlSettings> setXMLParameters();
  public:
    static float BMag;
    static float setBMag();
    static float velocityAmp;
    static float setVelocityAmp();
    static float fadeAmnt;
    static float setFadeAmnt();
    static float baseRadius;
    static float setBaseRadius();
    static int OSCInPort;
    static int setOSCInPort();
    static int OSCOutPort;
    static int setOSCOutPort();
    static int OSCKillPort;
    static int setOSCKillPort();
    static int maxNumPart;
    static int setMaxNumPart();
    static int CTADelay;
    static int setCTADelay();
    static int CTATextChange;
    static int setCTATextChange();
    static int CTATextSeparation;
    static int setCTATextSeparation();
    static int CTATextPadding;
    static int setCTATextPadding();

};
#endif
