#include "Baryon.h"

ofxXmlSettings Baryon::settings = setXMLsettings();

ofxXmlSettings Baryon::setXMLsettings(){
  ofxXmlSettings set;
  set.loadFile("settings.xml");
  return set;
}

void Baryon::specificParameters(){

}

Baryon::Baryon(shared_ptr<ParticleData>& _particleData):Model(_particleData){

}
