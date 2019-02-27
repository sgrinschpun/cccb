#include "Lepton.h"

void Lepton::setXMLSettingsName(){
  xmlSettingsName = "settings.xml";
}

Lepton::Lepton(shared_ptr<ParticleData>& _particleData):Model(_particleData){

}
