#ifndef _Baryon //
#define _Baryon //
#include "ofMain.h"
#include "Model.h"

class Baryon: public Model {
  private:
    void setXMLSettingsName();

    void specificParameters();

  public:
    Baryon(shared_ptr<ParticleData>& _particleData);

};
#endif
