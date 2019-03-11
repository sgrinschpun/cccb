#include "Baryon.h"

void Baryon::setXMLSettingsName(){
  xmlSettingsName = "baryon";
}

void Baryon::specificParameters(){

}

Baryon::Baryon(shared_ptr<ParticleData>& _particleData):Model(_particleData){
  setXMLSettingsName();
  buildParameters();
  setShape();
  setInfo();
  specificParameters();
}
