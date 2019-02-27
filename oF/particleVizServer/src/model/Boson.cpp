#ifdef DEBUG
#define DEBUG_MSG(str) do { std::cout << str << std::endl; } while( false )
#else
#define DEBUG_MSG(str) do { } while ( false )
#endif
#include "Boson.h"

ofxXmlSettings Boson::settings = setXMLsettings();

ofxXmlSettings Boson::setXMLsettings(){
  ofxXmlSettings set;
  switch(data->getName()){
    case "gamma":
      set.loadFile("settings.xml");
      break;
    case "h0(H_1)":
      set.loadFile("settings.xml");
      break;
    case "Z0":
      set.loadFile("settings.xml");
      break;
    case "W+":
    case "W-":
      set.loadFile("settings.xml");
      break;
  }
  return set
}

Boson::Boson(shared_ptr<ParticleData>& _particleData):Model(_particleData){

}
