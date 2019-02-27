#ifndef _Baryon //
#define _Baryon //
#include "ofMain.h"
#include "Model.h"

class Baryon: public Model {
  private:
    static ofxXmlSettings settings;
    static ofxXmlSettings setXMLsettings();

    void specificParameters();

  public:
    Baryon(shared_ptr<ParticleData>& _particleData);

};
#endif
