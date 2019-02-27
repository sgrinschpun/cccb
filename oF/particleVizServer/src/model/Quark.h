#ifndef _Quark //
#define _Quark //
#include "ofMain.h"
#include "Model.h"

class Quark: public Model {
  private:
    static ofxXmlSettings settings;
    static ofxXmlSettings setXMLsettings();

  public:
    Quark(shared_ptr<ParticleData>& _particleData);

};
#endif
