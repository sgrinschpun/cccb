#ifdef DEBUG
#define DEBUG_MSG(str) do { std::cout << str << std::endl; } while( false )
#else
#define DEBUG_MSG(str) do { } while ( false )
#endif
#include "Boson.h"

void Boson::setXMLSettingsName(){
  string name = data->getName();
  if (name == "gamma"){xmlSettingsName = "gamma";}
  else if (name == "h0(H_1)"){xmlSettingsName = "higgs";}
  else if (name == "Z0"){xmlSettingsName = "Z0";}
  else if (name == "W+"){xmlSettingsName = "W";}
  else if (name == "W-"){xmlSettingsName = "W";}
}

Boson::Boson(shared_ptr<ParticleData>& _particleData):Model(_particleData){

}
