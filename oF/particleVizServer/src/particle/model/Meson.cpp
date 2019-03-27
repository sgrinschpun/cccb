#include "Meson.h"
#include "Parameters.h"
void Meson::setXMLSettingsName(){
  xmlSettingsName = "meson";
}

void Meson::specificParameters(){
  float mass = data->getMass();
  if (mass!=0){radius = Parameters::baseRadius*mass;}
}

Meson::Meson(shared_ptr<ParticleData>& _particleData):Model(_particleData){
  setXMLSettingsName();
  buildParameters();
  specificParameters();
  setShape();
  setInfo();
}
