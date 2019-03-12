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
  //float mass = data->getMass();
  //if (mass!=0){radius = 100*mass;}

  string name = data->getName();
  const string antileptons[] = {"e+", "mu+", "tau+"};
  auto it = find(begin(antileptons), end(antileptons), name);
  if (it != end(antileptons)) {
    colMode = 1;
    width=10;
  }


}


Lepton::Lepton(shared_ptr<ParticleData>& _particleData):Model(_particleData){
  setXMLSettingsName();
  buildParameters();
  specificParameters();
  setShape();
  setInfo();
}
