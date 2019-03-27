#ifdef DEBUG
#define DEBUG_MSG(str) do { std::cout << str << std::endl; } while( false )
#else
#define DEBUG_MSG(str) do { } while ( false )
#endif
#include "Boson.h"
#include "Parameters.h"

void Boson::setXMLSettingsName(){
  string name = data->getName();
  if (name == "gamma"){xmlSettingsName = "gamma";}
  else if (name == "h0(H_1)"){xmlSettingsName = "higgs";}
  else if (name == "Z0"){xmlSettingsName = "Z";}
  else if (name == "W+"){xmlSettingsName = "W";}
  else if (name == "W-"){xmlSettingsName = "W";}
}

void Boson::specificParameters(){
  float mass = data->getMass();
  if (mass!=0){radius = baseRadius*mass;}

}

Boson::Boson(shared_ptr<ParticleData>& _particleData):Model(_particleData){
  setXMLSettingsName();
  buildParameters();
  specificParameters();
  setShape();
  setInfo();
}
