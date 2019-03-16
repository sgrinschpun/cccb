#include "CallToActionModel.h"

void CallToActionModel::setXMLSettingsName(){
  xmlSettingsName = data->getName();
}

void CallToActionModel::specificParameters(){

}

CallToActionModel::CallToActionModel(shared_ptr<ParticleData>& _particleData):Model(_particleData){
  setXMLSettingsName();
  buildParameters();
  specificParameters();
  setShape();
  setInfo();
}
