#ifdef DEBUG
#define DEBUG_MSG(str) do { std::cout << str << std::endl; } while( false )
#else
#define DEBUG_MSG(str) do { } while ( false )
#endif
#include "Lepton.h"

void Lepton::setXMLSettingsName(){
  string name = data->getName();
  if (name == "e-"||name == "e+"){xmlSettingsName = "electron";}
  else if (name == "mu-"||name == "mu+"){xmlSettingsName = "muon";}
  else if (name == "tau-"||name == "tau+"){xmlSettingsName = "tau";}
}

void Lepton::specificParameters(){

}


Lepton::Lepton(shared_ptr<ParticleData>& _particleData):Model(_particleData){
  setXMLSettingsName();
  buildParameters();
  setShape();
  setInfo();
  specificParameters();
}
