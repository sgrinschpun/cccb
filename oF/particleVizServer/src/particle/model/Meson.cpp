#include "Meson.h"

void Meson::setXMLSettingsName(){
  xmlSettingsName = "meson";
}

void Meson::specificParameters(){
  float mass = data->getMass();
  if (mass!=0){radius = 100*mass;}
}

Meson::Meson(shared_ptr<ParticleData>& _particleData):Model(_particleData){
  setXMLSettingsName();
  buildParameters();
  specificParameters();
  setShape();
  setInfo();
}
