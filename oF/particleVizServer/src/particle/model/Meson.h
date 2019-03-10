#ifndef _Meson //
#define _Meson //
#include "ofMain.h"
#include "Model.h"

class Meson: public Model {
  private:
    void setXMLSettingsName() override;
    void specificParameters() override;

  public:
    Meson(shared_ptr<ParticleData>& _particleData);
    ~Meson(){}

};
#endif
