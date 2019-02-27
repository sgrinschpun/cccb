#include "Quark.h"

ofxXmlSettings Quark::settings = setXMLsettings();

ofxXmlSettings Quark::setXMLsettings(){
  ofxXmlSettings set;
  set.loadFile("settings.xml");
  return set
}

Quark::Quark(shared_ptr<ParticleData>& _particleData):Model(_particleData){

}
