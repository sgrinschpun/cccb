#include "Meson.h"

void Meson::setXMLSettingsName(){
  xmlSettingsName = "meson";
}

void Meson::specificParameters(){
}

Meson::Meson(shared_ptr<ParticleData>& _particleData):Model(_particleData){
  setXMLSettingsName();
  buildParameters();
  specificParameters();
  setShape();
  setInfo();
}
