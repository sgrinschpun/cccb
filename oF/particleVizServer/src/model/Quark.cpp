#include "Quark.h"


void Quark::setXMLSettingsName(){
  xmlSettingsName = "quark";
}

Quark::Quark(shared_ptr<ParticleData>& _particleData):Model(_particleData){

}
