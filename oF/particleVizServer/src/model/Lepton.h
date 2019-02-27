#ifndef _Lepton //
#define _Lepton //
#include "ofMain.h"
#include "Model.h"

class Lepton: public Model {
  private:
    static ofxXmlSettings settings;
    static ofxXmlSettings setXMLsettings();

  public:
    Lepton(shared_ptr<ParticleData>& _particleData);

};
#endif
