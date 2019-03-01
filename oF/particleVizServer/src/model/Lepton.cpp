#ifdef DEBUG
#define DEBUG_MSG(str) do { std::cout << str << std::endl; } while( false )
#else
#define DEBUG_MSG(str) do { } while ( false )
#endif
#include "Lepton.h"

void Lepton::setXMLSettingsName(){
  xmlSettingsName = "electron";
}

void Lepton::specificParameters(){

}


Lepton::Lepton(shared_ptr<ParticleData>& _particleData):Model(_particleData){
  setXMLSettingsName();
  buildParameters();
  setShape();
  specificParameters();
}
