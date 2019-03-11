#include "Quark.h"


void Quark::setXMLSettingsName(){
  xmlSettingsName = "quark";
}

void Quark::specificParameters(){

}

Quark::Quark(shared_ptr<ParticleData>& _particleData):Model(_particleData){
  setXMLSettingsName();
  buildParameters();
  setShape();
  setInfo();
  specificParameters();
}
