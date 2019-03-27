#include "Baryon.h"
#include "Parameters.h"
void Baryon::setXMLSettingsName(){
  xmlSettingsName = "baryon";
}

void Baryon::specificParameters(){
  float mass = data->getMass();
  if (mass!=0){radius = baseRadius*mass;}

}

Baryon::Baryon(shared_ptr<ParticleData>& _particleData):Model(_particleData){
  setXMLSettingsName();
  buildParameters();
  specificParameters();
  setShape();
  setInfo();
}
