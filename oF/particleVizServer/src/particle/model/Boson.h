#ifndef _Boson //
#define _Boson //
#include "ofMain.h"
#include "Model.h"

class Boson: public Model {
  private:
    void setXMLSettingsName() override;
    void specificParameters() override;

  public:
    Boson(shared_ptr<ParticleData>& _particleData);
    ~Boson(){}

};
#endif
