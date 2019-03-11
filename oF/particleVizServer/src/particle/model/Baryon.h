#ifndef _Baryon //
#define _Baryon //
#include "ofMain.h"
#include "Model.h"

class Baryon: public Model {
  private:
    void setXMLSettingsName() override;
    void specificParameters() override;

  public:
    Baryon(shared_ptr<ParticleData>& _particleData);
    ~Baryon(){}

};
#endif
