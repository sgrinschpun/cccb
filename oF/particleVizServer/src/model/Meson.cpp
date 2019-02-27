#include "Meson.h"

ofxXmlSettings Meson::settings = setXMLsettings();

ofxXmlSettings Meson::setXMLsettings(){
  ofxXmlSettings set;
  set.loadFile("settings.xml");
  return set
}

void Meson::specificParameters(){

}

Meson::Meson(shared_ptr<ParticleData>& _particleData):Model(_particleData){

}
