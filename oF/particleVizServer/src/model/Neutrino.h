#ifndef _Neutrino //
#define _Neutrino //
#include "ofMain.h"
#include "Model.h"

class Neutrino: public Model {
  private:
    static ofxXmlSettings settings;
    static ofxXmlSettings setXMLsettings();

  public:
    Neutrino(shared_ptr<ParticleData>& _particleData);

};
#endif
