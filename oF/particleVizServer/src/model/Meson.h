#ifndef _Meson //
#define _Meson //
#include "ofMain.h"
#include "Model.h"

class Meson: public Model {
  private:
    static ofxXmlSettings settings;
    static ofxXmlSettings setXMLsettings();

    void specificParameters();

  public:
    Meson(shared_ptr<ParticleData>& _particleData);

};
#endif
