#ifndef _Neutrino //
#define _Neutrino //
#include "ofMain.h"
#include "Model.h"

class Neutrino: public Model {
  private:
    void setXMLSettingsName() override;
    void specificParameters() override;

  public:
    Neutrino(shared_ptr<ParticleData>& _particleData);

};
#endif
