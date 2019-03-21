#ifndef _CallToActionModel
#define _CallToActionModel
#include "ofMain.h"
#include "Model.h"

class CallToActionModel: public Model {
  private:
    void setXMLSettingsName() override;
    void specificParameters() override;

  public:
    CallToActionModel(shared_ptr<ParticleData>& _particleData);
    ~CallToActionModel(){}

};
#endif
