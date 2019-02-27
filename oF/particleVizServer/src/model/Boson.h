#ifndef _Boson //
#define _Boson //
#include "ofMain.h"
#include "Model.h"

class Boson: public Model {
  private:
    static ofxXmlSettings settings;
    static ofxXmlSettings setXMLsettings();

  public:
    Boson(shared_ptr<ParticleData>& _particleData);

};
#endif
